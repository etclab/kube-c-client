#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_owner_reference.h"



v1_owner_reference_t *v1_owner_reference_create(
    char *api_version,
    int block_owner_deletion,
    int controller,
    char *kind,
    char *name,
    char *uid
    ) {
    v1_owner_reference_t *v1_owner_reference_local_var = malloc(sizeof(v1_owner_reference_t));
    if (!v1_owner_reference_local_var) {
        return NULL;
    }
    v1_owner_reference_local_var->api_version = api_version;
    v1_owner_reference_local_var->block_owner_deletion = block_owner_deletion;
    v1_owner_reference_local_var->controller = controller;
    v1_owner_reference_local_var->kind = kind;
    v1_owner_reference_local_var->name = name;
    v1_owner_reference_local_var->uid = uid;

    return v1_owner_reference_local_var;
}


void v1_owner_reference_free(v1_owner_reference_t *v1_owner_reference) {
    if(NULL == v1_owner_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_owner_reference->api_version) {
        free(v1_owner_reference->api_version);
        v1_owner_reference->api_version = NULL;
    }
    if (v1_owner_reference->kind) {
        free(v1_owner_reference->kind);
        v1_owner_reference->kind = NULL;
    }
    if (v1_owner_reference->name) {
        free(v1_owner_reference->name);
        v1_owner_reference->name = NULL;
    }
    if (v1_owner_reference->uid) {
        free(v1_owner_reference->uid);
        v1_owner_reference->uid = NULL;
    }
    free(v1_owner_reference);
}

mazu_cJSON *v1_owner_reference_convertToJSON(v1_owner_reference_t *v1_owner_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_owner_reference->api_version
    if (!v1_owner_reference->api_version) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_owner_reference->api_version) == NULL) {
    goto fail; //String
    }


    // v1_owner_reference->block_owner_deletion
    if(v1_owner_reference->block_owner_deletion) {
    if(mazu_cJSON_AddBoolToObject(item, "blockOwnerDeletion", v1_owner_reference->block_owner_deletion) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_owner_reference->controller
    if(v1_owner_reference->controller) {
    if(mazu_cJSON_AddBoolToObject(item, "controller", v1_owner_reference->controller) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_owner_reference->kind
    if (!v1_owner_reference->kind) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_owner_reference->kind) == NULL) {
    goto fail; //String
    }


    // v1_owner_reference->name
    if (!v1_owner_reference->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_owner_reference->name) == NULL) {
    goto fail; //String
    }


    // v1_owner_reference->uid
    if (!v1_owner_reference->uid) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_owner_reference->uid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_owner_reference_t *v1_owner_reference_parseFromJSON(mazu_cJSON *v1_owner_referenceJSON){

    v1_owner_reference_t *v1_owner_reference_local_var = NULL;

    // v1_owner_reference->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "apiVersion");
    if (!api_version) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(api_version))
    {
    goto end; //String
    }

    // v1_owner_reference->block_owner_deletion
    mazu_cJSON *block_owner_deletion = mazu_cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "blockOwnerDeletion");
    if (block_owner_deletion) { 
    if(!mazu_cJSON_IsBool(block_owner_deletion))
    {
    goto end; //Bool
    }
    }

    // v1_owner_reference->controller
    mazu_cJSON *controller = mazu_cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "controller");
    if (controller) { 
    if(!mazu_cJSON_IsBool(controller))
    {
    goto end; //Bool
    }
    }

    // v1_owner_reference->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_owner_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_owner_reference->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "uid");
    if (!uid) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(uid))
    {
    goto end; //String
    }


    v1_owner_reference_local_var = v1_owner_reference_create (
        strdup(api_version->valuestring),
        block_owner_deletion ? block_owner_deletion->valueint : 0,
        controller ? controller->valueint : 0,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        strdup(uid->valuestring)
        );

    return v1_owner_reference_local_var;
end:
    return NULL;

}
