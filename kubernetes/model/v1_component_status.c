#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_component_status.h"



v1_component_status_t *v1_component_status_create(
    char *api_version,
    list_t *conditions,
    char *kind,
    v1_object_meta_t *metadata
    ) {
    v1_component_status_t *v1_component_status_local_var = malloc(sizeof(v1_component_status_t));
    if (!v1_component_status_local_var) {
        return NULL;
    }
    v1_component_status_local_var->api_version = api_version;
    v1_component_status_local_var->conditions = conditions;
    v1_component_status_local_var->kind = kind;
    v1_component_status_local_var->metadata = metadata;

    return v1_component_status_local_var;
}


void v1_component_status_free(v1_component_status_t *v1_component_status) {
    if(NULL == v1_component_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_component_status->api_version) {
        free(v1_component_status->api_version);
        v1_component_status->api_version = NULL;
    }
    if (v1_component_status->conditions) {
        list_ForEach(listEntry, v1_component_status->conditions) {
            v1_component_condition_free(listEntry->data);
        }
        list_freeList(v1_component_status->conditions);
        v1_component_status->conditions = NULL;
    }
    if (v1_component_status->kind) {
        free(v1_component_status->kind);
        v1_component_status->kind = NULL;
    }
    if (v1_component_status->metadata) {
        v1_object_meta_free(v1_component_status->metadata);
        v1_component_status->metadata = NULL;
    }
    free(v1_component_status);
}

mazu_cJSON *v1_component_status_convertToJSON(v1_component_status_t *v1_component_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_component_status->api_version
    if(v1_component_status->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_component_status->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_component_status->conditions
    if(v1_component_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_component_status->conditions) {
    list_ForEach(conditionsListEntry, v1_component_status->conditions) {
    mazu_cJSON *itemLocal = v1_component_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_component_status->kind
    if(v1_component_status->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_component_status->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_component_status->metadata
    if(v1_component_status->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_component_status->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_component_status_t *v1_component_status_parseFromJSON(mazu_cJSON *v1_component_statusJSON){

    v1_component_status_t *v1_component_status_local_var = NULL;

    // define the local list for v1_component_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_component_status->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1_component_status->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_component_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "conditions");
    if (conditions) { 
    mazu_cJSON *conditions_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    mazu_cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!mazu_cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_component_condition_t *conditionsItem = v1_component_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_component_status->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_component_status->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_component_statusJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_component_status_local_var = v1_component_status_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        conditions ? conditionsList : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_component_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_component_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
