#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_list_meta.h"



v1_list_meta_t *v1_list_meta_create(
    char *_continue,
    long remaining_item_count,
    char *resource_version,
    char *self_link
    ) {
    v1_list_meta_t *v1_list_meta_local_var = malloc(sizeof(v1_list_meta_t));
    if (!v1_list_meta_local_var) {
        return NULL;
    }
    v1_list_meta_local_var->_continue = _continue;
    v1_list_meta_local_var->remaining_item_count = remaining_item_count;
    v1_list_meta_local_var->resource_version = resource_version;
    v1_list_meta_local_var->self_link = self_link;

    return v1_list_meta_local_var;
}


void v1_list_meta_free(v1_list_meta_t *v1_list_meta) {
    if(NULL == v1_list_meta){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_list_meta->_continue) {
        free(v1_list_meta->_continue);
        v1_list_meta->_continue = NULL;
    }
    if (v1_list_meta->resource_version) {
        free(v1_list_meta->resource_version);
        v1_list_meta->resource_version = NULL;
    }
    if (v1_list_meta->self_link) {
        free(v1_list_meta->self_link);
        v1_list_meta->self_link = NULL;
    }
    free(v1_list_meta);
}

mazu_cJSON *v1_list_meta_convertToJSON(v1_list_meta_t *v1_list_meta) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_list_meta->_continue
    if(v1_list_meta->_continue) {
    if(mazu_cJSON_AddStringToObject(item, "continue", v1_list_meta->_continue) == NULL) {
    goto fail; //String
    }
    }


    // v1_list_meta->remaining_item_count
    if(v1_list_meta->remaining_item_count) {
    if(mazu_cJSON_AddNumberToObject(item, "remainingItemCount", v1_list_meta->remaining_item_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_list_meta->resource_version
    if(v1_list_meta->resource_version) {
    if(mazu_cJSON_AddStringToObject(item, "resourceVersion", v1_list_meta->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_list_meta->self_link
    if(v1_list_meta->self_link) {
    if(mazu_cJSON_AddStringToObject(item, "selfLink", v1_list_meta->self_link) == NULL) {
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

v1_list_meta_t *v1_list_meta_parseFromJSON(mazu_cJSON *v1_list_metaJSON){

    v1_list_meta_t *v1_list_meta_local_var = NULL;

    // v1_list_meta->_continue
    mazu_cJSON *_continue = mazu_cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "continue");
    if (_continue) { 
    if(!mazu_cJSON_IsString(_continue) && !mazu_cJSON_IsNull(_continue))
    {
    goto end; //String
    }
    }

    // v1_list_meta->remaining_item_count
    mazu_cJSON *remaining_item_count = mazu_cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "remainingItemCount");
    if (remaining_item_count) { 
    if(!mazu_cJSON_IsNumber(remaining_item_count))
    {
    goto end; //Numeric
    }
    }

    // v1_list_meta->resource_version
    mazu_cJSON *resource_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "resourceVersion");
    if (resource_version) { 
    if(!mazu_cJSON_IsString(resource_version) && !mazu_cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_list_meta->self_link
    mazu_cJSON *self_link = mazu_cJSON_GetObjectItemCaseSensitive(v1_list_metaJSON, "selfLink");
    if (self_link) { 
    if(!mazu_cJSON_IsString(self_link) && !mazu_cJSON_IsNull(self_link))
    {
    goto end; //String
    }
    }


    v1_list_meta_local_var = v1_list_meta_create (
        _continue && !mazu_cJSON_IsNull(_continue) ? strdup(_continue->valuestring) : NULL,
        remaining_item_count ? remaining_item_count->valuedouble : 0,
        resource_version && !mazu_cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        self_link && !mazu_cJSON_IsNull(self_link) ? strdup(self_link->valuestring) : NULL
        );

    return v1_list_meta_local_var;
end:
    return NULL;

}
