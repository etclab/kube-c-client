#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_role.h"



v1_role_t *v1_role_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
    ) {
    v1_role_t *v1_role_local_var = malloc(sizeof(v1_role_t));
    if (!v1_role_local_var) {
        return NULL;
    }
    v1_role_local_var->api_version = api_version;
    v1_role_local_var->kind = kind;
    v1_role_local_var->metadata = metadata;
    v1_role_local_var->rules = rules;

    return v1_role_local_var;
}


void v1_role_free(v1_role_t *v1_role) {
    if(NULL == v1_role){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_role->api_version) {
        free(v1_role->api_version);
        v1_role->api_version = NULL;
    }
    if (v1_role->kind) {
        free(v1_role->kind);
        v1_role->kind = NULL;
    }
    if (v1_role->metadata) {
        v1_object_meta_free(v1_role->metadata);
        v1_role->metadata = NULL;
    }
    if (v1_role->rules) {
        list_ForEach(listEntry, v1_role->rules) {
            v1_policy_rule_free(listEntry->data);
        }
        list_freeList(v1_role->rules);
        v1_role->rules = NULL;
    }
    free(v1_role);
}

mazu_cJSON *v1_role_convertToJSON(v1_role_t *v1_role) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_role->api_version
    if(v1_role->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_role->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_role->kind
    if(v1_role->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_role->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_role->metadata
    if(v1_role->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_role->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_role->rules
    if(v1_role->rules) {
    mazu_cJSON *rules = mazu_cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_role->rules) {
    list_ForEach(rulesListEntry, v1_role->rules) {
    mazu_cJSON *itemLocal = v1_policy_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(rules, itemLocal);
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

v1_role_t *v1_role_parseFromJSON(mazu_cJSON *v1_roleJSON){

    v1_role_t *v1_role_local_var = NULL;

    // define the local variable for v1_role->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_role->rules
    list_t *rulesList = NULL;

    // v1_role->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_role->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_role->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_role->rules
    mazu_cJSON *rules = mazu_cJSON_GetObjectItemCaseSensitive(v1_roleJSON, "rules");
    if (rules) { 
    mazu_cJSON *rules_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    mazu_cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!mazu_cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_policy_rule_t *rulesItem = v1_policy_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }


    v1_role_local_var = v1_role_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        rules ? rulesList : NULL
        );

    return v1_role_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_policy_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
