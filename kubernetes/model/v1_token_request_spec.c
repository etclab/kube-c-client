#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_spec.h"



v1_token_request_spec_t *v1_token_request_spec_create(
    list_t *audiences,
    v1_bound_object_reference_t *bound_object_ref,
    long expiration_seconds
    ) {
    v1_token_request_spec_t *v1_token_request_spec_local_var = malloc(sizeof(v1_token_request_spec_t));
    if (!v1_token_request_spec_local_var) {
        return NULL;
    }
    v1_token_request_spec_local_var->audiences = audiences;
    v1_token_request_spec_local_var->bound_object_ref = bound_object_ref;
    v1_token_request_spec_local_var->expiration_seconds = expiration_seconds;

    return v1_token_request_spec_local_var;
}


void v1_token_request_spec_free(v1_token_request_spec_t *v1_token_request_spec) {
    if(NULL == v1_token_request_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_request_spec->audiences) {
        list_ForEach(listEntry, v1_token_request_spec->audiences) {
            free(listEntry->data);
        }
        list_freeList(v1_token_request_spec->audiences);
        v1_token_request_spec->audiences = NULL;
    }
    if (v1_token_request_spec->bound_object_ref) {
        v1_bound_object_reference_free(v1_token_request_spec->bound_object_ref);
        v1_token_request_spec->bound_object_ref = NULL;
    }
    free(v1_token_request_spec);
}

mazu_cJSON *v1_token_request_spec_convertToJSON(v1_token_request_spec_t *v1_token_request_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_token_request_spec->audiences
    if (!v1_token_request_spec->audiences) {
        goto fail;
    }
    mazu_cJSON *audiences = mazu_cJSON_AddArrayToObject(item, "audiences");
    if(audiences == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_request_spec->audiences) {
    if(mazu_cJSON_AddStringToObject(audiences, "", (char*)audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_token_request_spec->bound_object_ref
    if(v1_token_request_spec->bound_object_ref) {
    mazu_cJSON *bound_object_ref_local_JSON = v1_bound_object_reference_convertToJSON(v1_token_request_spec->bound_object_ref);
    if(bound_object_ref_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "boundObjectRef", bound_object_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_token_request_spec->expiration_seconds
    if(v1_token_request_spec->expiration_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "expirationSeconds", v1_token_request_spec->expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_token_request_spec_t *v1_token_request_spec_parseFromJSON(mazu_cJSON *v1_token_request_specJSON){

    v1_token_request_spec_t *v1_token_request_spec_local_var = NULL;

    // define the local list for v1_token_request_spec->audiences
    list_t *audiencesList = NULL;

    // define the local variable for v1_token_request_spec->bound_object_ref
    v1_bound_object_reference_t *bound_object_ref_local_nonprim = NULL;

    // v1_token_request_spec->audiences
    mazu_cJSON *audiences = mazu_cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "audiences");
    if (!audiences) {
        goto end;
    }

    
    mazu_cJSON *audiences_local = NULL;
    if(!mazu_cJSON_IsArray(audiences)) {
        goto end;//primitive container
    }
    audiencesList = list_createList();

    mazu_cJSON_ArrayForEach(audiences_local, audiences)
    {
        if(!mazu_cJSON_IsString(audiences_local))
        {
            goto end;
        }
        list_addElement(audiencesList , strdup(audiences_local->valuestring));
    }

    // v1_token_request_spec->bound_object_ref
    mazu_cJSON *bound_object_ref = mazu_cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "boundObjectRef");
    if (bound_object_ref) { 
    bound_object_ref_local_nonprim = v1_bound_object_reference_parseFromJSON(bound_object_ref); //nonprimitive
    }

    // v1_token_request_spec->expiration_seconds
    mazu_cJSON *expiration_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "expirationSeconds");
    if (expiration_seconds) { 
    if(!mazu_cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_token_request_spec_local_var = v1_token_request_spec_create (
        audiencesList,
        bound_object_ref ? bound_object_ref_local_nonprim : NULL,
        expiration_seconds ? expiration_seconds->valuedouble : 0
        );

    return v1_token_request_spec_local_var;
end:
    if (audiencesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, audiencesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(audiencesList);
        audiencesList = NULL;
    }
    if (bound_object_ref_local_nonprim) {
        v1_bound_object_reference_free(bound_object_ref_local_nonprim);
        bound_object_ref_local_nonprim = NULL;
    }
    return NULL;

}
