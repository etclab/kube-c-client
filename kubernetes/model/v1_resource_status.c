#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_status.h"



v1_resource_status_t *v1_resource_status_create(
    char *name,
    list_t *resources
    ) {
    v1_resource_status_t *v1_resource_status_local_var = malloc(sizeof(v1_resource_status_t));
    if (!v1_resource_status_local_var) {
        return NULL;
    }
    v1_resource_status_local_var->name = name;
    v1_resource_status_local_var->resources = resources;

    return v1_resource_status_local_var;
}


void v1_resource_status_free(v1_resource_status_t *v1_resource_status) {
    if(NULL == v1_resource_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_status->name) {
        free(v1_resource_status->name);
        v1_resource_status->name = NULL;
    }
    if (v1_resource_status->resources) {
        list_ForEach(listEntry, v1_resource_status->resources) {
            v1_resource_health_free(listEntry->data);
        }
        list_freeList(v1_resource_status->resources);
        v1_resource_status->resources = NULL;
    }
    free(v1_resource_status);
}

mazu_cJSON *v1_resource_status_convertToJSON(v1_resource_status_t *v1_resource_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_resource_status->name
    if (!v1_resource_status->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_resource_status->name) == NULL) {
    goto fail; //String
    }


    // v1_resource_status->resources
    if(v1_resource_status->resources) {
    mazu_cJSON *resources = mazu_cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resourcesListEntry;
    if (v1_resource_status->resources) {
    list_ForEach(resourcesListEntry, v1_resource_status->resources) {
    mazu_cJSON *itemLocal = v1_resource_health_convertToJSON(resourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(resources, itemLocal);
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

v1_resource_status_t *v1_resource_status_parseFromJSON(mazu_cJSON *v1_resource_statusJSON){

    v1_resource_status_t *v1_resource_status_local_var = NULL;

    // define the local list for v1_resource_status->resources
    list_t *resourcesList = NULL;

    // v1_resource_status->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_resource_status->resources
    mazu_cJSON *resources = mazu_cJSON_GetObjectItemCaseSensitive(v1_resource_statusJSON, "resources");
    if (resources) { 
    mazu_cJSON *resources_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(resources)){
        goto end; //nonprimitive container
    }

    resourcesList = list_createList();

    mazu_cJSON_ArrayForEach(resources_local_nonprimitive,resources )
    {
        if(!mazu_cJSON_IsObject(resources_local_nonprimitive)){
            goto end;
        }
        v1_resource_health_t *resourcesItem = v1_resource_health_parseFromJSON(resources_local_nonprimitive);

        list_addElement(resourcesList, resourcesItem);
    }
    }


    v1_resource_status_local_var = v1_resource_status_create (
        strdup(name->valuestring),
        resources ? resourcesList : NULL
        );

    return v1_resource_status_local_var;
end:
    if (resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resourcesList) {
            v1_resource_health_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resourcesList);
        resourcesList = NULL;
    }
    return NULL;

}
