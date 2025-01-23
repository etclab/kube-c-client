#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_label_selector.h"



v1_label_selector_t *v1_label_selector_create(
    list_t *match_expressions,
    list_t* match_labels
    ) {
    v1_label_selector_t *v1_label_selector_local_var = malloc(sizeof(v1_label_selector_t));
    if (!v1_label_selector_local_var) {
        return NULL;
    }
    v1_label_selector_local_var->match_expressions = match_expressions;
    v1_label_selector_local_var->match_labels = match_labels;

    return v1_label_selector_local_var;
}


void v1_label_selector_free(v1_label_selector_t *v1_label_selector) {
    if(NULL == v1_label_selector){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_label_selector->match_expressions) {
        list_ForEach(listEntry, v1_label_selector->match_expressions) {
            v1_label_selector_requirement_free(listEntry->data);
        }
        list_freeList(v1_label_selector->match_expressions);
        v1_label_selector->match_expressions = NULL;
    }
    if (v1_label_selector->match_labels) {
        list_ForEach(listEntry, v1_label_selector->match_labels) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_label_selector->match_labels);
        v1_label_selector->match_labels = NULL;
    }
    free(v1_label_selector);
}

mazu_cJSON *v1_label_selector_convertToJSON(v1_label_selector_t *v1_label_selector) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_label_selector->match_expressions
    if(v1_label_selector->match_expressions) {
    mazu_cJSON *match_expressions = mazu_cJSON_AddArrayToObject(item, "matchExpressions");
    if(match_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_expressionsListEntry;
    if (v1_label_selector->match_expressions) {
    list_ForEach(match_expressionsListEntry, v1_label_selector->match_expressions) {
    mazu_cJSON *itemLocal = v1_label_selector_requirement_convertToJSON(match_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(match_expressions, itemLocal);
    }
    }
    }


    // v1_label_selector->match_labels
    if(v1_label_selector->match_labels) {
    mazu_cJSON *match_labels = mazu_cJSON_AddObjectToObject(item, "matchLabels");
    if(match_labels == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = match_labels;
    listEntry_t *match_labelsListEntry;
    if (v1_label_selector->match_labels) {
    list_ForEach(match_labelsListEntry, v1_label_selector->match_labels) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)match_labelsListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_label_selector_t *v1_label_selector_parseFromJSON(mazu_cJSON *v1_label_selectorJSON){

    v1_label_selector_t *v1_label_selector_local_var = NULL;

    // define the local list for v1_label_selector->match_expressions
    list_t *match_expressionsList = NULL;

    // define the local map for v1_label_selector->match_labels
    list_t *match_labelsList = NULL;

    // v1_label_selector->match_expressions
    mazu_cJSON *match_expressions = mazu_cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchExpressions");
    if (match_expressions) { 
    mazu_cJSON *match_expressions_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(match_expressions)){
        goto end; //nonprimitive container
    }

    match_expressionsList = list_createList();

    mazu_cJSON_ArrayForEach(match_expressions_local_nonprimitive,match_expressions )
    {
        if(!mazu_cJSON_IsObject(match_expressions_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_requirement_t *match_expressionsItem = v1_label_selector_requirement_parseFromJSON(match_expressions_local_nonprimitive);

        list_addElement(match_expressionsList, match_expressionsItem);
    }
    }

    // v1_label_selector->match_labels
    mazu_cJSON *match_labels = mazu_cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchLabels");
    if (match_labels) { 
    mazu_cJSON *match_labels_local_map = NULL;
    if(!mazu_cJSON_IsObject(match_labels) && !mazu_cJSON_IsNull(match_labels))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(match_labels))
    {
        match_labelsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(match_labels_local_map, match_labels)
        {
            mazu_cJSON *localMapObject = match_labels_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(match_labelsList , localMapKeyPair);
        }
    }
    }


    v1_label_selector_local_var = v1_label_selector_create (
        match_expressions ? match_expressionsList : NULL,
        match_labels ? match_labelsList : NULL
        );

    return v1_label_selector_local_var;
end:
    if (match_expressionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_expressionsList) {
            v1_label_selector_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_expressionsList);
        match_expressionsList = NULL;
    }
    if (match_labelsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_labelsList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(match_labelsList);
        match_labelsList = NULL;
    }
    return NULL;

}
