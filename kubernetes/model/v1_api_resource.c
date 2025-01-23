#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_resource.h"



v1_api_resource_t *v1_api_resource_create(
    list_t *categories,
    char *group,
    char *kind,
    char *name,
    int namespaced,
    list_t *short_names,
    char *singular_name,
    char *storage_version_hash,
    list_t *verbs,
    char *version
    ) {
    v1_api_resource_t *v1_api_resource_local_var = malloc(sizeof(v1_api_resource_t));
    if (!v1_api_resource_local_var) {
        return NULL;
    }
    v1_api_resource_local_var->categories = categories;
    v1_api_resource_local_var->group = group;
    v1_api_resource_local_var->kind = kind;
    v1_api_resource_local_var->name = name;
    v1_api_resource_local_var->namespaced = namespaced;
    v1_api_resource_local_var->short_names = short_names;
    v1_api_resource_local_var->singular_name = singular_name;
    v1_api_resource_local_var->storage_version_hash = storage_version_hash;
    v1_api_resource_local_var->verbs = verbs;
    v1_api_resource_local_var->version = version;

    return v1_api_resource_local_var;
}


void v1_api_resource_free(v1_api_resource_t *v1_api_resource) {
    if(NULL == v1_api_resource){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_resource->categories) {
        list_ForEach(listEntry, v1_api_resource->categories) {
            free(listEntry->data);
        }
        list_freeList(v1_api_resource->categories);
        v1_api_resource->categories = NULL;
    }
    if (v1_api_resource->group) {
        free(v1_api_resource->group);
        v1_api_resource->group = NULL;
    }
    if (v1_api_resource->kind) {
        free(v1_api_resource->kind);
        v1_api_resource->kind = NULL;
    }
    if (v1_api_resource->name) {
        free(v1_api_resource->name);
        v1_api_resource->name = NULL;
    }
    if (v1_api_resource->short_names) {
        list_ForEach(listEntry, v1_api_resource->short_names) {
            free(listEntry->data);
        }
        list_freeList(v1_api_resource->short_names);
        v1_api_resource->short_names = NULL;
    }
    if (v1_api_resource->singular_name) {
        free(v1_api_resource->singular_name);
        v1_api_resource->singular_name = NULL;
    }
    if (v1_api_resource->storage_version_hash) {
        free(v1_api_resource->storage_version_hash);
        v1_api_resource->storage_version_hash = NULL;
    }
    if (v1_api_resource->verbs) {
        list_ForEach(listEntry, v1_api_resource->verbs) {
            free(listEntry->data);
        }
        list_freeList(v1_api_resource->verbs);
        v1_api_resource->verbs = NULL;
    }
    if (v1_api_resource->version) {
        free(v1_api_resource->version);
        v1_api_resource->version = NULL;
    }
    free(v1_api_resource);
}

mazu_cJSON *v1_api_resource_convertToJSON(v1_api_resource_t *v1_api_resource) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_api_resource->categories
    if(v1_api_resource->categories) {
    mazu_cJSON *categories = mazu_cJSON_AddArrayToObject(item, "categories");
    if(categories == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *categoriesListEntry;
    list_ForEach(categoriesListEntry, v1_api_resource->categories) {
    if(mazu_cJSON_AddStringToObject(categories, "", (char*)categoriesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_api_resource->group
    if(v1_api_resource->group) {
    if(mazu_cJSON_AddStringToObject(item, "group", v1_api_resource->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_resource->kind
    if (!v1_api_resource->kind) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kind", v1_api_resource->kind) == NULL) {
    goto fail; //String
    }


    // v1_api_resource->name
    if (!v1_api_resource->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_api_resource->name) == NULL) {
    goto fail; //String
    }


    // v1_api_resource->namespaced
    if (!v1_api_resource->namespaced) {
        goto fail;
    }
    if(mazu_cJSON_AddBoolToObject(item, "namespaced", v1_api_resource->namespaced) == NULL) {
    goto fail; //Bool
    }


    // v1_api_resource->short_names
    if(v1_api_resource->short_names) {
    mazu_cJSON *short_names = mazu_cJSON_AddArrayToObject(item, "shortNames");
    if(short_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *short_namesListEntry;
    list_ForEach(short_namesListEntry, v1_api_resource->short_names) {
    if(mazu_cJSON_AddStringToObject(short_names, "", (char*)short_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_api_resource->singular_name
    if (!v1_api_resource->singular_name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "singularName", v1_api_resource->singular_name) == NULL) {
    goto fail; //String
    }


    // v1_api_resource->storage_version_hash
    if(v1_api_resource->storage_version_hash) {
    if(mazu_cJSON_AddStringToObject(item, "storageVersionHash", v1_api_resource->storage_version_hash) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_resource->verbs
    if (!v1_api_resource->verbs) {
        goto fail;
    }
    mazu_cJSON *verbs = mazu_cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_api_resource->verbs) {
    if(mazu_cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_api_resource->version
    if(v1_api_resource->version) {
    if(mazu_cJSON_AddStringToObject(item, "version", v1_api_resource->version) == NULL) {
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

v1_api_resource_t *v1_api_resource_parseFromJSON(mazu_cJSON *v1_api_resourceJSON){

    v1_api_resource_t *v1_api_resource_local_var = NULL;

    // define the local list for v1_api_resource->categories
    list_t *categoriesList = NULL;

    // define the local list for v1_api_resource->short_names
    list_t *short_namesList = NULL;

    // define the local list for v1_api_resource->verbs
    list_t *verbsList = NULL;

    // v1_api_resource->categories
    mazu_cJSON *categories = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "categories");
    if (categories) { 
    mazu_cJSON *categories_local = NULL;
    if(!mazu_cJSON_IsArray(categories)) {
        goto end;//primitive container
    }
    categoriesList = list_createList();

    mazu_cJSON_ArrayForEach(categories_local, categories)
    {
        if(!mazu_cJSON_IsString(categories_local))
        {
            goto end;
        }
        list_addElement(categoriesList , strdup(categories_local->valuestring));
    }
    }

    // v1_api_resource->group
    mazu_cJSON *group = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "group");
    if (group) { 
    if(!mazu_cJSON_IsString(group) && !mazu_cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_api_resource->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_api_resource->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_api_resource->namespaced
    mazu_cJSON *namespaced = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "namespaced");
    if (!namespaced) {
        goto end;
    }

    
    if(!mazu_cJSON_IsBool(namespaced))
    {
    goto end; //Bool
    }

    // v1_api_resource->short_names
    mazu_cJSON *short_names = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "shortNames");
    if (short_names) { 
    mazu_cJSON *short_names_local = NULL;
    if(!mazu_cJSON_IsArray(short_names)) {
        goto end;//primitive container
    }
    short_namesList = list_createList();

    mazu_cJSON_ArrayForEach(short_names_local, short_names)
    {
        if(!mazu_cJSON_IsString(short_names_local))
        {
            goto end;
        }
        list_addElement(short_namesList , strdup(short_names_local->valuestring));
    }
    }

    // v1_api_resource->singular_name
    mazu_cJSON *singular_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "singularName");
    if (!singular_name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(singular_name))
    {
    goto end; //String
    }

    // v1_api_resource->storage_version_hash
    mazu_cJSON *storage_version_hash = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "storageVersionHash");
    if (storage_version_hash) { 
    if(!mazu_cJSON_IsString(storage_version_hash) && !mazu_cJSON_IsNull(storage_version_hash))
    {
    goto end; //String
    }
    }

    // v1_api_resource->verbs
    mazu_cJSON *verbs = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    
    mazu_cJSON *verbs_local = NULL;
    if(!mazu_cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_createList();

    mazu_cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!mazu_cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }

    // v1_api_resource->version
    mazu_cJSON *version = mazu_cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "version");
    if (version) { 
    if(!mazu_cJSON_IsString(version) && !mazu_cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    v1_api_resource_local_var = v1_api_resource_create (
        categories ? categoriesList : NULL,
        group && !mazu_cJSON_IsNull(group) ? strdup(group->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        namespaced->valueint,
        short_names ? short_namesList : NULL,
        strdup(singular_name->valuestring),
        storage_version_hash && !mazu_cJSON_IsNull(storage_version_hash) ? strdup(storage_version_hash->valuestring) : NULL,
        verbsList,
        version && !mazu_cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return v1_api_resource_local_var;
end:
    if (categoriesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, categoriesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(categoriesList);
        categoriesList = NULL;
    }
    if (short_namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, short_namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(short_namesList);
        short_namesList = NULL;
    }
    if (verbsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, verbsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(verbsList);
        verbsList = NULL;
    }
    return NULL;

}
