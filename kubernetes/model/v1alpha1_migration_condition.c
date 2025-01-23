#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_migration_condition.h"



v1alpha1_migration_condition_t *v1alpha1_migration_condition_create(
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v1alpha1_migration_condition_t *v1alpha1_migration_condition_local_var = malloc(sizeof(v1alpha1_migration_condition_t));
    if (!v1alpha1_migration_condition_local_var) {
        return NULL;
    }
    v1alpha1_migration_condition_local_var->last_update_time = last_update_time;
    v1alpha1_migration_condition_local_var->message = message;
    v1alpha1_migration_condition_local_var->reason = reason;
    v1alpha1_migration_condition_local_var->status = status;
    v1alpha1_migration_condition_local_var->type = type;

    return v1alpha1_migration_condition_local_var;
}


void v1alpha1_migration_condition_free(v1alpha1_migration_condition_t *v1alpha1_migration_condition) {
    if(NULL == v1alpha1_migration_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_migration_condition->last_update_time) {
        free(v1alpha1_migration_condition->last_update_time);
        v1alpha1_migration_condition->last_update_time = NULL;
    }
    if (v1alpha1_migration_condition->message) {
        free(v1alpha1_migration_condition->message);
        v1alpha1_migration_condition->message = NULL;
    }
    if (v1alpha1_migration_condition->reason) {
        free(v1alpha1_migration_condition->reason);
        v1alpha1_migration_condition->reason = NULL;
    }
    if (v1alpha1_migration_condition->status) {
        free(v1alpha1_migration_condition->status);
        v1alpha1_migration_condition->status = NULL;
    }
    if (v1alpha1_migration_condition->type) {
        free(v1alpha1_migration_condition->type);
        v1alpha1_migration_condition->type = NULL;
    }
    free(v1alpha1_migration_condition);
}

mazu_cJSON *v1alpha1_migration_condition_convertToJSON(v1alpha1_migration_condition_t *v1alpha1_migration_condition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_migration_condition->last_update_time
    if(v1alpha1_migration_condition->last_update_time) {
    if(mazu_cJSON_AddStringToObject(item, "lastUpdateTime", v1alpha1_migration_condition->last_update_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1alpha1_migration_condition->message
    if(v1alpha1_migration_condition->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1alpha1_migration_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_migration_condition->reason
    if(v1alpha1_migration_condition->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1alpha1_migration_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_migration_condition->status
    if (!v1alpha1_migration_condition->status) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "status", v1alpha1_migration_condition->status) == NULL) {
    goto fail; //String
    }


    // v1alpha1_migration_condition->type
    if (!v1alpha1_migration_condition->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1alpha1_migration_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_migration_condition_t *v1alpha1_migration_condition_parseFromJSON(mazu_cJSON *v1alpha1_migration_conditionJSON){

    v1alpha1_migration_condition_t *v1alpha1_migration_condition_local_var = NULL;

    // v1alpha1_migration_condition->last_update_time
    mazu_cJSON *last_update_time = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "lastUpdateTime");
    if (last_update_time) { 
    if(!mazu_cJSON_IsString(last_update_time) && !mazu_cJSON_IsNull(last_update_time))
    {
    goto end; //DateTime
    }
    }

    // v1alpha1_migration_condition->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_migration_condition->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1alpha1_migration_condition->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1alpha1_migration_condition->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_migration_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1alpha1_migration_condition_local_var = v1alpha1_migration_condition_create (
        last_update_time && !mazu_cJSON_IsNull(last_update_time) ? strdup(last_update_time->valuestring) : NULL,
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1alpha1_migration_condition_local_var;
end:
    return NULL;

}
