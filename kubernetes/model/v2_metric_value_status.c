#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_metric_value_status.h"



v2_metric_value_status_t *v2_metric_value_status_create(
    int average_utilization,
    char *average_value,
    char *value
    ) {
    v2_metric_value_status_t *v2_metric_value_status_local_var = malloc(sizeof(v2_metric_value_status_t));
    if (!v2_metric_value_status_local_var) {
        return NULL;
    }
    v2_metric_value_status_local_var->average_utilization = average_utilization;
    v2_metric_value_status_local_var->average_value = average_value;
    v2_metric_value_status_local_var->value = value;

    return v2_metric_value_status_local_var;
}


void v2_metric_value_status_free(v2_metric_value_status_t *v2_metric_value_status) {
    if(NULL == v2_metric_value_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_metric_value_status->average_value) {
        free(v2_metric_value_status->average_value);
        v2_metric_value_status->average_value = NULL;
    }
    if (v2_metric_value_status->value) {
        free(v2_metric_value_status->value);
        v2_metric_value_status->value = NULL;
    }
    free(v2_metric_value_status);
}

mazu_cJSON *v2_metric_value_status_convertToJSON(v2_metric_value_status_t *v2_metric_value_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v2_metric_value_status->average_utilization
    if(v2_metric_value_status->average_utilization) {
    if(mazu_cJSON_AddNumberToObject(item, "averageUtilization", v2_metric_value_status->average_utilization) == NULL) {
    goto fail; //Numeric
    }
    }


    // v2_metric_value_status->average_value
    if(v2_metric_value_status->average_value) {
    if(mazu_cJSON_AddStringToObject(item, "averageValue", v2_metric_value_status->average_value) == NULL) {
    goto fail; //String
    }
    }


    // v2_metric_value_status->value
    if(v2_metric_value_status->value) {
    if(mazu_cJSON_AddStringToObject(item, "value", v2_metric_value_status->value) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v2_metric_value_status_t *v2_metric_value_status_parseFromJSON(mazu_cJSON *v2_metric_value_statusJSON){

    v2_metric_value_status_t *v2_metric_value_status_local_var = NULL;

    // v2_metric_value_status->average_utilization
    mazu_cJSON *average_utilization = mazu_cJSON_GetObjectItemCaseSensitive(v2_metric_value_statusJSON, "averageUtilization");
    if (average_utilization) { 
    if(!mazu_cJSON_IsNumber(average_utilization))
    {
    goto end; //Numeric
    }
    }

    // v2_metric_value_status->average_value
    mazu_cJSON *average_value = mazu_cJSON_GetObjectItemCaseSensitive(v2_metric_value_statusJSON, "averageValue");
    if (average_value) { 
    if(!mazu_cJSON_IsString(average_value) && !mazu_cJSON_IsNull(average_value))
    {
    goto end; //String
    }
    }

    // v2_metric_value_status->value
    mazu_cJSON *value = mazu_cJSON_GetObjectItemCaseSensitive(v2_metric_value_statusJSON, "value");
    if (value) { 
    if(!mazu_cJSON_IsString(value) && !mazu_cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    v2_metric_value_status_local_var = v2_metric_value_status_create (
        average_utilization ? average_utilization->valuedouble : 0,
        average_value && !mazu_cJSON_IsNull(average_value) ? strdup(average_value->valuestring) : NULL,
        value && !mazu_cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return v2_metric_value_status_local_var;
end:
    return NULL;

}
