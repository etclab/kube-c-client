#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_certificate_signing_request_spec.h"



v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec_create(
    int expiration_seconds,
    list_t* extra,
    list_t *groups,
    char *request,
    char *signer_name,
    char *uid,
    list_t *usages,
    char *username
    ) {
    v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec_local_var = malloc(sizeof(v1_certificate_signing_request_spec_t));
    if (!v1_certificate_signing_request_spec_local_var) {
        return NULL;
    }
    v1_certificate_signing_request_spec_local_var->expiration_seconds = expiration_seconds;
    v1_certificate_signing_request_spec_local_var->extra = extra;
    v1_certificate_signing_request_spec_local_var->groups = groups;
    v1_certificate_signing_request_spec_local_var->request = request;
    v1_certificate_signing_request_spec_local_var->signer_name = signer_name;
    v1_certificate_signing_request_spec_local_var->uid = uid;
    v1_certificate_signing_request_spec_local_var->usages = usages;
    v1_certificate_signing_request_spec_local_var->username = username;

    return v1_certificate_signing_request_spec_local_var;
}


void v1_certificate_signing_request_spec_free(v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec) {
    if(NULL == v1_certificate_signing_request_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_certificate_signing_request_spec->extra) {
        list_ForEach(listEntry, v1_certificate_signing_request_spec->extra) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_certificate_signing_request_spec->extra);
        v1_certificate_signing_request_spec->extra = NULL;
    }
    if (v1_certificate_signing_request_spec->groups) {
        list_ForEach(listEntry, v1_certificate_signing_request_spec->groups) {
            free(listEntry->data);
        }
        list_freeList(v1_certificate_signing_request_spec->groups);
        v1_certificate_signing_request_spec->groups = NULL;
    }
    if (v1_certificate_signing_request_spec->request) {
        free(v1_certificate_signing_request_spec->request);
        v1_certificate_signing_request_spec->request = NULL;
    }
    if (v1_certificate_signing_request_spec->signer_name) {
        free(v1_certificate_signing_request_spec->signer_name);
        v1_certificate_signing_request_spec->signer_name = NULL;
    }
    if (v1_certificate_signing_request_spec->uid) {
        free(v1_certificate_signing_request_spec->uid);
        v1_certificate_signing_request_spec->uid = NULL;
    }
    if (v1_certificate_signing_request_spec->usages) {
        list_ForEach(listEntry, v1_certificate_signing_request_spec->usages) {
            free(listEntry->data);
        }
        list_freeList(v1_certificate_signing_request_spec->usages);
        v1_certificate_signing_request_spec->usages = NULL;
    }
    if (v1_certificate_signing_request_spec->username) {
        free(v1_certificate_signing_request_spec->username);
        v1_certificate_signing_request_spec->username = NULL;
    }
    free(v1_certificate_signing_request_spec);
}

mazu_cJSON *v1_certificate_signing_request_spec_convertToJSON(v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_certificate_signing_request_spec->expiration_seconds
    if(v1_certificate_signing_request_spec->expiration_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "expirationSeconds", v1_certificate_signing_request_spec->expiration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_certificate_signing_request_spec->extra
    if(v1_certificate_signing_request_spec->extra) {
    mazu_cJSON *extra = mazu_cJSON_AddObjectToObject(item, "extra");
    if(extra == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = extra;
    listEntry_t *extraListEntry;
    if (v1_certificate_signing_request_spec->extra) {
    list_ForEach(extraListEntry, v1_certificate_signing_request_spec->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
    }
    }
    }


    // v1_certificate_signing_request_spec->groups
    if(v1_certificate_signing_request_spec->groups) {
    mazu_cJSON *groups = mazu_cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *groupsListEntry;
    list_ForEach(groupsListEntry, v1_certificate_signing_request_spec->groups) {
    if(mazu_cJSON_AddStringToObject(groups, "", (char*)groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_certificate_signing_request_spec->request
    if (!v1_certificate_signing_request_spec->request) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "request", v1_certificate_signing_request_spec->request) == NULL) {
    goto fail; //ByteArray
    }


    // v1_certificate_signing_request_spec->signer_name
    if (!v1_certificate_signing_request_spec->signer_name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "signerName", v1_certificate_signing_request_spec->signer_name) == NULL) {
    goto fail; //String
    }


    // v1_certificate_signing_request_spec->uid
    if(v1_certificate_signing_request_spec->uid) {
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_certificate_signing_request_spec->uid) == NULL) {
    goto fail; //String
    }
    }


    // v1_certificate_signing_request_spec->usages
    if(v1_certificate_signing_request_spec->usages) {
    mazu_cJSON *usages = mazu_cJSON_AddArrayToObject(item, "usages");
    if(usages == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *usagesListEntry;
    list_ForEach(usagesListEntry, v1_certificate_signing_request_spec->usages) {
    if(mazu_cJSON_AddStringToObject(usages, "", (char*)usagesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_certificate_signing_request_spec->username
    if(v1_certificate_signing_request_spec->username) {
    if(mazu_cJSON_AddStringToObject(item, "username", v1_certificate_signing_request_spec->username) == NULL) {
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

v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec_parseFromJSON(mazu_cJSON *v1_certificate_signing_request_specJSON){

    v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec_local_var = NULL;

    // define the local map for v1_certificate_signing_request_spec->extra
    list_t *extraList = NULL;

    // define the local list for v1_certificate_signing_request_spec->groups
    list_t *groupsList = NULL;

    // define the local list for v1_certificate_signing_request_spec->usages
    list_t *usagesList = NULL;

    // v1_certificate_signing_request_spec->expiration_seconds
    mazu_cJSON *expiration_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "expirationSeconds");
    if (expiration_seconds) { 
    if(!mazu_cJSON_IsNumber(expiration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_certificate_signing_request_spec->extra
    mazu_cJSON *extra = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "extra");
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

    // v1_certificate_signing_request_spec->groups
    mazu_cJSON *groups = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "groups");
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

    // v1_certificate_signing_request_spec->request
    mazu_cJSON *request = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "request");
    if (!request) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(request))
    {
    goto end; //ByteArray
    }

    // v1_certificate_signing_request_spec->signer_name
    mazu_cJSON *signer_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "signerName");
    if (!signer_name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(signer_name))
    {
    goto end; //String
    }

    // v1_certificate_signing_request_spec->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "uid");
    if (uid) { 
    if(!mazu_cJSON_IsString(uid) && !mazu_cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }

    // v1_certificate_signing_request_spec->usages
    mazu_cJSON *usages = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "usages");
    if (usages) { 
    mazu_cJSON *usages_local = NULL;
    if(!mazu_cJSON_IsArray(usages)) {
        goto end;//primitive container
    }
    usagesList = list_createList();

    mazu_cJSON_ArrayForEach(usages_local, usages)
    {
        if(!mazu_cJSON_IsString(usages_local))
        {
            goto end;
        }
        list_addElement(usagesList , strdup(usages_local->valuestring));
    }
    }

    // v1_certificate_signing_request_spec->username
    mazu_cJSON *username = mazu_cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_request_specJSON, "username");
    if (username) { 
    if(!mazu_cJSON_IsString(username) && !mazu_cJSON_IsNull(username))
    {
    goto end; //String
    }
    }


    v1_certificate_signing_request_spec_local_var = v1_certificate_signing_request_spec_create (
        expiration_seconds ? expiration_seconds->valuedouble : 0,
        extra ? extraList : NULL,
        groups ? groupsList : NULL,
        strdup(request->valuestring),
        strdup(signer_name->valuestring),
        uid && !mazu_cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL,
        usages ? usagesList : NULL,
        username && !mazu_cJSON_IsNull(username) ? strdup(username->valuestring) : NULL
        );

    return v1_certificate_signing_request_spec_local_var;
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
    if (usagesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usagesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(usagesList);
        usagesList = NULL;
    }
    return NULL;

}
