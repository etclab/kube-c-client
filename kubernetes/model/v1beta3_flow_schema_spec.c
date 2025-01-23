#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_flow_schema_spec.h"



v1beta3_flow_schema_spec_t *v1beta3_flow_schema_spec_create(
    v1beta3_flow_distinguisher_method_t *distinguisher_method,
    int matching_precedence,
    v1beta3_priority_level_configuration_reference_t *priority_level_configuration,
    list_t *rules
    ) {
    v1beta3_flow_schema_spec_t *v1beta3_flow_schema_spec_local_var = malloc(sizeof(v1beta3_flow_schema_spec_t));
    if (!v1beta3_flow_schema_spec_local_var) {
        return NULL;
    }
    v1beta3_flow_schema_spec_local_var->distinguisher_method = distinguisher_method;
    v1beta3_flow_schema_spec_local_var->matching_precedence = matching_precedence;
    v1beta3_flow_schema_spec_local_var->priority_level_configuration = priority_level_configuration;
    v1beta3_flow_schema_spec_local_var->rules = rules;

    return v1beta3_flow_schema_spec_local_var;
}


void v1beta3_flow_schema_spec_free(v1beta3_flow_schema_spec_t *v1beta3_flow_schema_spec) {
    if(NULL == v1beta3_flow_schema_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_flow_schema_spec->distinguisher_method) {
        v1beta3_flow_distinguisher_method_free(v1beta3_flow_schema_spec->distinguisher_method);
        v1beta3_flow_schema_spec->distinguisher_method = NULL;
    }
    if (v1beta3_flow_schema_spec->priority_level_configuration) {
        v1beta3_priority_level_configuration_reference_free(v1beta3_flow_schema_spec->priority_level_configuration);
        v1beta3_flow_schema_spec->priority_level_configuration = NULL;
    }
    if (v1beta3_flow_schema_spec->rules) {
        list_ForEach(listEntry, v1beta3_flow_schema_spec->rules) {
            v1beta3_policy_rules_with_subjects_free(listEntry->data);
        }
        list_freeList(v1beta3_flow_schema_spec->rules);
        v1beta3_flow_schema_spec->rules = NULL;
    }
    free(v1beta3_flow_schema_spec);
}

mazu_cJSON *v1beta3_flow_schema_spec_convertToJSON(v1beta3_flow_schema_spec_t *v1beta3_flow_schema_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta3_flow_schema_spec->distinguisher_method
    if(v1beta3_flow_schema_spec->distinguisher_method) {
    mazu_cJSON *distinguisher_method_local_JSON = v1beta3_flow_distinguisher_method_convertToJSON(v1beta3_flow_schema_spec->distinguisher_method);
    if(distinguisher_method_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "distinguisherMethod", distinguisher_method_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta3_flow_schema_spec->matching_precedence
    if(v1beta3_flow_schema_spec->matching_precedence) {
    if(mazu_cJSON_AddNumberToObject(item, "matchingPrecedence", v1beta3_flow_schema_spec->matching_precedence) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta3_flow_schema_spec->priority_level_configuration
    if (!v1beta3_flow_schema_spec->priority_level_configuration) {
        goto fail;
    }
    mazu_cJSON *priority_level_configuration_local_JSON = v1beta3_priority_level_configuration_reference_convertToJSON(v1beta3_flow_schema_spec->priority_level_configuration);
    if(priority_level_configuration_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "priorityLevelConfiguration", priority_level_configuration_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta3_flow_schema_spec->rules
    if(v1beta3_flow_schema_spec->rules) {
    mazu_cJSON *rules = mazu_cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1beta3_flow_schema_spec->rules) {
    list_ForEach(rulesListEntry, v1beta3_flow_schema_spec->rules) {
    mazu_cJSON *itemLocal = v1beta3_policy_rules_with_subjects_convertToJSON(rulesListEntry->data);
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

v1beta3_flow_schema_spec_t *v1beta3_flow_schema_spec_parseFromJSON(mazu_cJSON *v1beta3_flow_schema_specJSON){

    v1beta3_flow_schema_spec_t *v1beta3_flow_schema_spec_local_var = NULL;

    // define the local variable for v1beta3_flow_schema_spec->distinguisher_method
    v1beta3_flow_distinguisher_method_t *distinguisher_method_local_nonprim = NULL;

    // define the local variable for v1beta3_flow_schema_spec->priority_level_configuration
    v1beta3_priority_level_configuration_reference_t *priority_level_configuration_local_nonprim = NULL;

    // define the local list for v1beta3_flow_schema_spec->rules
    list_t *rulesList = NULL;

    // v1beta3_flow_schema_spec->distinguisher_method
    mazu_cJSON *distinguisher_method = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_flow_schema_specJSON, "distinguisherMethod");
    if (distinguisher_method) { 
    distinguisher_method_local_nonprim = v1beta3_flow_distinguisher_method_parseFromJSON(distinguisher_method); //nonprimitive
    }

    // v1beta3_flow_schema_spec->matching_precedence
    mazu_cJSON *matching_precedence = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_flow_schema_specJSON, "matchingPrecedence");
    if (matching_precedence) { 
    if(!mazu_cJSON_IsNumber(matching_precedence))
    {
    goto end; //Numeric
    }
    }

    // v1beta3_flow_schema_spec->priority_level_configuration
    mazu_cJSON *priority_level_configuration = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_flow_schema_specJSON, "priorityLevelConfiguration");
    if (!priority_level_configuration) {
        goto end;
    }

    
    priority_level_configuration_local_nonprim = v1beta3_priority_level_configuration_reference_parseFromJSON(priority_level_configuration); //nonprimitive

    // v1beta3_flow_schema_spec->rules
    mazu_cJSON *rules = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_flow_schema_specJSON, "rules");
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
        v1beta3_policy_rules_with_subjects_t *rulesItem = v1beta3_policy_rules_with_subjects_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }


    v1beta3_flow_schema_spec_local_var = v1beta3_flow_schema_spec_create (
        distinguisher_method ? distinguisher_method_local_nonprim : NULL,
        matching_precedence ? matching_precedence->valuedouble : 0,
        priority_level_configuration_local_nonprim,
        rules ? rulesList : NULL
        );

    return v1beta3_flow_schema_spec_local_var;
end:
    if (distinguisher_method_local_nonprim) {
        v1beta3_flow_distinguisher_method_free(distinguisher_method_local_nonprim);
        distinguisher_method_local_nonprim = NULL;
    }
    if (priority_level_configuration_local_nonprim) {
        v1beta3_priority_level_configuration_reference_free(priority_level_configuration_local_nonprim);
        priority_level_configuration_local_nonprim = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1beta3_policy_rules_with_subjects_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
