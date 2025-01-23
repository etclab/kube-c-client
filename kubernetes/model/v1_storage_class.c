#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_class.h"



v1_storage_class_t *v1_storage_class_create(
    int allow_volume_expansion,
    list_t *allowed_topologies,
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *mount_options,
    list_t* parameters,
    char *provisioner,
    char *reclaim_policy,
    char *volume_binding_mode
    ) {
    v1_storage_class_t *v1_storage_class_local_var = malloc(sizeof(v1_storage_class_t));
    if (!v1_storage_class_local_var) {
        return NULL;
    }
    v1_storage_class_local_var->allow_volume_expansion = allow_volume_expansion;
    v1_storage_class_local_var->allowed_topologies = allowed_topologies;
    v1_storage_class_local_var->api_version = api_version;
    v1_storage_class_local_var->kind = kind;
    v1_storage_class_local_var->metadata = metadata;
    v1_storage_class_local_var->mount_options = mount_options;
    v1_storage_class_local_var->parameters = parameters;
    v1_storage_class_local_var->provisioner = provisioner;
    v1_storage_class_local_var->reclaim_policy = reclaim_policy;
    v1_storage_class_local_var->volume_binding_mode = volume_binding_mode;

    return v1_storage_class_local_var;
}


void v1_storage_class_free(v1_storage_class_t *v1_storage_class) {
    if(NULL == v1_storage_class){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_class->allowed_topologies) {
        list_ForEach(listEntry, v1_storage_class->allowed_topologies) {
            v1_topology_selector_term_free(listEntry->data);
        }
        list_freeList(v1_storage_class->allowed_topologies);
        v1_storage_class->allowed_topologies = NULL;
    }
    if (v1_storage_class->api_version) {
        free(v1_storage_class->api_version);
        v1_storage_class->api_version = NULL;
    }
    if (v1_storage_class->kind) {
        free(v1_storage_class->kind);
        v1_storage_class->kind = NULL;
    }
    if (v1_storage_class->metadata) {
        v1_object_meta_free(v1_storage_class->metadata);
        v1_storage_class->metadata = NULL;
    }
    if (v1_storage_class->mount_options) {
        list_ForEach(listEntry, v1_storage_class->mount_options) {
            free(listEntry->data);
        }
        list_freeList(v1_storage_class->mount_options);
        v1_storage_class->mount_options = NULL;
    }
    if (v1_storage_class->parameters) {
        list_ForEach(listEntry, v1_storage_class->parameters) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_storage_class->parameters);
        v1_storage_class->parameters = NULL;
    }
    if (v1_storage_class->provisioner) {
        free(v1_storage_class->provisioner);
        v1_storage_class->provisioner = NULL;
    }
    if (v1_storage_class->reclaim_policy) {
        free(v1_storage_class->reclaim_policy);
        v1_storage_class->reclaim_policy = NULL;
    }
    if (v1_storage_class->volume_binding_mode) {
        free(v1_storage_class->volume_binding_mode);
        v1_storage_class->volume_binding_mode = NULL;
    }
    free(v1_storage_class);
}

mazu_cJSON *v1_storage_class_convertToJSON(v1_storage_class_t *v1_storage_class) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_storage_class->allow_volume_expansion
    if(v1_storage_class->allow_volume_expansion) {
    if(mazu_cJSON_AddBoolToObject(item, "allowVolumeExpansion", v1_storage_class->allow_volume_expansion) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_storage_class->allowed_topologies
    if(v1_storage_class->allowed_topologies) {
    mazu_cJSON *allowed_topologies = mazu_cJSON_AddArrayToObject(item, "allowedTopologies");
    if(allowed_topologies == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_topologiesListEntry;
    if (v1_storage_class->allowed_topologies) {
    list_ForEach(allowed_topologiesListEntry, v1_storage_class->allowed_topologies) {
    mazu_cJSON *itemLocal = v1_topology_selector_term_convertToJSON(allowed_topologiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(allowed_topologies, itemLocal);
    }
    }
    }


    // v1_storage_class->api_version
    if(v1_storage_class->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", v1_storage_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_class->kind
    if(v1_storage_class->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_storage_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_class->metadata
    if(v1_storage_class->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_storage_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_storage_class->mount_options
    if(v1_storage_class->mount_options) {
    mazu_cJSON *mount_options = mazu_cJSON_AddArrayToObject(item, "mountOptions");
    if(mount_options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mount_optionsListEntry;
    list_ForEach(mount_optionsListEntry, v1_storage_class->mount_options) {
    if(mazu_cJSON_AddStringToObject(mount_options, "", (char*)mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_storage_class->parameters
    if(v1_storage_class->parameters) {
    mazu_cJSON *parameters = mazu_cJSON_AddObjectToObject(item, "parameters");
    if(parameters == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = parameters;
    listEntry_t *parametersListEntry;
    if (v1_storage_class->parameters) {
    list_ForEach(parametersListEntry, v1_storage_class->parameters) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)parametersListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_storage_class->provisioner
    if (!v1_storage_class->provisioner) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "provisioner", v1_storage_class->provisioner) == NULL) {
    goto fail; //String
    }


    // v1_storage_class->reclaim_policy
    if(v1_storage_class->reclaim_policy) {
    if(mazu_cJSON_AddStringToObject(item, "reclaimPolicy", v1_storage_class->reclaim_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_class->volume_binding_mode
    if(v1_storage_class->volume_binding_mode) {
    if(mazu_cJSON_AddStringToObject(item, "volumeBindingMode", v1_storage_class->volume_binding_mode) == NULL) {
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

v1_storage_class_t *v1_storage_class_parseFromJSON(mazu_cJSON *v1_storage_classJSON){

    v1_storage_class_t *v1_storage_class_local_var = NULL;

    // define the local list for v1_storage_class->allowed_topologies
    list_t *allowed_topologiesList = NULL;

    // define the local variable for v1_storage_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_storage_class->mount_options
    list_t *mount_optionsList = NULL;

    // define the local map for v1_storage_class->parameters
    list_t *parametersList = NULL;

    // v1_storage_class->allow_volume_expansion
    mazu_cJSON *allow_volume_expansion = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "allowVolumeExpansion");
    if (allow_volume_expansion) { 
    if(!mazu_cJSON_IsBool(allow_volume_expansion))
    {
    goto end; //Bool
    }
    }

    // v1_storage_class->allowed_topologies
    mazu_cJSON *allowed_topologies = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "allowedTopologies");
    if (allowed_topologies) { 
    mazu_cJSON *allowed_topologies_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(allowed_topologies)){
        goto end; //nonprimitive container
    }

    allowed_topologiesList = list_createList();

    mazu_cJSON_ArrayForEach(allowed_topologies_local_nonprimitive,allowed_topologies )
    {
        if(!mazu_cJSON_IsObject(allowed_topologies_local_nonprimitive)){
            goto end;
        }
        v1_topology_selector_term_t *allowed_topologiesItem = v1_topology_selector_term_parseFromJSON(allowed_topologies_local_nonprimitive);

        list_addElement(allowed_topologiesList, allowed_topologiesItem);
    }
    }

    // v1_storage_class->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_storage_class->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_storage_class->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_storage_class->mount_options
    mazu_cJSON *mount_options = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "mountOptions");
    if (mount_options) { 
    mazu_cJSON *mount_options_local = NULL;
    if(!mazu_cJSON_IsArray(mount_options)) {
        goto end;//primitive container
    }
    mount_optionsList = list_createList();

    mazu_cJSON_ArrayForEach(mount_options_local, mount_options)
    {
        if(!mazu_cJSON_IsString(mount_options_local))
        {
            goto end;
        }
        list_addElement(mount_optionsList , strdup(mount_options_local->valuestring));
    }
    }

    // v1_storage_class->parameters
    mazu_cJSON *parameters = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "parameters");
    if (parameters) { 
    mazu_cJSON *parameters_local_map = NULL;
    if(!mazu_cJSON_IsObject(parameters) && !mazu_cJSON_IsNull(parameters))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(parameters))
    {
        parametersList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(parameters_local_map, parameters)
        {
            mazu_cJSON *localMapObject = parameters_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(parametersList , localMapKeyPair);
        }
    }
    }

    // v1_storage_class->provisioner
    mazu_cJSON *provisioner = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "provisioner");
    if (!provisioner) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(provisioner))
    {
    goto end; //String
    }

    // v1_storage_class->reclaim_policy
    mazu_cJSON *reclaim_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "reclaimPolicy");
    if (reclaim_policy) { 
    if(!mazu_cJSON_IsString(reclaim_policy) && !mazu_cJSON_IsNull(reclaim_policy))
    {
    goto end; //String
    }
    }

    // v1_storage_class->volume_binding_mode
    mazu_cJSON *volume_binding_mode = mazu_cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "volumeBindingMode");
    if (volume_binding_mode) { 
    if(!mazu_cJSON_IsString(volume_binding_mode) && !mazu_cJSON_IsNull(volume_binding_mode))
    {
    goto end; //String
    }
    }


    v1_storage_class_local_var = v1_storage_class_create (
        allow_volume_expansion ? allow_volume_expansion->valueint : 0,
        allowed_topologies ? allowed_topologiesList : NULL,
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        mount_options ? mount_optionsList : NULL,
        parameters ? parametersList : NULL,
        strdup(provisioner->valuestring),
        reclaim_policy && !mazu_cJSON_IsNull(reclaim_policy) ? strdup(reclaim_policy->valuestring) : NULL,
        volume_binding_mode && !mazu_cJSON_IsNull(volume_binding_mode) ? strdup(volume_binding_mode->valuestring) : NULL
        );

    return v1_storage_class_local_var;
end:
    if (allowed_topologiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_topologiesList) {
            v1_topology_selector_term_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_topologiesList);
        allowed_topologiesList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (mount_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mount_optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mount_optionsList);
        mount_optionsList = NULL;
    }
    if (parametersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, parametersList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(parametersList);
        parametersList = NULL;
    }
    return NULL;

}
