#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range_spec.h"



v1_limit_range_spec_t *v1_limit_range_spec_create(
    list_t *limits
    ) {
    v1_limit_range_spec_t *v1_limit_range_spec_local_var = malloc(sizeof(v1_limit_range_spec_t));
    if (!v1_limit_range_spec_local_var) {
        return NULL;
    }
    v1_limit_range_spec_local_var->limits = limits;

    return v1_limit_range_spec_local_var;
}


void v1_limit_range_spec_free(v1_limit_range_spec_t *v1_limit_range_spec) {
    if(NULL == v1_limit_range_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_range_spec->limits) {
        list_ForEach(listEntry, v1_limit_range_spec->limits) {
            v1_limit_range_item_free(listEntry->data);
        }
        list_freeList(v1_limit_range_spec->limits);
        v1_limit_range_spec->limits = NULL;
    }
    free(v1_limit_range_spec);
}

mazu_cJSON *v1_limit_range_spec_convertToJSON(v1_limit_range_spec_t *v1_limit_range_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_limit_range_spec->limits
    if (!v1_limit_range_spec->limits) {
        goto fail;
    }
    mazu_cJSON *limits = mazu_cJSON_AddArrayToObject(item, "limits");
    if(limits == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *limitsListEntry;
    if (v1_limit_range_spec->limits) {
    list_ForEach(limitsListEntry, v1_limit_range_spec->limits) {
    mazu_cJSON *itemLocal = v1_limit_range_item_convertToJSON(limitsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(limits, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_limit_range_spec_t *v1_limit_range_spec_parseFromJSON(mazu_cJSON *v1_limit_range_specJSON){

    v1_limit_range_spec_t *v1_limit_range_spec_local_var = NULL;

    // define the local list for v1_limit_range_spec->limits
    list_t *limitsList = NULL;

    // v1_limit_range_spec->limits
    mazu_cJSON *limits = mazu_cJSON_GetObjectItemCaseSensitive(v1_limit_range_specJSON, "limits");
    if (!limits) {
        goto end;
    }

    
    mazu_cJSON *limits_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(limits)){
        goto end; //nonprimitive container
    }

    limitsList = list_createList();

    mazu_cJSON_ArrayForEach(limits_local_nonprimitive,limits )
    {
        if(!mazu_cJSON_IsObject(limits_local_nonprimitive)){
            goto end;
        }
        v1_limit_range_item_t *limitsItem = v1_limit_range_item_parseFromJSON(limits_local_nonprimitive);

        list_addElement(limitsList, limitsItem);
    }


    v1_limit_range_spec_local_var = v1_limit_range_spec_create (
        limitsList
        );

    return v1_limit_range_spec_local_var;
end:
    if (limitsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, limitsList) {
            v1_limit_range_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(limitsList);
        limitsList = NULL;
    }
    return NULL;

}
