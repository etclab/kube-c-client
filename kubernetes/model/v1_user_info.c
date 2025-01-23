#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_user_info.h"



v1_user_info_t *v1_user_info_create(
    list_t* extra,
    list_t *groups,
    char *uid,
    char *username
    ) {
    v1_user_info_t *v1_user_info_local_var = malloc(sizeof(v1_user_info_t));
    if (!v1_user_info_local_var) {
        return NULL;
    }
    v1_user_info_local_var->extra = extra;
    v1_user_info_local_var->groups = groups;
    v1_user_info_local_var->uid = uid;
    v1_user_info_local_var->username = username;

    return v1_user_info_local_var;
}


void v1_user_info_free(v1_user_info_t *v1_user_info) {
    if(NULL == v1_user_info){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_user_info->extra) {
        list_ForEach(listEntry, v1_user_info->extra) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_user_info->extra);
        v1_user_info->extra = NULL;
    }
    if (v1_user_info->groups) {
        list_ForEach(listEntry, v1_user_info->groups) {
            free(listEntry->data);
        }
        list_freeList(v1_user_info->groups);
        v1_user_info->groups = NULL;
    }
    if (v1_user_info->uid) {
        free(v1_user_info->uid);
        v1_user_info->uid = NULL;
    }
    if (v1_user_info->username) {
        free(v1_user_info->username);
        v1_user_info->username = NULL;
    }
    free(v1_user_info);
}

mazu_cJSON *v1_user_info_convertToJSON(v1_user_info_t *v1_user_info) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_user_info->extra
    if(v1_user_info->extra) {
    mazu_cJSON *extra = mazu_cJSON_AddObjectToObject(item, "extra");
    if(extra == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = extra;
    listEntry_t *extraListEntry;
    if (v1_user_info->extra) {
    list_ForEach(extraListEntry, v1_user_info->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
    }
    }
    }


    // v1_user_info->groups
    if(v1_user_info->groups) {
    mazu_cJSON *groups = mazu_cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *groupsListEntry;
    list_ForEach(groupsListEntry, v1_user_info->groups) {
    if(mazu_cJSON_AddStringToObject(groups, "", (char*)groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_user_info->uid
    if(v1_user_info->uid) {
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_user_info->uid) == NULL) {
    goto fail; //String
    }
    }


    // v1_user_info->username
    if(v1_user_info->username) {
    if(mazu_cJSON_AddStringToObject(item, "username", v1_user_info->username) == NULL) {
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

v1_user_info_t *v1_user_info_parseFromJSON(mazu_cJSON *v1_user_infoJSON){

    v1_user_info_t *v1_user_info_local_var = NULL;

    // define the local map for v1_user_info->extra
    list_t *extraList = NULL;

    // define the local list for v1_user_info->groups
    list_t *groupsList = NULL;

    // v1_user_info->extra
    mazu_cJSON *extra = mazu_cJSON_GetObjectItemCaseSensitive(v1_user_infoJSON, "extra");
    if (extra) { 
    mazu_cJSON *extra_local_map = NULL;
    if(!mazu_cJSON_IsObject(extra) && !mazu_cJSON_IsNull(extra))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(extra))
    {
        extraList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(extra_local_map, extra)
        {
            mazu_cJSON *localMapObject = extra_local_map;
            list_addElement(extraList , localMapKeyPair);
        }
    }
    }

    // v1_user_info->groups
    mazu_cJSON *groups = mazu_cJSON_GetObjectItemCaseSensitive(v1_user_infoJSON, "groups");
    if (groups) { 
    mazu_cJSON *groups_local = NULL;
    if(!mazu_cJSON_IsArray(groups)) {
        goto end;//primitive container
    }
    groupsList = list_createList();

    mazu_cJSON_ArrayForEach(groups_local, groups)
    {
        if(!mazu_cJSON_IsString(groups_local))
        {
            goto end;
        }
        list_addElement(groupsList , strdup(groups_local->valuestring));
    }
    }

    // v1_user_info->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_user_infoJSON, "uid");
    if (uid) { 
    if(!mazu_cJSON_IsString(uid) && !mazu_cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }

    // v1_user_info->username
    mazu_cJSON *username = mazu_cJSON_GetObjectItemCaseSensitive(v1_user_infoJSON, "username");
    if (username) { 
    if(!mazu_cJSON_IsString(username) && !mazu_cJSON_IsNull(username))
    {
    goto end; //String
    }
    }


    v1_user_info_local_var = v1_user_info_create (
        extra ? extraList : NULL,
        groups ? groupsList : NULL,
        uid && !mazu_cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL,
        username && !mazu_cJSON_IsNull(username) ? strdup(username->valuestring) : NULL
        );

    return v1_user_info_local_var;
end:
    if (extraList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, extraList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(extraList);
        extraList = NULL;
    }
    if (groupsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, groupsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(groupsList);
        groupsList = NULL;
    }
    return NULL;

}
