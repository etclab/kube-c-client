#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_named_rule_with_operations.h"



v1_named_rule_with_operations_t *v1_named_rule_with_operations_create(
    list_t *api_groups,
    list_t *api_versions,
    list_t *operations,
    list_t *resource_names,
    list_t *resources,
    char *scope
    ) {
    v1_named_rule_with_operations_t *v1_named_rule_with_operations_local_var = malloc(sizeof(v1_named_rule_with_operations_t));
    if (!v1_named_rule_with_operations_local_var) {
        return NULL;
    }
    v1_named_rule_with_operations_local_var->api_groups = api_groups;
    v1_named_rule_with_operations_local_var->api_versions = api_versions;
    v1_named_rule_with_operations_local_var->operations = operations;
    v1_named_rule_with_operations_local_var->resource_names = resource_names;
    v1_named_rule_with_operations_local_var->resources = resources;
    v1_named_rule_with_operations_local_var->scope = scope;

    return v1_named_rule_with_operations_local_var;
}


void v1_named_rule_with_operations_free(v1_named_rule_with_operations_t *v1_named_rule_with_operations) {
    if(NULL == v1_named_rule_with_operations){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_named_rule_with_operations->api_groups) {
        list_ForEach(listEntry, v1_named_rule_with_operations->api_groups) {
            free(listEntry->data);
        }
        list_freeList(v1_named_rule_with_operations->api_groups);
        v1_named_rule_with_operations->api_groups = NULL;
    }
    if (v1_named_rule_with_operations->api_versions) {
        list_ForEach(listEntry, v1_named_rule_with_operations->api_versions) {
            free(listEntry->data);
        }
        list_freeList(v1_named_rule_with_operations->api_versions);
        v1_named_rule_with_operations->api_versions = NULL;
    }
    if (v1_named_rule_with_operations->operations) {
        list_ForEach(listEntry, v1_named_rule_with_operations->operations) {
            free(listEntry->data);
        }
        list_freeList(v1_named_rule_with_operations->operations);
        v1_named_rule_with_operations->operations = NULL;
    }
    if (v1_named_rule_with_operations->resource_names) {
        list_ForEach(listEntry, v1_named_rule_with_operations->resource_names) {
            free(listEntry->data);
        }
        list_freeList(v1_named_rule_with_operations->resource_names);
        v1_named_rule_with_operations->resource_names = NULL;
    }
    if (v1_named_rule_with_operations->resources) {
        list_ForEach(listEntry, v1_named_rule_with_operations->resources) {
            free(listEntry->data);
        }
        list_freeList(v1_named_rule_with_operations->resources);
        v1_named_rule_with_operations->resources = NULL;
    }
    if (v1_named_rule_with_operations->scope) {
        free(v1_named_rule_with_operations->scope);
        v1_named_rule_with_operations->scope = NULL;
    }
    free(v1_named_rule_with_operations);
}

mazu_cJSON *v1_named_rule_with_operations_convertToJSON(v1_named_rule_with_operations_t *v1_named_rule_with_operations) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_named_rule_with_operations->api_groups
    if(v1_named_rule_with_operations->api_groups) {
    mazu_cJSON *api_groups = mazu_cJSON_AddArrayToObject(item, "apiGroups");
    if(api_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1_named_rule_with_operations->api_groups) {
    if(mazu_cJSON_AddStringToObject(api_groups, "", (char*)api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_named_rule_with_operations->api_versions
    if(v1_named_rule_with_operations->api_versions) {
    mazu_cJSON *api_versions = mazu_cJSON_AddArrayToObject(item, "apiVersions");
    if(api_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *api_versionsListEntry;
    list_ForEach(api_versionsListEntry, v1_named_rule_with_operations->api_versions) {
    if(mazu_cJSON_AddStringToObject(api_versions, "", (char*)api_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_named_rule_with_operations->operations
    if(v1_named_rule_with_operations->operations) {
    mazu_cJSON *operations = mazu_cJSON_AddArrayToObject(item, "operations");
    if(operations == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *operationsListEntry;
    list_ForEach(operationsListEntry, v1_named_rule_with_operations->operations) {
    if(mazu_cJSON_AddStringToObject(operations, "", (char*)operationsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_named_rule_with_operations->resource_names
    if(v1_named_rule_with_operations->resource_names) {
    mazu_cJSON *resource_names = mazu_cJSON_AddArrayToObject(item, "resourceNames");
    if(resource_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resource_namesListEntry;
    list_ForEach(resource_namesListEntry, v1_named_rule_with_operations->resource_names) {
    if(mazu_cJSON_AddStringToObject(resource_names, "", (char*)resource_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_named_rule_with_operations->resources
    if(v1_named_rule_with_operations->resources) {
    mazu_cJSON *resources = mazu_cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1_named_rule_with_operations->resources) {
    if(mazu_cJSON_AddStringToObject(resources, "", (char*)resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_named_rule_with_operations->scope
    if(v1_named_rule_with_operations->scope) {
    if(mazu_cJSON_AddStringToObject(item, "scope", v1_named_rule_with_operations->scope) == NULL) {
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

v1_named_rule_with_operations_t *v1_named_rule_with_operations_parseFromJSON(mazu_cJSON *v1_named_rule_with_operationsJSON){

    v1_named_rule_with_operations_t *v1_named_rule_with_operations_local_var = NULL;

    // define the local list for v1_named_rule_with_operations->api_groups
    list_t *api_groupsList = NULL;

    // define the local list for v1_named_rule_with_operations->api_versions
    list_t *api_versionsList = NULL;

    // define the local list for v1_named_rule_with_operations->operations
    list_t *operationsList = NULL;

    // define the local list for v1_named_rule_with_operations->resource_names
    list_t *resource_namesList = NULL;

    // define the local list for v1_named_rule_with_operations->resources
    list_t *resourcesList = NULL;

    // v1_named_rule_with_operations->api_groups
    mazu_cJSON *api_groups = mazu_cJSON_GetObjectItemCaseSensitive(v1_named_rule_with_operationsJSON, "apiGroups");
    if (api_groups) { 
    mazu_cJSON *api_groups_local = NULL;
    if(!mazu_cJSON_IsArray(api_groups)) {
        goto end;//primitive container
    }
    api_groupsList = list_createList();

    mazu_cJSON_ArrayForEach(api_groups_local, api_groups)
    {
        if(!mazu_cJSON_IsString(api_groups_local))
        {
            goto end;
        }
        list_addElement(api_groupsList , strdup(api_groups_local->valuestring));
    }
    }

    // v1_named_rule_with_operations->api_versions
    mazu_cJSON *api_versions = mazu_cJSON_GetObjectItemCaseSensitive(v1_named_rule_with_operationsJSON, "apiVersions");
    if (api_versions) { 
    mazu_cJSON *api_versions_local = NULL;
    if(!mazu_cJSON_IsArray(api_versions)) {
        goto end;//primitive container
    }
    api_versionsList = list_createList();

    mazu_cJSON_ArrayForEach(api_versions_local, api_versions)
    {
        if(!mazu_cJSON_IsString(api_versions_local))
        {
            goto end;
        }
        list_addElement(api_versionsList , strdup(api_versions_local->valuestring));
    }
    }

    // v1_named_rule_with_operations->operations
    mazu_cJSON *operations = mazu_cJSON_GetObjectItemCaseSensitive(v1_named_rule_with_operationsJSON, "operations");
    if (operations) { 
    mazu_cJSON *operations_local = NULL;
    if(!mazu_cJSON_IsArray(operations)) {
        goto end;//primitive container
    }
    operationsList = list_createList();

    mazu_cJSON_ArrayForEach(operations_local, operations)
    {
        if(!mazu_cJSON_IsString(operations_local))
        {
            goto end;
        }
        list_addElement(operationsList , strdup(operations_local->valuestring));
    }
    }

    // v1_named_rule_with_operations->resource_names
    mazu_cJSON *resource_names = mazu_cJSON_GetObjectItemCaseSensitive(v1_named_rule_with_operationsJSON, "resourceNames");
    if (resource_names) { 
    mazu_cJSON *resource_names_local = NULL;
    if(!mazu_cJSON_IsArray(resource_names)) {
        goto end;//primitive container
    }
    resource_namesList = list_createList();

    mazu_cJSON_ArrayForEach(resource_names_local, resource_names)
    {
        if(!mazu_cJSON_IsString(resource_names_local))
        {
            goto end;
        }
        list_addElement(resource_namesList , strdup(resource_names_local->valuestring));
    }
    }

    // v1_named_rule_with_operations->resources
    mazu_cJSON *resources = mazu_cJSON_GetObjectItemCaseSensitive(v1_named_rule_with_operationsJSON, "resources");
    if (resources) { 
    mazu_cJSON *resources_local = NULL;
    if(!mazu_cJSON_IsArray(resources)) {
        goto end;//primitive container
    }
    resourcesList = list_createList();

    mazu_cJSON_ArrayForEach(resources_local, resources)
    {
        if(!mazu_cJSON_IsString(resources_local))
        {
            goto end;
        }
        list_addElement(resourcesList , strdup(resources_local->valuestring));
    }
    }

    // v1_named_rule_with_operations->scope
    mazu_cJSON *scope = mazu_cJSON_GetObjectItemCaseSensitive(v1_named_rule_with_operationsJSON, "scope");
    if (scope) { 
    if(!mazu_cJSON_IsString(scope) && !mazu_cJSON_IsNull(scope))
    {
    goto end; //String
    }
    }


    v1_named_rule_with_operations_local_var = v1_named_rule_with_operations_create (
        api_groups ? api_groupsList : NULL,
        api_versions ? api_versionsList : NULL,
        operations ? operationsList : NULL,
        resource_names ? resource_namesList : NULL,
        resources ? resourcesList : NULL,
        scope && !mazu_cJSON_IsNull(scope) ? strdup(scope->valuestring) : NULL
        );

    return v1_named_rule_with_operations_local_var;
end:
    if (api_groupsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, api_groupsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(api_groupsList);
        api_groupsList = NULL;
    }
    if (api_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, api_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(api_versionsList);
        api_versionsList = NULL;
    }
    if (operationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, operationsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(operationsList);
        operationsList = NULL;
    }
    if (resource_namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_namesList);
        resource_namesList = NULL;
    }
    if (resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resourcesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resourcesList);
        resourcesList = NULL;
    }
    return NULL;

}
