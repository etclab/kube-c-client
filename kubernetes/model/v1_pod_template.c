#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_template.h"



v1_pod_template_t *v1_pod_template_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_template_spec_t *_template
    ) {
    v1_pod_template_t *v1_pod_template_local_var = malloc(sizeof(v1_pod_template_t));
    if (!v1_pod_template_local_var) {
        return NULL;
    }
    v1_pod_template_local_var->api_version = api_version;
    v1_pod_template_local_var->kind = kind;
    v1_pod_template_local_var->metadata = metadata;
    v1_pod_template_local_var->_template = _template;

    return v1_pod_template_local_var;
}


void v1_pod_template_free(v1_pod_template_t *v1_pod_template) {
    if(NULL == v1_pod_template){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_template->api_version) {
        free(v1_pod_template->api_version);
        v1_pod_template->api_version = NULL;
    }
    if (v1_pod_template->kind) {
        free(v1_pod_template->kind);
        v1_pod_template->kind = NULL;
    }
    if (v1_pod_template->metadata) {
        v1_object_meta_free(v1_pod_template->metadata);
        v1_pod_template->metadata = NULL;
    }
    if (v1_pod_template->_template) {
        v1_pod_template_spec_free(v1_pod_template->_template);
        v1_pod_template->_template = NULL;
    }
    free(v1_pod_template);
}

mazu_cJSON *v1_pod_template_convertToJSON(v1_pod_template_t *v1_pod_template) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_template->api_version
    if(v1_pod_template->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_pod_template->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_template->kind
    if(v1_pod_template->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_pod_template->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_template->metadata
    if(v1_pod_template->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_pod_template->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_template->_template
    if(v1_pod_template->_template) {
    mazu_cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_pod_template->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "template", _template_local_JSON);
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

v1_pod_template_t *v1_pod_template_parseFromJSON(mazu_cJSON *v1_pod_templateJSON){

    v1_pod_template_t *v1_pod_template_local_var = NULL;

    // define the local variable for v1_pod_template->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_pod_template->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_pod_template->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_pod_template->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_pod_template->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_pod_template->_template
    mazu_cJSON *_template = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_templateJSON, "template");
    if (_template) { 
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive
    }


    v1_pod_template_local_var = v1_pod_template_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        _template ? _template_local_nonprim : NULL
        );

    return v1_pod_template_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
