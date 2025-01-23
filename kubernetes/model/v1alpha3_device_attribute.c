#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_attribute.h"



v1alpha3_device_attribute_t *v1alpha3_device_attribute_create(
    int _bool,
    long _int,
    char *string,
    char *version
    ) {
    v1alpha3_device_attribute_t *v1alpha3_device_attribute_local_var = malloc(sizeof(v1alpha3_device_attribute_t));
    if (!v1alpha3_device_attribute_local_var) {
        return NULL;
    }
    v1alpha3_device_attribute_local_var->_bool = _bool;
    v1alpha3_device_attribute_local_var->_int = _int;
    v1alpha3_device_attribute_local_var->string = string;
    v1alpha3_device_attribute_local_var->version = version;

    return v1alpha3_device_attribute_local_var;
}


void v1alpha3_device_attribute_free(v1alpha3_device_attribute_t *v1alpha3_device_attribute) {
    if(NULL == v1alpha3_device_attribute){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_attribute->string) {
        free(v1alpha3_device_attribute->string);
        v1alpha3_device_attribute->string = NULL;
    }
    if (v1alpha3_device_attribute->version) {
        free(v1alpha3_device_attribute->version);
        v1alpha3_device_attribute->version = NULL;
    }
    free(v1alpha3_device_attribute);
}

mazu_cJSON *v1alpha3_device_attribute_convertToJSON(v1alpha3_device_attribute_t *v1alpha3_device_attribute) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha3_device_attribute->_bool
    if(v1alpha3_device_attribute->_bool) {
    if(mazu_cJSON_AddBoolToObject(item, "bool", v1alpha3_device_attribute->_bool) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha3_device_attribute->_int
    if(v1alpha3_device_attribute->_int) {
    if(mazu_cJSON_AddNumberToObject(item, "int", v1alpha3_device_attribute->_int) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_device_attribute->string
    if(v1alpha3_device_attribute->string) {
    if(mazu_cJSON_AddStringToObject(item, "string", v1alpha3_device_attribute->string) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_attribute->version
    if(v1alpha3_device_attribute->version) {
    if(mazu_cJSON_AddStringToObject(item, "version", v1alpha3_device_attribute->version) == NULL) {
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

v1alpha3_device_attribute_t *v1alpha3_device_attribute_parseFromJSON(mazu_cJSON *v1alpha3_device_attributeJSON){

    v1alpha3_device_attribute_t *v1alpha3_device_attribute_local_var = NULL;

    // v1alpha3_device_attribute->_bool
    mazu_cJSON *_bool = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "bool");
    if (_bool) { 
    if(!mazu_cJSON_IsBool(_bool))
    {
    goto end; //Bool
    }
    }

    // v1alpha3_device_attribute->_int
    mazu_cJSON *_int = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "int");
    if (_int) { 
    if(!mazu_cJSON_IsNumber(_int))
    {
    goto end; //Numeric
    }
    }

    // v1alpha3_device_attribute->string
    mazu_cJSON *string = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "string");
    if (string) { 
    if(!mazu_cJSON_IsString(string) && !mazu_cJSON_IsNull(string))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_attribute->version
    mazu_cJSON *version = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_device_attributeJSON, "version");
    if (version) { 
    if(!mazu_cJSON_IsString(version) && !mazu_cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1alpha3_device_attribute_local_var = v1alpha3_device_attribute_create (
        _bool ? _bool->valueint : 0,
        _int ? _int->valuedouble : 0,
        string && !mazu_cJSON_IsNull(string) ? strdup(string->valuestring) : NULL,
        version && !mazu_cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1alpha3_device_attribute_local_var;
end:
    return NULL;

}
