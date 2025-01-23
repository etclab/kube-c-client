#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_env_from_source.h"



v1_env_from_source_t *v1_env_from_source_create(
    v1_config_map_env_source_t *config_map_ref,
    char *prefix,
    v1_secret_env_source_t *secret_ref
    ) {
    v1_env_from_source_t *v1_env_from_source_local_var = malloc(sizeof(v1_env_from_source_t));
    if (!v1_env_from_source_local_var) {
        return NULL;
    }
    v1_env_from_source_local_var->config_map_ref = config_map_ref;
    v1_env_from_source_local_var->prefix = prefix;
    v1_env_from_source_local_var->secret_ref = secret_ref;

    return v1_env_from_source_local_var;
}


void v1_env_from_source_free(v1_env_from_source_t *v1_env_from_source) {
    if(NULL == v1_env_from_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_env_from_source->config_map_ref) {
        v1_config_map_env_source_free(v1_env_from_source->config_map_ref);
        v1_env_from_source->config_map_ref = NULL;
    }
    if (v1_env_from_source->prefix) {
        free(v1_env_from_source->prefix);
        v1_env_from_source->prefix = NULL;
    }
    if (v1_env_from_source->secret_ref) {
        v1_secret_env_source_free(v1_env_from_source->secret_ref);
        v1_env_from_source->secret_ref = NULL;
    }
    free(v1_env_from_source);
}

mazu_cJSON *v1_env_from_source_convertToJSON(v1_env_from_source_t *v1_env_from_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_env_from_source->config_map_ref
    if(v1_env_from_source->config_map_ref) {
    mazu_cJSON *config_map_ref_local_JSON = v1_config_map_env_source_convertToJSON(v1_env_from_source->config_map_ref);
    if(config_map_ref_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "configMapRef", config_map_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_env_from_source->prefix
    if(v1_env_from_source->prefix) {
    if(mazu_cJSON_AddStringToObject(item, "prefix", v1_env_from_source->prefix) == NULL) {
    goto fail; //String
    }
    }


    // v1_env_from_source->secret_ref
    if(v1_env_from_source->secret_ref) {
    mazu_cJSON *secret_ref_local_JSON = v1_secret_env_source_convertToJSON(v1_env_from_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
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

v1_env_from_source_t *v1_env_from_source_parseFromJSON(mazu_cJSON *v1_env_from_sourceJSON){

    v1_env_from_source_t *v1_env_from_source_local_var = NULL;

    // define the local variable for v1_env_from_source->config_map_ref
    v1_config_map_env_source_t *config_map_ref_local_nonprim = NULL;

    // define the local variable for v1_env_from_source->secret_ref
    v1_secret_env_source_t *secret_ref_local_nonprim = NULL;

    // v1_env_from_source->config_map_ref
    mazu_cJSON *config_map_ref = mazu_cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "configMapRef");
    if (config_map_ref) { 
    config_map_ref_local_nonprim = v1_config_map_env_source_parseFromJSON(config_map_ref); //nonprimitive
    }

    // v1_env_from_source->prefix
    mazu_cJSON *prefix = mazu_cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "prefix");
    if (prefix) { 
    if(!mazu_cJSON_IsString(prefix) && !mazu_cJSON_IsNull(prefix))
    {
    goto end; //String
    }
    }

    // v1_env_from_source->secret_ref
    mazu_cJSON *secret_ref = mazu_cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "secretRef");
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_secret_env_source_parseFromJSON(secret_ref); //nonprimitive
    }


    v1_env_from_source_local_var = v1_env_from_source_create (
        config_map_ref ? config_map_ref_local_nonprim : NULL,
        prefix && !mazu_cJSON_IsNull(prefix) ? strdup(prefix->valuestring) : NULL,
        secret_ref ? secret_ref_local_nonprim : NULL
        );

    return v1_env_from_source_local_var;
end:
    if (config_map_ref_local_nonprim) {
        v1_config_map_env_source_free(config_map_ref_local_nonprim);
        config_map_ref_local_nonprim = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_env_source_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
