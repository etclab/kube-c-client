#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_status_cause.h"



v1_status_cause_t *v1_status_cause_create(
    char *field,
    char *message,
    char *reason
    ) {
    v1_status_cause_t *v1_status_cause_local_var = malloc(sizeof(v1_status_cause_t));
    if (!v1_status_cause_local_var) {
        return NULL;
    }
    v1_status_cause_local_var->field = field;
    v1_status_cause_local_var->message = message;
    v1_status_cause_local_var->reason = reason;

    return v1_status_cause_local_var;
}


void v1_status_cause_free(v1_status_cause_t *v1_status_cause) {
    if(NULL == v1_status_cause){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_status_cause->field) {
        free(v1_status_cause->field);
        v1_status_cause->field = NULL;
    }
    if (v1_status_cause->message) {
        free(v1_status_cause->message);
        v1_status_cause->message = NULL;
    }
    if (v1_status_cause->reason) {
        free(v1_status_cause->reason);
        v1_status_cause->reason = NULL;
    }
    free(v1_status_cause);
}

mazu_cJSON *v1_status_cause_convertToJSON(v1_status_cause_t *v1_status_cause) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_status_cause->field
    if(v1_status_cause->field) {
    if(mazu_cJSON_AddStringToObject(item, "field", v1_status_cause->field) == NULL) {
    goto fail; //String
    }
    }


    // v1_status_cause->message
    if(v1_status_cause->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1_status_cause->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_status_cause->reason
    if(v1_status_cause->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1_status_cause->reason) == NULL) {
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

v1_status_cause_t *v1_status_cause_parseFromJSON(mazu_cJSON *v1_status_causeJSON){

    v1_status_cause_t *v1_status_cause_local_var = NULL;

    // v1_status_cause->field
    mazu_cJSON *field = mazu_cJSON_GetObjectItemCaseSensitive(v1_status_causeJSON, "field");
    if (field) { 
    if(!mazu_cJSON_IsString(field) && !mazu_cJSON_IsNull(field))
    {
    goto end; //String
    }
    }

    // v1_status_cause->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1_status_causeJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_status_cause->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1_status_causeJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_status_cause_local_var = v1_status_cause_create (
        field && !mazu_cJSON_IsNull(field) ? strdup(field->valuestring) : NULL,
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_status_cause_local_var;
end:
    return NULL;

}
