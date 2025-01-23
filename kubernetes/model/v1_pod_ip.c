#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_ip.h"



v1_pod_ip_t *v1_pod_ip_create(
    char *ip
    ) {
    v1_pod_ip_t *v1_pod_ip_local_var = malloc(sizeof(v1_pod_ip_t));
    if (!v1_pod_ip_local_var) {
        return NULL;
    }
    v1_pod_ip_local_var->ip = ip;

    return v1_pod_ip_local_var;
}


void v1_pod_ip_free(v1_pod_ip_t *v1_pod_ip) {
    if(NULL == v1_pod_ip){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_ip->ip) {
        free(v1_pod_ip->ip);
        v1_pod_ip->ip = NULL;
    }
    free(v1_pod_ip);
}

mazu_cJSON *v1_pod_ip_convertToJSON(v1_pod_ip_t *v1_pod_ip) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_ip->ip
    if (!v1_pod_ip->ip) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "ip", v1_pod_ip->ip) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_ip_t *v1_pod_ip_parseFromJSON(mazu_cJSON *v1_pod_ipJSON){

    v1_pod_ip_t *v1_pod_ip_local_var = NULL;

    // v1_pod_ip->ip
    mazu_cJSON *ip = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_ipJSON, "ip");
    if (!ip) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(ip))
    {
    goto end; //String
    }


    v1_pod_ip_local_var = v1_pod_ip_create (
        strdup(ip->valuestring)
        );

    return v1_pod_ip_local_var;
end:
    return NULL;

}
