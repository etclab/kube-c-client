#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint_conditions.h"



v1_endpoint_conditions_t *v1_endpoint_conditions_create(
    int ready,
    int serving,
    int terminating
    ) {
    v1_endpoint_conditions_t *v1_endpoint_conditions_local_var = malloc(sizeof(v1_endpoint_conditions_t));
    if (!v1_endpoint_conditions_local_var) {
        return NULL;
    }
    v1_endpoint_conditions_local_var->ready = ready;
    v1_endpoint_conditions_local_var->serving = serving;
    v1_endpoint_conditions_local_var->terminating = terminating;

    return v1_endpoint_conditions_local_var;
}


void v1_endpoint_conditions_free(v1_endpoint_conditions_t *v1_endpoint_conditions) {
    if(NULL == v1_endpoint_conditions){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_endpoint_conditions);
}

mazu_cJSON *v1_endpoint_conditions_convertToJSON(v1_endpoint_conditions_t *v1_endpoint_conditions) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_endpoint_conditions->ready
    if(v1_endpoint_conditions->ready) {
    if(mazu_cJSON_AddBoolToObject(item, "ready", v1_endpoint_conditions->ready) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_endpoint_conditions->serving
    if(v1_endpoint_conditions->serving) {
    if(mazu_cJSON_AddBoolToObject(item, "serving", v1_endpoint_conditions->serving) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_endpoint_conditions->terminating
    if(v1_endpoint_conditions->terminating) {
    if(mazu_cJSON_AddBoolToObject(item, "terminating", v1_endpoint_conditions->terminating) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_endpoint_conditions_t *v1_endpoint_conditions_parseFromJSON(mazu_cJSON *v1_endpoint_conditionsJSON){

    v1_endpoint_conditions_t *v1_endpoint_conditions_local_var = NULL;

    // v1_endpoint_conditions->ready
    mazu_cJSON *ready = mazu_cJSON_GetObjectItemCaseSensitive(v1_endpoint_conditionsJSON, "ready");
    if (ready) { 
    if(!mazu_cJSON_IsBool(ready))
    {
    goto end; //Bool
    }
    }

    // v1_endpoint_conditions->serving
    mazu_cJSON *serving = mazu_cJSON_GetObjectItemCaseSensitive(v1_endpoint_conditionsJSON, "serving");
    if (serving) { 
    if(!mazu_cJSON_IsBool(serving))
    {
    goto end; //Bool
    }
    }

    // v1_endpoint_conditions->terminating
    mazu_cJSON *terminating = mazu_cJSON_GetObjectItemCaseSensitive(v1_endpoint_conditionsJSON, "terminating");
    if (terminating) { 
    if(!mazu_cJSON_IsBool(terminating))
    {
    goto end; //Bool
    }
    }


    v1_endpoint_conditions_local_var = v1_endpoint_conditions_create (
        ready ? ready->valueint : 0,
        serving ? serving->valueint : 0,
        terminating ? terminating->valueint : 0
        );

    return v1_endpoint_conditions_local_var;
end:
    return NULL;

}
