#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_attachment_status.h"



v1_volume_attachment_status_t *v1_volume_attachment_status_create(
    v1_volume_error_t *attach_error,
    int attached,
    list_t* attachment_metadata,
    v1_volume_error_t *detach_error
    ) {
    v1_volume_attachment_status_t *v1_volume_attachment_status_local_var = malloc(sizeof(v1_volume_attachment_status_t));
    if (!v1_volume_attachment_status_local_var) {
        return NULL;
    }
    v1_volume_attachment_status_local_var->attach_error = attach_error;
    v1_volume_attachment_status_local_var->attached = attached;
    v1_volume_attachment_status_local_var->attachment_metadata = attachment_metadata;
    v1_volume_attachment_status_local_var->detach_error = detach_error;

    return v1_volume_attachment_status_local_var;
}


void v1_volume_attachment_status_free(v1_volume_attachment_status_t *v1_volume_attachment_status) {
    if(NULL == v1_volume_attachment_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_attachment_status->attach_error) {
        v1_volume_error_free(v1_volume_attachment_status->attach_error);
        v1_volume_attachment_status->attach_error = NULL;
    }
    if (v1_volume_attachment_status->attachment_metadata) {
        list_ForEach(listEntry, v1_volume_attachment_status->attachment_metadata) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_volume_attachment_status->attachment_metadata);
        v1_volume_attachment_status->attachment_metadata = NULL;
    }
    if (v1_volume_attachment_status->detach_error) {
        v1_volume_error_free(v1_volume_attachment_status->detach_error);
        v1_volume_attachment_status->detach_error = NULL;
    }
    free(v1_volume_attachment_status);
}

mazu_cJSON *v1_volume_attachment_status_convertToJSON(v1_volume_attachment_status_t *v1_volume_attachment_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_volume_attachment_status->attach_error
    if(v1_volume_attachment_status->attach_error) {
    mazu_cJSON *attach_error_local_JSON = v1_volume_error_convertToJSON(v1_volume_attachment_status->attach_error);
    if(attach_error_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "attachError", attach_error_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_volume_attachment_status->attached
    if (!v1_volume_attachment_status->attached) {
        goto fail;
    }
    if(mazu_cJSON_AddBoolToObject(item, "attached", v1_volume_attachment_status->attached) == NULL) {
    goto fail; //Bool
    }


    // v1_volume_attachment_status->attachment_metadata
    if(v1_volume_attachment_status->attachment_metadata) {
    mazu_cJSON *attachment_metadata = mazu_cJSON_AddObjectToObject(item, "attachmentMetadata");
    if(attachment_metadata == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = attachment_metadata;
    listEntry_t *attachment_metadataListEntry;
    if (v1_volume_attachment_status->attachment_metadata) {
    list_ForEach(attachment_metadataListEntry, v1_volume_attachment_status->attachment_metadata) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)attachment_metadataListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_volume_attachment_status->detach_error
    if(v1_volume_attachment_status->detach_error) {
    mazu_cJSON *detach_error_local_JSON = v1_volume_error_convertToJSON(v1_volume_attachment_status->detach_error);
    if(detach_error_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "detachError", detach_error_local_JSON);
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

v1_volume_attachment_status_t *v1_volume_attachment_status_parseFromJSON(mazu_cJSON *v1_volume_attachment_statusJSON){

    v1_volume_attachment_status_t *v1_volume_attachment_status_local_var = NULL;

    // define the local variable for v1_volume_attachment_status->attach_error
    v1_volume_error_t *attach_error_local_nonprim = NULL;

    // define the local map for v1_volume_attachment_status->attachment_metadata
    list_t *attachment_metadataList = NULL;

    // define the local variable for v1_volume_attachment_status->detach_error
    v1_volume_error_t *detach_error_local_nonprim = NULL;

    // v1_volume_attachment_status->attach_error
    mazu_cJSON *attach_error = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_statusJSON, "attachError");
    if (attach_error) { 
    attach_error_local_nonprim = v1_volume_error_parseFromJSON(attach_error); //nonprimitive
    }

    // v1_volume_attachment_status->attached
    mazu_cJSON *attached = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_statusJSON, "attached");
    if (!attached) {
        goto end;
    }

    
    if(!mazu_cJSON_IsBool(attached))
    {
    goto end; //Bool
    }

    // v1_volume_attachment_status->attachment_metadata
    mazu_cJSON *attachment_metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_statusJSON, "attachmentMetadata");
    if (attachment_metadata) { 
    mazu_cJSON *attachment_metadata_local_map = NULL;
    if(!mazu_cJSON_IsObject(attachment_metadata) && !mazu_cJSON_IsNull(attachment_metadata))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(attachment_metadata))
    {
        attachment_metadataList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(attachment_metadata_local_map, attachment_metadata)
        {
            mazu_cJSON *localMapObject = attachment_metadata_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(attachment_metadataList , localMapKeyPair);
        }
    }
    }

    // v1_volume_attachment_status->detach_error
    mazu_cJSON *detach_error = mazu_cJSON_GetObjectItemCaseSensitive(v1_volume_attachment_statusJSON, "detachError");
    if (detach_error) { 
    detach_error_local_nonprim = v1_volume_error_parseFromJSON(detach_error); //nonprimitive
    }


    v1_volume_attachment_status_local_var = v1_volume_attachment_status_create (
        attach_error ? attach_error_local_nonprim : NULL,
        attached->valueint,
        attachment_metadata ? attachment_metadataList : NULL,
        detach_error ? detach_error_local_nonprim : NULL
        );

    return v1_volume_attachment_status_local_var;
end:
    if (attach_error_local_nonprim) {
        v1_volume_error_free(attach_error_local_nonprim);
        attach_error_local_nonprim = NULL;
    }
    if (attachment_metadataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, attachment_metadataList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(attachment_metadataList);
        attachment_metadataList = NULL;
    }
    if (detach_error_local_nonprim) {
        v1_volume_error_free(detach_error_local_nonprim);
        detach_error_local_nonprim = NULL;
    }
    return NULL;

}
