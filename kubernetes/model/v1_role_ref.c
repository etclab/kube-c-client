#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_role_ref.h"



v1_role_ref_t *v1_role_ref_create(
    char *api_group,
    char *kind,
    char *name
    ) {
    v1_role_ref_t *v1_role_ref_local_var = malloc(sizeof(v1_role_ref_t));
    if (!v1_role_ref_local_var) {
        return NULL;
    }
    v1_role_ref_local_var->api_group = api_group;
    v1_role_ref_local_var->kind = kind;
    v1_role_ref_local_var->name = name;

    return v1_role_ref_local_var;
}


void v1_role_ref_free(v1_role_ref_t *v1_role_ref) {
    if(NULL == v1_role_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_role_ref->api_group) {
        free(v1_role_ref->api_group);
        v1_role_ref->api_group = NULL;
    }
    if (v1_role_ref->kind) {
        free(v1_role_ref->kind);
        v1_role_ref->kind = NULL;
    }
    if (v1_role_ref->name) {
        free(v1_role_ref->name);
        v1_role_ref->name = NULL;
    }
    free(v1_role_ref);
}

mazu_cJSON *v1_role_ref_convertToJSON(v1_role_ref_t *v1_role_ref) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_role_ref->api_group
    if (!v1_role_ref->api_group) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "apiGroup", v1_role_ref->api_group) == NULL) {
    goto fail; //String
    }


    // v1_role_ref->kind
    if (!v1_role_ref->kind) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_role_ref->kind) == NULL) {
    goto fail; //String
    }


    // v1_role_ref->name
    if (!v1_role_ref->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_role_ref->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_role_ref_t *v1_role_ref_parseFromJSON(mazu_cJSON *v1_role_refJSON){

    v1_role_ref_t *v1_role_ref_local_var = NULL;

    // v1_role_ref->api_group
    mazu_cJSON *api_group = mazu_cJSON_GetObjectItemCaseSensitive(v1_role_refJSON, "apiGroup");
    if (!api_group) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(api_group))
    {
    goto end; //String
    }

    // v1_role_ref->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_role_refJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_role_ref->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_role_refJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_role_ref_local_var = v1_role_ref_create (
        strdup(api_group->valuestring),
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1_role_ref_local_var;
end:
    return NULL;

}
