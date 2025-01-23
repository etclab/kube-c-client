#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_allocation_configuration.h"



v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration_create(
    v1alpha3_opaque_device_configuration_t *opaque,
    list_t *requests,
    char *source
    ) {
    v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration_local_var = malloc(sizeof(v1alpha3_device_allocation_configuration_t));
    if (!v1alpha3_device_allocation_configuration_local_var) {
        return NULL;
    }
    v1alpha3_device_allocation_configuration_local_var->opaque = opaque;
    v1alpha3_device_allocation_configuration_local_var->requests = requests;
    v1alpha3_device_allocation_configuration_local_var->source = source;

    return v1alpha3_device_allocation_configuration_local_var;
}


void v1alpha3_device_allocation_configuration_free(v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration) {
    if(NULL == v1alpha3_device_allocation_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_allocation_configuration->opaque) {
        v1alpha3_opaque_device_configuration_free(v1alpha3_device_allocation_configuration->opaque);
        v1alpha3_device_allocation_configuration->opaque = NULL;
    }
    if (v1alpha3_device_allocation_configuration->requests) {
        list_ForEach(listEntry, v1alpha3_device_allocation_configuration->requests) {
            free(listEntry->data);
        }
        list_freeList(v1alpha3_device_allocation_configuration->requests);
        v1alpha3_device_allocation_configuration->requests = NULL;
    }
    if (v1alpha3_device_allocation_configuration->source) {
        free(v1alpha3_device_allocation_configuration->source);
        v1alpha3_device_allocation_configuration->source = NULL;
    }
    free(v1alpha3_device_allocation_configuration);
}

mazu_cJSON *v1alpha3_device_allocation_configuration_convertToJSON(v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha3_device_allocation_configuration->opaque
    if(v1alpha3_device_allocation_configuration->opaque) {
    mazu_cJSON *opaque_local_JSON = v1alpha3_opaque_device_configuration_convertToJSON(v1alpha3_device_allocation_configuration->opaque);
    if(opaque_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "opaque", opaque_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_device_allocation_configuration->requests
    if(v1alpha3_device_allocation_configuration->requests) {
    mazu_cJSON *requests = mazu_cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requestsListEntry;
    list_ForEach(requestsListEntry, v1alpha3_device_allocation_configuration->requests) {
    if(mazu_cJSON_AddStringToObject(requests, "", (char*)requestsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1alpha3_device_allocation_configuration->source
    if (!v1alpha3_device_allocation_configuration->source) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "source", v1alpha3_device_allocation_configuration->source) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration_parseFromJSON(mazu_cJSON *v1alpha3_device_allocation_configurationJSON){

    v1alpha3_device_allocation_configuration_t *v1alpha3_device_allocation_configuration_local_var = NULL;

    // define the local variable for v1alpha3_device_allocation_configuration->opaque
    v1alpha3_opaque_device_configuration_t *opaque_local_nonprim = NULL;

    // define the local list for v1alpha3_device_allocation_configuration->requests
    list_t *requestsList = NULL;

    // v1alpha3_device_allocation_configuration->opaque
    mazu_cJSON *opaque = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_allocation_configurationJSON, "opaque");
    if (opaque) { 
    opaque_local_nonprim = v1alpha3_opaque_device_configuration_parseFromJSON(opaque); //nonprimitive
    }

    // v1alpha3_device_allocation_configuration->requests
    mazu_cJSON *requests = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_allocation_configurationJSON, "requests");
    if (requests) { 
    mazu_cJSON *requests_local = NULL;
    if(!mazu_cJSON_IsArray(requests)) {
        goto end;//primitive container
    }
    requestsList = list_createList();

    mazu_cJSON_ArrayForEach(requests_local, requests)
    {
        if(!mazu_cJSON_IsString(requests_local))
        {
            goto end;
        }
        list_addElement(requestsList , strdup(requests_local->valuestring));
    }
    }

    // v1alpha3_device_allocation_configuration->source
    mazu_cJSON *source = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_allocation_configurationJSON, "source");
    if (!source) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(source))
    {
    goto end; //String
    }


    v1alpha3_device_allocation_configuration_local_var = v1alpha3_device_allocation_configuration_create (
        opaque ? opaque_local_nonprim : NULL,
        requests ? requestsList : NULL,
        strdup(source->valuestring)
        );

    return v1alpha3_device_allocation_configuration_local_var;
end:
    if (opaque_local_nonprim) {
        v1alpha3_opaque_device_configuration_free(opaque_local_nonprim);
        opaque_local_nonprim = NULL;
    }
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
