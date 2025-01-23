#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version_migration_status.h"



v1alpha1_storage_version_migration_status_t *v1alpha1_storage_version_migration_status_create(
    list_t *conditions,
    char *resource_version
    ) {
    v1alpha1_storage_version_migration_status_t *v1alpha1_storage_version_migration_status_local_var = malloc(sizeof(v1alpha1_storage_version_migration_status_t));
    if (!v1alpha1_storage_version_migration_status_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_migration_status_local_var->conditions = conditions;
    v1alpha1_storage_version_migration_status_local_var->resource_version = resource_version;

    return v1alpha1_storage_version_migration_status_local_var;
}


void v1alpha1_storage_version_migration_status_free(v1alpha1_storage_version_migration_status_t *v1alpha1_storage_version_migration_status) {
    if(NULL == v1alpha1_storage_version_migration_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version_migration_status->conditions) {
        list_ForEach(listEntry, v1alpha1_storage_version_migration_status->conditions) {
            v1alpha1_migration_condition_free(listEntry->data);
        }
        list_freeList(v1alpha1_storage_version_migration_status->conditions);
        v1alpha1_storage_version_migration_status->conditions = NULL;
    }
    if (v1alpha1_storage_version_migration_status->resource_version) {
        free(v1alpha1_storage_version_migration_status->resource_version);
        v1alpha1_storage_version_migration_status->resource_version = NULL;
    }
    free(v1alpha1_storage_version_migration_status);
}

mazu_cJSON *v1alpha1_storage_version_migration_status_convertToJSON(v1alpha1_storage_version_migration_status_t *v1alpha1_storage_version_migration_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_storage_version_migration_status->conditions
    if(v1alpha1_storage_version_migration_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1alpha1_storage_version_migration_status->conditions) {
    list_ForEach(conditionsListEntry, v1alpha1_storage_version_migration_status->conditions) {
    mazu_cJSON *itemLocal = v1alpha1_migration_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1alpha1_storage_version_migration_status->resource_version
    if(v1alpha1_storage_version_migration_status->resource_version) {
    if(mazu_cJSON_AddStringToObject(item, "resourceVersion", v1alpha1_storage_version_migration_status->resource_version) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_storage_version_migration_status_t *v1alpha1_storage_version_migration_status_parseFromJSON(mazu_cJSON *v1alpha1_storage_version_migration_statusJSON){

    v1alpha1_storage_version_migration_status_t *v1alpha1_storage_version_migration_status_local_var = NULL;

    // define the local list for v1alpha1_storage_version_migration_status->conditions
    list_t *conditionsList = NULL;

    // v1alpha1_storage_version_migration_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migration_statusJSON, "conditions");
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
        v1alpha1_migration_condition_t *conditionsItem = v1alpha1_migration_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1alpha1_storage_version_migration_status->resource_version
    mazu_cJSON *resource_version = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_migration_statusJSON, "resourceVersion");
    if (resource_version) { 
    if(!mazu_cJSON_IsString(resource_version) && !mazu_cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }


    v1alpha1_storage_version_migration_status_local_var = v1alpha1_storage_version_migration_status_create (
        conditions ? conditionsList : NULL,
        resource_version && !mazu_cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL
        );

    return v1alpha1_storage_version_migration_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1alpha1_migration_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
