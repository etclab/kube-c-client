#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_subject.h"



v1beta3_subject_t *v1beta3_subject_create(
    v1beta3_group_subject_t *group,
    char *kind,
    v1beta3_service_account_subject_t *service_account,
    v1beta3_user_subject_t *user
    ) {
    v1beta3_subject_t *v1beta3_subject_local_var = malloc(sizeof(v1beta3_subject_t));
    if (!v1beta3_subject_local_var) {
        return NULL;
    }
    v1beta3_subject_local_var->group = group;
    v1beta3_subject_local_var->kind = kind;
    v1beta3_subject_local_var->service_account = service_account;
    v1beta3_subject_local_var->user = user;

    return v1beta3_subject_local_var;
}


void v1beta3_subject_free(v1beta3_subject_t *v1beta3_subject) {
    if(NULL == v1beta3_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_subject->group) {
        v1beta3_group_subject_free(v1beta3_subject->group);
        v1beta3_subject->group = NULL;
    }
    if (v1beta3_subject->kind) {
        free(v1beta3_subject->kind);
        v1beta3_subject->kind = NULL;
    }
    if (v1beta3_subject->service_account) {
        v1beta3_service_account_subject_free(v1beta3_subject->service_account);
        v1beta3_subject->service_account = NULL;
    }
    if (v1beta3_subject->user) {
        v1beta3_user_subject_free(v1beta3_subject->user);
        v1beta3_subject->user = NULL;
    }
    free(v1beta3_subject);
}

mazu_cJSON *v1beta3_subject_convertToJSON(v1beta3_subject_t *v1beta3_subject) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta3_subject->group
    if(v1beta3_subject->group) {
    mazu_cJSON *group_local_JSON = v1beta3_group_subject_convertToJSON(v1beta3_subject->group);
    if(group_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "group", group_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta3_subject->kind
    if (!v1beta3_subject->kind) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kind", v1beta3_subject->kind) == NULL) {
    goto fail; //String
    }


    // v1beta3_subject->service_account
    if(v1beta3_subject->service_account) {
    mazu_cJSON *service_account_local_JSON = v1beta3_service_account_subject_convertToJSON(v1beta3_subject->service_account);
    if(service_account_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "serviceAccount", service_account_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta3_subject->user
    if(v1beta3_subject->user) {
    mazu_cJSON *user_local_JSON = v1beta3_user_subject_convertToJSON(v1beta3_subject->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "user", user_local_JSON);
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

v1beta3_subject_t *v1beta3_subject_parseFromJSON(mazu_cJSON *v1beta3_subjectJSON){

    v1beta3_subject_t *v1beta3_subject_local_var = NULL;

    // define the local variable for v1beta3_subject->group
    v1beta3_group_subject_t *group_local_nonprim = NULL;

    // define the local variable for v1beta3_subject->service_account
    v1beta3_service_account_subject_t *service_account_local_nonprim = NULL;

    // define the local variable for v1beta3_subject->user
    v1beta3_user_subject_t *user_local_nonprim = NULL;

    // v1beta3_subject->group
    mazu_cJSON *group = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_subjectJSON, "group");
    if (group) { 
    group_local_nonprim = v1beta3_group_subject_parseFromJSON(group); //nonprimitive
    }

    // v1beta3_subject->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1beta3_subject->service_account
    mazu_cJSON *service_account = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_subjectJSON, "serviceAccount");
    if (service_account) { 
    service_account_local_nonprim = v1beta3_service_account_subject_parseFromJSON(service_account); //nonprimitive
    }

    // v1beta3_subject->user
    mazu_cJSON *user = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_subjectJSON, "user");
    if (user) { 
    user_local_nonprim = v1beta3_user_subject_parseFromJSON(user); //nonprimitive
    }


    v1beta3_subject_local_var = v1beta3_subject_create (
        group ? group_local_nonprim : NULL,
        strdup(kind->valuestring),
        service_account ? service_account_local_nonprim : NULL,
        user ? user_local_nonprim : NULL
        );

    return v1beta3_subject_local_var;
end:
    if (group_local_nonprim) {
        v1beta3_group_subject_free(group_local_nonprim);
        group_local_nonprim = NULL;
    }
    if (service_account_local_nonprim) {
        v1beta3_service_account_subject_free(service_account_local_nonprim);
        service_account_local_nonprim = NULL;
    }
    if (user_local_nonprim) {
        v1beta3_user_subject_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
