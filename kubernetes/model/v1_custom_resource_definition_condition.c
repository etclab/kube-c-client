#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_condition.h"



v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition_local_var = malloc(sizeof(v1_custom_resource_definition_condition_t));
    if (!v1_custom_resource_definition_condition_local_var) {
        return NULL;
    }
    v1_custom_resource_definition_condition_local_var->last_transition_time = last_transition_time;
    v1_custom_resource_definition_condition_local_var->message = message;
    v1_custom_resource_definition_condition_local_var->reason = reason;
    v1_custom_resource_definition_condition_local_var->status = status;
    v1_custom_resource_definition_condition_local_var->type = type;

    return v1_custom_resource_definition_condition_local_var;
}


void v1_custom_resource_definition_condition_free(v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition) {
    if(NULL == v1_custom_resource_definition_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_definition_condition->last_transition_time) {
        free(v1_custom_resource_definition_condition->last_transition_time);
        v1_custom_resource_definition_condition->last_transition_time = NULL;
    }
    if (v1_custom_resource_definition_condition->message) {
        free(v1_custom_resource_definition_condition->message);
        v1_custom_resource_definition_condition->message = NULL;
    }
    if (v1_custom_resource_definition_condition->reason) {
        free(v1_custom_resource_definition_condition->reason);
        v1_custom_resource_definition_condition->reason = NULL;
    }
    if (v1_custom_resource_definition_condition->status) {
        free(v1_custom_resource_definition_condition->status);
        v1_custom_resource_definition_condition->status = NULL;
    }
    if (v1_custom_resource_definition_condition->type) {
        free(v1_custom_resource_definition_condition->type);
        v1_custom_resource_definition_condition->type = NULL;
    }
    free(v1_custom_resource_definition_condition);
}

mazu_cJSON *v1_custom_resource_definition_condition_convertToJSON(v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_custom_resource_definition_condition->last_transition_time
    if(v1_custom_resource_definition_condition->last_transition_time) {
    if(mazu_cJSON_AddStringToObject(item, "lastTransitionTime", v1_custom_resource_definition_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_custom_resource_definition_condition->message
    if(v1_custom_resource_definition_condition->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1_custom_resource_definition_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_definition_condition->reason
    if(v1_custom_resource_definition_condition->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1_custom_resource_definition_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_definition_condition->status
    if (!v1_custom_resource_definition_condition->status) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "status", v1_custom_resource_definition_condition->status) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_definition_condition->type
    if (!v1_custom_resource_definition_condition->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1_custom_resource_definition_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition_parseFromJSON(mazu_cJSON *v1_custom_resource_definition_conditionJSON){

    v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition_local_var = NULL;

    // v1_custom_resource_definition_condition->last_transition_time
    mazu_cJSON *last_transition_time = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!mazu_cJSON_IsString(last_transition_time) && !mazu_cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_custom_resource_definition_condition->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_conditionJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_definition_condition->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_conditionJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_definition_condition->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_condition->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_custom_resource_definition_condition_local_var = v1_custom_resource_definition_condition_create (
        last_transition_time && !mazu_cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_custom_resource_definition_condition_local_var;
end:
    return NULL;

}
