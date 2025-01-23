#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_reference.h"



v1_object_reference_t *v1_object_reference_create(
    char *api_version,
    char *field_path,
    char *kind,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
    ) {
    v1_object_reference_t *v1_object_reference_local_var = malloc(sizeof(v1_object_reference_t));
    if (!v1_object_reference_local_var) {
        return NULL;
    }
    v1_object_reference_local_var->api_version = api_version;
    v1_object_reference_local_var->field_path = field_path;
    v1_object_reference_local_var->kind = kind;
    v1_object_reference_local_var->name = name;
    v1_object_reference_local_var->_namespace = _namespace;
    v1_object_reference_local_var->resource_version = resource_version;
    v1_object_reference_local_var->uid = uid;

    return v1_object_reference_local_var;
}


void v1_object_reference_free(v1_object_reference_t *v1_object_reference) {
    if(NULL == v1_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_object_reference->api_version) {
        free(v1_object_reference->api_version);
        v1_object_reference->api_version = NULL;
    }
    if (v1_object_reference->field_path) {
        free(v1_object_reference->field_path);
        v1_object_reference->field_path = NULL;
    }
    if (v1_object_reference->kind) {
        free(v1_object_reference->kind);
        v1_object_reference->kind = NULL;
    }
    if (v1_object_reference->name) {
        free(v1_object_reference->name);
        v1_object_reference->name = NULL;
    }
    if (v1_object_reference->_namespace) {
        free(v1_object_reference->_namespace);
        v1_object_reference->_namespace = NULL;
    }
    if (v1_object_reference->resource_version) {
        free(v1_object_reference->resource_version);
        v1_object_reference->resource_version = NULL;
    }
    if (v1_object_reference->uid) {
        free(v1_object_reference->uid);
        v1_object_reference->uid = NULL;
    }
    free(v1_object_reference);
}

mazu_cJSON *v1_object_reference_convertToJSON(v1_object_reference_t *v1_object_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_object_reference->api_version
    if(v1_object_reference->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_object_reference->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_reference->field_path
    if(v1_object_reference->field_path) {
    if(mazu_cJSON_AddStringToObject(item, "fieldPath", v1_object_reference->field_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_reference->kind
    if(v1_object_reference->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_object_reference->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_reference->name
    if(v1_object_reference->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_object_reference->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_reference->_namespace
    if(v1_object_reference->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_object_reference->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_reference->resource_version
    if(v1_object_reference->resource_version) {
    if(mazu_cJSON_AddStringToObject(item, "resourceVersion", v1_object_reference->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_reference->uid
    if(v1_object_reference->uid) {
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_object_reference->uid) == NULL) {
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

v1_object_reference_t *v1_object_reference_parseFromJSON(mazu_cJSON *v1_object_referenceJSON){

    v1_object_reference_t *v1_object_reference_local_var = NULL;

    // v1_object_reference->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_object_reference->field_path
    mazu_cJSON *field_path = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "fieldPath");
    if (field_path) { 
    if(!mazu_cJSON_IsString(field_path) && !mazu_cJSON_IsNull(field_path))
    {
    goto end; //String
    }
    }

    // v1_object_reference->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_object_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_object_reference->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_object_reference->resource_version
    mazu_cJSON *resource_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "resourceVersion");
    if (resource_version) { 
    if(!mazu_cJSON_IsString(resource_version) && !mazu_cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_object_reference->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "uid");
    if (uid) { 
    if(!mazu_cJSON_IsString(uid) && !mazu_cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1_object_reference_local_var = v1_object_reference_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        field_path && !mazu_cJSON_IsNull(field_path) ? strdup(field_path->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        resource_version && !mazu_cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        uid && !mazu_cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1_object_reference_local_var;
end:
    return NULL;

}
