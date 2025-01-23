#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_azure_disk_volume_source.h"



v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_create(
    char *caching_mode,
    char *disk_name,
    char *disk_uri,
    char *fs_type,
    char *kind,
    int read_only
    ) {
    v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_local_var = malloc(sizeof(v1_azure_disk_volume_source_t));
    if (!v1_azure_disk_volume_source_local_var) {
        return NULL;
    }
    v1_azure_disk_volume_source_local_var->caching_mode = caching_mode;
    v1_azure_disk_volume_source_local_var->disk_name = disk_name;
    v1_azure_disk_volume_source_local_var->disk_uri = disk_uri;
    v1_azure_disk_volume_source_local_var->fs_type = fs_type;
    v1_azure_disk_volume_source_local_var->kind = kind;
    v1_azure_disk_volume_source_local_var->read_only = read_only;

    return v1_azure_disk_volume_source_local_var;
}


void v1_azure_disk_volume_source_free(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source) {
    if(NULL == v1_azure_disk_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_azure_disk_volume_source->caching_mode) {
        free(v1_azure_disk_volume_source->caching_mode);
        v1_azure_disk_volume_source->caching_mode = NULL;
    }
    if (v1_azure_disk_volume_source->disk_name) {
        free(v1_azure_disk_volume_source->disk_name);
        v1_azure_disk_volume_source->disk_name = NULL;
    }
    if (v1_azure_disk_volume_source->disk_uri) {
        free(v1_azure_disk_volume_source->disk_uri);
        v1_azure_disk_volume_source->disk_uri = NULL;
    }
    if (v1_azure_disk_volume_source->fs_type) {
        free(v1_azure_disk_volume_source->fs_type);
        v1_azure_disk_volume_source->fs_type = NULL;
    }
    if (v1_azure_disk_volume_source->kind) {
        free(v1_azure_disk_volume_source->kind);
        v1_azure_disk_volume_source->kind = NULL;
    }
    free(v1_azure_disk_volume_source);
}

mazu_cJSON *v1_azure_disk_volume_source_convertToJSON(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_azure_disk_volume_source->caching_mode
    if(v1_azure_disk_volume_source->caching_mode) {
    if(mazu_cJSON_AddStringToObject(item, "cachingMode", v1_azure_disk_volume_source->caching_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_disk_volume_source->disk_name
    if (!v1_azure_disk_volume_source->disk_name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "diskName", v1_azure_disk_volume_source->disk_name) == NULL) {
    goto fail; //String
    }


    // v1_azure_disk_volume_source->disk_uri
    if (!v1_azure_disk_volume_source->disk_uri) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "diskURI", v1_azure_disk_volume_source->disk_uri) == NULL) {
    goto fail; //String
    }


    // v1_azure_disk_volume_source->fs_type
    if(v1_azure_disk_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_azure_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_disk_volume_source->kind
    if(v1_azure_disk_volume_source->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_azure_disk_volume_source->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_azure_disk_volume_source->read_only
    if(v1_azure_disk_volume_source->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_azure_disk_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_parseFromJSON(mazu_cJSON *v1_azure_disk_volume_sourceJSON){

    v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_local_var = NULL;

    // v1_azure_disk_volume_source->caching_mode
    mazu_cJSON *caching_mode = mazu_cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "cachingMode");
    if (caching_mode) { 
    if(!mazu_cJSON_IsString(caching_mode) && !mazu_cJSON_IsNull(caching_mode))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->disk_name
    mazu_cJSON *disk_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "diskName");
    if (!disk_name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(disk_name))
    {
    goto end; //String
    }

    // v1_azure_disk_volume_source->disk_uri
    mazu_cJSON *disk_uri = mazu_cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "diskURI");
    if (!disk_uri) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(disk_uri))
    {
    goto end; //String
    }

    // v1_azure_disk_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    v1_azure_disk_volume_source_local_var = v1_azure_disk_volume_source_create (
        caching_mode && !mazu_cJSON_IsNull(caching_mode) ? strdup(caching_mode->valuestring) : NULL,
        strdup(disk_name->valuestring),
        strdup(disk_uri->valuestring),
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        read_only ? read_only->valueint : 0
        );

    return v1_azure_disk_volume_source_local_var;
end:
    return NULL;

}
