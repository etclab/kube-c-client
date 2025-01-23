#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_field_selector_requirement.h"



v1_field_selector_requirement_t *v1_field_selector_requirement_create(
    char *key,
    char *_operator,
    list_t *values
    ) {
    v1_field_selector_requirement_t *v1_field_selector_requirement_local_var = malloc(sizeof(v1_field_selector_requirement_t));
    if (!v1_field_selector_requirement_local_var) {
        return NULL;
    }
    v1_field_selector_requirement_local_var->key = key;
    v1_field_selector_requirement_local_var->_operator = _operator;
    v1_field_selector_requirement_local_var->values = values;

    return v1_field_selector_requirement_local_var;
}


void v1_field_selector_requirement_free(v1_field_selector_requirement_t *v1_field_selector_requirement) {
    if(NULL == v1_field_selector_requirement){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_field_selector_requirement->key) {
        free(v1_field_selector_requirement->key);
        v1_field_selector_requirement->key = NULL;
    }
    if (v1_field_selector_requirement->_operator) {
        free(v1_field_selector_requirement->_operator);
        v1_field_selector_requirement->_operator = NULL;
    }
    if (v1_field_selector_requirement->values) {
        list_ForEach(listEntry, v1_field_selector_requirement->values) {
            free(listEntry->data);
        }
        list_freeList(v1_field_selector_requirement->values);
        v1_field_selector_requirement->values = NULL;
    }
    free(v1_field_selector_requirement);
}

mazu_cJSON *v1_field_selector_requirement_convertToJSON(v1_field_selector_requirement_t *v1_field_selector_requirement) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_field_selector_requirement->key
    if (!v1_field_selector_requirement->key) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "key", v1_field_selector_requirement->key) == NULL) {
    goto fail; //String
    }


    // v1_field_selector_requirement->_operator
    if (!v1_field_selector_requirement->_operator) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "operator", v1_field_selector_requirement->_operator) == NULL) {
    goto fail; //String
    }


    // v1_field_selector_requirement->values
    if(v1_field_selector_requirement->values) {
    mazu_cJSON *values = mazu_cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_field_selector_requirement->values) {
    if(mazu_cJSON_AddStringToObject(values, "", (char*)valuesListEntry->data) == NULL)
    {
        goto fail;
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

v1_field_selector_requirement_t *v1_field_selector_requirement_parseFromJSON(mazu_cJSON *v1_field_selector_requirementJSON){

    v1_field_selector_requirement_t *v1_field_selector_requirement_local_var = NULL;

    // define the local list for v1_field_selector_requirement->values
    list_t *valuesList = NULL;

    // v1_field_selector_requirement->key
    mazu_cJSON *key = mazu_cJSON_GetObjectItemCaseSensitive(v1_field_selector_requirementJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_field_selector_requirement->_operator
    mazu_cJSON *_operator = mazu_cJSON_GetObjectItemCaseSensitive(v1_field_selector_requirementJSON, "operator");
    if (!_operator) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(_operator))
    {
    goto end; //String
    }

    // v1_field_selector_requirement->values
    mazu_cJSON *values = mazu_cJSON_GetObjectItemCaseSensitive(v1_field_selector_requirementJSON, "values");
    if (values) { 
    mazu_cJSON *values_local = NULL;
    if(!mazu_cJSON_IsArray(values)) {
        goto end;//primitive container
    }
    valuesList = list_createList();

    mazu_cJSON_ArrayForEach(values_local, values)
    {
        if(!mazu_cJSON_IsString(values_local))
        {
            goto end;
        }
        list_addElement(valuesList , strdup(values_local->valuestring));
    }
    }


    v1_field_selector_requirement_local_var = v1_field_selector_requirement_create (
        strdup(key->valuestring),
        strdup(_operator->valuestring),
        values ? valuesList : NULL
        );

    return v1_field_selector_requirement_local_var;
end:
    if (valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valuesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valuesList);
        valuesList = NULL;
    }
    return NULL;

}
