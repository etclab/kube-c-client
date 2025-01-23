#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map_node_config_source.h"



v1_config_map_node_config_source_t *v1_config_map_node_config_source_create(
    char *kubelet_config_key,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
    ) {
    v1_config_map_node_config_source_t *v1_config_map_node_config_source_local_var = malloc(sizeof(v1_config_map_node_config_source_t));
    if (!v1_config_map_node_config_source_local_var) {
        return NULL;
    }
    v1_config_map_node_config_source_local_var->kubelet_config_key = kubelet_config_key;
    v1_config_map_node_config_source_local_var->name = name;
    v1_config_map_node_config_source_local_var->_namespace = _namespace;
    v1_config_map_node_config_source_local_var->resource_version = resource_version;
    v1_config_map_node_config_source_local_var->uid = uid;

    return v1_config_map_node_config_source_local_var;
}


void v1_config_map_node_config_source_free(v1_config_map_node_config_source_t *v1_config_map_node_config_source) {
    if(NULL == v1_config_map_node_config_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_config_map_node_config_source->kubelet_config_key) {
        free(v1_config_map_node_config_source->kubelet_config_key);
        v1_config_map_node_config_source->kubelet_config_key = NULL;
    }
    if (v1_config_map_node_config_source->name) {
        free(v1_config_map_node_config_source->name);
        v1_config_map_node_config_source->name = NULL;
    }
    if (v1_config_map_node_config_source->_namespace) {
        free(v1_config_map_node_config_source->_namespace);
        v1_config_map_node_config_source->_namespace = NULL;
    }
    if (v1_config_map_node_config_source->resource_version) {
        free(v1_config_map_node_config_source->resource_version);
        v1_config_map_node_config_source->resource_version = NULL;
    }
    if (v1_config_map_node_config_source->uid) {
        free(v1_config_map_node_config_source->uid);
        v1_config_map_node_config_source->uid = NULL;
    }
    free(v1_config_map_node_config_source);
}

mazu_cJSON *v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_t *v1_config_map_node_config_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_config_map_node_config_source->kubelet_config_key
    if (!v1_config_map_node_config_source->kubelet_config_key) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kubeletConfigKey", v1_config_map_node_config_source->kubelet_config_key) == NULL) {
    goto fail; //String
    }


    // v1_config_map_node_config_source->name
    if (!v1_config_map_node_config_source->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_config_map_node_config_source->name) == NULL) {
    goto fail; //String
    }


    // v1_config_map_node_config_source->_namespace
    if (!v1_config_map_node_config_source->_namespace) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_config_map_node_config_source->_namespace) == NULL) {
    goto fail; //String
    }


    // v1_config_map_node_config_source->resource_version
    if(v1_config_map_node_config_source->resource_version) {
    if(mazu_cJSON_AddStringToObject(item, "resourceVersion", v1_config_map_node_config_source->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_config_map_node_config_source->uid
    if(v1_config_map_node_config_source->uid) {
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_config_map_node_config_source->uid) == NULL) {
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

v1_config_map_node_config_source_t *v1_config_map_node_config_source_parseFromJSON(mazu_cJSON *v1_config_map_node_config_sourceJSON){

    v1_config_map_node_config_source_t *v1_config_map_node_config_source_local_var = NULL;

    // v1_config_map_node_config_source->kubelet_config_key
    mazu_cJSON *kubelet_config_key = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "kubeletConfigKey");
    if (!kubelet_config_key) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kubelet_config_key))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "namespace");
    if (!_namespace) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(_namespace))
    {
    goto end; //String
    }

    // v1_config_map_node_config_source->resource_version
    mazu_cJSON *resource_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "resourceVersion");
    if (resource_version) { 
    if(!mazu_cJSON_IsString(resource_version) && !mazu_cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_config_map_node_config_source->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_map_node_config_sourceJSON, "uid");
    if (uid) { 
    if(!mazu_cJSON_IsString(uid) && !mazu_cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1_config_map_node_config_source_local_var = v1_config_map_node_config_source_create (
        strdup(kubelet_config_key->valuestring),
        strdup(name->valuestring),
        strdup(_namespace->valuestring),
        resource_version && !mazu_cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        uid && !mazu_cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1_config_map_node_config_source_local_var;
end:
    return NULL;

}
