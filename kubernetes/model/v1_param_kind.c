#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_param_kind.h"



v1_param_kind_t *v1_param_kind_create(
    char *api_version,
    char *kind
    ) {
    v1_param_kind_t *v1_param_kind_local_var = malloc(sizeof(v1_param_kind_t));
    if (!v1_param_kind_local_var) {
        return NULL;
    }
    v1_param_kind_local_var->api_version = api_version;
    v1_param_kind_local_var->kind = kind;

    return v1_param_kind_local_var;
}


void v1_param_kind_free(v1_param_kind_t *v1_param_kind) {
    if(NULL == v1_param_kind){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_param_kind->api_version) {
        free(v1_param_kind->api_version);
        v1_param_kind->api_version = NULL;
    }
    if (v1_param_kind->kind) {
        free(v1_param_kind->kind);
        v1_param_kind->kind = NULL;
    }
    free(v1_param_kind);
}

mazu_cJSON *v1_param_kind_convertToJSON(v1_param_kind_t *v1_param_kind) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_param_kind->api_version
    if(v1_param_kind->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_param_kind->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_param_kind->kind
    if(v1_param_kind->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_param_kind->kind) == NULL) {
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

v1_param_kind_t *v1_param_kind_parseFromJSON(mazu_cJSON *v1_param_kindJSON){

    v1_param_kind_t *v1_param_kind_local_var = NULL;

    // v1_param_kind->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_param_kindJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_param_kind->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_param_kindJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }


    v1_param_kind_local_var = v1_param_kind_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL
        );

    return v1_param_kind_local_var;
end:
    return NULL;

}
