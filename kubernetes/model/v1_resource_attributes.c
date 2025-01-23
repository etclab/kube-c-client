#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_attributes.h"



v1_resource_attributes_t *v1_resource_attributes_create(
    v1_field_selector_attributes_t *field_selector,
    char *group,
    v1_label_selector_attributes_t *label_selector,
    char *name,
    char *_namespace,
    char *resource,
    char *subresource,
    char *verb,
    char *version
    ) {
    v1_resource_attributes_t *v1_resource_attributes_local_var = malloc(sizeof(v1_resource_attributes_t));
    if (!v1_resource_attributes_local_var) {
        return NULL;
    }
    v1_resource_attributes_local_var->field_selector = field_selector;
    v1_resource_attributes_local_var->group = group;
    v1_resource_attributes_local_var->label_selector = label_selector;
    v1_resource_attributes_local_var->name = name;
    v1_resource_attributes_local_var->_namespace = _namespace;
    v1_resource_attributes_local_var->resource = resource;
    v1_resource_attributes_local_var->subresource = subresource;
    v1_resource_attributes_local_var->verb = verb;
    v1_resource_attributes_local_var->version = version;

    return v1_resource_attributes_local_var;
}


void v1_resource_attributes_free(v1_resource_attributes_t *v1_resource_attributes) {
    if(NULL == v1_resource_attributes){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_attributes->field_selector) {
        v1_field_selector_attributes_free(v1_resource_attributes->field_selector);
        v1_resource_attributes->field_selector = NULL;
    }
    if (v1_resource_attributes->group) {
        free(v1_resource_attributes->group);
        v1_resource_attributes->group = NULL;
    }
    if (v1_resource_attributes->label_selector) {
        v1_label_selector_attributes_free(v1_resource_attributes->label_selector);
        v1_resource_attributes->label_selector = NULL;
    }
    if (v1_resource_attributes->name) {
        free(v1_resource_attributes->name);
        v1_resource_attributes->name = NULL;
    }
    if (v1_resource_attributes->_namespace) {
        free(v1_resource_attributes->_namespace);
        v1_resource_attributes->_namespace = NULL;
    }
    if (v1_resource_attributes->resource) {
        free(v1_resource_attributes->resource);
        v1_resource_attributes->resource = NULL;
    }
    if (v1_resource_attributes->subresource) {
        free(v1_resource_attributes->subresource);
        v1_resource_attributes->subresource = NULL;
    }
    if (v1_resource_attributes->verb) {
        free(v1_resource_attributes->verb);
        v1_resource_attributes->verb = NULL;
    }
    if (v1_resource_attributes->version) {
        free(v1_resource_attributes->version);
        v1_resource_attributes->version = NULL;
    }
    free(v1_resource_attributes);
}

mazu_cJSON *v1_resource_attributes_convertToJSON(v1_resource_attributes_t *v1_resource_attributes) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_resource_attributes->field_selector
    if(v1_resource_attributes->field_selector) {
    mazu_cJSON *field_selector_local_JSON = v1_field_selector_attributes_convertToJSON(v1_resource_attributes->field_selector);
    if(field_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "fieldSelector", field_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_attributes->group
    if(v1_resource_attributes->group) {
    if(mazu_cJSON_AddStringToObject(item, "group", v1_resource_attributes->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->label_selector
    if(v1_resource_attributes->label_selector) {
    mazu_cJSON *label_selector_local_JSON = v1_label_selector_attributes_convertToJSON(v1_resource_attributes->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_attributes->name
    if(v1_resource_attributes->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_resource_attributes->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->_namespace
    if(v1_resource_attributes->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_resource_attributes->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->resource
    if(v1_resource_attributes->resource) {
    if(mazu_cJSON_AddStringToObject(item, "resource", v1_resource_attributes->resource) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->subresource
    if(v1_resource_attributes->subresource) {
    if(mazu_cJSON_AddStringToObject(item, "subresource", v1_resource_attributes->subresource) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->verb
    if(v1_resource_attributes->verb) {
    if(mazu_cJSON_AddStringToObject(item, "verb", v1_resource_attributes->verb) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_attributes->version
    if(v1_resource_attributes->version) {
    if(mazu_cJSON_AddStringToObject(item, "version", v1_resource_attributes->version) == NULL) {
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

v1_resource_attributes_t *v1_resource_attributes_parseFromJSON(mazu_cJSON *v1_resource_attributesJSON){

    v1_resource_attributes_t *v1_resource_attributes_local_var = NULL;

    // define the local variable for v1_resource_attributes->field_selector
    v1_field_selector_attributes_t *field_selector_local_nonprim = NULL;

    // define the local variable for v1_resource_attributes->label_selector
    v1_label_selector_attributes_t *label_selector_local_nonprim = NULL;

    // v1_resource_attributes->field_selector
    mazu_cJSON *field_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "fieldSelector");
    if (field_selector) { 
    field_selector_local_nonprim = v1_field_selector_attributes_parseFromJSON(field_selector); //nonprimitive
    }

    // v1_resource_attributes->group
    mazu_cJSON *group = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "group");
    if (group) { 
    if(!mazu_cJSON_IsString(group) && !mazu_cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->label_selector
    mazu_cJSON *label_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "labelSelector");
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_attributes_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_resource_attributes->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->resource
    mazu_cJSON *resource = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "resource");
    if (resource) { 
    if(!mazu_cJSON_IsString(resource) && !mazu_cJSON_IsNull(resource))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->subresource
    mazu_cJSON *subresource = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "subresource");
    if (subresource) { 
    if(!mazu_cJSON_IsString(subresource) && !mazu_cJSON_IsNull(subresource))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->verb
    mazu_cJSON *verb = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "verb");
    if (verb) { 
    if(!mazu_cJSON_IsString(verb) && !mazu_cJSON_IsNull(verb))
    {
    goto end; //String
    }
    }

    // v1_resource_attributes->version
    mazu_cJSON *version = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_attributesJSON, "version");
    if (version) { 
    if(!mazu_cJSON_IsString(version) && !mazu_cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1_resource_attributes_local_var = v1_resource_attributes_create (
        field_selector ? field_selector_local_nonprim : NULL,
        group && !mazu_cJSON_IsNull(group) ? strdup(group->valuestring) : NULL,
        label_selector ? label_selector_local_nonprim : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        resource && !mazu_cJSON_IsNull(resource) ? strdup(resource->valuestring) : NULL,
        subresource && !mazu_cJSON_IsNull(subresource) ? strdup(subresource->valuestring) : NULL,
        verb && !mazu_cJSON_IsNull(verb) ? strdup(verb->valuestring) : NULL,
        version && !mazu_cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1_resource_attributes_local_var;
end:
    if (field_selector_local_nonprim) {
        v1_field_selector_attributes_free(field_selector_local_nonprim);
        field_selector_local_nonprim = NULL;
    }
    if (label_selector_local_nonprim) {
        v1_label_selector_attributes_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    return NULL;

}
