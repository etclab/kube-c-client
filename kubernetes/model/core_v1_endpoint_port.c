#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core_v1_endpoint_port.h"



core_v1_endpoint_port_t *core_v1_endpoint_port_create(
    char *app_protocol,
    char *name,
    int port,
    char *protocol
    ) {
    core_v1_endpoint_port_t *core_v1_endpoint_port_local_var = malloc(sizeof(core_v1_endpoint_port_t));
    if (!core_v1_endpoint_port_local_var) {
        return NULL;
    }
    core_v1_endpoint_port_local_var->app_protocol = app_protocol;
    core_v1_endpoint_port_local_var->name = name;
    core_v1_endpoint_port_local_var->port = port;
    core_v1_endpoint_port_local_var->protocol = protocol;

    return core_v1_endpoint_port_local_var;
}


void core_v1_endpoint_port_free(core_v1_endpoint_port_t *core_v1_endpoint_port) {
    if(NULL == core_v1_endpoint_port){
        return ;
    }
    listEntry_t *listEntry;
    if (core_v1_endpoint_port->app_protocol) {
        free(core_v1_endpoint_port->app_protocol);
        core_v1_endpoint_port->app_protocol = NULL;
    }
    if (core_v1_endpoint_port->name) {
        free(core_v1_endpoint_port->name);
        core_v1_endpoint_port->name = NULL;
    }
    if (core_v1_endpoint_port->protocol) {
        free(core_v1_endpoint_port->protocol);
        core_v1_endpoint_port->protocol = NULL;
    }
    free(core_v1_endpoint_port);
}

mazu_cJSON *core_v1_endpoint_port_convertToJSON(core_v1_endpoint_port_t *core_v1_endpoint_port) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // core_v1_endpoint_port->app_protocol
    if(core_v1_endpoint_port->app_protocol) {
    if(mazu_cJSON_AddStringToObject(item, "appProtocol", core_v1_endpoint_port->app_protocol) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_endpoint_port->name
    if(core_v1_endpoint_port->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", core_v1_endpoint_port->name) == NULL) {
    goto fail; //String
    }
    }


    // core_v1_endpoint_port->port
    if (!core_v1_endpoint_port->port) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "port", core_v1_endpoint_port->port) == NULL) {
    goto fail; //Numeric
    }


    // core_v1_endpoint_port->protocol
    if(core_v1_endpoint_port->protocol) {
    if(mazu_cJSON_AddStringToObject(item, "protocol", core_v1_endpoint_port->protocol) == NULL) {
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

core_v1_endpoint_port_t *core_v1_endpoint_port_parseFromJSON(mazu_cJSON *core_v1_endpoint_portJSON){

    core_v1_endpoint_port_t *core_v1_endpoint_port_local_var = NULL;

    // core_v1_endpoint_port->app_protocol
    mazu_cJSON *app_protocol = mazu_cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "appProtocol");
    if (app_protocol) { 
    if(!mazu_cJSON_IsString(app_protocol) && !mazu_cJSON_IsNull(app_protocol))
    {
    goto end; //String
    }
    }

    // core_v1_endpoint_port->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // core_v1_endpoint_port->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "port");
    if (!port) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // core_v1_endpoint_port->protocol
    mazu_cJSON *protocol = mazu_cJSON_GetObjectItemCaseSensitive(core_v1_endpoint_portJSON, "protocol");
    if (protocol) { 
    if(!mazu_cJSON_IsString(protocol) && !mazu_cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }


    core_v1_endpoint_port_local_var = core_v1_endpoint_port_create (
        app_protocol && !mazu_cJSON_IsNull(app_protocol) ? strdup(app_protocol->valuestring) : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        port->valuedouble,
        protocol && !mazu_cJSON_IsNull(protocol) ? strdup(protocol->valuestring) : NULL
        );

    return core_v1_endpoint_port_local_var;
end:
    return NULL;

}
