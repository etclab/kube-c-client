#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_reference.h"



v1_secret_reference_t *v1_secret_reference_create(
    char *name,
    char *_namespace
    ) {
    v1_secret_reference_t *v1_secret_reference_local_var = malloc(sizeof(v1_secret_reference_t));
    if (!v1_secret_reference_local_var) {
        return NULL;
    }
    v1_secret_reference_local_var->name = name;
    v1_secret_reference_local_var->_namespace = _namespace;

    return v1_secret_reference_local_var;
}


void v1_secret_reference_free(v1_secret_reference_t *v1_secret_reference) {
    if(NULL == v1_secret_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_reference->name) {
        free(v1_secret_reference->name);
        v1_secret_reference->name = NULL;
    }
    if (v1_secret_reference->_namespace) {
        free(v1_secret_reference->_namespace);
        v1_secret_reference->_namespace = NULL;
    }
    free(v1_secret_reference);
}

mazu_cJSON *v1_secret_reference_convertToJSON(v1_secret_reference_t *v1_secret_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_secret_reference->name
    if(v1_secret_reference->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_secret_reference->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_secret_reference->_namespace
    if(v1_secret_reference->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_secret_reference->_namespace) == NULL) {
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

v1_secret_reference_t *v1_secret_reference_parseFromJSON(mazu_cJSON *v1_secret_referenceJSON){

    v1_secret_reference_t *v1_secret_reference_local_var = NULL;

    // v1_secret_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_secret_referenceJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_secret_reference->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_secret_referenceJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }


    v1_secret_reference_local_var = v1_secret_reference_create (
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL
        );

    return v1_secret_reference_local_var;
end:
    return NULL;

}
