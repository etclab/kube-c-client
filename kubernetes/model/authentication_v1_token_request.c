#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "authentication_v1_token_request.h"



authentication_v1_token_request_t *authentication_v1_token_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_request_spec_t *spec,
    v1_token_request_status_t *status
    ) {
    authentication_v1_token_request_t *authentication_v1_token_request_local_var = malloc(sizeof(authentication_v1_token_request_t));
    if (!authentication_v1_token_request_local_var) {
        return NULL;
    }
    authentication_v1_token_request_local_var->api_version = api_version;
    authentication_v1_token_request_local_var->kind = kind;
    authentication_v1_token_request_local_var->metadata = metadata;
    authentication_v1_token_request_local_var->spec = spec;
    authentication_v1_token_request_local_var->status = status;

    return authentication_v1_token_request_local_var;
}


void authentication_v1_token_request_free(authentication_v1_token_request_t *authentication_v1_token_request) {
    if(NULL == authentication_v1_token_request){
        return ;
    }
    listEntry_t *listEntry;
    if (authentication_v1_token_request->api_version) {
        free(authentication_v1_token_request->api_version);
        authentication_v1_token_request->api_version = NULL;
    }
    if (authentication_v1_token_request->kind) {
        free(authentication_v1_token_request->kind);
        authentication_v1_token_request->kind = NULL;
    }
    if (authentication_v1_token_request->metadata) {
        v1_object_meta_free(authentication_v1_token_request->metadata);
        authentication_v1_token_request->metadata = NULL;
    }
    if (authentication_v1_token_request->spec) {
        v1_token_request_spec_free(authentication_v1_token_request->spec);
        authentication_v1_token_request->spec = NULL;
    }
    if (authentication_v1_token_request->status) {
        v1_token_request_status_free(authentication_v1_token_request->status);
        authentication_v1_token_request->status = NULL;
    }
    free(authentication_v1_token_request);
}

mazu_cJSON *authentication_v1_token_request_convertToJSON(authentication_v1_token_request_t *authentication_v1_token_request) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // authentication_v1_token_request->api_version
    if(authentication_v1_token_request->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", authentication_v1_token_request->api_version) == NULL) {
    goto fail; //String
    }
    }


    // authentication_v1_token_request->kind
    if(authentication_v1_token_request->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", authentication_v1_token_request->kind) == NULL) {
    goto fail; //String
    }
    }


    // authentication_v1_token_request->metadata
    if(authentication_v1_token_request->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(authentication_v1_token_request->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // authentication_v1_token_request->spec
    if (!authentication_v1_token_request->spec) {
        goto fail;
    }
    mazu_cJSON *spec_local_JSON = v1_token_request_spec_convertToJSON(authentication_v1_token_request->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // authentication_v1_token_request->status
    if(authentication_v1_token_request->status) {
    mazu_cJSON *status_local_JSON = v1_token_request_status_convertToJSON(authentication_v1_token_request->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

authentication_v1_token_request_t *authentication_v1_token_request_parseFromJSON(mazu_cJSON *authentication_v1_token_requestJSON){

    authentication_v1_token_request_t *authentication_v1_token_request_local_var = NULL;

    // define the local variable for authentication_v1_token_request->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for authentication_v1_token_request->spec
    v1_token_request_spec_t *spec_local_nonprim = NULL;

    // define the local variable for authentication_v1_token_request->status
    v1_token_request_status_t *status_local_nonprim = NULL;

    // authentication_v1_token_request->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // authentication_v1_token_request->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // authentication_v1_token_request->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // authentication_v1_token_request->spec
    mazu_cJSON *spec = mazu_cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_token_request_spec_parseFromJSON(spec); //nonprimitive

    // authentication_v1_token_request->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "status");
    if (status) { 
    status_local_nonprim = v1_token_request_status_parseFromJSON(status); //nonprimitive
    }


    authentication_v1_token_request_local_var = authentication_v1_token_request_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return authentication_v1_token_request_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_token_request_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_token_request_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
