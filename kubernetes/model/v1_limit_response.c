#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_response.h"



v1_limit_response_t *v1_limit_response_create(
    v1_queuing_configuration_t *queuing,
    char *type
    ) {
    v1_limit_response_t *v1_limit_response_local_var = malloc(sizeof(v1_limit_response_t));
    if (!v1_limit_response_local_var) {
        return NULL;
    }
    v1_limit_response_local_var->queuing = queuing;
    v1_limit_response_local_var->type = type;

    return v1_limit_response_local_var;
}


void v1_limit_response_free(v1_limit_response_t *v1_limit_response) {
    if(NULL == v1_limit_response){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_response->queuing) {
        v1_queuing_configuration_free(v1_limit_response->queuing);
        v1_limit_response->queuing = NULL;
    }
    if (v1_limit_response->type) {
        free(v1_limit_response->type);
        v1_limit_response->type = NULL;
    }
    free(v1_limit_response);
}

mazu_cJSON *v1_limit_response_convertToJSON(v1_limit_response_t *v1_limit_response) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_limit_response->queuing
    if(v1_limit_response->queuing) {
    mazu_cJSON *queuing_local_JSON = v1_queuing_configuration_convertToJSON(v1_limit_response->queuing);
    if(queuing_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "queuing", queuing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_limit_response->type
    if (!v1_limit_response->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1_limit_response->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_limit_response_t *v1_limit_response_parseFromJSON(mazu_cJSON *v1_limit_responseJSON){

    v1_limit_response_t *v1_limit_response_local_var = NULL;

    // define the local variable for v1_limit_response->queuing
    v1_queuing_configuration_t *queuing_local_nonprim = NULL;

    // v1_limit_response->queuing
    mazu_cJSON *queuing = mazu_cJSON_GetObjectItemCaseSensitive(v1_limit_responseJSON, "queuing");
    if (queuing) { 
    queuing_local_nonprim = v1_queuing_configuration_parseFromJSON(queuing); //nonprimitive
    }

    // v1_limit_response->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1_limit_responseJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_limit_response_local_var = v1_limit_response_create (
        queuing ? queuing_local_nonprim : NULL,
        strdup(type->valuestring)
        );

    return v1_limit_response_local_var;
end:
    if (queuing_local_nonprim) {
        v1_queuing_configuration_free(queuing_local_nonprim);
        queuing_local_nonprim = NULL;
    }
    return NULL;

}
