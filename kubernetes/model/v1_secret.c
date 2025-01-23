#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret.h"



v1_secret_t *v1_secret_create(
    char *api_version,
    list_t* data,
    int immutable,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* string_data,
    char *type
    ) {
    v1_secret_t *v1_secret_local_var = malloc(sizeof(v1_secret_t));
    if (!v1_secret_local_var) {
        return NULL;
    }
    v1_secret_local_var->api_version = api_version;
    v1_secret_local_var->data = data;
    v1_secret_local_var->immutable = immutable;
    v1_secret_local_var->kind = kind;
    v1_secret_local_var->metadata = metadata;
    v1_secret_local_var->string_data = string_data;
    v1_secret_local_var->type = type;

    return v1_secret_local_var;
}


void v1_secret_free(v1_secret_t *v1_secret) {
    if(NULL == v1_secret){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret->api_version) {
        free(v1_secret->api_version);
        v1_secret->api_version = NULL;
    }
    if (v1_secret->data) {
        list_ForEach(listEntry, v1_secret->data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_secret->data);
        v1_secret->data = NULL;
    }
    if (v1_secret->kind) {
        free(v1_secret->kind);
        v1_secret->kind = NULL;
    }
    if (v1_secret->metadata) {
        v1_object_meta_free(v1_secret->metadata);
        v1_secret->metadata = NULL;
    }
    if (v1_secret->string_data) {
        list_ForEach(listEntry, v1_secret->string_data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_secret->string_data);
        v1_secret->string_data = NULL;
    }
    if (v1_secret->type) {
        free(v1_secret->type);
        v1_secret->type = NULL;
    }
    free(v1_secret);
}

mazu_cJSON *v1_secret_convertToJSON(v1_secret_t *v1_secret) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_secret->api_version
    if(v1_secret->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_secret->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_secret->data
    if(v1_secret->data) {
    mazu_cJSON *data = mazu_cJSON_AddObjectToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = data;
    listEntry_t *dataListEntry;
    if (v1_secret->data) {
    list_ForEach(dataListEntry, v1_secret->data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dataListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_secret->immutable
    if(v1_secret->immutable) {
    if(mazu_cJSON_AddBoolToObject(item, "immutable", v1_secret->immutable) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_secret->kind
    if(v1_secret->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_secret->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_secret->metadata
    if(v1_secret->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_secret->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_secret->string_data
    if(v1_secret->string_data) {
    mazu_cJSON *string_data = mazu_cJSON_AddObjectToObject(item, "stringData");
    if(string_data == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = string_data;
    listEntry_t *string_dataListEntry;
    if (v1_secret->string_data) {
    list_ForEach(string_dataListEntry, v1_secret->string_data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)string_dataListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_secret->type
    if(v1_secret->type) {
    if(mazu_cJSON_AddStringToObject(item, "type", v1_secret->type) == NULL) {
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

v1_secret_t *v1_secret_parseFromJSON(mazu_cJSON *v1_secretJSON){

    v1_secret_t *v1_secret_local_var = NULL;

    // define the local map for v1_secret->data
    list_t *dataList = NULL;

    // define the local variable for v1_secret->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local map for v1_secret->string_data
    list_t *string_dataList = NULL;

    // v1_secret->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_secret->data
    mazu_cJSON *data = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "data");
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

    // v1_secret->immutable
    mazu_cJSON *immutable = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "immutable");
    if (immutable) { 
    if(!mazu_cJSON_IsBool(immutable))
    {
    goto end; //Bool
    }
    }

    // v1_secret->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_secret->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_secret->string_data
    mazu_cJSON *string_data = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "stringData");
    if (string_data) { 
    mazu_cJSON *string_data_local_map = NULL;
    if(!mazu_cJSON_IsObject(string_data) && !mazu_cJSON_IsNull(string_data))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(string_data))
    {
        string_dataList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(string_data_local_map, string_data)
        {
            mazu_cJSON *localMapObject = string_data_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(string_dataList , localMapKeyPair);
        }
    }
    }

    // v1_secret->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "type");
    if (type) { 
    if(!mazu_cJSON_IsString(type) && !mazu_cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    v1_secret_local_var = v1_secret_create (
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        data ? dataList : NULL,
        immutable ? immutable->valueint : 0,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        string_data ? string_dataList : NULL,
        type && !mazu_cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return v1_secret_local_var;
end:
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
    if (string_dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, string_dataList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(string_dataList);
        string_dataList = NULL;
    }
    return NULL;

}
