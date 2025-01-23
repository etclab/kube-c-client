#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler_condition.h"



v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_condition_t));
    if (!v2_horizontal_pod_autoscaler_condition_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_condition_local_var->last_transition_time = last_transition_time;
    v2_horizontal_pod_autoscaler_condition_local_var->message = message;
    v2_horizontal_pod_autoscaler_condition_local_var->reason = reason;
    v2_horizontal_pod_autoscaler_condition_local_var->status = status;
    v2_horizontal_pod_autoscaler_condition_local_var->type = type;

    return v2_horizontal_pod_autoscaler_condition_local_var;
}


void v2_horizontal_pod_autoscaler_condition_free(v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition) {
    if(NULL == v2_horizontal_pod_autoscaler_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler_condition->last_transition_time) {
        free(v2_horizontal_pod_autoscaler_condition->last_transition_time);
        v2_horizontal_pod_autoscaler_condition->last_transition_time = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->message) {
        free(v2_horizontal_pod_autoscaler_condition->message);
        v2_horizontal_pod_autoscaler_condition->message = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->reason) {
        free(v2_horizontal_pod_autoscaler_condition->reason);
        v2_horizontal_pod_autoscaler_condition->reason = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->status) {
        free(v2_horizontal_pod_autoscaler_condition->status);
        v2_horizontal_pod_autoscaler_condition->status = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->type) {
        free(v2_horizontal_pod_autoscaler_condition->type);
        v2_horizontal_pod_autoscaler_condition->type = NULL;
    }
    free(v2_horizontal_pod_autoscaler_condition);
}

mazu_cJSON *v2_horizontal_pod_autoscaler_condition_convertToJSON(v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler_condition->last_transition_time
    if(v2_horizontal_pod_autoscaler_condition->last_transition_time) {
    if(mazu_cJSON_AddStringToObject(item, "lastTransitionTime", v2_horizontal_pod_autoscaler_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v2_horizontal_pod_autoscaler_condition->message
    if(v2_horizontal_pod_autoscaler_condition->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v2_horizontal_pod_autoscaler_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_condition->reason
    if(v2_horizontal_pod_autoscaler_condition->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v2_horizontal_pod_autoscaler_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_condition->status
    if (!v2_horizontal_pod_autoscaler_condition->status) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "status", v2_horizontal_pod_autoscaler_condition->status) == NULL) {
    goto fail; //String
    }


    // v2_horizontal_pod_autoscaler_condition->type
    if (!v2_horizontal_pod_autoscaler_condition->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v2_horizontal_pod_autoscaler_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_parseFromJSON(mazu_cJSON *v2_horizontal_pod_autoscaler_conditionJSON){

    v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_local_var = NULL;

    // v2_horizontal_pod_autoscaler_condition->last_transition_time
    mazu_cJSON *last_transition_time = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!mazu_cJSON_IsString(last_transition_time) && !mazu_cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v2_horizontal_pod_autoscaler_condition->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_condition->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_condition->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(status))
    {
    goto end; //String
    }

    // v2_horizontal_pod_autoscaler_condition->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v2_horizontal_pod_autoscaler_condition_local_var = v2_horizontal_pod_autoscaler_condition_create (
        last_transition_time && !mazu_cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v2_horizontal_pod_autoscaler_condition_local_var;
end:
    return NULL;

}
