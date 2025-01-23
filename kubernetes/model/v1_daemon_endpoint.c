#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_endpoint.h"



v1_daemon_endpoint_t *v1_daemon_endpoint_create(
    int port
    ) {
    v1_daemon_endpoint_t *v1_daemon_endpoint_local_var = malloc(sizeof(v1_daemon_endpoint_t));
    if (!v1_daemon_endpoint_local_var) {
        return NULL;
    }
    v1_daemon_endpoint_local_var->port = port;

    return v1_daemon_endpoint_local_var;
}


void v1_daemon_endpoint_free(v1_daemon_endpoint_t *v1_daemon_endpoint) {
    if(NULL == v1_daemon_endpoint){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_daemon_endpoint);
}

mazu_cJSON *v1_daemon_endpoint_convertToJSON(v1_daemon_endpoint_t *v1_daemon_endpoint) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_daemon_endpoint->port
    if (!v1_daemon_endpoint->port) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "Port", v1_daemon_endpoint->port) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_daemon_endpoint_t *v1_daemon_endpoint_parseFromJSON(mazu_cJSON *v1_daemon_endpointJSON){

    v1_daemon_endpoint_t *v1_daemon_endpoint_local_var = NULL;

    // v1_daemon_endpoint->port
    mazu_cJSON *port = mazu_cJSON_GetObjectItemCaseSensitive(v1_daemon_endpointJSON, "Port");
    if (!port) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }


    v1_daemon_endpoint_local_var = v1_daemon_endpoint_create (
        port->valuedouble
        );

    return v1_daemon_endpoint_local_var;
end:
    return NULL;

}
