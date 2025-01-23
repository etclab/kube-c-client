#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_status.h"



v1_job_status_t *v1_job_status_create(
    int active,
    char *completed_indexes,
    char *completion_time,
    list_t *conditions,
    int failed,
    char *failed_indexes,
    int ready,
    char *start_time,
    int succeeded,
    int terminating,
    v1_uncounted_terminated_pods_t *uncounted_terminated_pods
    ) {
    v1_job_status_t *v1_job_status_local_var = malloc(sizeof(v1_job_status_t));
    if (!v1_job_status_local_var) {
        return NULL;
    }
    v1_job_status_local_var->active = active;
    v1_job_status_local_var->completed_indexes = completed_indexes;
    v1_job_status_local_var->completion_time = completion_time;
    v1_job_status_local_var->conditions = conditions;
    v1_job_status_local_var->failed = failed;
    v1_job_status_local_var->failed_indexes = failed_indexes;
    v1_job_status_local_var->ready = ready;
    v1_job_status_local_var->start_time = start_time;
    v1_job_status_local_var->succeeded = succeeded;
    v1_job_status_local_var->terminating = terminating;
    v1_job_status_local_var->uncounted_terminated_pods = uncounted_terminated_pods;

    return v1_job_status_local_var;
}


void v1_job_status_free(v1_job_status_t *v1_job_status) {
    if(NULL == v1_job_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_job_status->completed_indexes) {
        free(v1_job_status->completed_indexes);
        v1_job_status->completed_indexes = NULL;
    }
    if (v1_job_status->completion_time) {
        free(v1_job_status->completion_time);
        v1_job_status->completion_time = NULL;
    }
    if (v1_job_status->conditions) {
        list_ForEach(listEntry, v1_job_status->conditions) {
            v1_job_condition_free(listEntry->data);
        }
        list_freeList(v1_job_status->conditions);
        v1_job_status->conditions = NULL;
    }
    if (v1_job_status->failed_indexes) {
        free(v1_job_status->failed_indexes);
        v1_job_status->failed_indexes = NULL;
    }
    if (v1_job_status->start_time) {
        free(v1_job_status->start_time);
        v1_job_status->start_time = NULL;
    }
    if (v1_job_status->uncounted_terminated_pods) {
        v1_uncounted_terminated_pods_free(v1_job_status->uncounted_terminated_pods);
        v1_job_status->uncounted_terminated_pods = NULL;
    }
    free(v1_job_status);
}

mazu_cJSON *v1_job_status_convertToJSON(v1_job_status_t *v1_job_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_job_status->active
    if(v1_job_status->active) {
    if(mazu_cJSON_AddNumberToObject(item, "active", v1_job_status->active) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->completed_indexes
    if(v1_job_status->completed_indexes) {
    if(mazu_cJSON_AddStringToObject(item, "completedIndexes", v1_job_status->completed_indexes) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_status->completion_time
    if(v1_job_status->completion_time) {
    if(mazu_cJSON_AddStringToObject(item, "completionTime", v1_job_status->completion_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_job_status->conditions
    if(v1_job_status->conditions) {
    mazu_cJSON *conditions = mazu_cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_job_status->conditions) {
    list_ForEach(conditionsListEntry, v1_job_status->conditions) {
    mazu_cJSON *itemLocal = v1_job_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_job_status->failed
    if(v1_job_status->failed) {
    if(mazu_cJSON_AddNumberToObject(item, "failed", v1_job_status->failed) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->failed_indexes
    if(v1_job_status->failed_indexes) {
    if(mazu_cJSON_AddStringToObject(item, "failedIndexes", v1_job_status->failed_indexes) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_status->ready
    if(v1_job_status->ready) {
    if(mazu_cJSON_AddNumberToObject(item, "ready", v1_job_status->ready) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->start_time
    if(v1_job_status->start_time) {
    if(mazu_cJSON_AddStringToObject(item, "startTime", v1_job_status->start_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_job_status->succeeded
    if(v1_job_status->succeeded) {
    if(mazu_cJSON_AddNumberToObject(item, "succeeded", v1_job_status->succeeded) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->terminating
    if(v1_job_status->terminating) {
    if(mazu_cJSON_AddNumberToObject(item, "terminating", v1_job_status->terminating) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_status->uncounted_terminated_pods
    if(v1_job_status->uncounted_terminated_pods) {
    mazu_cJSON *uncounted_terminated_pods_local_JSON = v1_uncounted_terminated_pods_convertToJSON(v1_job_status->uncounted_terminated_pods);
    if(uncounted_terminated_pods_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "uncountedTerminatedPods", uncounted_terminated_pods_local_JSON);
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

v1_job_status_t *v1_job_status_parseFromJSON(mazu_cJSON *v1_job_statusJSON){

    v1_job_status_t *v1_job_status_local_var = NULL;

    // define the local list for v1_job_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_job_status->uncounted_terminated_pods
    v1_uncounted_terminated_pods_t *uncounted_terminated_pods_local_nonprim = NULL;

    // v1_job_status->active
    mazu_cJSON *active = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "active");
    if (active) { 
    if(!mazu_cJSON_IsNumber(active))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->completed_indexes
    mazu_cJSON *completed_indexes = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "completedIndexes");
    if (completed_indexes) { 
    if(!mazu_cJSON_IsString(completed_indexes) && !mazu_cJSON_IsNull(completed_indexes))
    {
    goto end; //String
    }
    }

    // v1_job_status->completion_time
    mazu_cJSON *completion_time = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "completionTime");
    if (completion_time) { 
    if(!mazu_cJSON_IsString(completion_time) && !mazu_cJSON_IsNull(completion_time))
    {
    goto end; //DateTime
    }
    }

    // v1_job_status->conditions
    mazu_cJSON *conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "conditions");
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
        v1_job_condition_t *conditionsItem = v1_job_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_job_status->failed
    mazu_cJSON *failed = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "failed");
    if (failed) { 
    if(!mazu_cJSON_IsNumber(failed))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->failed_indexes
    mazu_cJSON *failed_indexes = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "failedIndexes");
    if (failed_indexes) { 
    if(!mazu_cJSON_IsString(failed_indexes) && !mazu_cJSON_IsNull(failed_indexes))
    {
    goto end; //String
    }
    }

    // v1_job_status->ready
    mazu_cJSON *ready = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "ready");
    if (ready) { 
    if(!mazu_cJSON_IsNumber(ready))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->start_time
    mazu_cJSON *start_time = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "startTime");
    if (start_time) { 
    if(!mazu_cJSON_IsString(start_time) && !mazu_cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }
    }

    // v1_job_status->succeeded
    mazu_cJSON *succeeded = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "succeeded");
    if (succeeded) { 
    if(!mazu_cJSON_IsNumber(succeeded))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->terminating
    mazu_cJSON *terminating = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "terminating");
    if (terminating) { 
    if(!mazu_cJSON_IsNumber(terminating))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->uncounted_terminated_pods
    mazu_cJSON *uncounted_terminated_pods = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "uncountedTerminatedPods");
    if (uncounted_terminated_pods) { 
    uncounted_terminated_pods_local_nonprim = v1_uncounted_terminated_pods_parseFromJSON(uncounted_terminated_pods); //nonprimitive
    }


    v1_job_status_local_var = v1_job_status_create (
        active ? active->valuedouble : 0,
        completed_indexes && !mazu_cJSON_IsNull(completed_indexes) ? strdup(completed_indexes->valuestring) : NULL,
        completion_time && !mazu_cJSON_IsNull(completion_time) ? strdup(completion_time->valuestring) : NULL,
        conditions ? conditionsList : NULL,
        failed ? failed->valuedouble : 0,
        failed_indexes && !mazu_cJSON_IsNull(failed_indexes) ? strdup(failed_indexes->valuestring) : NULL,
        ready ? ready->valuedouble : 0,
        start_time && !mazu_cJSON_IsNull(start_time) ? strdup(start_time->valuestring) : NULL,
        succeeded ? succeeded->valuedouble : 0,
        terminating ? terminating->valuedouble : 0,
        uncounted_terminated_pods ? uncounted_terminated_pods_local_nonprim : NULL
        );

    return v1_job_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_job_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (uncounted_terminated_pods_local_nonprim) {
        v1_uncounted_terminated_pods_free(uncounted_terminated_pods_local_nonprim);
        uncounted_terminated_pods_local_nonprim = NULL;
    }
    return NULL;

}
