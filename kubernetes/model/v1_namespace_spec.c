#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace_spec.h"



v1_namespace_spec_t *v1_namespace_spec_create(
    list_t *finalizers
    ) {
    v1_namespace_spec_t *v1_namespace_spec_local_var = malloc(sizeof(v1_namespace_spec_t));
    if (!v1_namespace_spec_local_var) {
        return NULL;
    }
    v1_namespace_spec_local_var->finalizers = finalizers;

    return v1_namespace_spec_local_var;
}


void v1_namespace_spec_free(v1_namespace_spec_t *v1_namespace_spec) {
    if(NULL == v1_namespace_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace_spec->finalizers) {
        list_ForEach(listEntry, v1_namespace_spec->finalizers) {
            free(listEntry->data);
        }
        list_freeList(v1_namespace_spec->finalizers);
        v1_namespace_spec->finalizers = NULL;
    }
    free(v1_namespace_spec);
}

mazu_cJSON *v1_namespace_spec_convertToJSON(v1_namespace_spec_t *v1_namespace_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_namespace_spec->finalizers
    if(v1_namespace_spec->finalizers) {
    mazu_cJSON *finalizers = mazu_cJSON_AddArrayToObject(item, "finalizers");
    if(finalizers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *finalizersListEntry;
    list_ForEach(finalizersListEntry, v1_namespace_spec->finalizers) {
    if(mazu_cJSON_AddStringToObject(finalizers, "", (char*)finalizersListEntry->data) == NULL)
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

v1_namespace_spec_t *v1_namespace_spec_parseFromJSON(mazu_cJSON *v1_namespace_specJSON){

    v1_namespace_spec_t *v1_namespace_spec_local_var = NULL;

    // define the local list for v1_namespace_spec->finalizers
    list_t *finalizersList = NULL;

    // v1_namespace_spec->finalizers
    mazu_cJSON *finalizers = mazu_cJSON_GetObjectItemCaseSensitive(v1_namespace_specJSON, "finalizers");
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


    v1_namespace_spec_local_var = v1_namespace_spec_create (
        finalizers ? finalizersList : NULL
        );

    return v1_namespace_spec_local_var;
end:
    if (finalizersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, finalizersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(finalizersList);
        finalizersList = NULL;
    }
    return NULL;

}
