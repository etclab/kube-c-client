#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_waiting.h"



v1_container_state_waiting_t *v1_container_state_waiting_create(
    char *message,
    char *reason
    ) {
    v1_container_state_waiting_t *v1_container_state_waiting_local_var = malloc(sizeof(v1_container_state_waiting_t));
    if (!v1_container_state_waiting_local_var) {
        return NULL;
    }
    v1_container_state_waiting_local_var->message = message;
    v1_container_state_waiting_local_var->reason = reason;

    return v1_container_state_waiting_local_var;
}


void v1_container_state_waiting_free(v1_container_state_waiting_t *v1_container_state_waiting) {
    if(NULL == v1_container_state_waiting){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_state_waiting->message) {
        free(v1_container_state_waiting->message);
        v1_container_state_waiting->message = NULL;
    }
    if (v1_container_state_waiting->reason) {
        free(v1_container_state_waiting->reason);
        v1_container_state_waiting->reason = NULL;
    }
    free(v1_container_state_waiting);
}

mazu_cJSON *v1_container_state_waiting_convertToJSON(v1_container_state_waiting_t *v1_container_state_waiting) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_container_state_waiting->message
    if(v1_container_state_waiting->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1_container_state_waiting->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_container_state_waiting->reason
    if(v1_container_state_waiting->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1_container_state_waiting->reason) == NULL) {
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

v1_container_state_waiting_t *v1_container_state_waiting_parseFromJSON(mazu_cJSON *v1_container_state_waitingJSON){

    v1_container_state_waiting_t *v1_container_state_waiting_local_var = NULL;

    // v1_container_state_waiting->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1_container_state_waitingJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_container_state_waiting->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1_container_state_waitingJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_container_state_waiting_local_var = v1_container_state_waiting_create (
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_container_state_waiting_local_var;
end:
    return NULL;

}
