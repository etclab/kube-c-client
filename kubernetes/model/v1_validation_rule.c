#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validation_rule.h"



v1_validation_rule_t *v1_validation_rule_create(
    char *field_path,
    char *message,
    char *message_expression,
    int optional_old_self,
    char *reason,
    char *rule
    ) {
    v1_validation_rule_t *v1_validation_rule_local_var = malloc(sizeof(v1_validation_rule_t));
    if (!v1_validation_rule_local_var) {
        return NULL;
    }
    v1_validation_rule_local_var->field_path = field_path;
    v1_validation_rule_local_var->message = message;
    v1_validation_rule_local_var->message_expression = message_expression;
    v1_validation_rule_local_var->optional_old_self = optional_old_self;
    v1_validation_rule_local_var->reason = reason;
    v1_validation_rule_local_var->rule = rule;

    return v1_validation_rule_local_var;
}


void v1_validation_rule_free(v1_validation_rule_t *v1_validation_rule) {
    if(NULL == v1_validation_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validation_rule->field_path) {
        free(v1_validation_rule->field_path);
        v1_validation_rule->field_path = NULL;
    }
    if (v1_validation_rule->message) {
        free(v1_validation_rule->message);
        v1_validation_rule->message = NULL;
    }
    if (v1_validation_rule->message_expression) {
        free(v1_validation_rule->message_expression);
        v1_validation_rule->message_expression = NULL;
    }
    if (v1_validation_rule->reason) {
        free(v1_validation_rule->reason);
        v1_validation_rule->reason = NULL;
    }
    if (v1_validation_rule->rule) {
        free(v1_validation_rule->rule);
        v1_validation_rule->rule = NULL;
    }
    free(v1_validation_rule);
}

mazu_cJSON *v1_validation_rule_convertToJSON(v1_validation_rule_t *v1_validation_rule) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_validation_rule->field_path
    if(v1_validation_rule->field_path) {
    if(mazu_cJSON_AddStringToObject(item, "fieldPath", v1_validation_rule->field_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->message
    if(v1_validation_rule->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1_validation_rule->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->message_expression
    if(v1_validation_rule->message_expression) {
    if(mazu_cJSON_AddStringToObject(item, "messageExpression", v1_validation_rule->message_expression) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->optional_old_self
    if(v1_validation_rule->optional_old_self) {
    if(mazu_cJSON_AddBoolToObject(item, "optionalOldSelf", v1_validation_rule->optional_old_self) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_validation_rule->reason
    if(v1_validation_rule->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1_validation_rule->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_validation_rule->rule
    if (!v1_validation_rule->rule) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "rule", v1_validation_rule->rule) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_validation_rule_t *v1_validation_rule_parseFromJSON(mazu_cJSON *v1_validation_ruleJSON){

    v1_validation_rule_t *v1_validation_rule_local_var = NULL;

    // v1_validation_rule->field_path
    mazu_cJSON *field_path = mazu_cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "fieldPath");
    if (field_path) { 
    if(!mazu_cJSON_IsString(field_path) && !mazu_cJSON_IsNull(field_path))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->message_expression
    mazu_cJSON *message_expression = mazu_cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "messageExpression");
    if (message_expression) { 
    if(!mazu_cJSON_IsString(message_expression) && !mazu_cJSON_IsNull(message_expression))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->optional_old_self
    mazu_cJSON *optional_old_self = mazu_cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "optionalOldSelf");
    if (optional_old_self) { 
    if(!mazu_cJSON_IsBool(optional_old_self))
    {
    goto end; //Bool
    }
    }

    // v1_validation_rule->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_validation_rule->rule
    mazu_cJSON *rule = mazu_cJSON_GetObjectItemCaseSensitive(v1_validation_ruleJSON, "rule");
    if (!rule) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(rule))
    {
    goto end; //String
    }


    v1_validation_rule_local_var = v1_validation_rule_create (
        field_path && !mazu_cJSON_IsNull(field_path) ? strdup(field_path->valuestring) : NULL,
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        message_expression && !mazu_cJSON_IsNull(message_expression) ? strdup(message_expression->valuestring) : NULL,
        optional_old_self ? optional_old_self->valueint : 0,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(rule->valuestring)
        );

    return v1_validation_rule_local_var;
end:
    return NULL;

}
