#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_client_ip_config.h"



v1_client_ip_config_t *v1_client_ip_config_create(
    int timeout_seconds
    ) {
    v1_client_ip_config_t *v1_client_ip_config_local_var = malloc(sizeof(v1_client_ip_config_t));
    if (!v1_client_ip_config_local_var) {
        return NULL;
    }
    v1_client_ip_config_local_var->timeout_seconds = timeout_seconds;

    return v1_client_ip_config_local_var;
}


void v1_client_ip_config_free(v1_client_ip_config_t *v1_client_ip_config) {
    if(NULL == v1_client_ip_config){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_client_ip_config);
}

mazu_cJSON *v1_client_ip_config_convertToJSON(v1_client_ip_config_t *v1_client_ip_config) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_client_ip_config->timeout_seconds
    if(v1_client_ip_config->timeout_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "timeoutSeconds", v1_client_ip_config->timeout_seconds) == NULL) {
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

v1_client_ip_config_t *v1_client_ip_config_parseFromJSON(mazu_cJSON *v1_client_ip_configJSON){

    v1_client_ip_config_t *v1_client_ip_config_local_var = NULL;

    // v1_client_ip_config->timeout_seconds
    mazu_cJSON *timeout_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_client_ip_configJSON, "timeoutSeconds");
    if (timeout_seconds) { 
    if(!mazu_cJSON_IsNumber(timeout_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_client_ip_config_local_var = v1_client_ip_config_create (
        timeout_seconds ? timeout_seconds->valuedouble : 0
        );

    return v1_client_ip_config_local_var;
end:
    return NULL;

}
