#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_runtime_handler.h"



v1_node_runtime_handler_t *v1_node_runtime_handler_create(
    v1_node_runtime_handler_features_t *features,
    char *name
    ) {
    v1_node_runtime_handler_t *v1_node_runtime_handler_local_var = malloc(sizeof(v1_node_runtime_handler_t));
    if (!v1_node_runtime_handler_local_var) {
        return NULL;
    }
    v1_node_runtime_handler_local_var->features = features;
    v1_node_runtime_handler_local_var->name = name;

    return v1_node_runtime_handler_local_var;
}


void v1_node_runtime_handler_free(v1_node_runtime_handler_t *v1_node_runtime_handler) {
    if(NULL == v1_node_runtime_handler){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_runtime_handler->features) {
        v1_node_runtime_handler_features_free(v1_node_runtime_handler->features);
        v1_node_runtime_handler->features = NULL;
    }
    if (v1_node_runtime_handler->name) {
        free(v1_node_runtime_handler->name);
        v1_node_runtime_handler->name = NULL;
    }
    free(v1_node_runtime_handler);
}

mazu_cJSON *v1_node_runtime_handler_convertToJSON(v1_node_runtime_handler_t *v1_node_runtime_handler) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_node_runtime_handler->features
    if(v1_node_runtime_handler->features) {
    mazu_cJSON *features_local_JSON = v1_node_runtime_handler_features_convertToJSON(v1_node_runtime_handler->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_runtime_handler->name
    if(v1_node_runtime_handler->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_node_runtime_handler->name) == NULL) {
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

v1_node_runtime_handler_t *v1_node_runtime_handler_parseFromJSON(mazu_cJSON *v1_node_runtime_handlerJSON){

    v1_node_runtime_handler_t *v1_node_runtime_handler_local_var = NULL;

    // define the local variable for v1_node_runtime_handler->features
    v1_node_runtime_handler_features_t *features_local_nonprim = NULL;

    // v1_node_runtime_handler->features
    mazu_cJSON *features = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handlerJSON, "features");
    if (features) { 
    features_local_nonprim = v1_node_runtime_handler_features_parseFromJSON(features); //nonprimitive
    }

    // v1_node_runtime_handler->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_runtime_handlerJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    v1_node_runtime_handler_local_var = v1_node_runtime_handler_create (
        features ? features_local_nonprim : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return v1_node_runtime_handler_local_var;
end:
    if (features_local_nonprim) {
        v1_node_runtime_handler_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    return NULL;

}
