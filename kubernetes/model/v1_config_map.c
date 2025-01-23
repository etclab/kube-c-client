#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map.h"



v1_config_map_t *v1_config_map_create(
    char *api_version,
    list_t* binary_data,
    list_t* data,
    int immutable,
    char *kind,
    v1_object_meta_t *metadata
    ) {
    v1_config_map_t *v1_config_map_local_var = malloc(sizeof(v1_config_map_t));
    if (!v1_config_map_local_var) {
        return NULL;
    }
    v1_config_map_local_var->api_version = api_version;
    v1_config_map_local_var->binary_data = binary_data;
    v1_config_map_local_var->data = data;
    v1_config_map_local_var->immutable = immutable;
    v1_config_map_local_var->kind = kind;
    v1_config_map_local_var->metadata = metadata;

    return v1_config_map_local_var;
}


void v1_config_map_free(v1_config_map_t *v1_config_map) {
    if(NULL == v1_config_map){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_config_map->api_version) {
        free(v1_config_map->api_version);
        v1_config_map->api_version = NULL;
    }
    if (v1_config_map->binary_data) {
        list_ForEach(listEntry, v1_config_map->binary_data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_config_map->binary_data);
        v1_config_map->binary_data = NULL;
    }
    if (v1_config_map->data) {
        list_ForEach(listEntry, v1_config_map->data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_config_map->data);
        v1_config_map->data = NULL;
    }
    if (v1_config_map->kind) {
        free(v1_config_map->kind);
        v1_config_map->kind = NULL;
    }
    if (v1_config_map->metadata) {
        v1_object_meta_free(v1_config_map->metadata);
        v1_config_map->metadata = NULL;
    }
    free(v1_config_map);
}

mazu_cJSON *v1_config_map_convertToJSON(v1_config_map_t *v1_config_map) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_config_map->api_version
    if(v1_config_map->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_config_map->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_config_map->binary_data
    if(v1_config_map->binary_data) {
    mazu_cJSON *binary_data = mazu_cJSON_AddObjectToObject(item, "binaryData");
    if(binary_data == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = binary_data;
    listEntry_t *binary_dataListEntry;
    if (v1_config_map->binary_data) {
    list_ForEach(binary_dataListEntry, v1_config_map->binary_data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)binary_dataListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_config_map->data
    if(v1_config_map->data) {
    mazu_cJSON *data = mazu_cJSON_AddObjectToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = data;
    listEntry_t *dataListEntry;
    if (v1_config_map->data) {
    list_ForEach(dataListEntry, v1_config_map->data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dataListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_config_map->immutable
    if(v1_config_map->immutable) {
    if(mazu_cJSON_AddBoolToObject(item, "immutable", v1_config_map->immutable) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_config_map->kind
    if(v1_config_map->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_config_map->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_config_map->metadata
    if(v1_config_map->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_config_map->metadata);
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

v1_config_map_t *v1_config_map_parseFromJSON(mazu_cJSON *v1_config_mapJSON){

    v1_config_map_t *v1_config_map_local_var = NULL;

    // define the local map for v1_config_map->binary_data
    list_t *binary_dataList = NULL;

    // define the local map for v1_config_map->data
    list_t *dataList = NULL;

    // define the local variable for v1_config_map->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1_config_map->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_config_map->binary_data
    mazu_cJSON *binary_data = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "binaryData");
    if (binary_data) { 
    mazu_cJSON *binary_data_local_map = NULL;
    if(!mazu_cJSON_IsObject(binary_data) && !mazu_cJSON_IsNull(binary_data))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(binary_data))
    {
        binary_dataList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(binary_data_local_map, binary_data)
        {
            mazu_cJSON *localMapObject = binary_data_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(binary_dataList , localMapKeyPair);
        }
    }
    }

    // v1_config_map->data
    mazu_cJSON *data = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "data");
    if (data) { 
    mazu_cJSON *data_local_map = NULL;
    if(!mazu_cJSON_IsObject(data) && !mazu_cJSON_IsNull(data))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(data))
    {
        dataList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(data_local_map, data)
        {
            mazu_cJSON *localMapObject = data_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(dataList , localMapKeyPair);
        }
    }
    }

    // v1_config_map->immutable
    mazu_cJSON *immutable = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "immutable");
    if (immutable) { 
    if(!mazu_cJSON_IsBool(immutable))
    {
    goto end; //Bool
    }
    }

    // v1_config_map->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_config_map->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_config_map_local_var = v1_config_map_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        binary_data ? binary_dataList : NULL,
        data ? dataList : NULL,
        immutable ? immutable->valueint : 0,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_config_map_local_var;
end:
    if (binary_dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, binary_dataList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(binary_dataList);
        binary_dataList = NULL;
    }
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
