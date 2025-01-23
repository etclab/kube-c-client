#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_readiness_gate.h"



v1_pod_readiness_gate_t *v1_pod_readiness_gate_create(
    char *condition_type
    ) {
    v1_pod_readiness_gate_t *v1_pod_readiness_gate_local_var = malloc(sizeof(v1_pod_readiness_gate_t));
    if (!v1_pod_readiness_gate_local_var) {
        return NULL;
    }
    v1_pod_readiness_gate_local_var->condition_type = condition_type;

    return v1_pod_readiness_gate_local_var;
}


void v1_pod_readiness_gate_free(v1_pod_readiness_gate_t *v1_pod_readiness_gate) {
    if(NULL == v1_pod_readiness_gate){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_readiness_gate->condition_type) {
        free(v1_pod_readiness_gate->condition_type);
        v1_pod_readiness_gate->condition_type = NULL;
    }
    free(v1_pod_readiness_gate);
}

mazu_cJSON *v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_t *v1_pod_readiness_gate) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_readiness_gate->condition_type
    if (!v1_pod_readiness_gate->condition_type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "conditionType", v1_pod_readiness_gate->condition_type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_readiness_gate_t *v1_pod_readiness_gate_parseFromJSON(mazu_cJSON *v1_pod_readiness_gateJSON){

    v1_pod_readiness_gate_t *v1_pod_readiness_gate_local_var = NULL;

    // v1_pod_readiness_gate->condition_type
    mazu_cJSON *condition_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_readiness_gateJSON, "conditionType");
    if (!condition_type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(condition_type))
    {
    goto end; //String
    }


    v1_pod_readiness_gate_local_var = v1_pod_readiness_gate_create (
        strdup(condition_type->valuestring)
        );

    return v1_pod_readiness_gate_local_var;
end:
    return NULL;

}
