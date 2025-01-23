#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_claim.h"



v1_resource_claim_t *v1_resource_claim_create(
    char *name,
    char *request
    ) {
    v1_resource_claim_t *v1_resource_claim_local_var = malloc(sizeof(v1_resource_claim_t));
    if (!v1_resource_claim_local_var) {
        return NULL;
    }
    v1_resource_claim_local_var->name = name;
    v1_resource_claim_local_var->request = request;

    return v1_resource_claim_local_var;
}


void v1_resource_claim_free(v1_resource_claim_t *v1_resource_claim) {
    if(NULL == v1_resource_claim){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_claim->name) {
        free(v1_resource_claim->name);
        v1_resource_claim->name = NULL;
    }
    if (v1_resource_claim->request) {
        free(v1_resource_claim->request);
        v1_resource_claim->request = NULL;
    }
    free(v1_resource_claim);
}

mazu_cJSON *v1_resource_claim_convertToJSON(v1_resource_claim_t *v1_resource_claim) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_resource_claim->name
    if (!v1_resource_claim->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_resource_claim->name) == NULL) {
    goto fail; //String
    }


    // v1_resource_claim->request
    if(v1_resource_claim->request) {
    if(mazu_cJSON_AddStringToObject(item, "request", v1_resource_claim->request) == NULL) {
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

v1_resource_claim_t *v1_resource_claim_parseFromJSON(mazu_cJSON *v1_resource_claimJSON){

    v1_resource_claim_t *v1_resource_claim_local_var = NULL;

    // v1_resource_claim->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_claimJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_resource_claim->request
    mazu_cJSON *request = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_claimJSON, "request");
    if (request) { 
    if(!mazu_cJSON_IsString(request) && !mazu_cJSON_IsNull(request))
    {
    goto end; //String
    }
    }


    v1_resource_claim_local_var = v1_resource_claim_create (
        strdup(name->valuestring),
        request && !mazu_cJSON_IsNull(request) ? strdup(request->valuestring) : NULL
        );

    return v1_resource_claim_local_var;
end:
    return NULL;

}
