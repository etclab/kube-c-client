#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "admissionregistration_v1_webhook_client_config.h"



admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_create(
    char *ca_bundle,
    admissionregistration_v1_service_reference_t *service,
    char *url
    ) {
    admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_local_var = malloc(sizeof(admissionregistration_v1_webhook_client_config_t));
    if (!admissionregistration_v1_webhook_client_config_local_var) {
        return NULL;
    }
    admissionregistration_v1_webhook_client_config_local_var->ca_bundle = ca_bundle;
    admissionregistration_v1_webhook_client_config_local_var->service = service;
    admissionregistration_v1_webhook_client_config_local_var->url = url;

    return admissionregistration_v1_webhook_client_config_local_var;
}


void admissionregistration_v1_webhook_client_config_free(admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config) {
    if(NULL == admissionregistration_v1_webhook_client_config){
        return ;
    }
    listEntry_t *listEntry;
    if (admissionregistration_v1_webhook_client_config->ca_bundle) {
        free(admissionregistration_v1_webhook_client_config->ca_bundle);
        admissionregistration_v1_webhook_client_config->ca_bundle = NULL;
    }
    if (admissionregistration_v1_webhook_client_config->service) {
        admissionregistration_v1_service_reference_free(admissionregistration_v1_webhook_client_config->service);
        admissionregistration_v1_webhook_client_config->service = NULL;
    }
    if (admissionregistration_v1_webhook_client_config->url) {
        free(admissionregistration_v1_webhook_client_config->url);
        admissionregistration_v1_webhook_client_config->url = NULL;
    }
    free(admissionregistration_v1_webhook_client_config);
}

mazu_cJSON *admissionregistration_v1_webhook_client_config_convertToJSON(admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // admissionregistration_v1_webhook_client_config->ca_bundle
    if(admissionregistration_v1_webhook_client_config->ca_bundle) {
    if(mazu_cJSON_AddStringToObject(item, "caBundle", admissionregistration_v1_webhook_client_config->ca_bundle) == NULL) {
    goto fail; //ByteArray
    }
    }


    // admissionregistration_v1_webhook_client_config->service
    if(admissionregistration_v1_webhook_client_config->service) {
    mazu_cJSON *service_local_JSON = admissionregistration_v1_service_reference_convertToJSON(admissionregistration_v1_webhook_client_config->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // admissionregistration_v1_webhook_client_config->url
    if(admissionregistration_v1_webhook_client_config->url) {
    if(mazu_cJSON_AddStringToObject(item, "url", admissionregistration_v1_webhook_client_config->url) == NULL) {
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

admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_parseFromJSON(mazu_cJSON *admissionregistration_v1_webhook_client_configJSON){

    admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_local_var = NULL;

    // define the local variable for admissionregistration_v1_webhook_client_config->service
    admissionregistration_v1_service_reference_t *service_local_nonprim = NULL;

    // admissionregistration_v1_webhook_client_config->ca_bundle
    mazu_cJSON *ca_bundle = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_webhook_client_configJSON, "caBundle");
    if (ca_bundle) { 
    if(!mazu_cJSON_IsString(ca_bundle))
    {
    goto end; //ByteArray
    }
    }

    // admissionregistration_v1_webhook_client_config->service
    mazu_cJSON *service = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_webhook_client_configJSON, "service");
    if (service) { 
    service_local_nonprim = admissionregistration_v1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // admissionregistration_v1_webhook_client_config->url
    mazu_cJSON *url = mazu_cJSON_GetObjectItemCaseSensitive(admissionregistration_v1_webhook_client_configJSON, "url");
    if (url) { 
    if(!mazu_cJSON_IsString(url) && !mazu_cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    admissionregistration_v1_webhook_client_config_local_var = admissionregistration_v1_webhook_client_config_create (
        ca_bundle ? strdup(ca_bundle->valuestring) : NULL,
        service ? service_local_nonprim : NULL,
        url && !mazu_cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return admissionregistration_v1_webhook_client_config_local_var;
end:
    if (service_local_nonprim) {
        admissionregistration_v1_service_reference_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    return NULL;

}
