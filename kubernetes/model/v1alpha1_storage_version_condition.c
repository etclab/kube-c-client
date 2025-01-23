#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version_condition.h"



v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_create(
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
    ) {
    v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_local_var = malloc(sizeof(v1alpha1_storage_version_condition_t));
    if (!v1alpha1_storage_version_condition_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_condition_local_var->last_transition_time = last_transition_time;
    v1alpha1_storage_version_condition_local_var->message = message;
    v1alpha1_storage_version_condition_local_var->observed_generation = observed_generation;
    v1alpha1_storage_version_condition_local_var->reason = reason;
    v1alpha1_storage_version_condition_local_var->status = status;
    v1alpha1_storage_version_condition_local_var->type = type;

    return v1alpha1_storage_version_condition_local_var;
}


void v1alpha1_storage_version_condition_free(v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition) {
    if(NULL == v1alpha1_storage_version_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version_condition->last_transition_time) {
        free(v1alpha1_storage_version_condition->last_transition_time);
        v1alpha1_storage_version_condition->last_transition_time = NULL;
    }
    if (v1alpha1_storage_version_condition->message) {
        free(v1alpha1_storage_version_condition->message);
        v1alpha1_storage_version_condition->message = NULL;
    }
    if (v1alpha1_storage_version_condition->reason) {
        free(v1alpha1_storage_version_condition->reason);
        v1alpha1_storage_version_condition->reason = NULL;
    }
    if (v1alpha1_storage_version_condition->status) {
        free(v1alpha1_storage_version_condition->status);
        v1alpha1_storage_version_condition->status = NULL;
    }
    if (v1alpha1_storage_version_condition->type) {
        free(v1alpha1_storage_version_condition->type);
        v1alpha1_storage_version_condition->type = NULL;
    }
    free(v1alpha1_storage_version_condition);
}

mazu_cJSON *v1alpha1_storage_version_condition_convertToJSON(v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_storage_version_condition->last_transition_time
    if(v1alpha1_storage_version_condition->last_transition_time) {
    if(mazu_cJSON_AddStringToObject(item, "lastTransitionTime", v1alpha1_storage_version_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_storage_version_condition->message
    if (!v1alpha1_storage_version_condition->message) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "message", v1alpha1_storage_version_condition->message) == NULL) {
    goto fail; //String
    }


    // v1alpha1_storage_version_condition->observed_generation
    if(v1alpha1_storage_version_condition->observed_generation) {
    if(mazu_cJSON_AddNumberToObject(item, "observedGeneration", v1alpha1_storage_version_condition->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha1_storage_version_condition->reason
    if (!v1alpha1_storage_version_condition->reason) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "reason", v1alpha1_storage_version_condition->reason) == NULL) {
    goto fail; //String
    }


    // v1alpha1_storage_version_condition->status
    if (!v1alpha1_storage_version_condition->status) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "status", v1alpha1_storage_version_condition->status) == NULL) {
    goto fail; //String
    }


    // v1alpha1_storage_version_condition->type
    if (!v1alpha1_storage_version_condition->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1alpha1_storage_version_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_parseFromJSON(mazu_cJSON *v1alpha1_storage_version_conditionJSON){

    v1alpha1_storage_version_condition_t *v1alpha1_storage_version_condition_local_var = NULL;

    // v1alpha1_storage_version_condition->last_transition_time
    mazu_cJSON *last_transition_time = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!mazu_cJSON_IsString(last_transition_time) && !mazu_cJSON_IsNull(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_storage_version_condition->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "message");
    if (!message) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(message))
    {
    goto end; //String
    }

    // v1alpha1_storage_version_condition->observed_generation
    mazu_cJSON *observed_generation = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "observedGeneration");
    if (observed_generation) { 
    if(!mazu_cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1alpha1_storage_version_condition->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "reason");
    if (!reason) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(reason))
    {
    goto end; //String
    }

    // v1alpha1_storage_version_condition->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1alpha1_storage_version_condition->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_version_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1alpha1_storage_version_condition_local_var = v1alpha1_storage_version_condition_create (
        last_transition_time && !mazu_cJSON_IsNull(last_transition_time) ? strdup(last_transition_time->valuestring) : NULL,
        strdup(message->valuestring),
        observed_generation ? observed_generation->valuedouble : 0,
        strdup(reason->valuestring),
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1alpha1_storage_version_condition_local_var;
end:
    return NULL;

}
