#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_node_driver.h"



v1_csi_node_driver_t *v1_csi_node_driver_create(
    v1_volume_node_resources_t *allocatable,
    char *name,
    char *node_id,
    list_t *topology_keys
    ) {
    v1_csi_node_driver_t *v1_csi_node_driver_local_var = malloc(sizeof(v1_csi_node_driver_t));
    if (!v1_csi_node_driver_local_var) {
        return NULL;
    }
    v1_csi_node_driver_local_var->allocatable = allocatable;
    v1_csi_node_driver_local_var->name = name;
    v1_csi_node_driver_local_var->node_id = node_id;
    v1_csi_node_driver_local_var->topology_keys = topology_keys;

    return v1_csi_node_driver_local_var;
}


void v1_csi_node_driver_free(v1_csi_node_driver_t *v1_csi_node_driver) {
    if(NULL == v1_csi_node_driver){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_node_driver->allocatable) {
        v1_volume_node_resources_free(v1_csi_node_driver->allocatable);
        v1_csi_node_driver->allocatable = NULL;
    }
    if (v1_csi_node_driver->name) {
        free(v1_csi_node_driver->name);
        v1_csi_node_driver->name = NULL;
    }
    if (v1_csi_node_driver->node_id) {
        free(v1_csi_node_driver->node_id);
        v1_csi_node_driver->node_id = NULL;
    }
    if (v1_csi_node_driver->topology_keys) {
        list_ForEach(listEntry, v1_csi_node_driver->topology_keys) {
            free(listEntry->data);
        }
        list_freeList(v1_csi_node_driver->topology_keys);
        v1_csi_node_driver->topology_keys = NULL;
    }
    free(v1_csi_node_driver);
}

mazu_cJSON *v1_csi_node_driver_convertToJSON(v1_csi_node_driver_t *v1_csi_node_driver) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_csi_node_driver->allocatable
    if(v1_csi_node_driver->allocatable) {
    mazu_cJSON *allocatable_local_JSON = v1_volume_node_resources_convertToJSON(v1_csi_node_driver->allocatable);
    if(allocatable_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "allocatable", allocatable_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_csi_node_driver->name
    if (!v1_csi_node_driver->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_csi_node_driver->name) == NULL) {
    goto fail; //String
    }


    // v1_csi_node_driver->node_id
    if (!v1_csi_node_driver->node_id) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "nodeID", v1_csi_node_driver->node_id) == NULL) {
    goto fail; //String
    }


    // v1_csi_node_driver->topology_keys
    if(v1_csi_node_driver->topology_keys) {
    mazu_cJSON *topology_keys = mazu_cJSON_AddArrayToObject(item, "topologyKeys");
    if(topology_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *topology_keysListEntry;
    list_ForEach(topology_keysListEntry, v1_csi_node_driver->topology_keys) {
    if(mazu_cJSON_AddStringToObject(topology_keys, "", (char*)topology_keysListEntry->data) == NULL)
    {
        goto fail;
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

v1_csi_node_driver_t *v1_csi_node_driver_parseFromJSON(mazu_cJSON *v1_csi_node_driverJSON){

    v1_csi_node_driver_t *v1_csi_node_driver_local_var = NULL;

    // define the local variable for v1_csi_node_driver->allocatable
    v1_volume_node_resources_t *allocatable_local_nonprim = NULL;

    // define the local list for v1_csi_node_driver->topology_keys
    list_t *topology_keysList = NULL;

    // v1_csi_node_driver->allocatable
    mazu_cJSON *allocatable = mazu_cJSON_GetObjectItemCaseSensitive(v1_csi_node_driverJSON, "allocatable");
    if (allocatable) { 
    allocatable_local_nonprim = v1_volume_node_resources_parseFromJSON(allocatable); //nonprimitive
    }

    // v1_csi_node_driver->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_csi_node_driverJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_csi_node_driver->node_id
    mazu_cJSON *node_id = mazu_cJSON_GetObjectItemCaseSensitive(v1_csi_node_driverJSON, "nodeID");
    if (!node_id) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(node_id))
    {
    goto end; //String
    }

    // v1_csi_node_driver->topology_keys
    mazu_cJSON *topology_keys = mazu_cJSON_GetObjectItemCaseSensitive(v1_csi_node_driverJSON, "topologyKeys");
    if (topology_keys) { 
    mazu_cJSON *topology_keys_local = NULL;
    if(!mazu_cJSON_IsArray(topology_keys)) {
        goto end;//primitive container
    }
    topology_keysList = list_createList();

    mazu_cJSON_ArrayForEach(topology_keys_local, topology_keys)
    {
        if(!mazu_cJSON_IsString(topology_keys_local))
        {
            goto end;
        }
        list_addElement(topology_keysList , strdup(topology_keys_local->valuestring));
    }
    }


    v1_csi_node_driver_local_var = v1_csi_node_driver_create (
        allocatable ? allocatable_local_nonprim : NULL,
        strdup(name->valuestring),
        strdup(node_id->valuestring),
        topology_keys ? topology_keysList : NULL
        );

    return v1_csi_node_driver_local_var;
end:
    if (allocatable_local_nonprim) {
        v1_volume_node_resources_free(allocatable_local_nonprim);
        allocatable_local_nonprim = NULL;
    }
    if (topology_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, topology_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(topology_keysList);
        topology_keysList = NULL;
    }
    return NULL;

}
