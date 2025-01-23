#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_deployment_spec.h"



v1_deployment_spec_t *v1_deployment_spec_create(
    int min_ready_seconds,
    int paused,
    int progress_deadline_seconds,
    int replicas,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *_template
    ) {
    v1_deployment_spec_t *v1_deployment_spec_local_var = malloc(sizeof(v1_deployment_spec_t));
    if (!v1_deployment_spec_local_var) {
        return NULL;
    }
    v1_deployment_spec_local_var->min_ready_seconds = min_ready_seconds;
    v1_deployment_spec_local_var->paused = paused;
    v1_deployment_spec_local_var->progress_deadline_seconds = progress_deadline_seconds;
    v1_deployment_spec_local_var->replicas = replicas;
    v1_deployment_spec_local_var->revision_history_limit = revision_history_limit;
    v1_deployment_spec_local_var->selector = selector;
    v1_deployment_spec_local_var->strategy = strategy;
    v1_deployment_spec_local_var->_template = _template;

    return v1_deployment_spec_local_var;
}


void v1_deployment_spec_free(v1_deployment_spec_t *v1_deployment_spec) {
    if(NULL == v1_deployment_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_deployment_spec->selector) {
        v1_label_selector_free(v1_deployment_spec->selector);
        v1_deployment_spec->selector = NULL;
    }
    if (v1_deployment_spec->strategy) {
        v1_deployment_strategy_free(v1_deployment_spec->strategy);
        v1_deployment_spec->strategy = NULL;
    }
    if (v1_deployment_spec->_template) {
        v1_pod_template_spec_free(v1_deployment_spec->_template);
        v1_deployment_spec->_template = NULL;
    }
    free(v1_deployment_spec);
}

mazu_cJSON *v1_deployment_spec_convertToJSON(v1_deployment_spec_t *v1_deployment_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_deployment_spec->min_ready_seconds
    if(v1_deployment_spec->min_ready_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "minReadySeconds", v1_deployment_spec->min_ready_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->paused
    if(v1_deployment_spec->paused) {
    if(mazu_cJSON_AddBoolToObject(item, "paused", v1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_deployment_spec->progress_deadline_seconds
    if(v1_deployment_spec->progress_deadline_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "progressDeadlineSeconds", v1_deployment_spec->progress_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->replicas
    if(v1_deployment_spec->replicas) {
    if(mazu_cJSON_AddNumberToObject(item, "replicas", v1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->revision_history_limit
    if(v1_deployment_spec->revision_history_limit) {
    if(mazu_cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1_deployment_spec->revision_history_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_deployment_spec->selector
    if (!v1_deployment_spec->selector) {
        goto fail;
    }
    mazu_cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_deployment_spec->strategy
    if(v1_deployment_spec->strategy) {
    mazu_cJSON *strategy_local_JSON = v1_deployment_strategy_convertToJSON(v1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_deployment_spec->_template
    if (!v1_deployment_spec->_template) {
        goto fail;
    }
    mazu_cJSON *_template_local_JSON = v1_pod_template_spec_convertToJSON(v1_deployment_spec->_template);
    if(_template_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "template", _template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_deployment_spec_t *v1_deployment_spec_parseFromJSON(mazu_cJSON *v1_deployment_specJSON){

    v1_deployment_spec_t *v1_deployment_spec_local_var = NULL;

    // define the local variable for v1_deployment_spec->selector
    v1_label_selector_t *selector_local_nonprim = NULL;

    // define the local variable for v1_deployment_spec->strategy
    v1_deployment_strategy_t *strategy_local_nonprim = NULL;

    // define the local variable for v1_deployment_spec->_template
    v1_pod_template_spec_t *_template_local_nonprim = NULL;

    // v1_deployment_spec->min_ready_seconds
    mazu_cJSON *min_ready_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "minReadySeconds");
    if (min_ready_seconds) { 
    if(!mazu_cJSON_IsNumber(min_ready_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->paused
    mazu_cJSON *paused = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "paused");
    if (paused) { 
    if(!mazu_cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // v1_deployment_spec->progress_deadline_seconds
    mazu_cJSON *progress_deadline_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "progressDeadlineSeconds");
    if (progress_deadline_seconds) { 
    if(!mazu_cJSON_IsNumber(progress_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->replicas
    mazu_cJSON *replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!mazu_cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->revision_history_limit
    mazu_cJSON *revision_history_limit = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "revisionHistoryLimit");
    if (revision_history_limit) { 
    if(!mazu_cJSON_IsNumber(revision_history_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->selector
    mazu_cJSON *selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_deployment_spec->strategy
    mazu_cJSON *strategy = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "strategy");
    if (strategy) { 
    strategy_local_nonprim = v1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // v1_deployment_spec->_template
    mazu_cJSON *_template = mazu_cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "template");
    if (!_template) {
        goto end;
    }

    
    _template_local_nonprim = v1_pod_template_spec_parseFromJSON(_template); //nonprimitive


    v1_deployment_spec_local_var = v1_deployment_spec_create (
        min_ready_seconds ? min_ready_seconds->valuedouble : 0,
        paused ? paused->valueint : 0,
        progress_deadline_seconds ? progress_deadline_seconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        revision_history_limit ? revision_history_limit->valuedouble : 0,
        selector_local_nonprim,
        strategy ? strategy_local_nonprim : NULL,
        _template_local_nonprim
        );

    return v1_deployment_spec_local_var;
end:
    if (selector_local_nonprim) {
        v1_label_selector_free(selector_local_nonprim);
        selector_local_nonprim = NULL;
    }
    if (strategy_local_nonprim) {
        v1_deployment_strategy_free(strategy_local_nonprim);
        strategy_local_nonprim = NULL;
    }
    if (_template_local_nonprim) {
        v1_pod_template_spec_free(_template_local_nonprim);
        _template_local_nonprim = NULL;
    }
    return NULL;

}
