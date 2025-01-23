#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_status.h"



v1_persistent_volume_status_t *v1_persistent_volume_status_create(
    char *last_phase_transition_time,
    char *message,
    char *phase,
    char *reason
    ) {
    v1_persistent_volume_status_t *v1_persistent_volume_status_local_var = malloc(sizeof(v1_persistent_volume_status_t));
    if (!v1_persistent_volume_status_local_var) {
        return NULL;
    }
    v1_persistent_volume_status_local_var->last_phase_transition_time = last_phase_transition_time;
    v1_persistent_volume_status_local_var->message = message;
    v1_persistent_volume_status_local_var->phase = phase;
    v1_persistent_volume_status_local_var->reason = reason;

    return v1_persistent_volume_status_local_var;
}


void v1_persistent_volume_status_free(v1_persistent_volume_status_t *v1_persistent_volume_status) {
    if(NULL == v1_persistent_volume_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_status->last_phase_transition_time) {
        free(v1_persistent_volume_status->last_phase_transition_time);
        v1_persistent_volume_status->last_phase_transition_time = NULL;
    }
    if (v1_persistent_volume_status->message) {
        free(v1_persistent_volume_status->message);
        v1_persistent_volume_status->message = NULL;
    }
    if (v1_persistent_volume_status->phase) {
        free(v1_persistent_volume_status->phase);
        v1_persistent_volume_status->phase = NULL;
    }
    if (v1_persistent_volume_status->reason) {
        free(v1_persistent_volume_status->reason);
        v1_persistent_volume_status->reason = NULL;
    }
    free(v1_persistent_volume_status);
}

mazu_cJSON *v1_persistent_volume_status_convertToJSON(v1_persistent_volume_status_t *v1_persistent_volume_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_persistent_volume_status->last_phase_transition_time
    if(v1_persistent_volume_status->last_phase_transition_time) {
    if(mazu_cJSON_AddStringToObject(item, "lastPhaseTransitionTime", v1_persistent_volume_status->last_phase_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_persistent_volume_status->message
    if(v1_persistent_volume_status->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1_persistent_volume_status->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_status->phase
    if(v1_persistent_volume_status->phase) {
    if(mazu_cJSON_AddStringToObject(item, "phase", v1_persistent_volume_status->phase) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_status->reason
    if(v1_persistent_volume_status->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1_persistent_volume_status->reason) == NULL) {
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

v1_persistent_volume_status_t *v1_persistent_volume_status_parseFromJSON(mazu_cJSON *v1_persistent_volume_statusJSON){

    v1_persistent_volume_status_t *v1_persistent_volume_status_local_var = NULL;

    // v1_persistent_volume_status->last_phase_transition_time
    mazu_cJSON *last_phase_transition_time = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "lastPhaseTransitionTime");
    if (last_phase_transition_time) { 
    if(!mazu_cJSON_IsString(last_phase_transition_time) && !mazu_cJSON_IsNull(last_phase_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v1_persistent_volume_status->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_status->phase
    mazu_cJSON *phase = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "phase");
    if (phase) { 
    if(!mazu_cJSON_IsString(phase) && !mazu_cJSON_IsNull(phase))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_status->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_statusJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_persistent_volume_status_local_var = v1_persistent_volume_status_create (
        last_phase_transition_time && !mazu_cJSON_IsNull(last_phase_transition_time) ? strdup(last_phase_transition_time->valuestring) : NULL,
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        phase && !mazu_cJSON_IsNull(phase) ? strdup(phase->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_persistent_volume_status_local_var;
end:
    return NULL;

}
