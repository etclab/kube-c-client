#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "discovery_v1_endpoint_port.h"



discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_local_var = malloc(sizeof(discovery_v1_endpoint_port_t));
    if (!discovery_v1_endpoint_port_local_var) {
        return NULL;
    }
    discovery_v1_endpoint_port_local_var->app_protocol = app_protocol;
    discovery_v1_endpoint_port_local_var->name = name;
    discovery_v1_endpoint_port_local_var->port = port;
    discovery_v1_endpoint_port_local_var->protocol = protocol;

    return discovery_v1_endpoint_port_local_var;
}


void discovery_v1_endpoint_port_free(discovery_v1_endpoint_port_t *discovery_v1_endpoint_port) {
    if(NULL == discovery_v1_endpoint_port){
        return ;
    }
    listEntry_t *listEntry;
    if (discovery_v1_endpoint_port->app_protocol) {
        free(discovery_v1_endpoint_port->app_protocol);
        discovery_v1_endpoint_port->app_protocol = NULL;
    }
    if (discovery_v1_endpoint_port->name) {
        free(discovery_v1_endpoint_port->name);
        discovery_v1_endpoint_port->name = NULL;
    }
    if (discovery_v1_endpoint_port->protocol) {
        free(discovery_v1_endpoint_port->protocol);
        discovery_v1_endpoint_port->protocol = NULL;
    }
    free(discovery_v1_endpoint_port);
}

mazu_cJSON *discovery_v1_endpoint_port_convertToJSON(discovery_v1_endpoint_port_t *discovery_v1_endpoint_port) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // discovery_v1_endpoint_port->app_protocol
    if(discovery_v1_endpoint_port->app_protocol) {
    if(mazu_cJSON_AddStringToObject(item, "appProtocol", discovery_v1_endpoint_port->app_protocol) == NULL) {
    goto fail; //String
    }
    }


    // discovery_v1_endpoint_port->name
    if(discovery_v1_endpoint_port->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", discovery_v1_endpoint_port->name) == NULL) {
    goto fail; //String
    }
    }


    // discovery_v1_endpoint_port->port
    if(discovery_v1_endpoint_port->port) {
    if(mazu_cJSON_AddNumberToObject(item, "port", discovery_v1_endpoint_port->port) == NULL) {
    goto fail; //Numeric
    }
    }


    // discovery_v1_endpoint_port->protocol
    if(discovery_v1_endpoint_port->protocol) {
    if(mazu_cJSON_AddStringToObject(item, "protocol", discovery_v1_endpoint_port->protocol) == NULL) {
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

discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_parseFromJSON(mazu_cJSON *discovery_v1_endpoint_portJSON){

    discovery_v1_endpoint_port_t *discovery_v1_endpoint_port_local_var = NULL;

    // discovery_v1_endpoint_port->app_protocol
    mazu_cJSON *app_protocol = mazu_cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "appProtocol");
    if (app_protocol) { 
    if(!mazu_cJSON_IsString(app_protocol) && !mazu_cJSON_IsNull(app_protocol))
    {
    goto end; //String
    }
    }

    // discovery_v1_endpoint_port->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // discovery_v1_endpoint_port->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "port");
    if (port) { 
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }

    // discovery_v1_endpoint_port->protocol
    mazu_cJSON *protocol = mazu_cJSON_GetObjectItemCaseSensitive(discovery_v1_endpoint_portJSON, "protocol");
    if (protocol) { 
    if(!mazu_cJSON_IsString(protocol) && !mazu_cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }


    discovery_v1_endpoint_port_local_var = discovery_v1_endpoint_port_create (
        app_protocol && !mazu_cJSON_IsNull(app_protocol) ? strdup(app_protocol->valuestring) : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        port ? port->valuedouble : 0,
        protocol && !mazu_cJSON_IsNull(protocol) ? strdup(protocol->valuestring) : NULL
        );

    return discovery_v1_endpoint_port_local_var;
end:
    return NULL;

}
