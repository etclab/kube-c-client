#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_runtime_handler_features.h"



v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_create(
    int recursive_read_only_mounts,
    int user_namespaces
    ) {
    v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_local_var = malloc(sizeof(v1_node_runtime_handler_features_t));
    if (!v1_node_runtime_handler_features_local_var) {
        return NULL;
    }
    v1_node_runtime_handler_features_local_var->recursive_read_only_mounts = recursive_read_only_mounts;
    v1_node_runtime_handler_features_local_var->user_namespaces = user_namespaces;

    return v1_node_runtime_handler_features_local_var;
}


void v1_node_runtime_handler_features_free(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features) {
    if(NULL == v1_node_runtime_handler_features){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_node_runtime_handler_features);
}

mazu_cJSON *v1_node_runtime_handler_features_convertToJSON(v1_node_runtime_handler_features_t *v1_node_runtime_handler_features) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_node_runtime_handler_features->recursive_read_only_mounts
    if(v1_node_runtime_handler_features->recursive_read_only_mounts) {
    if(mazu_cJSON_AddBoolToObject(item, "recursiveReadOnlyMounts", v1_node_runtime_handler_features->recursive_read_only_mounts) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_node_runtime_handler_features->user_namespaces
    if(v1_node_runtime_handler_features->user_namespaces) {
    if(mazu_cJSON_AddBoolToObject(item, "userNamespaces", v1_node_runtime_handler_features->user_namespaces) == NULL) {
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

v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_parseFromJSON(mazu_cJSON *v1_node_runtime_handler_featuresJSON){

    v1_node_runtime_handler_features_t *v1_node_runtime_handler_features_local_var = NULL;

    // v1_node_runtime_handler_features->recursive_read_only_mounts
    mazu_cJSON *recursive_read_only_mounts = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handler_featuresJSON, "recursiveReadOnlyMounts");
    if (recursive_read_only_mounts) { 
    if(!mazu_cJSON_IsBool(recursive_read_only_mounts))
    {
    goto end; //Bool
    }
    }

    // v1_node_runtime_handler_features->user_namespaces
    mazu_cJSON *user_namespaces = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handler_featuresJSON, "userNamespaces");
    if (user_namespaces) { 
    if(!mazu_cJSON_IsBool(user_namespaces))
    {
    goto end; //Bool
    }
    }


    v1_node_runtime_handler_features_local_var = v1_node_runtime_handler_features_create (
        recursive_read_only_mounts ? recursive_read_only_mounts->valueint : 0,
        user_namespaces ? user_namespaces->valueint : 0
        );

    return v1_node_runtime_handler_features_local_var;
end:
    return NULL;

}
