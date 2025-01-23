#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_preconditions.h"



v1_preconditions_t *v1_preconditions_create(
    char *resource_version,
    char *uid
    ) {
    v1_preconditions_t *v1_preconditions_local_var = malloc(sizeof(v1_preconditions_t));
    if (!v1_preconditions_local_var) {
        return NULL;
    }
    v1_preconditions_local_var->resource_version = resource_version;
    v1_preconditions_local_var->uid = uid;

    return v1_preconditions_local_var;
}


void v1_preconditions_free(v1_preconditions_t *v1_preconditions) {
    if(NULL == v1_preconditions){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_preconditions->resource_version) {
        free(v1_preconditions->resource_version);
        v1_preconditions->resource_version = NULL;
    }
    if (v1_preconditions->uid) {
        free(v1_preconditions->uid);
        v1_preconditions->uid = NULL;
    }
    free(v1_preconditions);
}

mazu_cJSON *v1_preconditions_convertToJSON(v1_preconditions_t *v1_preconditions) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_preconditions->resource_version
    if(v1_preconditions->resource_version) {
    if(mazu_cJSON_AddStringToObject(item, "resourceVersion", v1_preconditions->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_preconditions->uid
    if(v1_preconditions->uid) {
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_preconditions->uid) == NULL) {
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

v1_preconditions_t *v1_preconditions_parseFromJSON(mazu_cJSON *v1_preconditionsJSON){

    v1_preconditions_t *v1_preconditions_local_var = NULL;

    // v1_preconditions->resource_version
    mazu_cJSON *resource_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "resourceVersion");
    if (resource_version) { 
    if(!mazu_cJSON_IsString(resource_version) && !mazu_cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_preconditions->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_preconditionsJSON, "uid");
    if (uid) { 
    if(!mazu_cJSON_IsString(uid) && !mazu_cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1_preconditions_local_var = v1_preconditions_create (
        resource_version && !mazu_cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        uid && !mazu_cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1_preconditions_local_var;
end:
    return NULL;

}
