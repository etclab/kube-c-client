#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_service.h"



v1_api_service_t *v1_api_service_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_api_service_spec_t *spec,
    v1_api_service_status_t *status
    ) {
    v1_api_service_t *v1_api_service_local_var = malloc(sizeof(v1_api_service_t));
    if (!v1_api_service_local_var) {
        return NULL;
    }
    v1_api_service_local_var->api_version = api_version;
    v1_api_service_local_var->kind = kind;
    v1_api_service_local_var->metadata = metadata;
    v1_api_service_local_var->spec = spec;
    v1_api_service_local_var->status = status;

    return v1_api_service_local_var;
}


void v1_api_service_free(v1_api_service_t *v1_api_service) {
    if(NULL == v1_api_service){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_service->api_version) {
        free(v1_api_service->api_version);
        v1_api_service->api_version = NULL;
    }
    if (v1_api_service->kind) {
        free(v1_api_service->kind);
        v1_api_service->kind = NULL;
    }
    if (v1_api_service->metadata) {
        v1_object_meta_free(v1_api_service->metadata);
        v1_api_service->metadata = NULL;
    }
    if (v1_api_service->spec) {
        v1_api_service_spec_free(v1_api_service->spec);
        v1_api_service->spec = NULL;
    }
    if (v1_api_service->status) {
        v1_api_service_status_free(v1_api_service->status);
        v1_api_service->status = NULL;
    }
    free(v1_api_service);
}

mazu_cJSON *v1_api_service_convertToJSON(v1_api_service_t *v1_api_service) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_api_service->api_version
    if(v1_api_service->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_api_service->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_service->kind
    if(v1_api_service->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_api_service->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_service->metadata
    if(v1_api_service->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_api_service->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_api_service->spec
    if(v1_api_service->spec) {
    mazu_cJSON *spec_local_JSON = v1_api_service_spec_convertToJSON(v1_api_service->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_api_service->status
    if(v1_api_service->status) {
    mazu_cJSON *status_local_JSON = v1_api_service_status_convertToJSON(v1_api_service->status);
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

v1_api_service_t *v1_api_service_parseFromJSON(mazu_cJSON *v1_api_serviceJSON){

    v1_api_service_t *v1_api_service_local_var = NULL;

    // define the local variable for v1_api_service->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_api_service->spec
    v1_api_service_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_api_service->status
    v1_api_service_status_t *status_local_nonprim = NULL;

    // v1_api_service->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_serviceJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_api_service->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_serviceJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_api_service->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_serviceJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_api_service->spec
    mazu_cJSON *spec = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_serviceJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1_api_service_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_api_service->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_serviceJSON, "status");
    if (status) { 
    status_local_nonprim = v1_api_service_status_parseFromJSON(status); //nonprimitive
    }


    v1_api_service_local_var = v1_api_service_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_api_service_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_api_service_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_api_service_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
