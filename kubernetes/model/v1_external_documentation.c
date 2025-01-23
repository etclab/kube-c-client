#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_external_documentation.h"



v1_external_documentation_t *v1_external_documentation_create(
    char *description,
    char *url
    ) {
    v1_external_documentation_t *v1_external_documentation_local_var = malloc(sizeof(v1_external_documentation_t));
    if (!v1_external_documentation_local_var) {
        return NULL;
    }
    v1_external_documentation_local_var->description = description;
    v1_external_documentation_local_var->url = url;

    return v1_external_documentation_local_var;
}


void v1_external_documentation_free(v1_external_documentation_t *v1_external_documentation) {
    if(NULL == v1_external_documentation){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_external_documentation->description) {
        free(v1_external_documentation->description);
        v1_external_documentation->description = NULL;
    }
    if (v1_external_documentation->url) {
        free(v1_external_documentation->url);
        v1_external_documentation->url = NULL;
    }
    free(v1_external_documentation);
}

mazu_cJSON *v1_external_documentation_convertToJSON(v1_external_documentation_t *v1_external_documentation) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_external_documentation->description
    if(v1_external_documentation->description) {
    if(mazu_cJSON_AddStringToObject(item, "description", v1_external_documentation->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_external_documentation->url
    if(v1_external_documentation->url) {
    if(mazu_cJSON_AddStringToObject(item, "url", v1_external_documentation->url) == NULL) {
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

v1_external_documentation_t *v1_external_documentation_parseFromJSON(mazu_cJSON *v1_external_documentationJSON){

    v1_external_documentation_t *v1_external_documentation_local_var = NULL;

    // v1_external_documentation->description
    mazu_cJSON *description = mazu_cJSON_GetObjectItemCaseSensitive(v1_external_documentationJSON, "description");
    if (description) { 
    if(!mazu_cJSON_IsString(description) && !mazu_cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_external_documentation->url
    mazu_cJSON *url = mazu_cJSON_GetObjectItemCaseSensitive(v1_external_documentationJSON, "url");
    if (url) { 
    if(!mazu_cJSON_IsString(url) && !mazu_cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    v1_external_documentation_local_var = v1_external_documentation_create (
        description && !mazu_cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        url && !mazu_cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return v1_external_documentation_local_var;
end:
    return NULL;

}
