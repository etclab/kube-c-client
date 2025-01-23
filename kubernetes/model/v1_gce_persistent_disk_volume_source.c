#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_gce_persistent_disk_volume_source.h"



v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_create(
    char *fs_type,
    int partition,
    char *pd_name,
    int read_only
    ) {
    v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_local_var = malloc(sizeof(v1_gce_persistent_disk_volume_source_t));
    if (!v1_gce_persistent_disk_volume_source_local_var) {
        return NULL;
    }
    v1_gce_persistent_disk_volume_source_local_var->fs_type = fs_type;
    v1_gce_persistent_disk_volume_source_local_var->partition = partition;
    v1_gce_persistent_disk_volume_source_local_var->pd_name = pd_name;
    v1_gce_persistent_disk_volume_source_local_var->read_only = read_only;

    return v1_gce_persistent_disk_volume_source_local_var;
}


void v1_gce_persistent_disk_volume_source_free(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source) {
    if(NULL == v1_gce_persistent_disk_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_gce_persistent_disk_volume_source->fs_type) {
        free(v1_gce_persistent_disk_volume_source->fs_type);
        v1_gce_persistent_disk_volume_source->fs_type = NULL;
    }
    if (v1_gce_persistent_disk_volume_source->pd_name) {
        free(v1_gce_persistent_disk_volume_source->pd_name);
        v1_gce_persistent_disk_volume_source->pd_name = NULL;
    }
    free(v1_gce_persistent_disk_volume_source);
}

mazu_cJSON *v1_gce_persistent_disk_volume_source_convertToJSON(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_gce_persistent_disk_volume_source->fs_type
    if(v1_gce_persistent_disk_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_gce_persistent_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_gce_persistent_disk_volume_source->partition
    if(v1_gce_persistent_disk_volume_source->partition) {
    if(mazu_cJSON_AddNumberToObject(item, "partition", v1_gce_persistent_disk_volume_source->partition) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_gce_persistent_disk_volume_source->pd_name
    if (!v1_gce_persistent_disk_volume_source->pd_name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "pdName", v1_gce_persistent_disk_volume_source->pd_name) == NULL) {
    goto fail; //String
    }


    // v1_gce_persistent_disk_volume_source->read_only
    if(v1_gce_persistent_disk_volume_source->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_gce_persistent_disk_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_parseFromJSON(mazu_cJSON *v1_gce_persistent_disk_volume_sourceJSON){

    v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_local_var = NULL;

    // v1_gce_persistent_disk_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_gce_persistent_disk_volume_source->partition
    mazu_cJSON *partition = mazu_cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "partition");
    if (partition) { 
    if(!mazu_cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    }

    // v1_gce_persistent_disk_volume_source->pd_name
    mazu_cJSON *pd_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "pdName");
    if (!pd_name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(pd_name))
    {
    goto end; //String
    }

    // v1_gce_persistent_disk_volume_source->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    v1_gce_persistent_disk_volume_source_local_var = v1_gce_persistent_disk_volume_source_create (
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        partition ? partition->valuedouble : 0,
        strdup(pd_name->valuestring),
        read_only ? read_only->valueint : 0
        );

    return v1_gce_persistent_disk_volume_source_local_var;
end:
    return NULL;

}
