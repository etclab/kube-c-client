#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_server_address_by_client_cidr.h"



v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_create(
    char *client_cidr,
    char *server_address
    ) {
    v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_local_var = malloc(sizeof(v1_server_address_by_client_cidr_t));
    if (!v1_server_address_by_client_cidr_local_var) {
        return NULL;
    }
    v1_server_address_by_client_cidr_local_var->client_cidr = client_cidr;
    v1_server_address_by_client_cidr_local_var->server_address = server_address;

    return v1_server_address_by_client_cidr_local_var;
}


void v1_server_address_by_client_cidr_free(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr) {
    if(NULL == v1_server_address_by_client_cidr){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_server_address_by_client_cidr->client_cidr) {
        free(v1_server_address_by_client_cidr->client_cidr);
        v1_server_address_by_client_cidr->client_cidr = NULL;
    }
    if (v1_server_address_by_client_cidr->server_address) {
        free(v1_server_address_by_client_cidr->server_address);
        v1_server_address_by_client_cidr->server_address = NULL;
    }
    free(v1_server_address_by_client_cidr);
}

mazu_cJSON *v1_server_address_by_client_cidr_convertToJSON(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_server_address_by_client_cidr->client_cidr
    if (!v1_server_address_by_client_cidr->client_cidr) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "clientCIDR", v1_server_address_by_client_cidr->client_cidr) == NULL) {
    goto fail; //String
    }


    // v1_server_address_by_client_cidr->server_address
    if (!v1_server_address_by_client_cidr->server_address) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "serverAddress", v1_server_address_by_client_cidr->server_address) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_parseFromJSON(mazu_cJSON *v1_server_address_by_client_cidrJSON){

    v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_local_var = NULL;

    // v1_server_address_by_client_cidr->client_cidr
    mazu_cJSON *client_cidr = mazu_cJSON_GetObjectItemCaseSensitive(v1_server_address_by_client_cidrJSON, "clientCIDR");
    if (!client_cidr) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(client_cidr))
    {
    goto end; //String
    }

    // v1_server_address_by_client_cidr->server_address
    mazu_cJSON *server_address = mazu_cJSON_GetObjectItemCaseSensitive(v1_server_address_by_client_cidrJSON, "serverAddress");
    if (!server_address) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(server_address))
    {
    goto end; //String
    }


    v1_server_address_by_client_cidr_local_var = v1_server_address_by_client_cidr_create (
        strdup(client_cidr->valuestring),
        strdup(server_address->valuestring)
        );

    return v1_server_address_by_client_cidr_local_var;
end:
    return NULL;

}
