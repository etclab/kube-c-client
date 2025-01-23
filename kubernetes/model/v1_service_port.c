#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_port.h"



v1_service_port_t *v1_service_port_create(
    char *app_protocol,
    char *name,
    int node_port,
    int port,
    char *protocol,
    int_or_string_t *target_port
    ) {
    v1_service_port_t *v1_service_port_local_var = malloc(sizeof(v1_service_port_t));
    if (!v1_service_port_local_var) {
        return NULL;
    }
    v1_service_port_local_var->app_protocol = app_protocol;
    v1_service_port_local_var->name = name;
    v1_service_port_local_var->node_port = node_port;
    v1_service_port_local_var->port = port;
    v1_service_port_local_var->protocol = protocol;
    v1_service_port_local_var->target_port = target_port;

    return v1_service_port_local_var;
}


void v1_service_port_free(v1_service_port_t *v1_service_port) {
    if(NULL == v1_service_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_port->app_protocol) {
        free(v1_service_port->app_protocol);
        v1_service_port->app_protocol = NULL;
    }
    if (v1_service_port->name) {
        free(v1_service_port->name);
        v1_service_port->name = NULL;
    }
    if (v1_service_port->protocol) {
        free(v1_service_port->protocol);
        v1_service_port->protocol = NULL;
    }
    if (v1_service_port->target_port) {
        int_or_string_free(v1_service_port->target_port);
        v1_service_port->target_port = NULL;
    }
    free(v1_service_port);
}

mazu_cJSON *v1_service_port_convertToJSON(v1_service_port_t *v1_service_port) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_service_port->app_protocol
    if(v1_service_port->app_protocol) {
    if(mazu_cJSON_AddStringToObject(item, "appProtocol", v1_service_port->app_protocol) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_port->name
    if(v1_service_port->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_service_port->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_port->node_port
    if(v1_service_port->node_port) {
    if(mazu_cJSON_AddNumberToObject(item, "nodePort", v1_service_port->node_port) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_service_port->port
    if (!v1_service_port->port) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "port", v1_service_port->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_service_port->protocol
    if(v1_service_port->protocol) {
    if(mazu_cJSON_AddStringToObject(item, "protocol", v1_service_port->protocol) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_port->target_port
    if(v1_service_port->target_port) {
    mazu_cJSON *target_port_local_JSON = int_or_string_convertToJSON(v1_service_port->target_port);
    if(target_port_local_JSON == NULL) {
        goto fail; // custom
    }
    mazu_cJSON_AddItemToObject(item, "targetPort", target_port_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_service_port_t *v1_service_port_parseFromJSON(mazu_cJSON *v1_service_portJSON){

    v1_service_port_t *v1_service_port_local_var = NULL;

    // define the local variable for v1_service_port->target_port
    int_or_string_t *target_port_local_nonprim = NULL;

    // v1_service_port->app_protocol
    mazu_cJSON *app_protocol = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "appProtocol");
    if (app_protocol) { 
    if(!mazu_cJSON_IsString(app_protocol) && !mazu_cJSON_IsNull(app_protocol))
    {
    goto end; //String
    }
    }

    // v1_service_port->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_service_port->node_port
    mazu_cJSON *node_port = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "nodePort");
    if (node_port) { 
    if(!mazu_cJSON_IsNumber(node_port))
    {
    goto end; //Numeric
    }
    }

    // v1_service_port->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_service_port->protocol
    mazu_cJSON *protocol = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "protocol");
    if (protocol) { 
    if(!mazu_cJSON_IsString(protocol) && !mazu_cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }

    // v1_service_port->target_port
    mazu_cJSON *target_port = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_portJSON, "targetPort");
    if (target_port) { 
    target_port_local_nonprim = int_or_string_parseFromJSON(target_port); //custom
    }


    v1_service_port_local_var = v1_service_port_create (
        app_protocol && !mazu_cJSON_IsNull(app_protocol) ? strdup(app_protocol->valuestring) : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        node_port ? node_port->valuedouble : 0,
        port->valuedouble,
        protocol && !mazu_cJSON_IsNull(protocol) ? strdup(protocol->valuestring) : NULL,
        target_port ? target_port_local_nonprim : NULL
        );

    return v1_service_port_local_var;
end:
    if (target_port_local_nonprim) {
        int_or_string_free(target_port_local_nonprim);
        target_port_local_nonprim = NULL;
    }
    return NULL;

}
