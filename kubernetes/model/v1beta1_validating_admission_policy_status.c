#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_validating_admission_policy_status.h"



v1beta1_validating_admission_policy_status_t *v1beta1_validating_admission_policy_status_create(
    list_t *conditions,
    long observed_generation,
    v1beta1_type_checking_t *type_checking
    ) {
    v1beta1_validating_admission_policy_status_t *v1beta1_validating_admission_policy_status_local_var = malloc(sizeof(v1beta1_validating_admission_policy_status_t));
    if (!v1beta1_validating_admission_policy_status_local_var) {
        return NULL;
    }
    v1beta1_validating_admission_policy_status_local_var->conditions = conditions;
    v1beta1_validating_admission_policy_status_local_var->observed_generation = observed_generation;
    v1beta1_validating_admission_policy_status_local_var->type_checking = type_checking;

    return v1beta1_validating_admission_policy_status_local_var;
}


void v1beta1_validating_admission_policy_status_free(v1beta1_validating_admission_policy_status_t *v1beta1_validating_admission_policy_status) {
    if(NULL == v1beta1_validating_admission_policy_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_validating_admission_policy_status->conditions) {
        list_ForEach(listEntry, v1beta1_validating_admission_policy_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1beta1_validating_admission_policy_status->conditions);
        v1beta1_validating_admission_policy_status->conditions = NULL;
    }
    if (v1beta1_validating_admission_policy_status->type_checking) {
        v1beta1_type_checking_free(v1beta1_validating_admission_policy_status->type_checking);
        v1beta1_validating_admission_policy_status->type_checking = NULL;
    }
    free(v1beta1_validating_admission_policy_status);
}

mazu_cJSON *v1beta1_validating_admission_policy_status_convertToJSON(v1beta1_validating_admission_policy_status_t *v1beta1_validating_admission_policy_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta1_validating_admission_policy_status->conditions
    if(v1beta1_validating_admission_policy_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta1_validating_admission_policy_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta1_validating_admission_policy_status->conditions) {
    mazu_cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1beta1_validating_admission_policy_status->observed_generation
    if(v1beta1_validating_admission_policy_status->observed_generation) {
    if(mazu_cJSON_AddNumberToObject(item, "observedGeneration", v1beta1_validating_admission_policy_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1beta1_validating_admission_policy_status->type_checking
    if(v1beta1_validating_admission_policy_status->type_checking) {
    mazu_cJSON *type_checking_local_JSON = v1beta1_type_checking_convertToJSON(v1beta1_validating_admission_policy_status->type_checking);
    if(type_checking_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "typeChecking", type_checking_local_JSON);
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

v1beta1_validating_admission_policy_status_t *v1beta1_validating_admission_policy_status_parseFromJSON(mazu_cJSON *v1beta1_validating_admission_policy_statusJSON){

    v1beta1_validating_admission_policy_status_t *v1beta1_validating_admission_policy_status_local_var = NULL;

    // define the local list for v1beta1_validating_admission_policy_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1beta1_validating_admission_policy_status->type_checking
    v1beta1_type_checking_t *type_checking_local_nonprim = NULL;

    // v1beta1_validating_admission_policy_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policy_statusJSON, "conditions");
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
        v1_condition_t *conditionsItem = v1_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta1_validating_admission_policy_status->observed_generation
    mazu_cJSON *observed_generation = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policy_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!mazu_cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_validating_admission_policy_status->type_checking
    mazu_cJSON *type_checking = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_validating_admission_policy_statusJSON, "typeChecking");
    if (type_checking) { 
    type_checking_local_nonprim = v1beta1_type_checking_parseFromJSON(type_checking); //nonprimitive
    }


    v1beta1_validating_admission_policy_status_local_var = v1beta1_validating_admission_policy_status_create (
        conditions ? conditionsList : NULL,
        observed_generation ? observed_generation->valuedouble : 0,
        type_checking ? type_checking_local_nonprim : NULL
        );

    return v1beta1_validating_admission_policy_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (type_checking_local_nonprim) {
        v1beta1_type_checking_free(type_checking_local_nonprim);
        type_checking_local_nonprim = NULL;
    }
    return NULL;

}
