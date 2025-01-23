#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set_status.h"



v1_replica_set_status_t *v1_replica_set_status_create(
    int available_replicas,
    list_t *conditions,
    int fully_labeled_replicas,
    long observed_generation,
    int ready_replicas,
    int replicas
    ) {
    v1_replica_set_status_t *v1_replica_set_status_local_var = malloc(sizeof(v1_replica_set_status_t));
    if (!v1_replica_set_status_local_var) {
        return NULL;
    }
    v1_replica_set_status_local_var->available_replicas = available_replicas;
    v1_replica_set_status_local_var->conditions = conditions;
    v1_replica_set_status_local_var->fully_labeled_replicas = fully_labeled_replicas;
    v1_replica_set_status_local_var->observed_generation = observed_generation;
    v1_replica_set_status_local_var->ready_replicas = ready_replicas;
    v1_replica_set_status_local_var->replicas = replicas;

    return v1_replica_set_status_local_var;
}


void v1_replica_set_status_free(v1_replica_set_status_t *v1_replica_set_status) {
    if(NULL == v1_replica_set_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_replica_set_status->conditions) {
        list_ForEach(listEntry, v1_replica_set_status->conditions) {
            v1_replica_set_condition_free(listEntry->data);
        }
        list_freeList(v1_replica_set_status->conditions);
        v1_replica_set_status->conditions = NULL;
    }
    free(v1_replica_set_status);
}

mazu_cJSON *v1_replica_set_status_convertToJSON(v1_replica_set_status_t *v1_replica_set_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_replica_set_status->available_replicas
    if(v1_replica_set_status->available_replicas) {
    if(mazu_cJSON_AddNumberToObject(item, "availableReplicas", v1_replica_set_status->available_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->conditions
    if(v1_replica_set_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_replica_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_replica_set_status->conditions) {
    mazu_cJSON *itemLocal = v1_replica_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_replica_set_status->fully_labeled_replicas
    if(v1_replica_set_status->fully_labeled_replicas) {
    if(mazu_cJSON_AddNumberToObject(item, "fullyLabeledReplicas", v1_replica_set_status->fully_labeled_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->observed_generation
    if(v1_replica_set_status->observed_generation) {
    if(mazu_cJSON_AddNumberToObject(item, "observedGeneration", v1_replica_set_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->ready_replicas
    if(v1_replica_set_status->ready_replicas) {
    if(mazu_cJSON_AddNumberToObject(item, "readyReplicas", v1_replica_set_status->ready_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_replica_set_status->replicas
    if (!v1_replica_set_status->replicas) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "replicas", v1_replica_set_status->replicas) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_replica_set_status_t *v1_replica_set_status_parseFromJSON(mazu_cJSON *v1_replica_set_statusJSON){

    v1_replica_set_status_t *v1_replica_set_status_local_var = NULL;

    // define the local list for v1_replica_set_status->conditions
    list_t *conditionsList = NULL;

    // v1_replica_set_status->available_replicas
    mazu_cJSON *available_replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "availableReplicas");
    if (available_replicas) { 
    if(!mazu_cJSON_IsNumber(available_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "conditions");
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
        v1_replica_set_condition_t *conditionsItem = v1_replica_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_replica_set_status->fully_labeled_replicas
    mazu_cJSON *fully_labeled_replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "fullyLabeledReplicas");
    if (fully_labeled_replicas) { 
    if(!mazu_cJSON_IsNumber(fully_labeled_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->observed_generation
    mazu_cJSON *observed_generation = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!mazu_cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->ready_replicas
    mazu_cJSON *ready_replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "readyReplicas");
    if (ready_replicas) { 
    if(!mazu_cJSON_IsNumber(ready_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->replicas
    mazu_cJSON *replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }


    v1_replica_set_status_local_var = v1_replica_set_status_create (
        available_replicas ? available_replicas->valuedouble : 0,
        conditions ? conditionsList : NULL,
        fully_labeled_replicas ? fully_labeled_replicas->valuedouble : 0,
        observed_generation ? observed_generation->valuedouble : 0,
        ready_replicas ? ready_replicas->valuedouble : 0,
        replicas->valuedouble
        );

    return v1_replica_set_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_replica_set_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    return NULL;

}
