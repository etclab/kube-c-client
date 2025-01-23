#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_resource_metric_source.h"



v2_resource_metric_source_t *v2_resource_metric_source_create(
    char *name,
    v2_metric_target_t *target
    ) {
    v2_resource_metric_source_t *v2_resource_metric_source_local_var = malloc(sizeof(v2_resource_metric_source_t));
    if (!v2_resource_metric_source_local_var) {
        return NULL;
    }
    v2_resource_metric_source_local_var->name = name;
    v2_resource_metric_source_local_var->target = target;

    return v2_resource_metric_source_local_var;
}


void v2_resource_metric_source_free(v2_resource_metric_source_t *v2_resource_metric_source) {
    if(NULL == v2_resource_metric_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_resource_metric_source->name) {
        free(v2_resource_metric_source->name);
        v2_resource_metric_source->name = NULL;
    }
    if (v2_resource_metric_source->target) {
        v2_metric_target_free(v2_resource_metric_source->target);
        v2_resource_metric_source->target = NULL;
    }
    free(v2_resource_metric_source);
}

mazu_cJSON *v2_resource_metric_source_convertToJSON(v2_resource_metric_source_t *v2_resource_metric_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v2_resource_metric_source->name
    if (!v2_resource_metric_source->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v2_resource_metric_source->name) == NULL) {
    goto fail; //String
    }


    // v2_resource_metric_source->target
    if (!v2_resource_metric_source->target) {
        goto fail;
    }
    mazu_cJSON *target_local_JSON = v2_metric_target_convertToJSON(v2_resource_metric_source->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "target", target_local_JSON);
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

v2_resource_metric_source_t *v2_resource_metric_source_parseFromJSON(mazu_cJSON *v2_resource_metric_sourceJSON){

    v2_resource_metric_source_t *v2_resource_metric_source_local_var = NULL;

    // define the local variable for v2_resource_metric_source->target
    v2_metric_target_t *target_local_nonprim = NULL;

    // v2_resource_metric_source->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v2_resource_metric_sourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v2_resource_metric_source->target
    mazu_cJSON *target = mazu_cJSON_GetObjectItemCaseSensitive(v2_resource_metric_sourceJSON, "target");
    if (!target) {
        goto end;
    }

    
    target_local_nonprim = v2_metric_target_parseFromJSON(target); //nonprimitive


    v2_resource_metric_source_local_var = v2_resource_metric_source_create (
        strdup(name->valuestring),
        target_local_nonprim
        );

    return v2_resource_metric_source_local_var;
end:
    if (target_local_nonprim) {
        v2_metric_target_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
