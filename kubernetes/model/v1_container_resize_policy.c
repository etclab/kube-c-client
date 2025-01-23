#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_resize_policy.h"



v1_container_resize_policy_t *v1_container_resize_policy_create(
    char *resource_name,
    char *restart_policy
    ) {
    v1_container_resize_policy_t *v1_container_resize_policy_local_var = malloc(sizeof(v1_container_resize_policy_t));
    if (!v1_container_resize_policy_local_var) {
        return NULL;
    }
    v1_container_resize_policy_local_var->resource_name = resource_name;
    v1_container_resize_policy_local_var->restart_policy = restart_policy;

    return v1_container_resize_policy_local_var;
}


void v1_container_resize_policy_free(v1_container_resize_policy_t *v1_container_resize_policy) {
    if(NULL == v1_container_resize_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_resize_policy->resource_name) {
        free(v1_container_resize_policy->resource_name);
        v1_container_resize_policy->resource_name = NULL;
    }
    if (v1_container_resize_policy->restart_policy) {
        free(v1_container_resize_policy->restart_policy);
        v1_container_resize_policy->restart_policy = NULL;
    }
    free(v1_container_resize_policy);
}

mazu_cJSON *v1_container_resize_policy_convertToJSON(v1_container_resize_policy_t *v1_container_resize_policy) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_container_resize_policy->resource_name
    if (!v1_container_resize_policy->resource_name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "resourceName", v1_container_resize_policy->resource_name) == NULL) {
    goto fail; //String
    }


    // v1_container_resize_policy->restart_policy
    if (!v1_container_resize_policy->restart_policy) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "restartPolicy", v1_container_resize_policy->restart_policy) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_container_resize_policy_t *v1_container_resize_policy_parseFromJSON(mazu_cJSON *v1_container_resize_policyJSON){

    v1_container_resize_policy_t *v1_container_resize_policy_local_var = NULL;

    // v1_container_resize_policy->resource_name
    mazu_cJSON *resource_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_container_resize_policyJSON, "resourceName");
    if (!resource_name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(resource_name))
    {
    goto end; //String
    }

    // v1_container_resize_policy->restart_policy
    mazu_cJSON *restart_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_container_resize_policyJSON, "restartPolicy");
    if (!restart_policy) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(restart_policy))
    {
    goto end; //String
    }


    v1_container_resize_policy_local_var = v1_container_resize_policy_create (
        strdup(resource_name->valuestring),
        strdup(restart_policy->valuestring)
        );

    return v1_container_resize_policy_local_var;
end:
    return NULL;

}
