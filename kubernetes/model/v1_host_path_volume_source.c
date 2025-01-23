#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_host_path_volume_source.h"



v1_host_path_volume_source_t *v1_host_path_volume_source_create(
    char *path,
    char *type
    ) {
    v1_host_path_volume_source_t *v1_host_path_volume_source_local_var = malloc(sizeof(v1_host_path_volume_source_t));
    if (!v1_host_path_volume_source_local_var) {
        return NULL;
    }
    v1_host_path_volume_source_local_var->path = path;
    v1_host_path_volume_source_local_var->type = type;

    return v1_host_path_volume_source_local_var;
}


void v1_host_path_volume_source_free(v1_host_path_volume_source_t *v1_host_path_volume_source) {
    if(NULL == v1_host_path_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_host_path_volume_source->path) {
        free(v1_host_path_volume_source->path);
        v1_host_path_volume_source->path = NULL;
    }
    if (v1_host_path_volume_source->type) {
        free(v1_host_path_volume_source->type);
        v1_host_path_volume_source->type = NULL;
    }
    free(v1_host_path_volume_source);
}

mazu_cJSON *v1_host_path_volume_source_convertToJSON(v1_host_path_volume_source_t *v1_host_path_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_host_path_volume_source->path
    if (!v1_host_path_volume_source->path) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "path", v1_host_path_volume_source->path) == NULL) {
    goto fail; //String
    }


    // v1_host_path_volume_source->type
    if(v1_host_path_volume_source->type) {
    if(mazu_cJSON_AddStringToObject(item, "type", v1_host_path_volume_source->type) == NULL) {
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

v1_host_path_volume_source_t *v1_host_path_volume_source_parseFromJSON(mazu_cJSON *v1_host_path_volume_sourceJSON){

    v1_host_path_volume_source_t *v1_host_path_volume_source_local_var = NULL;

    // v1_host_path_volume_source->path
    mazu_cJSON *path = mazu_cJSON_GetObjectItemCaseSensitive(v1_host_path_volume_sourceJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_host_path_volume_source->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1_host_path_volume_sourceJSON, "type");
    if (type) { 
    if(!mazu_cJSON_IsString(type) && !mazu_cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    v1_host_path_volume_source_local_var = v1_host_path_volume_source_create (
        strdup(path->valuestring),
        type && !mazu_cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return v1_host_path_volume_source_local_var;
end:
    return NULL;

}
