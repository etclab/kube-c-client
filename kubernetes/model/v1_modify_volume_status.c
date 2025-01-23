#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_modify_volume_status.h"



v1_modify_volume_status_t *v1_modify_volume_status_create(
    char *status,
    char *target_volume_attributes_class_name
    ) {
    v1_modify_volume_status_t *v1_modify_volume_status_local_var = malloc(sizeof(v1_modify_volume_status_t));
    if (!v1_modify_volume_status_local_var) {
        return NULL;
    }
    v1_modify_volume_status_local_var->status = status;
    v1_modify_volume_status_local_var->target_volume_attributes_class_name = target_volume_attributes_class_name;

    return v1_modify_volume_status_local_var;
}


void v1_modify_volume_status_free(v1_modify_volume_status_t *v1_modify_volume_status) {
    if(NULL == v1_modify_volume_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_modify_volume_status->status) {
        free(v1_modify_volume_status->status);
        v1_modify_volume_status->status = NULL;
    }
    if (v1_modify_volume_status->target_volume_attributes_class_name) {
        free(v1_modify_volume_status->target_volume_attributes_class_name);
        v1_modify_volume_status->target_volume_attributes_class_name = NULL;
    }
    free(v1_modify_volume_status);
}

mazu_cJSON *v1_modify_volume_status_convertToJSON(v1_modify_volume_status_t *v1_modify_volume_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_modify_volume_status->status
    if (!v1_modify_volume_status->status) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "status", v1_modify_volume_status->status) == NULL) {
    goto fail; //String
    }


    // v1_modify_volume_status->target_volume_attributes_class_name
    if(v1_modify_volume_status->target_volume_attributes_class_name) {
    if(mazu_cJSON_AddStringToObject(item, "targetVolumeAttributesClassName", v1_modify_volume_status->target_volume_attributes_class_name) == NULL) {
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

v1_modify_volume_status_t *v1_modify_volume_status_parseFromJSON(mazu_cJSON *v1_modify_volume_statusJSON){

    v1_modify_volume_status_t *v1_modify_volume_status_local_var = NULL;

    // v1_modify_volume_status->status
    mazu_cJSON *status = mazu_cJSON_GetObjectItemCaseSensitive(v1_modify_volume_statusJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_modify_volume_status->target_volume_attributes_class_name
    mazu_cJSON *target_volume_attributes_class_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_modify_volume_statusJSON, "targetVolumeAttributesClassName");
    if (target_volume_attributes_class_name) { 
    if(!mazu_cJSON_IsString(target_volume_attributes_class_name) && !mazu_cJSON_IsNull(target_volume_attributes_class_name))
    {
    goto end; //String
    }
    }


    v1_modify_volume_status_local_var = v1_modify_volume_status_create (
        strdup(status->valuestring),
        target_volume_attributes_class_name && !mazu_cJSON_IsNull(target_volume_attributes_class_name) ? strdup(target_volume_attributes_class_name->valuestring) : NULL
        );

    return v1_modify_volume_status_local_var;
end:
    return NULL;

}
