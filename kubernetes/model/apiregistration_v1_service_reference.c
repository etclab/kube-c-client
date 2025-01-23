#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apiregistration_v1_service_reference.h"



apiregistration_v1_service_reference_t *apiregistration_v1_service_reference_create(
    char *name,
    char *_namespace,
    int port
    ) {
    apiregistration_v1_service_reference_t *apiregistration_v1_service_reference_local_var = malloc(sizeof(apiregistration_v1_service_reference_t));
    if (!apiregistration_v1_service_reference_local_var) {
        return NULL;
    }
    apiregistration_v1_service_reference_local_var->name = name;
    apiregistration_v1_service_reference_local_var->_namespace = _namespace;
    apiregistration_v1_service_reference_local_var->port = port;

    return apiregistration_v1_service_reference_local_var;
}


void apiregistration_v1_service_reference_free(apiregistration_v1_service_reference_t *apiregistration_v1_service_reference) {
    if(NULL == apiregistration_v1_service_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (apiregistration_v1_service_reference->name) {
        free(apiregistration_v1_service_reference->name);
        apiregistration_v1_service_reference->name = NULL;
    }
    if (apiregistration_v1_service_reference->_namespace) {
        free(apiregistration_v1_service_reference->_namespace);
        apiregistration_v1_service_reference->_namespace = NULL;
    }
    free(apiregistration_v1_service_reference);
}

mazu_cJSON *apiregistration_v1_service_reference_convertToJSON(apiregistration_v1_service_reference_t *apiregistration_v1_service_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // apiregistration_v1_service_reference->name
    if(apiregistration_v1_service_reference->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", apiregistration_v1_service_reference->name) == NULL) {
    goto fail; //String
    }
    }


    // apiregistration_v1_service_reference->_namespace
    if(apiregistration_v1_service_reference->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", apiregistration_v1_service_reference->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // apiregistration_v1_service_reference->port
    if(apiregistration_v1_service_reference->port) {
    if(mazu_cJSON_AddNumberToObject(item, "port", apiregistration_v1_service_reference->port) == NULL) {
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

apiregistration_v1_service_reference_t *apiregistration_v1_service_reference_parseFromJSON(mazu_cJSON *apiregistration_v1_service_referenceJSON){

    apiregistration_v1_service_reference_t *apiregistration_v1_service_reference_local_var = NULL;

    // apiregistration_v1_service_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(apiregistration_v1_service_referenceJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // apiregistration_v1_service_reference->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(apiregistration_v1_service_referenceJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // apiregistration_v1_service_reference->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(apiregistration_v1_service_referenceJSON, "port");
    if (port) { 
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    apiregistration_v1_service_reference_local_var = apiregistration_v1_service_reference_create (
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        port ? port->valuedouble : 0
        );

    return apiregistration_v1_service_reference_local_var;
end:
    return NULL;

}
