#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_service_status.h"



v1_api_service_status_t *v1_api_service_status_create(
    list_t *conditions
    ) {
    v1_api_service_status_t *v1_api_service_status_local_var = malloc(sizeof(v1_api_service_status_t));
    if (!v1_api_service_status_local_var) {
        return NULL;
    }
    v1_api_service_status_local_var->conditions = conditions;

    return v1_api_service_status_local_var;
}


void v1_api_service_status_free(v1_api_service_status_t *v1_api_service_status) {
    if(NULL == v1_api_service_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_service_status->conditions) {
        list_ForEach(listEntry, v1_api_service_status->conditions) {
            v1_api_service_condition_free(listEntry->data);
        }
        list_freeList(v1_api_service_status->conditions);
        v1_api_service_status->conditions = NULL;
    }
    free(v1_api_service_status);
}

mazu_cJSON *v1_api_service_status_convertToJSON(v1_api_service_status_t *v1_api_service_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_api_service_status->conditions
    if(v1_api_service_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_api_service_status->conditions) {
    list_ForEach(conditionsListEntry, v1_api_service_status->conditions) {
    mazu_cJSON *itemLocal = v1_api_service_condition_convertToJSON(conditionsListEntry->data);
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

v1_api_service_status_t *v1_api_service_status_parseFromJSON(mazu_cJSON *v1_api_service_statusJSON){

    v1_api_service_status_t *v1_api_service_status_local_var = NULL;

    // define the local list for v1_api_service_status->conditions
    list_t *conditionsList = NULL;

    // v1_api_service_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_service_statusJSON, "conditions");
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
        v1_api_service_condition_t *conditionsItem = v1_api_service_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    v1_api_service_status_local_var = v1_api_service_status_create (
        conditions ? conditionsList : NULL
        );

    return v1_api_service_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_api_service_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
