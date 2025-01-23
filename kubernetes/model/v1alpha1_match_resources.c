#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_match_resources.h"



v1alpha1_match_resources_t *v1alpha1_match_resources_create(
    list_t *exclude_resource_rules,
    char *match_policy,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *object_selector,
    list_t *resource_rules
    ) {
    v1alpha1_match_resources_t *v1alpha1_match_resources_local_var = malloc(sizeof(v1alpha1_match_resources_t));
    if (!v1alpha1_match_resources_local_var) {
        return NULL;
    }
    v1alpha1_match_resources_local_var->exclude_resource_rules = exclude_resource_rules;
    v1alpha1_match_resources_local_var->match_policy = match_policy;
    v1alpha1_match_resources_local_var->namespace_selector = namespace_selector;
    v1alpha1_match_resources_local_var->object_selector = object_selector;
    v1alpha1_match_resources_local_var->resource_rules = resource_rules;

    return v1alpha1_match_resources_local_var;
}


void v1alpha1_match_resources_free(v1alpha1_match_resources_t *v1alpha1_match_resources) {
    if(NULL == v1alpha1_match_resources){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_match_resources->exclude_resource_rules) {
        list_ForEach(listEntry, v1alpha1_match_resources->exclude_resource_rules) {
            v1alpha1_named_rule_with_operations_free(listEntry->data);
        }
        list_freeList(v1alpha1_match_resources->exclude_resource_rules);
        v1alpha1_match_resources->exclude_resource_rules = NULL;
    }
    if (v1alpha1_match_resources->match_policy) {
        free(v1alpha1_match_resources->match_policy);
        v1alpha1_match_resources->match_policy = NULL;
    }
    if (v1alpha1_match_resources->namespace_selector) {
        v1_label_selector_free(v1alpha1_match_resources->namespace_selector);
        v1alpha1_match_resources->namespace_selector = NULL;
    }
    if (v1alpha1_match_resources->object_selector) {
        v1_label_selector_free(v1alpha1_match_resources->object_selector);
        v1alpha1_match_resources->object_selector = NULL;
    }
    if (v1alpha1_match_resources->resource_rules) {
        list_ForEach(listEntry, v1alpha1_match_resources->resource_rules) {
            v1alpha1_named_rule_with_operations_free(listEntry->data);
        }
        list_freeList(v1alpha1_match_resources->resource_rules);
        v1alpha1_match_resources->resource_rules = NULL;
    }
    free(v1alpha1_match_resources);
}

mazu_cJSON *v1alpha1_match_resources_convertToJSON(v1alpha1_match_resources_t *v1alpha1_match_resources) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_match_resources->exclude_resource_rules
    if(v1alpha1_match_resources->exclude_resource_rules) {
    mazu_cJSON *exclude_resource_rules = mazu_cJSON_AddArrayToObject(item, "excludeResourceRules");
    if(exclude_resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *exclude_resource_rulesListEntry;
    if (v1alpha1_match_resources->exclude_resource_rules) {
    list_ForEach(exclude_resource_rulesListEntry, v1alpha1_match_resources->exclude_resource_rules) {
    mazu_cJSON *itemLocal = v1alpha1_named_rule_with_operations_convertToJSON(exclude_resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(exclude_resource_rules, itemLocal);
    }
    }
    }


    // v1alpha1_match_resources->match_policy
    if(v1alpha1_match_resources->match_policy) {
    if(mazu_cJSON_AddStringToObject(item, "matchPolicy", v1alpha1_match_resources->match_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_match_resources->namespace_selector
    if(v1alpha1_match_resources->namespace_selector) {
    mazu_cJSON *namespace_selector_local_JSON = v1_label_selector_convertToJSON(v1alpha1_match_resources->namespace_selector);
    if(namespace_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "namespaceSelector", namespace_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_match_resources->object_selector
    if(v1alpha1_match_resources->object_selector) {
    mazu_cJSON *object_selector_local_JSON = v1_label_selector_convertToJSON(v1alpha1_match_resources->object_selector);
    if(object_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "objectSelector", object_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_match_resources->resource_rules
    if(v1alpha1_match_resources->resource_rules) {
    mazu_cJSON *resource_rules = mazu_cJSON_AddArrayToObject(item, "resourceRules");
    if(resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_rulesListEntry;
    if (v1alpha1_match_resources->resource_rules) {
    list_ForEach(resource_rulesListEntry, v1alpha1_match_resources->resource_rules) {
    mazu_cJSON *itemLocal = v1alpha1_named_rule_with_operations_convertToJSON(resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(resource_rules, itemLocal);
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

v1alpha1_match_resources_t *v1alpha1_match_resources_parseFromJSON(mazu_cJSON *v1alpha1_match_resourcesJSON){

    v1alpha1_match_resources_t *v1alpha1_match_resources_local_var = NULL;

    // define the local list for v1alpha1_match_resources->exclude_resource_rules
    list_t *exclude_resource_rulesList = NULL;

    // define the local variable for v1alpha1_match_resources->namespace_selector
    v1_label_selector_t *namespace_selector_local_nonprim = NULL;

    // define the local variable for v1alpha1_match_resources->object_selector
    v1_label_selector_t *object_selector_local_nonprim = NULL;

    // define the local list for v1alpha1_match_resources->resource_rules
    list_t *resource_rulesList = NULL;

    // v1alpha1_match_resources->exclude_resource_rules
    mazu_cJSON *exclude_resource_rules = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_match_resourcesJSON, "excludeResourceRules");
    if (exclude_resource_rules) { 
    mazu_cJSON *exclude_resource_rules_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(exclude_resource_rules)){
        goto end; //nonprimitive container
    }

    exclude_resource_rulesList = list_createList();

    mazu_cJSON_ArrayForEach(exclude_resource_rules_local_nonprimitive,exclude_resource_rules )
    {
        if(!mazu_cJSON_IsObject(exclude_resource_rules_local_nonprimitive)){
            goto end;
        }
        v1alpha1_named_rule_with_operations_t *exclude_resource_rulesItem = v1alpha1_named_rule_with_operations_parseFromJSON(exclude_resource_rules_local_nonprimitive);

        list_addElement(exclude_resource_rulesList, exclude_resource_rulesItem);
    }
    }

    // v1alpha1_match_resources->match_policy
    mazu_cJSON *match_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_match_resourcesJSON, "matchPolicy");
    if (match_policy) { 
    if(!mazu_cJSON_IsString(match_policy) && !mazu_cJSON_IsNull(match_policy))
    {
    goto end; //String
    }
    }

    // v1alpha1_match_resources->namespace_selector
    mazu_cJSON *namespace_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_match_resourcesJSON, "namespaceSelector");
    if (namespace_selector) { 
    namespace_selector_local_nonprim = v1_label_selector_parseFromJSON(namespace_selector); //nonprimitive
    }

    // v1alpha1_match_resources->object_selector
    mazu_cJSON *object_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_match_resourcesJSON, "objectSelector");
    if (object_selector) { 
    object_selector_local_nonprim = v1_label_selector_parseFromJSON(object_selector); //nonprimitive
    }

    // v1alpha1_match_resources->resource_rules
    mazu_cJSON *resource_rules = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_match_resourcesJSON, "resourceRules");
    if (resource_rules) { 
    mazu_cJSON *resource_rules_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(resource_rules)){
        goto end; //nonprimitive container
    }

    resource_rulesList = list_createList();

    mazu_cJSON_ArrayForEach(resource_rules_local_nonprimitive,resource_rules )
    {
        if(!mazu_cJSON_IsObject(resource_rules_local_nonprimitive)){
            goto end;
        }
        v1alpha1_named_rule_with_operations_t *resource_rulesItem = v1alpha1_named_rule_with_operations_parseFromJSON(resource_rules_local_nonprimitive);

        list_addElement(resource_rulesList, resource_rulesItem);
    }
    }


    v1alpha1_match_resources_local_var = v1alpha1_match_resources_create (
        exclude_resource_rules ? exclude_resource_rulesList : NULL,
        match_policy && !mazu_cJSON_IsNull(match_policy) ? strdup(match_policy->valuestring) : NULL,
        namespace_selector ? namespace_selector_local_nonprim : NULL,
        object_selector ? object_selector_local_nonprim : NULL,
        resource_rules ? resource_rulesList : NULL
        );

    return v1alpha1_match_resources_local_var;
end:
    if (exclude_resource_rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, exclude_resource_rulesList) {
            v1alpha1_named_rule_with_operations_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(exclude_resource_rulesList);
        exclude_resource_rulesList = NULL;
    }
    if (namespace_selector_local_nonprim) {
        v1_label_selector_free(namespace_selector_local_nonprim);
        namespace_selector_local_nonprim = NULL;
    }
    if (object_selector_local_nonprim) {
        v1_label_selector_free(object_selector_local_nonprim);
        object_selector_local_nonprim = NULL;
    }
    if (resource_rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_rulesList) {
            v1alpha1_named_rule_with_operations_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_rulesList);
        resource_rulesList = NULL;
    }
    return NULL;

}
