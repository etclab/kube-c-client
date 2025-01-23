#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_volume_source.h"



v1_secret_volume_source_t *v1_secret_volume_source_create(
    int default_mode,
    list_t *items,
    int optional,
    char *secret_name
    ) {
    v1_secret_volume_source_t *v1_secret_volume_source_local_var = malloc(sizeof(v1_secret_volume_source_t));
    if (!v1_secret_volume_source_local_var) {
        return NULL;
    }
    v1_secret_volume_source_local_var->default_mode = default_mode;
    v1_secret_volume_source_local_var->items = items;
    v1_secret_volume_source_local_var->optional = optional;
    v1_secret_volume_source_local_var->secret_name = secret_name;

    return v1_secret_volume_source_local_var;
}


void v1_secret_volume_source_free(v1_secret_volume_source_t *v1_secret_volume_source) {
    if(NULL == v1_secret_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_volume_source->items) {
        list_ForEach(listEntry, v1_secret_volume_source->items) {
            v1_key_to_path_free(listEntry->data);
        }
        list_freeList(v1_secret_volume_source->items);
        v1_secret_volume_source->items = NULL;
    }
    if (v1_secret_volume_source->secret_name) {
        free(v1_secret_volume_source->secret_name);
        v1_secret_volume_source->secret_name = NULL;
    }
    free(v1_secret_volume_source);
}

mazu_cJSON *v1_secret_volume_source_convertToJSON(v1_secret_volume_source_t *v1_secret_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_secret_volume_source->default_mode
    if(v1_secret_volume_source->default_mode) {
    if(mazu_cJSON_AddNumberToObject(item, "defaultMode", v1_secret_volume_source->default_mode) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_secret_volume_source->items
    if(v1_secret_volume_source->items) {
    mazu_cJSON *items = mazu_cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v1_secret_volume_source->items) {
    list_ForEach(itemsListEntry, v1_secret_volume_source->items) {
    mazu_cJSON *itemLocal = v1_key_to_path_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(items, itemLocal);
    }
    }
    }


    // v1_secret_volume_source->optional
    if(v1_secret_volume_source->optional) {
    if(mazu_cJSON_AddBoolToObject(item, "optional", v1_secret_volume_source->optional) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_secret_volume_source->secret_name
    if(v1_secret_volume_source->secret_name) {
    if(mazu_cJSON_AddStringToObject(item, "secretName", v1_secret_volume_source->secret_name) == NULL) {
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

v1_secret_volume_source_t *v1_secret_volume_source_parseFromJSON(mazu_cJSON *v1_secret_volume_sourceJSON){

    v1_secret_volume_source_t *v1_secret_volume_source_local_var = NULL;

    // define the local list for v1_secret_volume_source->items
    list_t *itemsList = NULL;

    // v1_secret_volume_source->default_mode
    mazu_cJSON *default_mode = mazu_cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "defaultMode");
    if (default_mode) { 
    if(!mazu_cJSON_IsNumber(default_mode))
    {
    goto end; //Numeric
    }
    }

    // v1_secret_volume_source->items
    mazu_cJSON *items = mazu_cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "items");
    if (items) { 
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
        v1_key_to_path_t *itemsItem = v1_key_to_path_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }

    // v1_secret_volume_source->optional
    mazu_cJSON *optional = mazu_cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "optional");
    if (optional) { 
    if(!mazu_cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }

    // v1_secret_volume_source->secret_name
    mazu_cJSON *secret_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_secret_volume_sourceJSON, "secretName");
    if (secret_name) { 
    if(!mazu_cJSON_IsString(secret_name) && !mazu_cJSON_IsNull(secret_name))
    {
    goto end; //String
    }
    }


    v1_secret_volume_source_local_var = v1_secret_volume_source_create (
        default_mode ? default_mode->valuedouble : 0,
        items ? itemsList : NULL,
        optional ? optional->valueint : 0,
        secret_name && !mazu_cJSON_IsNull(secret_name) ? strdup(secret_name->valuestring) : NULL
        );

    return v1_secret_volume_source_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v1_key_to_path_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
