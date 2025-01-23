#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_cluster_trust_bundle_spec.h"



v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_create(
    char *signer_name,
    char *trust_bundle
    ) {
    v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_local_var = malloc(sizeof(v1alpha1_cluster_trust_bundle_spec_t));
    if (!v1alpha1_cluster_trust_bundle_spec_local_var) {
        return NULL;
    }
    v1alpha1_cluster_trust_bundle_spec_local_var->signer_name = signer_name;
    v1alpha1_cluster_trust_bundle_spec_local_var->trust_bundle = trust_bundle;

    return v1alpha1_cluster_trust_bundle_spec_local_var;
}


void v1alpha1_cluster_trust_bundle_spec_free(v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec) {
    if(NULL == v1alpha1_cluster_trust_bundle_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_cluster_trust_bundle_spec->signer_name) {
        free(v1alpha1_cluster_trust_bundle_spec->signer_name);
        v1alpha1_cluster_trust_bundle_spec->signer_name = NULL;
    }
    if (v1alpha1_cluster_trust_bundle_spec->trust_bundle) {
        free(v1alpha1_cluster_trust_bundle_spec->trust_bundle);
        v1alpha1_cluster_trust_bundle_spec->trust_bundle = NULL;
    }
    free(v1alpha1_cluster_trust_bundle_spec);
}

mazu_cJSON *v1alpha1_cluster_trust_bundle_spec_convertToJSON(v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_cluster_trust_bundle_spec->signer_name
    if(v1alpha1_cluster_trust_bundle_spec->signer_name) {
    if(mazu_cJSON_AddStringToObject(item, "signerName", v1alpha1_cluster_trust_bundle_spec->signer_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_cluster_trust_bundle_spec->trust_bundle
    if (!v1alpha1_cluster_trust_bundle_spec->trust_bundle) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "trustBundle", v1alpha1_cluster_trust_bundle_spec->trust_bundle) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_parseFromJSON(mazu_cJSON *v1alpha1_cluster_trust_bundle_specJSON){

    v1alpha1_cluster_trust_bundle_spec_t *v1alpha1_cluster_trust_bundle_spec_local_var = NULL;

    // v1alpha1_cluster_trust_bundle_spec->signer_name
    mazu_cJSON *signer_name = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_trust_bundle_specJSON, "signerName");
    if (signer_name) { 
    if(!mazu_cJSON_IsString(signer_name) && !mazu_cJSON_IsNull(signer_name))
    {
    goto end; //String
    }
    }

    // v1alpha1_cluster_trust_bundle_spec->trust_bundle
    mazu_cJSON *trust_bundle = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_trust_bundle_specJSON, "trustBundle");
    if (!trust_bundle) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(trust_bundle))
    {
    goto end; //String
    }


    v1alpha1_cluster_trust_bundle_spec_local_var = v1alpha1_cluster_trust_bundle_spec_create (
        signer_name && !mazu_cJSON_IsNull(signer_name) ? strdup(signer_name->valuestring) : NULL,
        strdup(trust_bundle->valuestring)
        );

    return v1alpha1_cluster_trust_bundle_spec_local_var;
end:
    return NULL;

}
