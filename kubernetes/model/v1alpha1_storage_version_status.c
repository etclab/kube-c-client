#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version_status.h"



v1alpha1_storage_version_status_t *v1alpha1_storage_version_status_create(
    char *common_encoding_version,
    list_t *conditions,
    list_t *storage_versions
    ) {
    v1alpha1_storage_version_status_t *v1alpha1_storage_version_status_local_var = malloc(sizeof(v1alpha1_storage_version_status_t));
    if (!v1alpha1_storage_version_status_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_status_local_var->common_encoding_version = common_encoding_version;
    v1alpha1_storage_version_status_local_var->conditions = conditions;
    v1alpha1_storage_version_status_local_var->storage_versions = storage_versions;

    return v1alpha1_storage_version_status_local_var;
}


void v1alpha1_storage_version_status_free(v1alpha1_storage_version_status_t *v1alpha1_storage_version_status) {
    if(NULL == v1alpha1_storage_version_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version_status->common_encoding_version) {
        free(v1alpha1_storage_version_status->common_encoding_version);
        v1alpha1_storage_version_status->common_encoding_version = NULL;
    }
    if (v1alpha1_storage_version_status->conditions) {
        list_ForEach(listEntry, v1alpha1_storage_version_status->conditions) {
            v1alpha1_storage_version_condition_free(listEntry->data);
        }
        list_freeList(v1alpha1_storage_version_status->conditions);
        v1alpha1_storage_version_status->conditions = NULL;
    }
    if (v1alpha1_storage_version_status->storage_versions) {
        list_ForEach(listEntry, v1alpha1_storage_version_status->storage_versions) {
            v1alpha1_server_storage_version_free(listEntry->data);
        }
        list_freeList(v1alpha1_storage_version_status->storage_versions);
        v1alpha1_storage_version_status->storage_versions = NULL;
    }
    free(v1alpha1_storage_version_status);
}

mazu_cJSON *v1alpha1_storage_version_status_convertToJSON(v1alpha1_storage_version_status_t *v1alpha1_storage_version_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_storage_version_status->common_encoding_version
    if(v1alpha1_storage_version_status->common_encoding_version) {
    if(mazu_cJSON_AddStringToObject(item, "commonEncodingVersion", v1alpha1_storage_version_status->common_encoding_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_storage_version_status->conditions
    if(v1alpha1_storage_version_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha1_storage_version_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha1_storage_version_status->conditions) {
    mazu_cJSON *itemLocal = v1alpha1_storage_version_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1alpha1_storage_version_status->storage_versions
    if(v1alpha1_storage_version_status->storage_versions) {
    mazu_cJSON *storage_versions = mazu_cJSON_AddArrayToObject(item, "storageVersions");
    if(storage_versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *storage_versionsListEntry;
    if (v1alpha1_storage_version_status->storage_versions) {
    list_ForEach(storage_versionsListEntry, v1alpha1_storage_version_status->storage_versions) {
    mazu_cJSON *itemLocal = v1alpha1_server_storage_version_convertToJSON(storage_versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(storage_versions, itemLocal);
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

v1alpha1_storage_version_status_t *v1alpha1_storage_version_status_parseFromJSON(mazu_cJSON *v1alpha1_storage_version_statusJSON){

    v1alpha1_storage_version_status_t *v1alpha1_storage_version_status_local_var = NULL;

    // define the local list for v1alpha1_storage_version_status->conditions
    list_t *conditionsList = NULL;

    // define the local list for v1alpha1_storage_version_status->storage_versions
    list_t *storage_versionsList = NULL;

    // v1alpha1_storage_version_status->common_encoding_version
    mazu_cJSON *common_encoding_version = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_statusJSON, "commonEncodingVersion");
    if (common_encoding_version) { 
    if(!mazu_cJSON_IsString(common_encoding_version) && !mazu_cJSON_IsNull(common_encoding_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_statusJSON, "conditions");
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
        v1alpha1_storage_version_condition_t *conditionsItem = v1alpha1_storage_version_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1alpha1_storage_version_status->storage_versions
    mazu_cJSON *storage_versions = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_statusJSON, "storageVersions");
    if (storage_versions) { 
    mazu_cJSON *storage_versions_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(storage_versions)){
        goto end; //nonprimitive container
    }

    storage_versionsList = list_createList();

    mazu_cJSON_ArrayForEach(storage_versions_local_nonprimitive,storage_versions )
    {
        if(!mazu_cJSON_IsObject(storage_versions_local_nonprimitive)){
            goto end;
        }
        v1alpha1_server_storage_version_t *storage_versionsItem = v1alpha1_server_storage_version_parseFromJSON(storage_versions_local_nonprimitive);

        list_addElement(storage_versionsList, storage_versionsItem);
    }
    }


    v1alpha1_storage_version_status_local_var = v1alpha1_storage_version_status_create (
        common_encoding_version && !mazu_cJSON_IsNull(common_encoding_version) ? strdup(common_encoding_version->valuestring) : NULL,
        conditions ? conditionsList : NULL,
        storage_versions ? storage_versionsList : NULL
        );

    return v1alpha1_storage_version_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1alpha1_storage_version_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (storage_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, storage_versionsList) {
            v1alpha1_server_storage_version_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(storage_versionsList);
        storage_versionsList = NULL;
    }
    return NULL;

}
