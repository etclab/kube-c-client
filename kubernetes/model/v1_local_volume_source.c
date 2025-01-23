#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_local_volume_source.h"



v1_local_volume_source_t *v1_local_volume_source_create(
    char *fs_type,
    char *path
    ) {
    v1_local_volume_source_t *v1_local_volume_source_local_var = malloc(sizeof(v1_local_volume_source_t));
    if (!v1_local_volume_source_local_var) {
        return NULL;
    }
    v1_local_volume_source_local_var->fs_type = fs_type;
    v1_local_volume_source_local_var->path = path;

    return v1_local_volume_source_local_var;
}


void v1_local_volume_source_free(v1_local_volume_source_t *v1_local_volume_source) {
    if(NULL == v1_local_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_local_volume_source->fs_type) {
        free(v1_local_volume_source->fs_type);
        v1_local_volume_source->fs_type = NULL;
    }
    if (v1_local_volume_source->path) {
        free(v1_local_volume_source->path);
        v1_local_volume_source->path = NULL;
    }
    free(v1_local_volume_source);
}

mazu_cJSON *v1_local_volume_source_convertToJSON(v1_local_volume_source_t *v1_local_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_local_volume_source->fs_type
    if(v1_local_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_local_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_local_volume_source->path
    if (!v1_local_volume_source->path) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "path", v1_local_volume_source->path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_local_volume_source_t *v1_local_volume_source_parseFromJSON(mazu_cJSON *v1_local_volume_sourceJSON){

    v1_local_volume_source_t *v1_local_volume_source_local_var = NULL;

    // v1_local_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_local_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_local_volume_source->path
    mazu_cJSON *path = mazu_cJSON_GetObjectItemCaseSensitive(v1_local_volume_sourceJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(path))
    {
    goto end; //String
    }


    v1_local_volume_source_local_var = v1_local_volume_source_create (
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        strdup(path->valuestring)
        );

    return v1_local_volume_source_local_var;
end:
    return NULL;

}
