#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_status.h"



v1_token_request_status_t *v1_token_request_status_create(
    char *expiration_timestamp,
    char *token
    ) {
    v1_token_request_status_t *v1_token_request_status_local_var = malloc(sizeof(v1_token_request_status_t));
    if (!v1_token_request_status_local_var) {
        return NULL;
    }
    v1_token_request_status_local_var->expiration_timestamp = expiration_timestamp;
    v1_token_request_status_local_var->token = token;

    return v1_token_request_status_local_var;
}


void v1_token_request_status_free(v1_token_request_status_t *v1_token_request_status) {
    if(NULL == v1_token_request_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_request_status->expiration_timestamp) {
        free(v1_token_request_status->expiration_timestamp);
        v1_token_request_status->expiration_timestamp = NULL;
    }
    if (v1_token_request_status->token) {
        free(v1_token_request_status->token);
        v1_token_request_status->token = NULL;
    }
    free(v1_token_request_status);
}

mazu_cJSON *v1_token_request_status_convertToJSON(v1_token_request_status_t *v1_token_request_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_token_request_status->expiration_timestamp
    if (!v1_token_request_status->expiration_timestamp) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "expirationTimestamp", v1_token_request_status->expiration_timestamp) == NULL) {
    goto fail; //Date-Time
    }


    // v1_token_request_status->token
    if (!v1_token_request_status->token) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "token", v1_token_request_status->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_token_request_status_t *v1_token_request_status_parseFromJSON(mazu_cJSON *v1_token_request_statusJSON){

    v1_token_request_status_t *v1_token_request_status_local_var = NULL;

    // v1_token_request_status->expiration_timestamp
    mazu_cJSON *expiration_timestamp = mazu_cJSON_GetObjectItemCaseSensitive(v1_token_request_statusJSON, "expirationTimestamp");
    if (!expiration_timestamp) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(expiration_timestamp) && !mazu_cJSON_IsNull(expiration_timestamp))
    {
    goto end; //DateTime
    }

    // v1_token_request_status->token
    mazu_cJSON *token = mazu_cJSON_GetObjectItemCaseSensitive(v1_token_request_statusJSON, "token");
    if (!token) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(token))
    {
    goto end; //String
    }


    v1_token_request_status_local_var = v1_token_request_status_create (
        strdup(expiration_timestamp->valuestring),
        strdup(token->valuestring)
        );

    return v1_token_request_status_local_var;
end:
    return NULL;

}
