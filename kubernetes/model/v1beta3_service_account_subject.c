#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_service_account_subject.h"



v1beta3_service_account_subject_t *v1beta3_service_account_subject_create(
    char *name,
    char *_namespace
    ) {
    v1beta3_service_account_subject_t *v1beta3_service_account_subject_local_var = malloc(sizeof(v1beta3_service_account_subject_t));
    if (!v1beta3_service_account_subject_local_var) {
        return NULL;
    }
    v1beta3_service_account_subject_local_var->name = name;
    v1beta3_service_account_subject_local_var->_namespace = _namespace;

    return v1beta3_service_account_subject_local_var;
}


void v1beta3_service_account_subject_free(v1beta3_service_account_subject_t *v1beta3_service_account_subject) {
    if(NULL == v1beta3_service_account_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_service_account_subject->name) {
        free(v1beta3_service_account_subject->name);
        v1beta3_service_account_subject->name = NULL;
    }
    if (v1beta3_service_account_subject->_namespace) {
        free(v1beta3_service_account_subject->_namespace);
        v1beta3_service_account_subject->_namespace = NULL;
    }
    free(v1beta3_service_account_subject);
}

mazu_cJSON *v1beta3_service_account_subject_convertToJSON(v1beta3_service_account_subject_t *v1beta3_service_account_subject) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta3_service_account_subject->name
    if (!v1beta3_service_account_subject->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1beta3_service_account_subject->name) == NULL) {
    goto fail; //String
    }


    // v1beta3_service_account_subject->_namespace
    if (!v1beta3_service_account_subject->_namespace) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1beta3_service_account_subject->_namespace) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1beta3_service_account_subject_t *v1beta3_service_account_subject_parseFromJSON(mazu_cJSON *v1beta3_service_account_subjectJSON){

    v1beta3_service_account_subject_t *v1beta3_service_account_subject_local_var = NULL;

    // v1beta3_service_account_subject->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_service_account_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1beta3_service_account_subject->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_service_account_subjectJSON, "namespace");
    if (!_namespace) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(_namespace))
    {
    goto end; //String
    }


    v1beta3_service_account_subject_local_var = v1beta3_service_account_subject_create (
        strdup(name->valuestring),
        strdup(_namespace->valuestring)
        );

    return v1beta3_service_account_subject_local_var;
end:
    return NULL;

}
