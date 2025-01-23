#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_self_subject_review.h"



v1alpha1_self_subject_review_t *v1alpha1_self_subject_review_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_self_subject_review_status_t *status
    ) {
    v1alpha1_self_subject_review_t *v1alpha1_self_subject_review_local_var = malloc(sizeof(v1alpha1_self_subject_review_t));
    if (!v1alpha1_self_subject_review_local_var) {
        return NULL;
    }
    v1alpha1_self_subject_review_local_var->api_version = api_version;
    v1alpha1_self_subject_review_local_var->kind = kind;
    v1alpha1_self_subject_review_local_var->metadata = metadata;
    v1alpha1_self_subject_review_local_var->status = status;

    return v1alpha1_self_subject_review_local_var;
}


void v1alpha1_self_subject_review_free(v1alpha1_self_subject_review_t *v1alpha1_self_subject_review) {
    if(NULL == v1alpha1_self_subject_review){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_self_subject_review->api_version) {
        free(v1alpha1_self_subject_review->api_version);
        v1alpha1_self_subject_review->api_version = NULL;
    }
    if (v1alpha1_self_subject_review->kind) {
        free(v1alpha1_self_subject_review->kind);
        v1alpha1_self_subject_review->kind = NULL;
    }
    if (v1alpha1_self_subject_review->metadata) {
        v1_object_meta_free(v1alpha1_self_subject_review->metadata);
        v1alpha1_self_subject_review->metadata = NULL;
    }
    if (v1alpha1_self_subject_review->status) {
        v1alpha1_self_subject_review_status_free(v1alpha1_self_subject_review->status);
        v1alpha1_self_subject_review->status = NULL;
    }
    free(v1alpha1_self_subject_review);
}

mazu_cJSON *v1alpha1_self_subject_review_convertToJSON(v1alpha1_self_subject_review_t *v1alpha1_self_subject_review) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_self_subject_review->api_version
    if(v1alpha1_self_subject_review->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1alpha1_self_subject_review->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_self_subject_review->kind
    if(v1alpha1_self_subject_review->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1alpha1_self_subject_review->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_self_subject_review->metadata
    if(v1alpha1_self_subject_review->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_self_subject_review->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_self_subject_review->status
    if(v1alpha1_self_subject_review->status) {
    mazu_cJSON *status_local_JSON = v1alpha1_self_subject_review_status_convertToJSON(v1alpha1_self_subject_review->status);
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

v1alpha1_self_subject_review_t *v1alpha1_self_subject_review_parseFromJSON(mazu_cJSON *v1alpha1_self_subject_reviewJSON){

    v1alpha1_self_subject_review_t *v1alpha1_self_subject_review_local_var = NULL;

    // define the local variable for v1alpha1_self_subject_review->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha1_self_subject_review->status
    v1alpha1_self_subject_review_status_t *status_local_nonprim = NULL;

    // v1alpha1_self_subject_review->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_self_subject_reviewJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_self_subject_review->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_self_subject_reviewJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_self_subject_review->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_self_subject_reviewJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_self_subject_review->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_self_subject_reviewJSON, "status");
    if (status) { 
    status_local_nonprim = v1alpha1_self_subject_review_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha1_self_subject_review_local_var = v1alpha1_self_subject_review_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1alpha1_self_subject_review_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha1_self_subject_review_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
