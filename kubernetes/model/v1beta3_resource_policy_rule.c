#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_resource_policy_rule.h"



v1beta3_resource_policy_rule_t *v1beta3_resource_policy_rule_create(
    list_t *api_groups,
    int cluster_scope,
    list_t *namespaces,
    list_t *resources,
    list_t *verbs
    ) {
    v1beta3_resource_policy_rule_t *v1beta3_resource_policy_rule_local_var = malloc(sizeof(v1beta3_resource_policy_rule_t));
    if (!v1beta3_resource_policy_rule_local_var) {
        return NULL;
    }
    v1beta3_resource_policy_rule_local_var->api_groups = api_groups;
    v1beta3_resource_policy_rule_local_var->cluster_scope = cluster_scope;
    v1beta3_resource_policy_rule_local_var->namespaces = namespaces;
    v1beta3_resource_policy_rule_local_var->resources = resources;
    v1beta3_resource_policy_rule_local_var->verbs = verbs;

    return v1beta3_resource_policy_rule_local_var;
}


void v1beta3_resource_policy_rule_free(v1beta3_resource_policy_rule_t *v1beta3_resource_policy_rule) {
    if(NULL == v1beta3_resource_policy_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_resource_policy_rule->api_groups) {
        list_ForEach(listEntry, v1beta3_resource_policy_rule->api_groups) {
            free(listEntry->data);
        }
        list_freeList(v1beta3_resource_policy_rule->api_groups);
        v1beta3_resource_policy_rule->api_groups = NULL;
    }
    if (v1beta3_resource_policy_rule->namespaces) {
        list_ForEach(listEntry, v1beta3_resource_policy_rule->namespaces) {
            free(listEntry->data);
        }
        list_freeList(v1beta3_resource_policy_rule->namespaces);
        v1beta3_resource_policy_rule->namespaces = NULL;
    }
    if (v1beta3_resource_policy_rule->resources) {
        list_ForEach(listEntry, v1beta3_resource_policy_rule->resources) {
            free(listEntry->data);
        }
        list_freeList(v1beta3_resource_policy_rule->resources);
        v1beta3_resource_policy_rule->resources = NULL;
    }
    if (v1beta3_resource_policy_rule->verbs) {
        list_ForEach(listEntry, v1beta3_resource_policy_rule->verbs) {
            free(listEntry->data);
        }
        list_freeList(v1beta3_resource_policy_rule->verbs);
        v1beta3_resource_policy_rule->verbs = NULL;
    }
    free(v1beta3_resource_policy_rule);
}

mazu_cJSON *v1beta3_resource_policy_rule_convertToJSON(v1beta3_resource_policy_rule_t *v1beta3_resource_policy_rule) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta3_resource_policy_rule->api_groups
    if (!v1beta3_resource_policy_rule->api_groups) {
        goto fail;
    }
    mazu_cJSON *api_groups = mazu_cJSON_AddArrayToObject(item, "apiGroups");
    if(api_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1beta3_resource_policy_rule->api_groups) {
    if(mazu_cJSON_AddStringToObject(api_groups, "", (char*)api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1beta3_resource_policy_rule->cluster_scope
    if(v1beta3_resource_policy_rule->cluster_scope) {
    if(mazu_cJSON_AddBoolToObject(item, "clusterScope", v1beta3_resource_policy_rule->cluster_scope) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta3_resource_policy_rule->namespaces
    if(v1beta3_resource_policy_rule->namespaces) {
    mazu_cJSON *namespaces = mazu_cJSON_AddArrayToObject(item, "namespaces");
    if(namespaces == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *namespacesListEntry;
    list_ForEach(namespacesListEntry, v1beta3_resource_policy_rule->namespaces) {
    if(mazu_cJSON_AddStringToObject(namespaces, "", (char*)namespacesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta3_resource_policy_rule->resources
    if (!v1beta3_resource_policy_rule->resources) {
        goto fail;
    }
    mazu_cJSON *resources = mazu_cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1beta3_resource_policy_rule->resources) {
    if(mazu_cJSON_AddStringToObject(resources, "", (char*)resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1beta3_resource_policy_rule->verbs
    if (!v1beta3_resource_policy_rule->verbs) {
        goto fail;
    }
    mazu_cJSON *verbs = mazu_cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1beta3_resource_policy_rule->verbs) {
    if(mazu_cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
    {
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

v1beta3_resource_policy_rule_t *v1beta3_resource_policy_rule_parseFromJSON(mazu_cJSON *v1beta3_resource_policy_ruleJSON){

    v1beta3_resource_policy_rule_t *v1beta3_resource_policy_rule_local_var = NULL;

    // define the local list for v1beta3_resource_policy_rule->api_groups
    list_t *api_groupsList = NULL;

    // define the local list for v1beta3_resource_policy_rule->namespaces
    list_t *namespacesList = NULL;

    // define the local list for v1beta3_resource_policy_rule->resources
    list_t *resourcesList = NULL;

    // define the local list for v1beta3_resource_policy_rule->verbs
    list_t *verbsList = NULL;

    // v1beta3_resource_policy_rule->api_groups
    mazu_cJSON *api_groups = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_resource_policy_ruleJSON, "apiGroups");
    if (!api_groups) {
        goto end;
    }

    
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

    // v1beta3_resource_policy_rule->cluster_scope
    mazu_cJSON *cluster_scope = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_resource_policy_ruleJSON, "clusterScope");
    if (cluster_scope) { 
    if(!mazu_cJSON_IsBool(cluster_scope))
    {
    goto end; //Bool
    }
    }

    // v1beta3_resource_policy_rule->namespaces
    mazu_cJSON *namespaces = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_resource_policy_ruleJSON, "namespaces");
    if (namespaces) { 
    mazu_cJSON *namespaces_local = NULL;
    if(!mazu_cJSON_IsArray(namespaces)) {
        goto end;//primitive container
    }
    namespacesList = list_createList();

    mazu_cJSON_ArrayForEach(namespaces_local, namespaces)
    {
        if(!mazu_cJSON_IsString(namespaces_local))
        {
            goto end;
        }
        list_addElement(namespacesList , strdup(namespaces_local->valuestring));
    }
    }

    // v1beta3_resource_policy_rule->resources
    mazu_cJSON *resources = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_resource_policy_ruleJSON, "resources");
    if (!resources) {
        goto end;
    }

    
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

    // v1beta3_resource_policy_rule->verbs
    mazu_cJSON *verbs = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_resource_policy_ruleJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    
    mazu_cJSON *verbs_local = NULL;
    if(!mazu_cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_createList();

    mazu_cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!mazu_cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1beta3_resource_policy_rule_local_var = v1beta3_resource_policy_rule_create (
        api_groupsList,
        cluster_scope ? cluster_scope->valueint : 0,
        namespaces ? namespacesList : NULL,
        resourcesList,
        verbsList
        );

    return v1beta3_resource_policy_rule_local_var;
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
    if (namespacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, namespacesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(namespacesList);
        namespacesList = NULL;
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
    if (verbsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, verbsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(verbsList);
        verbsList = NULL;
    }
    return NULL;

}
