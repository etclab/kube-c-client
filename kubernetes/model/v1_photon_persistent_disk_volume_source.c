#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_photon_persistent_disk_volume_source.h"



v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_create(
    char *fs_type,
    char *pd_id
    ) {
    v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_local_var = malloc(sizeof(v1_photon_persistent_disk_volume_source_t));
    if (!v1_photon_persistent_disk_volume_source_local_var) {
        return NULL;
    }
    v1_photon_persistent_disk_volume_source_local_var->fs_type = fs_type;
    v1_photon_persistent_disk_volume_source_local_var->pd_id = pd_id;

    return v1_photon_persistent_disk_volume_source_local_var;
}


void v1_photon_persistent_disk_volume_source_free(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source) {
    if(NULL == v1_photon_persistent_disk_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_photon_persistent_disk_volume_source->fs_type) {
        free(v1_photon_persistent_disk_volume_source->fs_type);
        v1_photon_persistent_disk_volume_source->fs_type = NULL;
    }
    if (v1_photon_persistent_disk_volume_source->pd_id) {
        free(v1_photon_persistent_disk_volume_source->pd_id);
        v1_photon_persistent_disk_volume_source->pd_id = NULL;
    }
    free(v1_photon_persistent_disk_volume_source);
}

mazu_cJSON *v1_photon_persistent_disk_volume_source_convertToJSON(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_photon_persistent_disk_volume_source->fs_type
    if(v1_photon_persistent_disk_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_photon_persistent_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_photon_persistent_disk_volume_source->pd_id
    if (!v1_photon_persistent_disk_volume_source->pd_id) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "pdID", v1_photon_persistent_disk_volume_source->pd_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_parseFromJSON(mazu_cJSON *v1_photon_persistent_disk_volume_sourceJSON){

    v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_local_var = NULL;

    // v1_photon_persistent_disk_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_photon_persistent_disk_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_photon_persistent_disk_volume_source->pd_id
    mazu_cJSON *pd_id = mazu_cJSON_GetObjectItemCaseSensitive(v1_photon_persistent_disk_volume_sourceJSON, "pdID");
    if (!pd_id) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(pd_id))
    {
    goto end; //String
    }


    v1_photon_persistent_disk_volume_source_local_var = v1_photon_persistent_disk_volume_source_create (
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        strdup(pd_id->valuestring)
        );

    return v1_photon_persistent_disk_volume_source_local_var;
end:
    return NULL;

}
