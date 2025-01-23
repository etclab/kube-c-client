#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_mount.h"



v1_volume_mount_t *v1_volume_mount_create(
    char *mount_path,
    char *mount_propagation,
    char *name,
    int read_only,
    char *recursive_read_only,
    char *sub_path,
    char *sub_path_expr
    ) {
    v1_volume_mount_t *v1_volume_mount_local_var = malloc(sizeof(v1_volume_mount_t));
    if (!v1_volume_mount_local_var) {
        return NULL;
    }
    v1_volume_mount_local_var->mount_path = mount_path;
    v1_volume_mount_local_var->mount_propagation = mount_propagation;
    v1_volume_mount_local_var->name = name;
    v1_volume_mount_local_var->read_only = read_only;
    v1_volume_mount_local_var->recursive_read_only = recursive_read_only;
    v1_volume_mount_local_var->sub_path = sub_path;
    v1_volume_mount_local_var->sub_path_expr = sub_path_expr;

    return v1_volume_mount_local_var;
}


void v1_volume_mount_free(v1_volume_mount_t *v1_volume_mount) {
    if(NULL == v1_volume_mount){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_mount->mount_path) {
        free(v1_volume_mount->mount_path);
        v1_volume_mount->mount_path = NULL;
    }
    if (v1_volume_mount->mount_propagation) {
        free(v1_volume_mount->mount_propagation);
        v1_volume_mount->mount_propagation = NULL;
    }
    if (v1_volume_mount->name) {
        free(v1_volume_mount->name);
        v1_volume_mount->name = NULL;
    }
    if (v1_volume_mount->recursive_read_only) {
        free(v1_volume_mount->recursive_read_only);
        v1_volume_mount->recursive_read_only = NULL;
    }
    if (v1_volume_mount->sub_path) {
        free(v1_volume_mount->sub_path);
        v1_volume_mount->sub_path = NULL;
    }
    if (v1_volume_mount->sub_path_expr) {
        free(v1_volume_mount->sub_path_expr);
        v1_volume_mount->sub_path_expr = NULL;
    }
    free(v1_volume_mount);
}

mazu_cJSON *v1_volume_mount_convertToJSON(v1_volume_mount_t *v1_volume_mount) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_volume_mount->mount_path
    if (!v1_volume_mount->mount_path) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "mountPath", v1_volume_mount->mount_path) == NULL) {
    goto fail; //String
    }


    // v1_volume_mount->mount_propagation
    if(v1_volume_mount->mount_propagation) {
    if(mazu_cJSON_AddStringToObject(item, "mountPropagation", v1_volume_mount->mount_propagation) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount->name
    if (!v1_volume_mount->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_volume_mount->name) == NULL) {
    goto fail; //String
    }


    // v1_volume_mount->read_only
    if(v1_volume_mount->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_volume_mount->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_volume_mount->recursive_read_only
    if(v1_volume_mount->recursive_read_only) {
    if(mazu_cJSON_AddStringToObject(item, "recursiveReadOnly", v1_volume_mount->recursive_read_only) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount->sub_path
    if(v1_volume_mount->sub_path) {
    if(mazu_cJSON_AddStringToObject(item, "subPath", v1_volume_mount->sub_path) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount->sub_path_expr
    if(v1_volume_mount->sub_path_expr) {
    if(mazu_cJSON_AddStringToObject(item, "subPathExpr", v1_volume_mount->sub_path_expr) == NULL) {
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

v1_volume_mount_t *v1_volume_mount_parseFromJSON(mazu_cJSON *v1_volume_mountJSON){

    v1_volume_mount_t *v1_volume_mount_local_var = NULL;

    // v1_volume_mount->mount_path
    mazu_cJSON *mount_path = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "mountPath");
    if (!mount_path) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(mount_path))
    {
    goto end; //String
    }

    // v1_volume_mount->mount_propagation
    mazu_cJSON *mount_propagation = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "mountPropagation");
    if (mount_propagation) { 
    if(!mazu_cJSON_IsString(mount_propagation) && !mazu_cJSON_IsNull(mount_propagation))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_volume_mount->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_volume_mount->recursive_read_only
    mazu_cJSON *recursive_read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "recursiveReadOnly");
    if (recursive_read_only) { 
    if(!mazu_cJSON_IsString(recursive_read_only) && !mazu_cJSON_IsNull(recursive_read_only))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->sub_path
    mazu_cJSON *sub_path = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "subPath");
    if (sub_path) { 
    if(!mazu_cJSON_IsString(sub_path) && !mazu_cJSON_IsNull(sub_path))
    {
    goto end; //String
    }
    }

    // v1_volume_mount->sub_path_expr
    mazu_cJSON *sub_path_expr = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_mountJSON, "subPathExpr");
    if (sub_path_expr) { 
    if(!mazu_cJSON_IsString(sub_path_expr) && !mazu_cJSON_IsNull(sub_path_expr))
    {
    goto end; //String
    }
    }


    v1_volume_mount_local_var = v1_volume_mount_create (
        strdup(mount_path->valuestring),
        mount_propagation && !mazu_cJSON_IsNull(mount_propagation) ? strdup(mount_propagation->valuestring) : NULL,
        strdup(name->valuestring),
        read_only ? read_only->valueint : 0,
        recursive_read_only && !mazu_cJSON_IsNull(recursive_read_only) ? strdup(recursive_read_only->valuestring) : NULL,
        sub_path && !mazu_cJSON_IsNull(sub_path) ? strdup(sub_path->valuestring) : NULL,
        sub_path_expr && !mazu_cJSON_IsNull(sub_path_expr) ? strdup(sub_path_expr->valuestring) : NULL
        );

    return v1_volume_mount_local_var;
end:
    return NULL;

}
