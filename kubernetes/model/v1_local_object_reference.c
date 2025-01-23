#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_local_object_reference.h"



v1_local_object_reference_t *v1_local_object_reference_create(
    char *name
    ) {
    v1_local_object_reference_t *v1_local_object_reference_local_var = malloc(sizeof(v1_local_object_reference_t));
    if (!v1_local_object_reference_local_var) {
        return NULL;
    }
    v1_local_object_reference_local_var->name = name;

    return v1_local_object_reference_local_var;
}


void v1_local_object_reference_free(v1_local_object_reference_t *v1_local_object_reference) {
    if(NULL == v1_local_object_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_local_object_reference->name) {
        free(v1_local_object_reference->name);
        v1_local_object_reference->name = NULL;
    }
    free(v1_local_object_reference);
}

mazu_cJSON *v1_local_object_reference_convertToJSON(v1_local_object_reference_t *v1_local_object_reference) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_local_object_reference->name
    if(v1_local_object_reference->name) {
    if(mazu_cJSON_AddStringToObject(item, "name", v1_local_object_reference->name) == NULL) {
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

v1_local_object_reference_t *v1_local_object_reference_parseFromJSON(mazu_cJSON *v1_local_object_referenceJSON){

    v1_local_object_reference_t *v1_local_object_reference_local_var = NULL;

    // v1_local_object_reference->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_local_object_referenceJSON, "name");
    if (name) { 
    if(!mazu_cJSON_IsString(name) && !mazu_cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    v1_local_object_reference_local_var = v1_local_object_reference_create (
        name && !mazu_cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return v1_local_object_reference_local_var;
end:
    return NULL;

}
