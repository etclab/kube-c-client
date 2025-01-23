#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set.h"



v1_replica_set_t *v1_replica_set_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_replica_set_spec_t *spec,
    v1_replica_set_status_t *status
    ) {
    v1_replica_set_t *v1_replica_set_local_var = malloc(sizeof(v1_replica_set_t));
    if (!v1_replica_set_local_var) {
        return NULL;
    }
    v1_replica_set_local_var->api_version = api_version;
    v1_replica_set_local_var->kind = kind;
    v1_replica_set_local_var->metadata = metadata;
    v1_replica_set_local_var->spec = spec;
    v1_replica_set_local_var->status = status;

    return v1_replica_set_local_var;
}


void v1_replica_set_free(v1_replica_set_t *v1_replica_set) {
    if(NULL == v1_replica_set){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replica_set->api_version) {
        free(v1_replica_set->api_version);
        v1_replica_set->api_version = NULL;
    }
    if (v1_replica_set->kind) {
        free(v1_replica_set->kind);
        v1_replica_set->kind = NULL;
    }
    if (v1_replica_set->metadata) {
        v1_object_meta_free(v1_replica_set->metadata);
        v1_replica_set->metadata = NULL;
    }
    if (v1_replica_set->spec) {
        v1_replica_set_spec_free(v1_replica_set->spec);
        v1_replica_set->spec = NULL;
    }
    if (v1_replica_set->status) {
        v1_replica_set_status_free(v1_replica_set->status);
        v1_replica_set->status = NULL;
    }
    free(v1_replica_set);
}

mazu_cJSON *v1_replica_set_convertToJSON(v1_replica_set_t *v1_replica_set) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_replica_set->api_version
    if(v1_replica_set->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_replica_set->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_replica_set->kind
    if(v1_replica_set->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_replica_set->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_replica_set->metadata
    if(v1_replica_set->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_replica_set->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_replica_set->spec
    if(v1_replica_set->spec) {
    mazu_cJSON *spec_local_JSON = v1_replica_set_spec_convertToJSON(v1_replica_set->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_replica_set->status
    if(v1_replica_set->status) {
    mazu_cJSON *status_local_JSON = v1_replica_set_status_convertToJSON(v1_replica_set->status);
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

v1_replica_set_t *v1_replica_set_parseFromJSON(mazu_cJSON *v1_replica_setJSON){

    v1_replica_set_t *v1_replica_set_local_var = NULL;

    // define the local variable for v1_replica_set->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_replica_set->spec
    v1_replica_set_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_replica_set->status
    v1_replica_set_status_t *status_local_nonprim = NULL;

    // v1_replica_set->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_replica_set->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_replica_set->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_replica_set->spec
    mazu_cJSON *spec = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1_replica_set_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_replica_set->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "status");
    if (status) { 
    status_local_nonprim = v1_replica_set_status_parseFromJSON(status); //nonprimitive
    }


    v1_replica_set_local_var = v1_replica_set_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_replica_set_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_replica_set_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_replica_set_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
