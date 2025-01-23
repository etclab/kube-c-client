#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_param_ref.h"



v1_param_ref_t *v1_param_ref_create(
    char *name,
    char *_namespace,
    char *parameter_not_found_action,
    v1_label_selector_t *selector
    ) {
    v1_param_ref_t *v1_param_ref_local_var = malloc(sizeof(v1_param_ref_t));
    if (!v1_param_ref_local_var) {
        return NULL;
    }
    v1_param_ref_local_var->name = name;
    v1_param_ref_local_var->_namespace = _namespace;
    v1_param_ref_local_var->parameter_not_found_action = parameter_not_found_action;
    v1_param_ref_local_var->selector = selector;

    return v1_param_ref_local_var;
}


void v1_param_ref_free(v1_param_ref_t *v1_param_ref) {
    if(NULL == v1_param_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_param_ref->name) {
        free(v1_param_ref->name);
        v1_param_ref->name = NULL;
    }
    if (v1_param_ref->_namespace) {
        free(v1_param_ref->_namespace);
        v1_param_ref->_namespace = NULL;
    }
    if (v1_param_ref->parameter_not_found_action) {
        free(v1_param_ref->parameter_not_found_action);
        v1_param_ref->parameter_not_found_action = NULL;
    }
    if (v1_param_ref->selector) {
        v1_label_selector_free(v1_param_ref->selector);
        v1_param_ref->selector = NULL;
    }
    free(v1_param_ref);
}

mazu_cJSON *v1_param_ref_convertToJSON(v1_param_ref_t *v1_param_ref) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_param_ref->name
    if(v1_param_ref->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_param_ref->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_param_ref->_namespace
    if(v1_param_ref->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_param_ref->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_param_ref->parameter_not_found_action
    if(v1_param_ref->parameter_not_found_action) {
    if(mazu_cJSON_AddStringToObject(item, "parameterNotFoundAction", v1_param_ref->parameter_not_found_action) == NULL) {
    goto fail; //String
    }
    }


    // v1_param_ref->selector
    if(v1_param_ref->selector) {
    mazu_cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_param_ref->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_param_ref_t *v1_param_ref_parseFromJSON(mazu_cJSON *v1_param_refJSON){

    v1_param_ref_t *v1_param_ref_local_var = NULL;

    // define the local variable for v1_param_ref->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // v1_param_ref->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_param_refJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_param_ref->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_param_refJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_param_ref->parameter_not_found_action
    mazu_cJSON *parameter_not_found_action = mazu_cJSON_GetObjectItemCaseSensitive(v1_param_refJSON, "parameterNotFoundAction");
    if (parameter_not_found_action) { 
    if(!mazu_cJSON_IsString(parameter_not_found_action) && !mazu_cJSON_IsNull(parameter_not_found_action))
    {
    goto end; //String
    }
    }

    // v1_param_ref->selector
    mazu_cJSON *selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_param_refJSON, "selector");
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v1_param_ref_local_var = v1_param_ref_create (
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        parameter_not_found_action && !mazu_cJSON_IsNull(parameter_not_found_action) ? strdup(parameter_not_found_action->valuestring) : NULL,
        selector ? selector_local_nonprim : NULL
        );

    return v1_param_ref_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    return NULL;

}
