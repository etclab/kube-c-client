#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_cross_version_object_reference.h"



v2_cross_version_object_reference_t *v2_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
    ) {
    v2_cross_version_object_reference_t *v2_cross_version_object_reference_local_var = malloc(sizeof(v2_cross_version_object_reference_t));
    if (!v2_cross_version_object_reference_local_var) {
        return NULL;
    }
    v2_cross_version_object_reference_local_var->api_version = api_version;
    v2_cross_version_object_reference_local_var->kind = kind;
    v2_cross_version_object_reference_local_var->name = name;

    return v2_cross_version_object_reference_local_var;
}


void v2_cross_version_object_reference_free(v2_cross_version_object_reference_t *v2_cross_version_object_reference) {
    if(NULL == v2_cross_version_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_cross_version_object_reference->api_version) {
        free(v2_cross_version_object_reference->api_version);
        v2_cross_version_object_reference->api_version = NULL;
    }
    if (v2_cross_version_object_reference->kind) {
        free(v2_cross_version_object_reference->kind);
        v2_cross_version_object_reference->kind = NULL;
    }
    if (v2_cross_version_object_reference->name) {
        free(v2_cross_version_object_reference->name);
        v2_cross_version_object_reference->name = NULL;
    }
    free(v2_cross_version_object_reference);
}

mazu_cJSON *v2_cross_version_object_reference_convertToJSON(v2_cross_version_object_reference_t *v2_cross_version_object_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v2_cross_version_object_reference->api_version
    if(v2_cross_version_object_reference->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v2_cross_version_object_reference->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2_cross_version_object_reference->kind
    if (!v2_cross_version_object_reference->kind) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kind", v2_cross_version_object_reference->kind) == NULL) {
    goto fail; //String
    }


    // v2_cross_version_object_reference->name
    if (!v2_cross_version_object_reference->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v2_cross_version_object_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v2_cross_version_object_reference_t *v2_cross_version_object_reference_parseFromJSON(mazu_cJSON *v2_cross_version_object_referenceJSON){

    v2_cross_version_object_reference_t *v2_cross_version_object_reference_local_var = NULL;

    // v2_cross_version_object_reference->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v2_cross_version_object_referenceJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v2_cross_version_object_reference->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v2_cross_version_object_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v2_cross_version_object_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v2_cross_version_object_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }


    v2_cross_version_object_reference_local_var = v2_cross_version_object_reference_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v2_cross_version_object_reference_local_var;
end:
    return NULL;

}
