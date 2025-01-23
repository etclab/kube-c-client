#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler_list.h"



v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_list_t));
    if (!v2_horizontal_pod_autoscaler_list_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_list_local_var->api_version = api_version;
    v2_horizontal_pod_autoscaler_list_local_var->items = items;
    v2_horizontal_pod_autoscaler_list_local_var->kind = kind;
    v2_horizontal_pod_autoscaler_list_local_var->metadata = metadata;

    return v2_horizontal_pod_autoscaler_list_local_var;
}


void v2_horizontal_pod_autoscaler_list_free(v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list) {
    if(NULL == v2_horizontal_pod_autoscaler_list){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler_list->api_version) {
        free(v2_horizontal_pod_autoscaler_list->api_version);
        v2_horizontal_pod_autoscaler_list->api_version = NULL;
    }
    if (v2_horizontal_pod_autoscaler_list->items) {
        list_ForEach(listEntry, v2_horizontal_pod_autoscaler_list->items) {
            v2_horizontal_pod_autoscaler_free(listEntry->data);
        }
        list_freeList(v2_horizontal_pod_autoscaler_list->items);
        v2_horizontal_pod_autoscaler_list->items = NULL;
    }
    if (v2_horizontal_pod_autoscaler_list->kind) {
        free(v2_horizontal_pod_autoscaler_list->kind);
        v2_horizontal_pod_autoscaler_list->kind = NULL;
    }
    if (v2_horizontal_pod_autoscaler_list->metadata) {
        v1_list_meta_free(v2_horizontal_pod_autoscaler_list->metadata);
        v2_horizontal_pod_autoscaler_list->metadata = NULL;
    }
    free(v2_horizontal_pod_autoscaler_list);
}

mazu_cJSON *v2_horizontal_pod_autoscaler_list_convertToJSON(v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler_list->api_version
    if(v2_horizontal_pod_autoscaler_list->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v2_horizontal_pod_autoscaler_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_list->items
    if (!v2_horizontal_pod_autoscaler_list->items) {
        goto fail;
    }
    mazu_cJSON *items = mazu_cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v2_horizontal_pod_autoscaler_list->items) {
    list_ForEach(itemsListEntry, v2_horizontal_pod_autoscaler_list->items) {
    mazu_cJSON *itemLocal = v2_horizontal_pod_autoscaler_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v2_horizontal_pod_autoscaler_list->kind
    if(v2_horizontal_pod_autoscaler_list->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v2_horizontal_pod_autoscaler_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_list->metadata
    if(v2_horizontal_pod_autoscaler_list->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v2_horizontal_pod_autoscaler_list->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_parseFromJSON(mazu_cJSON *v2_horizontal_pod_autoscaler_listJSON){

    v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_local_var = NULL;

    // define the local list for v2_horizontal_pod_autoscaler_list->items
    list_t *itemsList = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // v2_horizontal_pod_autoscaler_list->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_list->items
    mazu_cJSON *items = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "items");
    if (!items) {
        goto end;
    }

    
    mazu_cJSON *items_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    mazu_cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!mazu_cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v2_horizontal_pod_autoscaler_t *itemsItem = v2_horizontal_pod_autoscaler_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v2_horizontal_pod_autoscaler_list->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_list->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v2_horizontal_pod_autoscaler_list_local_var = v2_horizontal_pod_autoscaler_list_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v2_horizontal_pod_autoscaler_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v2_horizontal_pod_autoscaler_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
