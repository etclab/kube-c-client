#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_webhook_conversion.h"



v1_webhook_conversion_t *v1_webhook_conversion_create(
    apiextensions_v1_webhook_client_config_t *client_config,
    list_t *conversion_review_versions
    ) {
    v1_webhook_conversion_t *v1_webhook_conversion_local_var = malloc(sizeof(v1_webhook_conversion_t));
    if (!v1_webhook_conversion_local_var) {
        return NULL;
    }
    v1_webhook_conversion_local_var->client_config = client_config;
    v1_webhook_conversion_local_var->conversion_review_versions = conversion_review_versions;

    return v1_webhook_conversion_local_var;
}


void v1_webhook_conversion_free(v1_webhook_conversion_t *v1_webhook_conversion) {
    if(NULL == v1_webhook_conversion){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_webhook_conversion->client_config) {
        apiextensions_v1_webhook_client_config_free(v1_webhook_conversion->client_config);
        v1_webhook_conversion->client_config = NULL;
    }
    if (v1_webhook_conversion->conversion_review_versions) {
        list_ForEach(listEntry, v1_webhook_conversion->conversion_review_versions) {
            free(listEntry->data);
        }
        list_freeList(v1_webhook_conversion->conversion_review_versions);
        v1_webhook_conversion->conversion_review_versions = NULL;
    }
    free(v1_webhook_conversion);
}

mazu_cJSON *v1_webhook_conversion_convertToJSON(v1_webhook_conversion_t *v1_webhook_conversion) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_webhook_conversion->client_config
    if(v1_webhook_conversion->client_config) {
    mazu_cJSON *client_config_local_JSON = apiextensions_v1_webhook_client_config_convertToJSON(v1_webhook_conversion->client_config);
    if(client_config_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "clientConfig", client_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_webhook_conversion->conversion_review_versions
    if (!v1_webhook_conversion->conversion_review_versions) {
        goto fail;
    }
    mazu_cJSON *conversion_review_versions = mazu_cJSON_AddArrayToObject(item, "conversionReviewVersions");
    if(conversion_review_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *conversion_review_versionsListEntry;
    list_ForEach(conversion_review_versionsListEntry, v1_webhook_conversion->conversion_review_versions) {
    if(mazu_cJSON_AddStringToObject(conversion_review_versions, "", (char*)conversion_review_versionsListEntry->data) == NULL)
    {
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

v1_webhook_conversion_t *v1_webhook_conversion_parseFromJSON(mazu_cJSON *v1_webhook_conversionJSON){

    v1_webhook_conversion_t *v1_webhook_conversion_local_var = NULL;

    // define the local variable for v1_webhook_conversion->client_config
    apiextensions_v1_webhook_client_config_t *client_config_local_nonprim = NULL;

    // define the local list for v1_webhook_conversion->conversion_review_versions
    list_t *conversion_review_versionsList = NULL;

    // v1_webhook_conversion->client_config
    mazu_cJSON *client_config = mazu_cJSON_GetObjectItemCaseSensitive(v1_webhook_conversionJSON, "clientConfig");
    if (client_config) { 
    client_config_local_nonprim = apiextensions_v1_webhook_client_config_parseFromJSON(client_config); //nonprimitive
    }

    // v1_webhook_conversion->conversion_review_versions
    mazu_cJSON *conversion_review_versions = mazu_cJSON_GetObjectItemCaseSensitive(v1_webhook_conversionJSON, "conversionReviewVersions");
    if (!conversion_review_versions) {
        goto end;
    }

    
    mazu_cJSON *conversion_review_versions_local = NULL;
    if(!mazu_cJSON_IsArray(conversion_review_versions)) {
        goto end;//primitive container
    }
    conversion_review_versionsList = list_createList();

    mazu_cJSON_ArrayForEach(conversion_review_versions_local, conversion_review_versions)
    {
        if(!mazu_cJSON_IsString(conversion_review_versions_local))
        {
            goto end;
        }
        list_addElement(conversion_review_versionsList , strdup(conversion_review_versions_local->valuestring));
    }


    v1_webhook_conversion_local_var = v1_webhook_conversion_create (
        client_config ? client_config_local_nonprim : NULL,
        conversion_review_versionsList
        );

    return v1_webhook_conversion_local_var;
end:
    if (client_config_local_nonprim) {
        apiextensions_v1_webhook_client_config_free(client_config_local_nonprim);
        client_config_local_nonprim = NULL;
    }
    if (conversion_review_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conversion_review_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conversion_review_versionsList);
        conversion_review_versionsList = NULL;
    }
    return NULL;

}
