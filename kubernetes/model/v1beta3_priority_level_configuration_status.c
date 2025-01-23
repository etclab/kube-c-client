#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta3_priority_level_configuration_status.h"



v1beta3_priority_level_configuration_status_t *v1beta3_priority_level_configuration_status_create(
    list_t *conditions
    ) {
    v1beta3_priority_level_configuration_status_t *v1beta3_priority_level_configuration_status_local_var = malloc(sizeof(v1beta3_priority_level_configuration_status_t));
    if (!v1beta3_priority_level_configuration_status_local_var) {
        return NULL;
    }
    v1beta3_priority_level_configuration_status_local_var->conditions = conditions;

    return v1beta3_priority_level_configuration_status_local_var;
}


void v1beta3_priority_level_configuration_status_free(v1beta3_priority_level_configuration_status_t *v1beta3_priority_level_configuration_status) {
    if(NULL == v1beta3_priority_level_configuration_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta3_priority_level_configuration_status->conditions) {
        list_ForEach(listEntry, v1beta3_priority_level_configuration_status->conditions) {
            v1beta3_priority_level_configuration_condition_free(listEntry->data);
        }
        list_freeList(v1beta3_priority_level_configuration_status->conditions);
        v1beta3_priority_level_configuration_status->conditions = NULL;
    }
    free(v1beta3_priority_level_configuration_status);
}

mazu_cJSON *v1beta3_priority_level_configuration_status_convertToJSON(v1beta3_priority_level_configuration_status_t *v1beta3_priority_level_configuration_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta3_priority_level_configuration_status->conditions
    if(v1beta3_priority_level_configuration_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta3_priority_level_configuration_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta3_priority_level_configuration_status->conditions) {
    mazu_cJSON *itemLocal = v1beta3_priority_level_configuration_condition_convertToJSON(conditionsListEntry->data);
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

v1beta3_priority_level_configuration_status_t *v1beta3_priority_level_configuration_status_parseFromJSON(mazu_cJSON *v1beta3_priority_level_configuration_statusJSON){

    v1beta3_priority_level_configuration_status_t *v1beta3_priority_level_configuration_status_local_var = NULL;

    // define the local list for v1beta3_priority_level_configuration_status->conditions
    list_t *conditionsList = NULL;

    // v1beta3_priority_level_configuration_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1beta3_priority_level_configuration_statusJSON, "conditions");
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
        v1beta3_priority_level_configuration_condition_t *conditionsItem = v1beta3_priority_level_configuration_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }


    v1beta3_priority_level_configuration_status_local_var = v1beta3_priority_level_configuration_status_create (
        conditions ? conditionsList : NULL
        );

    return v1beta3_priority_level_configuration_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1beta3_priority_level_configuration_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
