#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_priority_class.h"



v1_priority_class_t *v1_priority_class_create(
    char *api_version,
    char *description,
    int global_default,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemption_policy,
    int value
    ) {
    v1_priority_class_t *v1_priority_class_local_var = malloc(sizeof(v1_priority_class_t));
    if (!v1_priority_class_local_var) {
        return NULL;
    }
    v1_priority_class_local_var->api_version = api_version;
    v1_priority_class_local_var->description = description;
    v1_priority_class_local_var->global_default = global_default;
    v1_priority_class_local_var->kind = kind;
    v1_priority_class_local_var->metadata = metadata;
    v1_priority_class_local_var->preemption_policy = preemption_policy;
    v1_priority_class_local_var->value = value;

    return v1_priority_class_local_var;
}


void v1_priority_class_free(v1_priority_class_t *v1_priority_class) {
    if(NULL == v1_priority_class){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_priority_class->api_version) {
        free(v1_priority_class->api_version);
        v1_priority_class->api_version = NULL;
    }
    if (v1_priority_class->description) {
        free(v1_priority_class->description);
        v1_priority_class->description = NULL;
    }
    if (v1_priority_class->kind) {
        free(v1_priority_class->kind);
        v1_priority_class->kind = NULL;
    }
    if (v1_priority_class->metadata) {
        v1_object_meta_free(v1_priority_class->metadata);
        v1_priority_class->metadata = NULL;
    }
    if (v1_priority_class->preemption_policy) {
        free(v1_priority_class->preemption_policy);
        v1_priority_class->preemption_policy = NULL;
    }
    free(v1_priority_class);
}

mazu_cJSON *v1_priority_class_convertToJSON(v1_priority_class_t *v1_priority_class) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_priority_class->api_version
    if(v1_priority_class->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_priority_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->description
    if(v1_priority_class->description) {
    if(mazu_cJSON_AddStringToObject(item, "description", v1_priority_class->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->global_default
    if(v1_priority_class->global_default) {
    if(mazu_cJSON_AddBoolToObject(item, "globalDefault", v1_priority_class->global_default) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_priority_class->kind
    if(v1_priority_class->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_priority_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->metadata
    if(v1_priority_class->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_priority_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_priority_class->preemption_policy
    if(v1_priority_class->preemption_policy) {
    if(mazu_cJSON_AddStringToObject(item, "preemptionPolicy", v1_priority_class->preemption_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->value
    if (!v1_priority_class->value) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "value", v1_priority_class->value) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_priority_class_t *v1_priority_class_parseFromJSON(mazu_cJSON *v1_priority_classJSON){

    v1_priority_class_t *v1_priority_class_local_var = NULL;

    // define the local variable for v1_priority_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1_priority_class->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_priority_class->description
    mazu_cJSON *description = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "description");
    if (description) { 
    if(!mazu_cJSON_IsString(description) && !mazu_cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_priority_class->global_default
    mazu_cJSON *global_default = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "globalDefault");
    if (global_default) { 
    if(!mazu_cJSON_IsBool(global_default))
    {
    goto end; //Bool
    }
    }

    // v1_priority_class->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_priority_class->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_priority_class->preemption_policy
    mazu_cJSON *preemption_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "preemptionPolicy");
    if (preemption_policy) { 
    if(!mazu_cJSON_IsString(preemption_policy) && !mazu_cJSON_IsNull(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1_priority_class->value
    mazu_cJSON *value = mazu_cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "value");
    if (!value) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }


    v1_priority_class_local_var = v1_priority_class_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        description && !mazu_cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        global_default ? global_default->valueint : 0,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        preemption_policy && !mazu_cJSON_IsNull(preemption_policy) ? strdup(preemption_policy->valuestring) : NULL,
        value->valuedouble
        );

    return v1_priority_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
