#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_host_ip.h"



v1_host_ip_t *v1_host_ip_create(
    char *ip
    ) {
    v1_host_ip_t *v1_host_ip_local_var = malloc(sizeof(v1_host_ip_t));
    if (!v1_host_ip_local_var) {
        return NULL;
    }
    v1_host_ip_local_var->ip = ip;

    return v1_host_ip_local_var;
}


void v1_host_ip_free(v1_host_ip_t *v1_host_ip) {
    if(NULL == v1_host_ip){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_host_ip->ip) {
        free(v1_host_ip->ip);
        v1_host_ip->ip = NULL;
    }
    free(v1_host_ip);
}

mazu_cJSON *v1_host_ip_convertToJSON(v1_host_ip_t *v1_host_ip) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_host_ip->ip
    if (!v1_host_ip->ip) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "ip", v1_host_ip->ip) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_host_ip_t *v1_host_ip_parseFromJSON(mazu_cJSON *v1_host_ipJSON){

    v1_host_ip_t *v1_host_ip_local_var = NULL;

    // v1_host_ip->ip
    mazu_cJSON *ip = mazu_cJSON_GetObjectItemCaseSensitive(v1_host_ipJSON, "ip");
    if (!ip) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(ip))
    {
    goto end; //String
    }


    v1_host_ip_local_var = v1_host_ip_create (
        strdup(ip->valuestring)
        );

    return v1_host_ip_local_var;
end:
    return NULL;

}
