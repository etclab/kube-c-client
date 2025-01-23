#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_port_status.h"



v1_ingress_port_status_t *v1_ingress_port_status_create(
    char *error,
    int port,
    char *protocol
    ) {
    v1_ingress_port_status_t *v1_ingress_port_status_local_var = malloc(sizeof(v1_ingress_port_status_t));
    if (!v1_ingress_port_status_local_var) {
        return NULL;
    }
    v1_ingress_port_status_local_var->error = error;
    v1_ingress_port_status_local_var->port = port;
    v1_ingress_port_status_local_var->protocol = protocol;

    return v1_ingress_port_status_local_var;
}


void v1_ingress_port_status_free(v1_ingress_port_status_t *v1_ingress_port_status) {
    if(NULL == v1_ingress_port_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_port_status->error) {
        free(v1_ingress_port_status->error);
        v1_ingress_port_status->error = NULL;
    }
    if (v1_ingress_port_status->protocol) {
        free(v1_ingress_port_status->protocol);
        v1_ingress_port_status->protocol = NULL;
    }
    free(v1_ingress_port_status);
}

mazu_cJSON *v1_ingress_port_status_convertToJSON(v1_ingress_port_status_t *v1_ingress_port_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_ingress_port_status->error
    if(v1_ingress_port_status->error) {
    if(mazu_cJSON_AddStringToObject(item, "error", v1_ingress_port_status->error) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_port_status->port
    if (!v1_ingress_port_status->port) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "port", v1_ingress_port_status->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_ingress_port_status->protocol
    if (!v1_ingress_port_status->protocol) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "protocol", v1_ingress_port_status->protocol) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_ingress_port_status_t *v1_ingress_port_status_parseFromJSON(mazu_cJSON *v1_ingress_port_statusJSON){

    v1_ingress_port_status_t *v1_ingress_port_status_local_var = NULL;

    // v1_ingress_port_status->error
    mazu_cJSON *error = mazu_cJSON_GetObjectItemCaseSensitive(v1_ingress_port_statusJSON, "error");
    if (error) { 
    if(!mazu_cJSON_IsString(error) && !mazu_cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // v1_ingress_port_status->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(v1_ingress_port_statusJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_ingress_port_status->protocol
    mazu_cJSON *protocol = mazu_cJSON_GetObjectItemCaseSensitive(v1_ingress_port_statusJSON, "protocol");
    if (!protocol) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(protocol))
    {
    goto end; //String
    }


    v1_ingress_port_status_local_var = v1_ingress_port_status_create (
        error && !mazu_cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        port->valuedouble,
        strdup(protocol->valuestring)
        );

    return v1_ingress_port_status_local_var;
end:
    return NULL;

}
