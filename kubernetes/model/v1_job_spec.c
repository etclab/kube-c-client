#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_spec.h"



v1_job_spec_t *v1_job_spec_create(
    long active_deadline_seconds,
    int backoff_limit,
    int backoff_limit_per_index,
    char *completion_mode,
    int completions,
    char *managed_by,
    int manual_selector,
    int max_failed_indexes,
    int parallelism,
    v1_pod_failure_policy_t *pod_failure_policy,
    char *pod_replacement_policy,
    v1_label_selector_t *selector,
    v1_success_policy_t *success_policy,
    int suspend,
    v1_pod_template_spec_t *_template,
    int ttl_seconds_after_finished
    ) {
    v1_job_spec_t *v1_job_spec_local_var = malloc(sizeof(v1_job_spec_t));
    if (!v1_job_spec_local_var) {
        return NULL;
    }
    v1_job_spec_local_var->active_deadline_seconds = active_deadline_seconds;
    v1_job_spec_local_var->backoff_limit = backoff_limit;
    v1_job_spec_local_var->backoff_limit_per_index = backoff_limit_per_index;
    v1_job_spec_local_var->completion_mode = completion_mode;
    v1_job_spec_local_var->completions = completions;
    v1_job_spec_local_var->managed_by = managed_by;
    v1_job_spec_local_var->manual_selector = manual_selector;
    v1_job_spec_local_var->max_failed_indexes = max_failed_indexes;
    v1_job_spec_local_var->parallelism = parallelism;
    v1_job_spec_local_var->pod_failure_policy = pod_failure_policy;
    v1_job_spec_local_var->pod_replacement_policy = pod_replacement_policy;
    v1_job_spec_local_var->selector = selector;
    v1_job_spec_local_var->success_policy = success_policy;
    v1_job_spec_local_var->suspend = suspend;
    v1_job_spec_local_var->_template = _template;
    v1_job_spec_local_var->ttl_seconds_after_finished = ttl_seconds_after_finished;

    return v1_job_spec_local_var;
}


void v1_job_spec_free(v1_job_spec_t *v1_job_spec) {
    if(NULL == v1_job_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_job_spec->completion_mode) {
        free(v1_job_spec->completion_mode);
        v1_job_spec->completion_mode = NULL;
    }
    if (v1_job_spec->managed_by) {
        free(v1_job_spec->managed_by);
        v1_job_spec->managed_by = NULL;
    }
    if (v1_job_spec->pod_failure_policy) {
        v1_pod_failure_policy_free(v1_job_spec->pod_failure_policy);
        v1_job_spec->pod_failure_policy = NULL;
    }
    if (v1_job_spec->pod_replacement_policy) {
        free(v1_job_spec->pod_replacement_policy);
        v1_job_spec->pod_replacement_policy = NULL;
    }
    if (v1_job_spec->selector) {
        v1_label_selector_free(v1_job_spec->selector);
        v1_job_spec->selector = NULL;
    }
    if (v1_job_spec->success_policy) {
        v1_success_policy_free(v1_job_spec->success_policy);
        v1_job_spec->success_policy = NULL;
    }
    if (v1_job_spec->_template) {
        v1_pod_template_spec_free(v1_job_spec->_template);
        v1_job_spec->_template = NULL;
    }
    free(v1_job_spec);
}

mazu_cJSON *v1_job_spec_convertToJSON(v1_job_spec_t *v1_job_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_job_spec->active_deadline_seconds
    if(v1_job_spec->active_deadline_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "activeDeadlineSeconds", v1_job_spec->active_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->backoff_limit
    if(v1_job_spec->backoff_limit) {
    if(mazu_cJSON_AddNumberToObject(item, "backoffLimit", v1_job_spec->backoff_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->backoff_limit_per_index
    if(v1_job_spec->backoff_limit_per_index) {
    if(mazu_cJSON_AddNumberToObject(item, "backoffLimitPerIndex", v1_job_spec->backoff_limit_per_index) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->completion_mode
    if(v1_job_spec->completion_mode) {
    if(mazu_cJSON_AddStringToObject(item, "completionMode", v1_job_spec->completion_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_spec->completions
    if(v1_job_spec->completions) {
    if(mazu_cJSON_AddNumberToObject(item, "completions", v1_job_spec->completions) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->managed_by
    if(v1_job_spec->managed_by) {
    if(mazu_cJSON_AddStringToObject(item, "managedBy", v1_job_spec->managed_by) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_spec->manual_selector
    if(v1_job_spec->manual_selector) {
    if(mazu_cJSON_AddBoolToObject(item, "manualSelector", v1_job_spec->manual_selector) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_job_spec->max_failed_indexes
    if(v1_job_spec->max_failed_indexes) {
    if(mazu_cJSON_AddNumberToObject(item, "maxFailedIndexes", v1_job_spec->max_failed_indexes) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->parallelism
    if(v1_job_spec->parallelism) {
    if(mazu_cJSON_AddNumberToObject(item, "parallelism", v1_job_spec->parallelism) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_job_spec->pod_failure_policy
    if(v1_job_spec->pod_failure_policy) {
    mazu_cJSON *pod_failure_policy_local_JSON = v1_pod_failure_policy_convertToJSON(v1_job_spec->pod_failure_policy);
    if(pod_failure_policy_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "podFailurePolicy", pod_failure_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->pod_replacement_policy
    if(v1_job_spec->pod_replacement_policy) {
    if(mazu_cJSON_AddStringToObject(item, "podReplacementPolicy", v1_job_spec->pod_replacement_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_job_spec->selector
    if(v1_job_spec->selector) {
    mazu_cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_job_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->success_policy
    if(v1_job_spec->success_policy) {
    mazu_cJSON *success_policy_local_JSON = v1_success_policy_convertToJSON(v1_job_spec->success_policy);
    if(success_policy_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "successPolicy", success_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_job_spec->suspend
    if(v1_job_spec->suspend) {
    if(mazu_cJSON_AddBoolToObject(item, "suspend", v1_job_spec->suspend) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_job_spec->_template
    if (!v1_job_spec->_template) {
        goto fail;
    }
    mazu_cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_job_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_job_spec->ttl_seconds_after_finished
    if(v1_job_spec->ttl_seconds_after_finished) {
    if(mazu_cJSON_AddNumberToObject(item, "ttlSecondsAfterFinished", v1_job_spec->ttl_seconds_after_finished) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_job_spec_t *v1_job_spec_parseFromJSON(mazu_cJSON *v1_job_specJSON){

    v1_job_spec_t *v1_job_spec_local_var = NULL;

    // define the local variable for v1_job_spec->pod_failure_policy
    v1_pod_failure_policy_t *pod_failure_policy_local_nonprim = NULL;

    // define the local variable for v1_job_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // define the local variable for v1_job_spec->success_policy
    v1_success_policy_t *success_policy_local_nonprim = NULL;

    // define the local variable for v1_job_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_job_spec->active_deadline_seconds
    mazu_cJSON *active_deadline_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "activeDeadlineSeconds");
    if (active_deadline_seconds) { 
    if(!mazu_cJSON_IsNumber(active_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->backoff_limit
    mazu_cJSON *backoff_limit = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "backoffLimit");
    if (backoff_limit) { 
    if(!mazu_cJSON_IsNumber(backoff_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->backoff_limit_per_index
    mazu_cJSON *backoff_limit_per_index = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "backoffLimitPerIndex");
    if (backoff_limit_per_index) { 
    if(!mazu_cJSON_IsNumber(backoff_limit_per_index))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->completion_mode
    mazu_cJSON *completion_mode = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "completionMode");
    if (completion_mode) { 
    if(!mazu_cJSON_IsString(completion_mode) && !mazu_cJSON_IsNull(completion_mode))
    {
    goto end; //String
    }
    }

    // v1_job_spec->completions
    mazu_cJSON *completions = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "completions");
    if (completions) { 
    if(!mazu_cJSON_IsNumber(completions))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->managed_by
    mazu_cJSON *managed_by = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "managedBy");
    if (managed_by) { 
    if(!mazu_cJSON_IsString(managed_by) && !mazu_cJSON_IsNull(managed_by))
    {
    goto end; //String
    }
    }

    // v1_job_spec->manual_selector
    mazu_cJSON *manual_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "manualSelector");
    if (manual_selector) { 
    if(!mazu_cJSON_IsBool(manual_selector))
    {
    goto end; //Bool
    }
    }

    // v1_job_spec->max_failed_indexes
    mazu_cJSON *max_failed_indexes = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "maxFailedIndexes");
    if (max_failed_indexes) { 
    if(!mazu_cJSON_IsNumber(max_failed_indexes))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->parallelism
    mazu_cJSON *parallelism = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "parallelism");
    if (parallelism) { 
    if(!mazu_cJSON_IsNumber(parallelism))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->pod_failure_policy
    mazu_cJSON *pod_failure_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "podFailurePolicy");
    if (pod_failure_policy) { 
    pod_failure_policy_local_nonprim = v1_pod_failure_policy_parseFromJSON(pod_failure_policy); //nonprimitive
    }

    // v1_job_spec->pod_replacement_policy
    mazu_cJSON *pod_replacement_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "podReplacementPolicy");
    if (pod_replacement_policy) { 
    if(!mazu_cJSON_IsString(pod_replacement_policy) && !mazu_cJSON_IsNull(pod_replacement_policy))
    {
    goto end; //String
    }
    }

    // v1_job_spec->selector
    mazu_cJSON *selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "selector");
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1_job_spec->success_policy
    mazu_cJSON *success_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "successPolicy");
    if (success_policy) { 
    success_policy_local_nonprim = v1_success_policy_parseFromJSON(success_policy); //nonprimitive
    }

    // v1_job_spec->suspend
    mazu_cJSON *suspend = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "suspend");
    if (suspend) { 
    if(!mazu_cJSON_IsBool(suspend))
    {
    goto end; //Bool
    }
    }

    // v1_job_spec->_template
    mazu_cJSON *_template = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "template");
    if (!_template) {
        goto end;
    }

    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive

    // v1_job_spec->ttl_seconds_after_finished
    mazu_cJSON *ttl_seconds_after_finished = mazu_cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "ttlSecondsAfterFinished");
    if (ttl_seconds_after_finished) { 
    if(!mazu_cJSON_IsNumber(ttl_seconds_after_finished))
    {
    goto end; //Numeric
    }
    }


    v1_job_spec_local_var = v1_job_spec_create (
        active_deadline_seconds ? active_deadline_seconds->valuedouble : 0,
        backoff_limit ? backoff_limit->valuedouble : 0,
        backoff_limit_per_index ? backoff_limit_per_index->valuedouble : 0,
        completion_mode && !mazu_cJSON_IsNull(completion_mode) ? strdup(completion_mode->valuestring) : NULL,
        completions ? completions->valuedouble : 0,
        managed_by && !mazu_cJSON_IsNull(managed_by) ? strdup(managed_by->valuestring) : NULL,
        manual_selector ? manual_selector->valueint : 0,
        max_failed_indexes ? max_failed_indexes->valuedouble : 0,
        parallelism ? parallelism->valuedouble : 0,
        pod_failure_policy ? pod_failure_policy_local_nonprim : NULL,
        pod_replacement_policy && !mazu_cJSON_IsNull(pod_replacement_policy) ? strdup(pod_replacement_policy->valuestring) : NULL,
        selector ? selector_local_nonprim : NULL,
        success_policy ? success_policy_local_nonprim : NULL,
        suspend ? suspend->valueint : 0,
        _template_local_nonprim,
        ttl_seconds_after_finished ? ttl_seconds_after_finished->valuedouble : 0
        );

    return v1_job_spec_local_var;
end:
    if (pod_failure_policy_local_nonprim) {
        v1_pod_failure_policy_free(pod_failure_policy_local_nonprim);
        pod_failure_policy_local_nonprim = NULL;
    }
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (success_policy_local_nonprim) {
        v1_success_policy_free(success_policy_local_nonprim);
        success_policy_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
