#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_certificate_signing_request_status.h"



v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_create(
    char *certificate,
    list_t *conditions
    ) {
    v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_local_var = malloc(sizeof(v1_certificate_signing_request_status_t));
    if (!v1_certificate_signing_request_status_local_var) {
        return NULL;
    }
    v1_certificate_signing_request_status_local_var->certificate = certificate;
    v1_certificate_signing_request_status_local_var->conditions = conditions;

    return v1_certificate_signing_request_status_local_var;
}


void v1_certificate_signing_request_status_free(v1_certificate_signing_request_status_t *v1_certificate_signing_request_status) {
    if(NULL == v1_certificate_signing_request_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_certificate_signing_request_status->certificate) {
        free(v1_certificate_signing_request_status->certificate);
        v1_certificate_signing_request_status->certificate = NULL;
    }
    if (v1_certificate_signing_request_status->conditions) {
        list_ForEach(listEntry, v1_certificate_signing_request_status->conditions) {
            v1_certificate_signing_request_condition_free(listEntry->data);
        }
        list_freeList(v1_certificate_signing_request_status->conditions);
        v1_certificate_signing_request_status->conditions = NULL;
    }
    free(v1_certificate_signing_request_status);
}

mazu_cJSON *v1_certificate_signing_request_status_convertToJSON(v1_certificate_signing_request_status_t *v1_certificate_signing_request_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_certificate_signing_request_status->certificate
    if(v1_certificate_signing_request_status->certificate) {
    if(mazu_cJSON_AddStringToObject(item, "certificate", v1_certificate_signing_request_status->certificate) == NULL) {
    goto fail; //ByteArray
    }
    }


    // v1_certificate_signing_request_status->conditions
    if(v1_certificate_signing_request_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_certificate_signing_request_status->conditions) {
    list_ForEach(conditionsListEntry, v1_certificate_signing_request_status->conditions) {
    mazu_cJSON *itemLocal = v1_certificate_signing_request_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_parseFromJSON(mazu_cJSON *v1_certificate_signing_request_statusJSON){

    v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_local_var = NULL;

    // define the local list for v1_certificate_signing_request_status->conditions
    list_t *conditionsList = NULL;

    // v1_certificate_signing_request_status->certificate
    mazu_cJSON *certificate = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_statusJSON, "certificate");
    if (certificate) { 
    if(!mazu_cJSON_IsString(certificate))
    {
    goto end; //ByteArray
    }
    }

    // v1_certificate_signing_request_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_statusJSON, "conditions");
    if (conditions) { 
    mazu_cJSON *conditions_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    mazu_cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!mazu_cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_certificate_signing_request_condition_t *conditionsItem = v1_certificate_signing_request_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    v1_certificate_signing_request_status_local_var = v1_certificate_signing_request_status_create (
        certificate ? strdup(certificate->valuestring) : NULL,
        conditions ? conditionsList : NULL
        );

    return v1_certificate_signing_request_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_certificate_signing_request_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
