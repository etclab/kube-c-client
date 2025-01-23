#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cluster_trust_bundle_projection.h"



v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_create(
    v1_label_selector_t *label_selector,
    char *name,
    int optional,
    char *path,
    char *signer_name
    ) {
    v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_local_var = malloc(sizeof(v1_cluster_trust_bundle_projection_t));
    if (!v1_cluster_trust_bundle_projection_local_var) {
        return NULL;
    }
    v1_cluster_trust_bundle_projection_local_var->label_selector = label_selector;
    v1_cluster_trust_bundle_projection_local_var->name = name;
    v1_cluster_trust_bundle_projection_local_var->optional = optional;
    v1_cluster_trust_bundle_projection_local_var->path = path;
    v1_cluster_trust_bundle_projection_local_var->signer_name = signer_name;

    return v1_cluster_trust_bundle_projection_local_var;
}


void v1_cluster_trust_bundle_projection_free(v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection) {
    if(NULL == v1_cluster_trust_bundle_projection){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cluster_trust_bundle_projection->label_selector) {
        v1_label_selector_free(v1_cluster_trust_bundle_projection->label_selector);
        v1_cluster_trust_bundle_projection->label_selector = NULL;
    }
    if (v1_cluster_trust_bundle_projection->name) {
        free(v1_cluster_trust_bundle_projection->name);
        v1_cluster_trust_bundle_projection->name = NULL;
    }
    if (v1_cluster_trust_bundle_projection->path) {
        free(v1_cluster_trust_bundle_projection->path);
        v1_cluster_trust_bundle_projection->path = NULL;
    }
    if (v1_cluster_trust_bundle_projection->signer_name) {
        free(v1_cluster_trust_bundle_projection->signer_name);
        v1_cluster_trust_bundle_projection->signer_name = NULL;
    }
    free(v1_cluster_trust_bundle_projection);
}

mazu_cJSON *v1_cluster_trust_bundle_projection_convertToJSON(v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_cluster_trust_bundle_projection->label_selector
    if(v1_cluster_trust_bundle_projection->label_selector) {
    mazu_cJSON *label_selector_local_JSON = v1_label_selector_convertToJSON(v1_cluster_trust_bundle_projection->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_cluster_trust_bundle_projection->name
    if(v1_cluster_trust_bundle_projection->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_cluster_trust_bundle_projection->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_cluster_trust_bundle_projection->optional
    if(v1_cluster_trust_bundle_projection->optional) {
    if(mazu_cJSON_AddBoolToObject(item, "optional", v1_cluster_trust_bundle_projection->optional) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_cluster_trust_bundle_projection->path
    if (!v1_cluster_trust_bundle_projection->path) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "path", v1_cluster_trust_bundle_projection->path) == NULL) {
    goto fail; //String
    }


    // v1_cluster_trust_bundle_projection->signer_name
    if(v1_cluster_trust_bundle_projection->signer_name) {
    if(mazu_cJSON_AddStringToObject(item, "signerName", v1_cluster_trust_bundle_projection->signer_name) == NULL) {
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

v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_parseFromJSON(mazu_cJSON *v1_cluster_trust_bundle_projectionJSON){

    v1_cluster_trust_bundle_projection_t *v1_cluster_trust_bundle_projection_local_var = NULL;

    // define the local variable for v1_cluster_trust_bundle_projection->label_selector
    v1_label_selector_t *label_selector_local_nonprim = NULL;

    // v1_cluster_trust_bundle_projection->label_selector
    mazu_cJSON *label_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "labelSelector");
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_cluster_trust_bundle_projection->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_cluster_trust_bundle_projection->optional
    mazu_cJSON *optional = mazu_cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "optional");
    if (optional) { 
    if(!mazu_cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }

    // v1_cluster_trust_bundle_projection->path
    mazu_cJSON *path = mazu_cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_cluster_trust_bundle_projection->signer_name
    mazu_cJSON *signer_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_cluster_trust_bundle_projectionJSON, "signerName");
    if (signer_name) { 
    if(!mazu_cJSON_IsString(signer_name) && !mazu_cJSON_IsNull(signer_name))
    {
    goto end; //String
    }
    }


    v1_cluster_trust_bundle_projection_local_var = v1_cluster_trust_bundle_projection_create (
        label_selector ? label_selector_local_nonprim : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        optional ? optional->valueint : 0,
        strdup(path->valuestring),
        signer_name && !mazu_cJSON_IsNull(signer_name) ? strdup(signer_name->valuestring) : NULL
        );

    return v1_cluster_trust_bundle_projection_local_var;
end:
    if (label_selector_local_nonprim) {
        v1_label_selector_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    return NULL;

}
