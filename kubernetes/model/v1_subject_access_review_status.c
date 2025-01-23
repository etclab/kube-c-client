#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_access_review_status.h"



v1_subject_access_review_status_t *v1_subject_access_review_status_create(
    int allowed,
    int denied,
    char *evaluation_error,
    char *reason
    ) {
    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = malloc(sizeof(v1_subject_access_review_status_t));
    if (!v1_subject_access_review_status_local_var) {
        return NULL;
    }
    v1_subject_access_review_status_local_var->allowed = allowed;
    v1_subject_access_review_status_local_var->denied = denied;
    v1_subject_access_review_status_local_var->evaluation_error = evaluation_error;
    v1_subject_access_review_status_local_var->reason = reason;

    return v1_subject_access_review_status_local_var;
}


void v1_subject_access_review_status_free(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    if(NULL == v1_subject_access_review_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_subject_access_review_status->evaluation_error) {
        free(v1_subject_access_review_status->evaluation_error);
        v1_subject_access_review_status->evaluation_error = NULL;
    }
    if (v1_subject_access_review_status->reason) {
        free(v1_subject_access_review_status->reason);
        v1_subject_access_review_status->reason = NULL;
    }
    free(v1_subject_access_review_status);
}

mazu_cJSON *v1_subject_access_review_status_convertToJSON(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_subject_access_review_status->allowed
    if (!v1_subject_access_review_status->allowed) {
        goto fail;
    }
    if(mazu_cJSON_AddBoolToObject(item, "allowed", v1_subject_access_review_status->allowed) == NULL) {
    goto fail; //Bool
    }


    // v1_subject_access_review_status->denied
    if(v1_subject_access_review_status->denied) {
    if(mazu_cJSON_AddBoolToObject(item, "denied", v1_subject_access_review_status->denied) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_subject_access_review_status->evaluation_error
    if(v1_subject_access_review_status->evaluation_error) {
    if(mazu_cJSON_AddStringToObject(item, "evaluationError", v1_subject_access_review_status->evaluation_error) == NULL) {
    goto fail; //String
    }
    }


    // v1_subject_access_review_status->reason
    if(v1_subject_access_review_status->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1_subject_access_review_status->reason) == NULL) {
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

v1_subject_access_review_status_t *v1_subject_access_review_status_parseFromJSON(mazu_cJSON *v1_subject_access_review_statusJSON){

    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = NULL;

    // v1_subject_access_review_status->allowed
    mazu_cJSON *allowed = mazu_cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "allowed");
    if (!allowed) {
        goto end;
    }

    
    if(!mazu_cJSON_IsBool(allowed))
    {
    goto end; //Bool
    }

    // v1_subject_access_review_status->denied
    mazu_cJSON *denied = mazu_cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "denied");
    if (denied) { 
    if(!mazu_cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    }

    // v1_subject_access_review_status->evaluation_error
    mazu_cJSON *evaluation_error = mazu_cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "evaluationError");
    if (evaluation_error) { 
    if(!mazu_cJSON_IsString(evaluation_error) && !mazu_cJSON_IsNull(evaluation_error))
    {
    goto end; //String
    }
    }

    // v1_subject_access_review_status->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1_subject_access_review_status_local_var = v1_subject_access_review_status_create (
        allowed->valueint,
        denied ? denied->valueint : 0,
        evaluation_error && !mazu_cJSON_IsNull(evaluation_error) ? strdup(evaluation_error->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1_subject_access_review_status_local_var;
end:
    return NULL;

}
