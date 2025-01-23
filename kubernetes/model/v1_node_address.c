#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_address.h"



v1_node_address_t *v1_node_address_create(
    char *address,
    char *type
    ) {
    v1_node_address_t *v1_node_address_local_var = malloc(sizeof(v1_node_address_t));
    if (!v1_node_address_local_var) {
        return NULL;
    }
    v1_node_address_local_var->address = address;
    v1_node_address_local_var->type = type;

    return v1_node_address_local_var;
}


void v1_node_address_free(v1_node_address_t *v1_node_address) {
    if(NULL == v1_node_address){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_address->address) {
        free(v1_node_address->address);
        v1_node_address->address = NULL;
    }
    if (v1_node_address->type) {
        free(v1_node_address->type);
        v1_node_address->type = NULL;
    }
    free(v1_node_address);
}

mazu_cJSON *v1_node_address_convertToJSON(v1_node_address_t *v1_node_address) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_node_address->address
    if (!v1_node_address->address) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "address", v1_node_address->address) == NULL) {
    goto fail; //String
    }


    // v1_node_address->type
    if (!v1_node_address->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1_node_address->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_node_address_t *v1_node_address_parseFromJSON(mazu_cJSON *v1_node_addressJSON){

    v1_node_address_t *v1_node_address_local_var = NULL;

    // v1_node_address->address
    mazu_cJSON *address = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_addressJSON, "address");
    if (!address) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(address))
    {
    goto end; //String
    }

    // v1_node_address->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_addressJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_node_address_local_var = v1_node_address_create (
        strdup(address->valuestring),
        strdup(type->valuestring)
        );

    return v1_node_address_local_var;
end:
    return NULL;

}
