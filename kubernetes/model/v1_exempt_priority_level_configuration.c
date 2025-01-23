#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_exempt_priority_level_configuration.h"



v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_create(
    int lendable_percent,
    int nominal_concurrency_shares
    ) {
    v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_local_var = malloc(sizeof(v1_exempt_priority_level_configuration_t));
    if (!v1_exempt_priority_level_configuration_local_var) {
        return NULL;
    }
    v1_exempt_priority_level_configuration_local_var->lendable_percent = lendable_percent;
    v1_exempt_priority_level_configuration_local_var->nominal_concurrency_shares = nominal_concurrency_shares;

    return v1_exempt_priority_level_configuration_local_var;
}


void v1_exempt_priority_level_configuration_free(v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration) {
    if(NULL == v1_exempt_priority_level_configuration){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_exempt_priority_level_configuration);
}

mazu_cJSON *v1_exempt_priority_level_configuration_convertToJSON(v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_exempt_priority_level_configuration->lendable_percent
    if(v1_exempt_priority_level_configuration->lendable_percent) {
    if(mazu_cJSON_AddNumberToObject(item, "lendablePercent", v1_exempt_priority_level_configuration->lendable_percent) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_exempt_priority_level_configuration->nominal_concurrency_shares
    if(v1_exempt_priority_level_configuration->nominal_concurrency_shares) {
    if(mazu_cJSON_AddNumberToObject(item, "nominalConcurrencyShares", v1_exempt_priority_level_configuration->nominal_concurrency_shares) == NULL) {
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

v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_parseFromJSON(mazu_cJSON *v1_exempt_priority_level_configurationJSON){

    v1_exempt_priority_level_configuration_t *v1_exempt_priority_level_configuration_local_var = NULL;

    // v1_exempt_priority_level_configuration->lendable_percent
    mazu_cJSON *lendable_percent = mazu_cJSON_GetObjectItemCaseSensitive(v1_exempt_priority_level_configurationJSON, "lendablePercent");
    if (lendable_percent) { 
    if(!mazu_cJSON_IsNumber(lendable_percent))
    {
    goto end; //Numeric
    }
    }

    // v1_exempt_priority_level_configuration->nominal_concurrency_shares
    mazu_cJSON *nominal_concurrency_shares = mazu_cJSON_GetObjectItemCaseSensitive(v1_exempt_priority_level_configurationJSON, "nominalConcurrencyShares");
    if (nominal_concurrency_shares) { 
    if(!mazu_cJSON_IsNumber(nominal_concurrency_shares))
    {
    goto end; //Numeric
    }
    }


    v1_exempt_priority_level_configuration_local_var = v1_exempt_priority_level_configuration_create (
        lendable_percent ? lendable_percent->valuedouble : 0,
        nominal_concurrency_shares ? nominal_concurrency_shares->valuedouble : 0
        );

    return v1_exempt_priority_level_configuration_local_var;
end:
    return NULL;

}
