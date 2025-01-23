#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_dns_config_option.h"



v1_pod_dns_config_option_t *v1_pod_dns_config_option_create(
    char *name,
    char *value
    ) {
    v1_pod_dns_config_option_t *v1_pod_dns_config_option_local_var = malloc(sizeof(v1_pod_dns_config_option_t));
    if (!v1_pod_dns_config_option_local_var) {
        return NULL;
    }
    v1_pod_dns_config_option_local_var->name = name;
    v1_pod_dns_config_option_local_var->value = value;

    return v1_pod_dns_config_option_local_var;
}


void v1_pod_dns_config_option_free(v1_pod_dns_config_option_t *v1_pod_dns_config_option) {
    if(NULL == v1_pod_dns_config_option){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_dns_config_option->name) {
        free(v1_pod_dns_config_option->name);
        v1_pod_dns_config_option->name = NULL;
    }
    if (v1_pod_dns_config_option->value) {
        free(v1_pod_dns_config_option->value);
        v1_pod_dns_config_option->value = NULL;
    }
    free(v1_pod_dns_config_option);
}

mazu_cJSON *v1_pod_dns_config_option_convertToJSON(v1_pod_dns_config_option_t *v1_pod_dns_config_option) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_dns_config_option->name
    if(v1_pod_dns_config_option->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_pod_dns_config_option->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_dns_config_option->value
    if(v1_pod_dns_config_option->value) {
    if(mazu_cJSON_AddStringToObject(item, "value", v1_pod_dns_config_option->value) == NULL) {
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

v1_pod_dns_config_option_t *v1_pod_dns_config_option_parseFromJSON(mazu_cJSON *v1_pod_dns_config_optionJSON){

    v1_pod_dns_config_option_t *v1_pod_dns_config_option_local_var = NULL;

    // v1_pod_dns_config_option->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_dns_config_optionJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_pod_dns_config_option->value
    mazu_cJSON *value = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_dns_config_optionJSON, "value");
    if (value) { 
    if(!mazu_cJSON_IsString(value) && !mazu_cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    v1_pod_dns_config_option_local_var = v1_pod_dns_config_option_create (
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        value && !mazu_cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return v1_pod_dns_config_option_local_var;
end:
    return NULL;

}
