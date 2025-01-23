#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_meta.h"



v1_object_meta_t *v1_object_meta_create(
    list_t* annotations,
    char *creation_timestamp,
    long deletion_grace_period_seconds,
    char *deletion_timestamp,
    list_t *finalizers,
    char *generate_name,
    long generation,
    list_t* labels,
    list_t *managed_fields,
    char *name,
    char *_namespace,
    list_t *owner_references,
    char *resource_version,
    char *self_link,
    char *uid
    ) {
    v1_object_meta_t *v1_object_meta_local_var = malloc(sizeof(v1_object_meta_t));
    if (!v1_object_meta_local_var) {
        return NULL;
    }
    v1_object_meta_local_var->annotations = annotations;
    v1_object_meta_local_var->creation_timestamp = creation_timestamp;
    v1_object_meta_local_var->deletion_grace_period_seconds = deletion_grace_period_seconds;
    v1_object_meta_local_var->deletion_timestamp = deletion_timestamp;
    v1_object_meta_local_var->finalizers = finalizers;
    v1_object_meta_local_var->generate_name = generate_name;
    v1_object_meta_local_var->generation = generation;
    v1_object_meta_local_var->labels = labels;
    v1_object_meta_local_var->managed_fields = managed_fields;
    v1_object_meta_local_var->name = name;
    v1_object_meta_local_var->_namespace = _namespace;
    v1_object_meta_local_var->owner_references = owner_references;
    v1_object_meta_local_var->resource_version = resource_version;
    v1_object_meta_local_var->self_link = self_link;
    v1_object_meta_local_var->uid = uid;

    return v1_object_meta_local_var;
}


void v1_object_meta_free(v1_object_meta_t *v1_object_meta) {
    if(NULL == v1_object_meta){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_object_meta->annotations) {
        list_ForEach(listEntry, v1_object_meta->annotations) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_object_meta->annotations);
        v1_object_meta->annotations = NULL;
    }
    if (v1_object_meta->creation_timestamp) {
        free(v1_object_meta->creation_timestamp);
        v1_object_meta->creation_timestamp = NULL;
    }
    if (v1_object_meta->deletion_timestamp) {
        free(v1_object_meta->deletion_timestamp);
        v1_object_meta->deletion_timestamp = NULL;
    }
    if (v1_object_meta->finalizers) {
        list_ForEach(listEntry, v1_object_meta->finalizers) {
            free(listEntry->data);
        }
        list_freeList(v1_object_meta->finalizers);
        v1_object_meta->finalizers = NULL;
    }
    if (v1_object_meta->generate_name) {
        free(v1_object_meta->generate_name);
        v1_object_meta->generate_name = NULL;
    }
    if (v1_object_meta->labels) {
        list_ForEach(listEntry, v1_object_meta->labels) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_object_meta->labels);
        v1_object_meta->labels = NULL;
    }
    if (v1_object_meta->managed_fields) {
        list_ForEach(listEntry, v1_object_meta->managed_fields) {
            v1_managed_fields_entry_free(listEntry->data);
        }
        list_freeList(v1_object_meta->managed_fields);
        v1_object_meta->managed_fields = NULL;
    }
    if (v1_object_meta->name) {
        free(v1_object_meta->name);
        v1_object_meta->name = NULL;
    }
    if (v1_object_meta->_namespace) {
        free(v1_object_meta->_namespace);
        v1_object_meta->_namespace = NULL;
    }
    if (v1_object_meta->owner_references) {
        list_ForEach(listEntry, v1_object_meta->owner_references) {
            v1_owner_reference_free(listEntry->data);
        }
        list_freeList(v1_object_meta->owner_references);
        v1_object_meta->owner_references = NULL;
    }
    if (v1_object_meta->resource_version) {
        free(v1_object_meta->resource_version);
        v1_object_meta->resource_version = NULL;
    }
    if (v1_object_meta->self_link) {
        free(v1_object_meta->self_link);
        v1_object_meta->self_link = NULL;
    }
    if (v1_object_meta->uid) {
        free(v1_object_meta->uid);
        v1_object_meta->uid = NULL;
    }
    free(v1_object_meta);
}

mazu_cJSON *v1_object_meta_convertToJSON(v1_object_meta_t *v1_object_meta) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_object_meta->annotations
    if(v1_object_meta->annotations) {
    mazu_cJSON *annotations = mazu_cJSON_AddObjectToObject(item, "annotations");
    if(annotations == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = annotations;
    listEntry_t *annotationsListEntry;
    if (v1_object_meta->annotations) {
    list_ForEach(annotationsListEntry, v1_object_meta->annotations) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)annotationsListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_object_meta->creation_timestamp
    if(v1_object_meta->creation_timestamp) {
    if(mazu_cJSON_AddStringToObject(item, "creationTimestamp", v1_object_meta->creation_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_object_meta->deletion_grace_period_seconds
    if(v1_object_meta->deletion_grace_period_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "deletionGracePeriodSeconds", v1_object_meta->deletion_grace_period_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_object_meta->deletion_timestamp
    if(v1_object_meta->deletion_timestamp) {
    if(mazu_cJSON_AddStringToObject(item, "deletionTimestamp", v1_object_meta->deletion_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_object_meta->finalizers
    if(v1_object_meta->finalizers) {
    mazu_cJSON *finalizers = mazu_cJSON_AddArrayToObject(item, "finalizers");
    if(finalizers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *finalizersListEntry;
    list_ForEach(finalizersListEntry, v1_object_meta->finalizers) {
    if(mazu_cJSON_AddStringToObject(finalizers, "", (char*)finalizersListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_object_meta->generate_name
    if(v1_object_meta->generate_name) {
    if(mazu_cJSON_AddStringToObject(item, "generateName", v1_object_meta->generate_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_meta->generation
    if(v1_object_meta->generation) {
    if(mazu_cJSON_AddNumberToObject(item, "generation", v1_object_meta->generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_object_meta->labels
    if(v1_object_meta->labels) {
    mazu_cJSON *labels = mazu_cJSON_AddObjectToObject(item, "labels");
    if(labels == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = labels;
    listEntry_t *labelsListEntry;
    if (v1_object_meta->labels) {
    list_ForEach(labelsListEntry, v1_object_meta->labels) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)labelsListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_object_meta->managed_fields
    if(v1_object_meta->managed_fields) {
    mazu_cJSON *managed_fields = mazu_cJSON_AddArrayToObject(item, "managedFields");
    if(managed_fields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *managed_fieldsListEntry;
    if (v1_object_meta->managed_fields) {
    list_ForEach(managed_fieldsListEntry, v1_object_meta->managed_fields) {
    mazu_cJSON *itemLocal = v1_managed_fields_entry_convertToJSON(managed_fieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(managed_fields, itemLocal);
    }
    }
    }


    // v1_object_meta->name
    if(v1_object_meta->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_object_meta->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_meta->_namespace
    if(v1_object_meta->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_object_meta->_namespace) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_meta->owner_references
    if(v1_object_meta->owner_references) {
    mazu_cJSON *owner_references = mazu_cJSON_AddArrayToObject(item, "ownerReferences");
    if(owner_references == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *owner_referencesListEntry;
    if (v1_object_meta->owner_references) {
    list_ForEach(owner_referencesListEntry, v1_object_meta->owner_references) {
    mazu_cJSON *itemLocal = v1_owner_reference_convertToJSON(owner_referencesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(owner_references, itemLocal);
    }
    }
    }


    // v1_object_meta->resource_version
    if(v1_object_meta->resource_version) {
    if(mazu_cJSON_AddStringToObject(item, "resourceVersion", v1_object_meta->resource_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_meta->self_link
    if(v1_object_meta->self_link) {
    if(mazu_cJSON_AddStringToObject(item, "selfLink", v1_object_meta->self_link) == NULL) {
    goto fail; //String
    }
    }


    // v1_object_meta->uid
    if(v1_object_meta->uid) {
    if(mazu_cJSON_AddStringToObject(item, "uid", v1_object_meta->uid) == NULL) {
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

v1_object_meta_t *v1_object_meta_parseFromJSON(mazu_cJSON *v1_object_metaJSON){

    v1_object_meta_t *v1_object_meta_local_var = NULL;

    // define the local map for v1_object_meta->annotations
    list_t *annotationsList = NULL;

    // define the local list for v1_object_meta->finalizers
    list_t *finalizersList = NULL;

    // define the local map for v1_object_meta->labels
    list_t *labelsList = NULL;

    // define the local list for v1_object_meta->managed_fields
    list_t *managed_fieldsList = NULL;

    // define the local list for v1_object_meta->owner_references
    list_t *owner_referencesList = NULL;

    // v1_object_meta->annotations
    mazu_cJSON *annotations = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "annotations");
    if (annotations) { 
    mazu_cJSON *annotations_local_map = NULL;
    if(!mazu_cJSON_IsObject(annotations) && !mazu_cJSON_IsNull(annotations))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(annotations))
    {
        annotationsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(annotations_local_map, annotations)
        {
            mazu_cJSON *localMapObject = annotations_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(annotationsList , localMapKeyPair);
        }
    }
    }

    // v1_object_meta->creation_timestamp
    mazu_cJSON *creation_timestamp = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "creationTimestamp");
    if (creation_timestamp) { 
    if(!mazu_cJSON_IsString(creation_timestamp) && !mazu_cJSON_IsNull(creation_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_object_meta->deletion_grace_period_seconds
    mazu_cJSON *deletion_grace_period_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "deletionGracePeriodSeconds");
    if (deletion_grace_period_seconds) { 
    if(!mazu_cJSON_IsNumber(deletion_grace_period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_object_meta->deletion_timestamp
    mazu_cJSON *deletion_timestamp = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "deletionTimestamp");
    if (deletion_timestamp) { 
    if(!mazu_cJSON_IsString(deletion_timestamp) && !mazu_cJSON_IsNull(deletion_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1_object_meta->finalizers
    mazu_cJSON *finalizers = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "finalizers");
    if (finalizers) { 
    mazu_cJSON *finalizers_local = NULL;
    if(!mazu_cJSON_IsArray(finalizers)) {
        goto end;//primitive container
    }
    finalizersList = list_createList();

    mazu_cJSON_ArrayForEach(finalizers_local, finalizers)
    {
        if(!mazu_cJSON_IsString(finalizers_local))
        {
            goto end;
        }
        list_addElement(finalizersList , strdup(finalizers_local->valuestring));
    }
    }

    // v1_object_meta->generate_name
    mazu_cJSON *generate_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "generateName");
    if (generate_name) { 
    if(!mazu_cJSON_IsString(generate_name) && !mazu_cJSON_IsNull(generate_name))
    {
    goto end; //String
    }
    }

    // v1_object_meta->generation
    mazu_cJSON *generation = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "generation");
    if (generation) { 
    if(!mazu_cJSON_IsNumber(generation))
    {
    goto end; //Numeric
    }
    }

    // v1_object_meta->labels
    mazu_cJSON *labels = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "labels");
    if (labels) { 
    mazu_cJSON *labels_local_map = NULL;
    if(!mazu_cJSON_IsObject(labels) && !mazu_cJSON_IsNull(labels))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(labels))
    {
        labelsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(labels_local_map, labels)
        {
            mazu_cJSON *localMapObject = labels_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(labelsList , localMapKeyPair);
        }
    }
    }

    // v1_object_meta->managed_fields
    mazu_cJSON *managed_fields = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "managedFields");
    if (managed_fields) { 
    mazu_cJSON *managed_fields_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(managed_fields)){
        goto end; //nonprimitive container
    }

    managed_fieldsList = list_createList();

    mazu_cJSON_ArrayForEach(managed_fields_local_nonprimitive,managed_fields )
    {
        if(!mazu_cJSON_IsObject(managed_fields_local_nonprimitive)){
            goto end;
        }
        v1_managed_fields_entry_t *managed_fieldsItem = v1_managed_fields_entry_parseFromJSON(managed_fields_local_nonprimitive);

        list_addElement(managed_fieldsList, managed_fieldsItem);
    }
    }

    // v1_object_meta->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_object_meta->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }

    // v1_object_meta->owner_references
    mazu_cJSON *owner_references = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "ownerReferences");
    if (owner_references) { 
    mazu_cJSON *owner_references_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(owner_references)){
        goto end; //nonprimitive container
    }

    owner_referencesList = list_createList();

    mazu_cJSON_ArrayForEach(owner_references_local_nonprimitive,owner_references )
    {
        if(!mazu_cJSON_IsObject(owner_references_local_nonprimitive)){
            goto end;
        }
        v1_owner_reference_t *owner_referencesItem = v1_owner_reference_parseFromJSON(owner_references_local_nonprimitive);

        list_addElement(owner_referencesList, owner_referencesItem);
    }
    }

    // v1_object_meta->resource_version
    mazu_cJSON *resource_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "resourceVersion");
    if (resource_version) { 
    if(!mazu_cJSON_IsString(resource_version) && !mazu_cJSON_IsNull(resource_version))
    {
    goto end; //String
    }
    }

    // v1_object_meta->self_link
    mazu_cJSON *self_link = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "selfLink");
    if (self_link) { 
    if(!mazu_cJSON_IsString(self_link) && !mazu_cJSON_IsNull(self_link))
    {
    goto end; //String
    }
    }

    // v1_object_meta->uid
    mazu_cJSON *uid = mazu_cJSON_GetObjectItemCaseSensitive(v1_object_metaJSON, "uid");
    if (uid) { 
    if(!mazu_cJSON_IsString(uid) && !mazu_cJSON_IsNull(uid))
    {
    goto end; //String
    }
    }


    v1_object_meta_local_var = v1_object_meta_create (
        annotations ? annotationsList : NULL,
        creation_timestamp && !mazu_cJSON_IsNull(creation_timestamp) ? strdup(creation_timestamp->valuestring) : NULL,
        deletion_grace_period_seconds ? deletion_grace_period_seconds->valuedouble : 0,
        deletion_timestamp && !mazu_cJSON_IsNull(deletion_timestamp) ? strdup(deletion_timestamp->valuestring) : NULL,
        finalizers ? finalizersList : NULL,
        generate_name && !mazu_cJSON_IsNull(generate_name) ? strdup(generate_name->valuestring) : NULL,
        generation ? generation->valuedouble : 0,
        labels ? labelsList : NULL,
        managed_fields ? managed_fieldsList : NULL,
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL,
        owner_references ? owner_referencesList : NULL,
        resource_version && !mazu_cJSON_IsNull(resource_version) ? strdup(resource_version->valuestring) : NULL,
        self_link && !mazu_cJSON_IsNull(self_link) ? strdup(self_link->valuestring) : NULL,
        uid && !mazu_cJSON_IsNull(uid) ? strdup(uid->valuestring) : NULL
        );

    return v1_object_meta_local_var;
end:
    if (annotationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, annotationsList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(annotationsList);
        annotationsList = NULL;
    }
    if (finalizersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, finalizersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(finalizersList);
        finalizersList = NULL;
    }
    if (labelsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, labelsList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(labelsList);
        labelsList = NULL;
    }
    if (managed_fieldsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, managed_fieldsList) {
            v1_managed_fields_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(managed_fieldsList);
        managed_fieldsList = NULL;
    }
    if (owner_referencesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, owner_referencesList) {
            v1_owner_reference_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(owner_referencesList);
        owner_referencesList = NULL;
    }
    return NULL;

}
