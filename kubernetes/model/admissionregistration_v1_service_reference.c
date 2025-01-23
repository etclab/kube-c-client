#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "admissionregistration_v1_service_reference.h"



admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_create(
    char *name,
    char *_namespace,
    char *path,
    int port
    ) {
    admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_local_var = malloc(sizeof(admissionregistration_v1_service_reference_t));
    if (!admissionregistration_v1_service_reference_local_var) {
        return NULL;
    }
    admissionregistration_v1_service_reference_local_var->name = name;
    admissionregistration_v1_service_reference_local_var->_namespace = _namespace;
    admissionregistration_v1_service_reference_local_var->path = path;
    admissionregistration_v1_service_reference_local_var->port = port;

    return admissionregistration_v1_service_reference_local_var;
}


void admissionregistration_v1_service_reference_free(admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference) {
    if(NULL == admissionregistration_v1_service_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (admissionregistration_v1_service_reference->name) {
        free(admissionregistration_v1_service_reference->name);
        admissionregistration_v1_service_reference->name = NULL;
    }
    if (admissionregistration_v1_service_reference->_namespace) {
        free(admissionregistration_v1_service_reference->_namespace);
        admissionregistration_v1_service_reference->_namespace = NULL;
    }
    if (admissionregistration_v1_service_reference->path) {
        free(admissionregistration_v1_service_reference->path);
        admissionregistration_v1_service_reference->path = NULL;
    }
    free(admissionregistration_v1_service_reference);
}

mazu_cJSON *admissionregistration_v1_service_reference_convertToJSON(admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // admissionregistration_v1_service_reference->name
    if (!admissionregistration_v1_service_reference->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", admissionregistration_v1_service_reference->name) == NULL) {
    goto fail; //String
    }


    // admissionregistration_v1_service_reference->_namespace
    if (!admissionregistration_v1_service_reference->_namespace) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "namespace", admissionregistration_v1_service_reference->_namespace) == NULL) {
    goto fail; //String
    }


    // admissionregistration_v1_service_reference->path
    if(admissionregistration_v1_service_reference->path) {
    if(mazu_cJSON_AddStringToObject(item, "path", admissionregistration_v1_service_reference->path) == NULL) {
    goto fail; //String
    }
    }


    // admissionregistration_v1_service_reference->port
    if(admissionregistration_v1_service_reference->port) {
    if(mazu_cJSON_AddNumberToObject(item, "port", admissionregistration_v1_service_reference->port) == NULL) {
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

admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_parseFromJSON(mazu_cJSON *admissionregistration_v1_service_referenceJSON){

    admissionregistration_v1_service_reference_t *admissionregistration_v1_service_reference_local_var = NULL;

    // admissionregistration_v1_service_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // admissionregistration_v1_service_reference->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "namespace");
    if (!_namespace) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(_namespace))
    {
    goto end; //String
    }

    // admissionregistration_v1_service_reference->path
    mazu_cJSON *path = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "path");
    if (path) { 
    if(!mazu_cJSON_IsString(path) && !mazu_cJSON_IsNull(path))
    {
    goto end; //String
    }
    }

    // admissionregistration_v1_service_reference->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_service_referenceJSON, "port");
    if (port) { 
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    admissionregistration_v1_service_reference_local_var = admissionregistration_v1_service_reference_create (
        strdup(name->valuestring),
        strdup(_namespace->valuestring),
        path && !mazu_cJSON_IsNull(path) ? strdup(path->valuestring) : NULL,
        port ? port->valuedouble : 0
        );

    return admissionregistration_v1_service_reference_local_var;
end:
    return NULL;

}
