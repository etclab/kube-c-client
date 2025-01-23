#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_queuing_configuration.h"



v1_queuing_configuration_t *v1_queuing_configuration_create(
    int hand_size,
    int queue_length_limit,
    int queues
    ) {
    v1_queuing_configuration_t *v1_queuing_configuration_local_var = malloc(sizeof(v1_queuing_configuration_t));
    if (!v1_queuing_configuration_local_var) {
        return NULL;
    }
    v1_queuing_configuration_local_var->hand_size = hand_size;
    v1_queuing_configuration_local_var->queue_length_limit = queue_length_limit;
    v1_queuing_configuration_local_var->queues = queues;

    return v1_queuing_configuration_local_var;
}


void v1_queuing_configuration_free(v1_queuing_configuration_t *v1_queuing_configuration) {
    if(NULL == v1_queuing_configuration){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_queuing_configuration);
}

mazu_cJSON *v1_queuing_configuration_convertToJSON(v1_queuing_configuration_t *v1_queuing_configuration) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_queuing_configuration->hand_size
    if(v1_queuing_configuration->hand_size) {
    if(mazu_cJSON_AddNumberToObject(item, "handSize", v1_queuing_configuration->hand_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_queuing_configuration->queue_length_limit
    if(v1_queuing_configuration->queue_length_limit) {
    if(mazu_cJSON_AddNumberToObject(item, "queueLengthLimit", v1_queuing_configuration->queue_length_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_queuing_configuration->queues
    if(v1_queuing_configuration->queues) {
    if(mazu_cJSON_AddNumberToObject(item, "queues", v1_queuing_configuration->queues) == NULL) {
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

v1_queuing_configuration_t *v1_queuing_configuration_parseFromJSON(mazu_cJSON *v1_queuing_configurationJSON){

    v1_queuing_configuration_t *v1_queuing_configuration_local_var = NULL;

    // v1_queuing_configuration->hand_size
    mazu_cJSON *hand_size = mazu_cJSON_GetObjectItemCaseSensitive(v1_queuing_configurationJSON, "handSize");
    if (hand_size) { 
    if(!mazu_cJSON_IsNumber(hand_size))
    {
    goto end; //Numeric
    }
    }

    // v1_queuing_configuration->queue_length_limit
    mazu_cJSON *queue_length_limit = mazu_cJSON_GetObjectItemCaseSensitive(v1_queuing_configurationJSON, "queueLengthLimit");
    if (queue_length_limit) { 
    if(!mazu_cJSON_IsNumber(queue_length_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_queuing_configuration->queues
    mazu_cJSON *queues = mazu_cJSON_GetObjectItemCaseSensitive(v1_queuing_configurationJSON, "queues");
    if (queues) { 
    if(!mazu_cJSON_IsNumber(queues))
    {
    goto end; //Numeric
    }
    }


    v1_queuing_configuration_local_var = v1_queuing_configuration_create (
        hand_size ? hand_size->valuedouble : 0,
        queue_length_limit ? queue_length_limit->valuedouble : 0,
        queues ? queues->valuedouble : 0
        );

    return v1_queuing_configuration_local_var;
end:
    return NULL;

}
