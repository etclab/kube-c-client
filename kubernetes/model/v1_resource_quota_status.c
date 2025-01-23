#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_status.h"



v1_resource_quota_status_t *v1_resource_quota_status_create(
    list_t* hard,
    list_t* used
    ) {
    v1_resource_quota_status_t *v1_resource_quota_status_local_var = malloc(sizeof(v1_resource_quota_status_t));
    if (!v1_resource_quota_status_local_var) {
        return NULL;
    }
    v1_resource_quota_status_local_var->hard = hard;
    v1_resource_quota_status_local_var->used = used;

    return v1_resource_quota_status_local_var;
}


void v1_resource_quota_status_free(v1_resource_quota_status_t *v1_resource_quota_status) {
    if(NULL == v1_resource_quota_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_quota_status->hard) {
        list_ForEach(listEntry, v1_resource_quota_status->hard) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_resource_quota_status->hard);
        v1_resource_quota_status->hard = NULL;
    }
    if (v1_resource_quota_status->used) {
        list_ForEach(listEntry, v1_resource_quota_status->used) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_resource_quota_status->used);
        v1_resource_quota_status->used = NULL;
    }
    free(v1_resource_quota_status);
}

mazu_cJSON *v1_resource_quota_status_convertToJSON(v1_resource_quota_status_t *v1_resource_quota_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_resource_quota_status->hard
    if(v1_resource_quota_status->hard) {
    mazu_cJSON *hard = mazu_cJSON_AddObjectToObject(item, "hard");
    if(hard == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = hard;
    listEntry_t *hardListEntry;
    if (v1_resource_quota_status->hard) {
    list_ForEach(hardListEntry, v1_resource_quota_status->hard) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)hardListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_resource_quota_status->used
    if(v1_resource_quota_status->used) {
    mazu_cJSON *used = mazu_cJSON_AddObjectToObject(item, "used");
    if(used == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = used;
    listEntry_t *usedListEntry;
    if (v1_resource_quota_status->used) {
    list_ForEach(usedListEntry, v1_resource_quota_status->used) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)usedListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_quota_status_t *v1_resource_quota_status_parseFromJSON(mazu_cJSON *v1_resource_quota_statusJSON){

    v1_resource_quota_status_t *v1_resource_quota_status_local_var = NULL;

    // define the local map for v1_resource_quota_status->hard
    list_t *hardList = NULL;

    // define the local map for v1_resource_quota_status->used
    list_t *usedList = NULL;

    // v1_resource_quota_status->hard
    mazu_cJSON *hard = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_quota_statusJSON, "hard");
    if (hard) { 
    mazu_cJSON *hard_local_map = NULL;
    if(!mazu_cJSON_IsObject(hard) && !mazu_cJSON_IsNull(hard))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(hard))
    {
        hardList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(hard_local_map, hard)
        {
            mazu_cJSON *localMapObject = hard_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(hardList , localMapKeyPair);
        }
    }
    }

    // v1_resource_quota_status->used
    mazu_cJSON *used = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_quota_statusJSON, "used");
    if (used) { 
    mazu_cJSON *used_local_map = NULL;
    if(!mazu_cJSON_IsObject(used) && !mazu_cJSON_IsNull(used))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(used))
    {
        usedList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(used_local_map, used)
        {
            mazu_cJSON *localMapObject = used_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(usedList , localMapKeyPair);
        }
    }
    }


    v1_resource_quota_status_local_var = v1_resource_quota_status_create (
        hard ? hardList : NULL,
        used ? usedList : NULL
        );

    return v1_resource_quota_status_local_var;
end:
    if (hardList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hardList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(hardList);
        hardList = NULL;
    }
    if (usedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usedList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(usedList);
        usedList = NULL;
    }
    return NULL;

}
