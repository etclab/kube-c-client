#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_success_policy_rule.h"



v1_success_policy_rule_t *v1_success_policy_rule_create(
    int succeeded_count,
    char *succeeded_indexes
    ) {
    v1_success_policy_rule_t *v1_success_policy_rule_local_var = malloc(sizeof(v1_success_policy_rule_t));
    if (!v1_success_policy_rule_local_var) {
        return NULL;
    }
    v1_success_policy_rule_local_var->succeeded_count = succeeded_count;
    v1_success_policy_rule_local_var->succeeded_indexes = succeeded_indexes;

    return v1_success_policy_rule_local_var;
}


void v1_success_policy_rule_free(v1_success_policy_rule_t *v1_success_policy_rule) {
    if(NULL == v1_success_policy_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_success_policy_rule->succeeded_indexes) {
        free(v1_success_policy_rule->succeeded_indexes);
        v1_success_policy_rule->succeeded_indexes = NULL;
    }
    free(v1_success_policy_rule);
}

mazu_cJSON *v1_success_policy_rule_convertToJSON(v1_success_policy_rule_t *v1_success_policy_rule) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_success_policy_rule->succeeded_count
    if(v1_success_policy_rule->succeeded_count) {
    if(mazu_cJSON_AddNumberToObject(item, "succeededCount", v1_success_policy_rule->succeeded_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_success_policy_rule->succeeded_indexes
    if(v1_success_policy_rule->succeeded_indexes) {
    if(mazu_cJSON_AddStringToObject(item, "succeededIndexes", v1_success_policy_rule->succeeded_indexes) == NULL) {
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

v1_success_policy_rule_t *v1_success_policy_rule_parseFromJSON(mazu_cJSON *v1_success_policy_ruleJSON){

    v1_success_policy_rule_t *v1_success_policy_rule_local_var = NULL;

    // v1_success_policy_rule->succeeded_count
    mazu_cJSON *succeeded_count = mazu_cJSON_GetObjectItemCaseSensitive(v1_success_policy_ruleJSON, "succeededCount");
    if (succeeded_count) { 
    if(!mazu_cJSON_IsNumber(succeeded_count))
    {
    goto end; //Numeric
    }
    }

    // v1_success_policy_rule->succeeded_indexes
    mazu_cJSON *succeeded_indexes = mazu_cJSON_GetObjectItemCaseSensitive(v1_success_policy_ruleJSON, "succeededIndexes");
    if (succeeded_indexes) { 
    if(!mazu_cJSON_IsString(succeeded_indexes) && !mazu_cJSON_IsNull(succeeded_indexes))
    {
    goto end; //String
    }
    }


    v1_success_policy_rule_local_var = v1_success_policy_rule_create (
        succeeded_count ? succeeded_count->valuedouble : 0,
        succeeded_indexes && !mazu_cJSON_IsNull(succeeded_indexes) ? strdup(succeeded_indexes->valuestring) : NULL
        );

    return v1_success_policy_rule_local_var;
end:
    return NULL;

}
