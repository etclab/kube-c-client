#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_backend_port.h"



v1_service_backend_port_t *v1_service_backend_port_create(
    char *name,
    int number
    ) {
    v1_service_backend_port_t *v1_service_backend_port_local_var = malloc(sizeof(v1_service_backend_port_t));
    if (!v1_service_backend_port_local_var) {
        return NULL;
    }
    v1_service_backend_port_local_var->name = name;
    v1_service_backend_port_local_var->number = number;

    return v1_service_backend_port_local_var;
}


void v1_service_backend_port_free(v1_service_backend_port_t *v1_service_backend_port) {
    if(NULL == v1_service_backend_port){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_backend_port->name) {
        free(v1_service_backend_port->name);
        v1_service_backend_port->name = NULL;
    }
    free(v1_service_backend_port);
}

mazu_cJSON *v1_service_backend_port_convertToJSON(v1_service_backend_port_t *v1_service_backend_port) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_service_backend_port->name
    if(v1_service_backend_port->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_service_backend_port->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_backend_port->number
    if(v1_service_backend_port->number) {
    if(mazu_cJSON_AddNumberToObject(item, "number", v1_service_backend_port->number) == NULL) {
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

v1_service_backend_port_t *v1_service_backend_port_parseFromJSON(mazu_cJSON *v1_service_backend_portJSON){

    v1_service_backend_port_t *v1_service_backend_port_local_var = NULL;

    // v1_service_backend_port->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_backend_portJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_service_backend_port->number
    mazu_cJSON *number = mazu_cJSON_GetObjectItemCaseSensitive(v1_service_backend_portJSON, "number");
    if (number) { 
    if(!mazu_cJSON_IsNumber(number))
    {
    goto end; //Numeric
    }
    }


    v1_service_backend_port_local_var = v1_service_backend_port_create (
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        number ? number->valuedouble : 0
        );

    return v1_service_backend_port_local_var;
end:
    return NULL;

}
