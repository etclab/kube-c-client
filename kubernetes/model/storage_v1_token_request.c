#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_v1_token_request.h"



storage_v1_token_request_t *storage_v1_token_request_create(
    char *audience,
    long expiration_seconds
    ) {
    storage_v1_token_request_t *storage_v1_token_request_local_var = malloc(sizeof(storage_v1_token_request_t));
    if (!storage_v1_token_request_local_var) {
        return NULL;
    }
    storage_v1_token_request_local_var->audience = audience;
    storage_v1_token_request_local_var->expiration_seconds = expiration_seconds;

    return storage_v1_token_request_local_var;
}


void storage_v1_token_request_free(storage_v1_token_request_t *storage_v1_token_request) {
    if(NULL == storage_v1_token_request){
        return ;
    }
    listEntry_t *listEntry;
    if (storage_v1_token_request->audience) {
        free(storage_v1_token_request->audience);
        storage_v1_token_request->audience = NULL;
    }
    free(storage_v1_token_request);
}

mazu_cJSON *storage_v1_token_request_convertToJSON(storage_v1_token_request_t *storage_v1_token_request) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // storage_v1_token_request->audience
    if (!storage_v1_token_request->audience) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "audience", storage_v1_token_request->audience) == NULL) {
    goto fail; //String
    }


    // storage_v1_token_request->expiration_seconds
    if(storage_v1_token_request->expiration_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "expirationSeconds", storage_v1_token_request->expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

storage_v1_token_request_t *storage_v1_token_request_parseFromJSON(mazu_cJSON *storage_v1_token_requestJSON){

    storage_v1_token_request_t *storage_v1_token_request_local_var = NULL;

    // storage_v1_token_request->audience
    mazu_cJSON *audience = mazu_cJSON_GetObjectItemCaseSensitive(storage_v1_token_requestJSON, "audience");
    if (!audience) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(audience))
    {
    goto end; //String
    }

    // storage_v1_token_request->expiration_seconds
    mazu_cJSON *expiration_seconds = mazu_cJSON_GetObjectItemCaseSensitive(storage_v1_token_requestJSON, "expirationSeconds");
    if (expiration_seconds) { 
    if(!mazu_cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    }


    storage_v1_token_request_local_var = storage_v1_token_request_create (
        strdup(audience->valuestring),
        expiration_seconds ? expiration_seconds->valuedouble : 0
        );

    return storage_v1_token_request_local_var;
end:
    return NULL;

}
