#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device.h"



v1alpha3_device_t *v1alpha3_device_create(
    v1alpha3_basic_device_t *basic,
    char *name
    ) {
    v1alpha3_device_t *v1alpha3_device_local_var = malloc(sizeof(v1alpha3_device_t));
    if (!v1alpha3_device_local_var) {
        return NULL;
    }
    v1alpha3_device_local_var->basic = basic;
    v1alpha3_device_local_var->name = name;

    return v1alpha3_device_local_var;
}


void v1alpha3_device_free(v1alpha3_device_t *v1alpha3_device) {
    if(NULL == v1alpha3_device){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device->basic) {
        v1alpha3_basic_device_free(v1alpha3_device->basic);
        v1alpha3_device->basic = NULL;
    }
    if (v1alpha3_device->name) {
        free(v1alpha3_device->name);
        v1alpha3_device->name = NULL;
    }
    free(v1alpha3_device);
}

mazu_cJSON *v1alpha3_device_convertToJSON(v1alpha3_device_t *v1alpha3_device) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha3_device->basic
    if(v1alpha3_device->basic) {
    mazu_cJSON *basic_local_JSON = v1alpha3_basic_device_convertToJSON(v1alpha3_device->basic);
    if(basic_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "basic", basic_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_device->name
    if (!v1alpha3_device->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1alpha3_device->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_device_t *v1alpha3_device_parseFromJSON(mazu_cJSON *v1alpha3_deviceJSON){

    v1alpha3_device_t *v1alpha3_device_local_var = NULL;

    // define the local variable for v1alpha3_device->basic
    v1alpha3_basic_device_t *basic_local_nonprim = NULL;

    // v1alpha3_device->basic
    mazu_cJSON *basic = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_deviceJSON, "basic");
    if (basic) { 
    basic_local_nonprim = v1alpha3_basic_device_parseFromJSON(basic); //nonprimitive
    }

    // v1alpha3_device->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_deviceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha3_device_local_var = v1alpha3_device_create (
        basic ? basic_local_nonprim : NULL,
        strdup(name->valuestring)
        );

    return v1alpha3_device_local_var;
end:
    if (basic_local_nonprim) {
        v1alpha3_basic_device_free(basic_local_nonprim);
        basic_local_nonprim = NULL;
    }
    return NULL;

}
