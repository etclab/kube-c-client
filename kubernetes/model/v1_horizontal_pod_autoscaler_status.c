#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler_status.h"



v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_create(
    int current_cpu_utilization_percentage,
    int current_replicas,
    int desired_replicas,
    char *last_scale_time,
    long observed_generation
    ) {
    v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_status_t));
    if (!v1_horizontal_pod_autoscaler_status_local_var) {
        return NULL;
    }
    v1_horizontal_pod_autoscaler_status_local_var->current_cpu_utilization_percentage = current_cpu_utilization_percentage;
    v1_horizontal_pod_autoscaler_status_local_var->current_replicas = current_replicas;
    v1_horizontal_pod_autoscaler_status_local_var->desired_replicas = desired_replicas;
    v1_horizontal_pod_autoscaler_status_local_var->last_scale_time = last_scale_time;
    v1_horizontal_pod_autoscaler_status_local_var->observed_generation = observed_generation;

    return v1_horizontal_pod_autoscaler_status_local_var;
}


void v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status) {
    if(NULL == v1_horizontal_pod_autoscaler_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_horizontal_pod_autoscaler_status->last_scale_time) {
        free(v1_horizontal_pod_autoscaler_status->last_scale_time);
        v1_horizontal_pod_autoscaler_status->last_scale_time = NULL;
    }
    free(v1_horizontal_pod_autoscaler_status);
}

mazu_cJSON *v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage
    if(v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage) {
    if(mazu_cJSON_AddNumberToObject(item, "currentCPUUtilizationPercentage", v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_horizontal_pod_autoscaler_status->current_replicas
    if (!v1_horizontal_pod_autoscaler_status->current_replicas) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "currentReplicas", v1_horizontal_pod_autoscaler_status->current_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_horizontal_pod_autoscaler_status->desired_replicas
    if (!v1_horizontal_pod_autoscaler_status->desired_replicas) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "desiredReplicas", v1_horizontal_pod_autoscaler_status->desired_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_horizontal_pod_autoscaler_status->last_scale_time
    if(v1_horizontal_pod_autoscaler_status->last_scale_time) {
    if(mazu_cJSON_AddStringToObject(item, "lastScaleTime", v1_horizontal_pod_autoscaler_status->last_scale_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_horizontal_pod_autoscaler_status->observed_generation
    if(v1_horizontal_pod_autoscaler_status->observed_generation) {
    if(mazu_cJSON_AddNumberToObject(item, "observedGeneration", v1_horizontal_pod_autoscaler_status->observed_generation) == NULL) {
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

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_parseFromJSON(mazu_cJSON *v1_horizontal_pod_autoscaler_statusJSON){

    v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_local_var = NULL;

    // v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage
    mazu_cJSON *current_cpu_utilization_percentage = mazu_cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "currentCPUUtilizationPercentage");
    if (current_cpu_utilization_percentage) { 
    if(!mazu_cJSON_IsNumber(current_cpu_utilization_percentage))
    {
    goto end; //Numeric
    }
    }

    // v1_horizontal_pod_autoscaler_status->current_replicas
    mazu_cJSON *current_replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "currentReplicas");
    if (!current_replicas) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(current_replicas))
    {
    goto end; //Numeric
    }

    // v1_horizontal_pod_autoscaler_status->desired_replicas
    mazu_cJSON *desired_replicas = mazu_cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "desiredReplicas");
    if (!desired_replicas) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(desired_replicas))
    {
    goto end; //Numeric
    }

    // v1_horizontal_pod_autoscaler_status->last_scale_time
    mazu_cJSON *last_scale_time = mazu_cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "lastScaleTime");
    if (last_scale_time) { 
    if(!mazu_cJSON_IsString(last_scale_time) && !mazu_cJSON_IsNull(last_scale_time))
    {
    goto end; //DateTime
    }
    }

    // v1_horizontal_pod_autoscaler_status->observed_generation
    mazu_cJSON *observed_generation = mazu_cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "observedGeneration");
    if (observed_generation) { 
    if(!mazu_cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }


    v1_horizontal_pod_autoscaler_status_local_var = v1_horizontal_pod_autoscaler_status_create (
        current_cpu_utilization_percentage ? current_cpu_utilization_percentage->valuedouble : 0,
        current_replicas->valuedouble,
        desired_replicas->valuedouble,
        last_scale_time && !mazu_cJSON_IsNull(last_scale_time) ? strdup(last_scale_time->valuestring) : NULL,
        observed_generation ? observed_generation->valuedouble : 0
        );

    return v1_horizontal_pod_autoscaler_status_local_var;
end:
    return NULL;

}
