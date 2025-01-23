#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_template_spec.h"



v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_create(
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_spec_t *spec
    ) {
    v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_local_var = malloc(sizeof(v1alpha3_resource_claim_template_spec_t));
    if (!v1alpha3_resource_claim_template_spec_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_template_spec_local_var->metadata = metadata;
    v1alpha3_resource_claim_template_spec_local_var->spec = spec;

    return v1alpha3_resource_claim_template_spec_local_var;
}


void v1alpha3_resource_claim_template_spec_free(v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec) {
    if(NULL == v1alpha3_resource_claim_template_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_template_spec->metadata) {
        v1_object_meta_free(v1alpha3_resource_claim_template_spec->metadata);
        v1alpha3_resource_claim_template_spec->metadata = NULL;
    }
    if (v1alpha3_resource_claim_template_spec->spec) {
        v1alpha3_resource_claim_spec_free(v1alpha3_resource_claim_template_spec->spec);
        v1alpha3_resource_claim_template_spec->spec = NULL;
    }
    free(v1alpha3_resource_claim_template_spec);
}

mazu_cJSON *v1alpha3_resource_claim_template_spec_convertToJSON(v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha3_resource_claim_template_spec->metadata
    if(v1alpha3_resource_claim_template_spec->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_resource_claim_template_spec->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_claim_template_spec->spec
    if (!v1alpha3_resource_claim_template_spec->spec) {
        goto fail;
    }
    mazu_cJSON *spec_local_JSON = v1alpha3_resource_claim_spec_convertToJSON(v1alpha3_resource_claim_template_spec->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_parseFromJSON(mazu_cJSON *v1alpha3_resource_claim_template_specJSON){

    v1alpha3_resource_claim_template_spec_t *v1alpha3_resource_claim_template_spec_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim_template_spec->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_resource_claim_template_spec->spec
    v1alpha3_resource_claim_spec_t *spec_local_nonprim = NULL;

    // v1alpha3_resource_claim_template_spec->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_template_specJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_resource_claim_template_spec->spec
    mazu_cJSON *spec = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_template_specJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_resource_claim_spec_parseFromJSON(spec); //nonprimitive


    v1alpha3_resource_claim_template_spec_local_var = v1alpha3_resource_claim_template_spec_create (
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1alpha3_resource_claim_template_spec_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_resource_claim_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
