#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_failure_policy.h"



v1_pod_failure_policy_t *v1_pod_failure_policy_create(
    list_t *rules
    ) {
    v1_pod_failure_policy_t *v1_pod_failure_policy_local_var = malloc(sizeof(v1_pod_failure_policy_t));
    if (!v1_pod_failure_policy_local_var) {
        return NULL;
    }
    v1_pod_failure_policy_local_var->rules = rules;

    return v1_pod_failure_policy_local_var;
}


void v1_pod_failure_policy_free(v1_pod_failure_policy_t *v1_pod_failure_policy) {
    if(NULL == v1_pod_failure_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_failure_policy->rules) {
        list_ForEach(listEntry, v1_pod_failure_policy->rules) {
            v1_pod_failure_policy_rule_free(listEntry->data);
        }
        list_freeList(v1_pod_failure_policy->rules);
        v1_pod_failure_policy->rules = NULL;
    }
    free(v1_pod_failure_policy);
}

mazu_cJSON *v1_pod_failure_policy_convertToJSON(v1_pod_failure_policy_t *v1_pod_failure_policy) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_failure_policy->rules
    if (!v1_pod_failure_policy->rules) {
        goto fail;
    }
    mazu_cJSON *rules = mazu_cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_pod_failure_policy->rules) {
    list_ForEach(rulesListEntry, v1_pod_failure_policy->rules) {
    mazu_cJSON *itemLocal = v1_pod_failure_policy_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(rules, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_failure_policy_t *v1_pod_failure_policy_parseFromJSON(mazu_cJSON *v1_pod_failure_policyJSON){

    v1_pod_failure_policy_t *v1_pod_failure_policy_local_var = NULL;

    // define the local list for v1_pod_failure_policy->rules
    list_t *rulesList = NULL;

    // v1_pod_failure_policy->rules
    mazu_cJSON *rules = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policyJSON, "rules");
    if (!rules) {
        goto end;
    }

    
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
        v1_pod_failure_policy_rule_t *rulesItem = v1_pod_failure_policy_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }


    v1_pod_failure_policy_local_var = v1_pod_failure_policy_create (
        rulesList
        );

    return v1_pod_failure_policy_local_var;
end:
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_pod_failure_policy_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
