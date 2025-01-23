#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_flow_distinguisher_method.h"



v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method_create(
    char *type
    ) {
    v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method_local_var = malloc(sizeof(v1beta3_flow_distinguisher_method_t));
    if (!v1beta3_flow_distinguisher_method_local_var) {
        return NULL;
    }
    v1beta3_flow_distinguisher_method_local_var->type = type;

    return v1beta3_flow_distinguisher_method_local_var;
}


void v1beta3_flow_distinguisher_method_free(v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method) {
    if(NULL == v1beta3_flow_distinguisher_method){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_flow_distinguisher_method->type) {
        free(v1beta3_flow_distinguisher_method->type);
        v1beta3_flow_distinguisher_method->type = NULL;
    }
    free(v1beta3_flow_distinguisher_method);
}

mazu_cJSON *v1beta3_flow_distinguisher_method_convertToJSON(v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta3_flow_distinguisher_method->type
    if (!v1beta3_flow_distinguisher_method->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1beta3_flow_distinguisher_method->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method_parseFromJSON(mazu_cJSON *v1beta3_flow_distinguisher_methodJSON){

    v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method_local_var = NULL;

    // v1beta3_flow_distinguisher_method->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_flow_distinguisher_methodJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1beta3_flow_distinguisher_method_local_var = v1beta3_flow_distinguisher_method_create (
        strdup(type->valuestring)
        );

    return v1beta3_flow_distinguisher_method_local_var;
end:
    return NULL;

}
