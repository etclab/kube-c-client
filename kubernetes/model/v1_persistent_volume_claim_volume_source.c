#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_volume_source.h"



v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_create(
    char *claim_name,
    int read_only
    ) {
    v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_local_var = malloc(sizeof(v1_persistent_volume_claim_volume_source_t));
    if (!v1_persistent_volume_claim_volume_source_local_var) {
        return NULL;
    }
    v1_persistent_volume_claim_volume_source_local_var->claim_name = claim_name;
    v1_persistent_volume_claim_volume_source_local_var->read_only = read_only;

    return v1_persistent_volume_claim_volume_source_local_var;
}


void v1_persistent_volume_claim_volume_source_free(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source) {
    if(NULL == v1_persistent_volume_claim_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_claim_volume_source->claim_name) {
        free(v1_persistent_volume_claim_volume_source->claim_name);
        v1_persistent_volume_claim_volume_source->claim_name = NULL;
    }
    free(v1_persistent_volume_claim_volume_source);
}

mazu_cJSON *v1_persistent_volume_claim_volume_source_convertToJSON(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_persistent_volume_claim_volume_source->claim_name
    if (!v1_persistent_volume_claim_volume_source->claim_name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "claimName", v1_persistent_volume_claim_volume_source->claim_name) == NULL) {
    goto fail; //String
    }


    // v1_persistent_volume_claim_volume_source->read_only
    if(v1_persistent_volume_claim_volume_source->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_persistent_volume_claim_volume_source->read_only) == NULL) {
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

v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_parseFromJSON(mazu_cJSON *v1_persistent_volume_claim_volume_sourceJSON){

    v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_local_var = NULL;

    // v1_persistent_volume_claim_volume_source->claim_name
    mazu_cJSON *claim_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_volume_sourceJSON, "claimName");
    if (!claim_name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(claim_name))
    {
    goto end; //String
    }

    // v1_persistent_volume_claim_volume_source->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    v1_persistent_volume_claim_volume_source_local_var = v1_persistent_volume_claim_volume_source_create (
        strdup(claim_name->valuestring),
        read_only ? read_only->valueint : 0
        );

    return v1_persistent_volume_claim_volume_source_local_var;
end:
    return NULL;

}
