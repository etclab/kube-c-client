#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_aws_elastic_block_store_volume_source.h"



v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_create(
    char *fs_type,
    int partition,
    int read_only,
    char *volume_id
    ) {
    v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_local_var = malloc(sizeof(v1_aws_elastic_block_store_volume_source_t));
    if (!v1_aws_elastic_block_store_volume_source_local_var) {
        return NULL;
    }
    v1_aws_elastic_block_store_volume_source_local_var->fs_type = fs_type;
    v1_aws_elastic_block_store_volume_source_local_var->partition = partition;
    v1_aws_elastic_block_store_volume_source_local_var->read_only = read_only;
    v1_aws_elastic_block_store_volume_source_local_var->volume_id = volume_id;

    return v1_aws_elastic_block_store_volume_source_local_var;
}


void v1_aws_elastic_block_store_volume_source_free(v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source) {
    if(NULL == v1_aws_elastic_block_store_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_aws_elastic_block_store_volume_source->fs_type) {
        free(v1_aws_elastic_block_store_volume_source->fs_type);
        v1_aws_elastic_block_store_volume_source->fs_type = NULL;
    }
    if (v1_aws_elastic_block_store_volume_source->volume_id) {
        free(v1_aws_elastic_block_store_volume_source->volume_id);
        v1_aws_elastic_block_store_volume_source->volume_id = NULL;
    }
    free(v1_aws_elastic_block_store_volume_source);
}

mazu_cJSON *v1_aws_elastic_block_store_volume_source_convertToJSON(v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_aws_elastic_block_store_volume_source->fs_type
    if(v1_aws_elastic_block_store_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_aws_elastic_block_store_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_aws_elastic_block_store_volume_source->partition
    if(v1_aws_elastic_block_store_volume_source->partition) {
    if(mazu_cJSON_AddNumberToObject(item, "partition", v1_aws_elastic_block_store_volume_source->partition) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_aws_elastic_block_store_volume_source->read_only
    if(v1_aws_elastic_block_store_volume_source->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_aws_elastic_block_store_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_aws_elastic_block_store_volume_source->volume_id
    if (!v1_aws_elastic_block_store_volume_source->volume_id) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "volumeID", v1_aws_elastic_block_store_volume_source->volume_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_parseFromJSON(mazu_cJSON *v1_aws_elastic_block_store_volume_sourceJSON){

    v1_aws_elastic_block_store_volume_source_t *v1_aws_elastic_block_store_volume_source_local_var = NULL;

    // v1_aws_elastic_block_store_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_aws_elastic_block_store_volume_source->partition
    mazu_cJSON *partition = mazu_cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "partition");
    if (partition) { 
    if(!mazu_cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    }

    // v1_aws_elastic_block_store_volume_source->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_aws_elastic_block_store_volume_source->volume_id
    mazu_cJSON *volume_id = mazu_cJSON_GetObjectItemCaseSensitive(v1_aws_elastic_block_store_volume_sourceJSON, "volumeID");
    if (!volume_id) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(volume_id))
    {
    goto end; //String
    }


    v1_aws_elastic_block_store_volume_source_local_var = v1_aws_elastic_block_store_volume_source_create (
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        partition ? partition->valuedouble : 0,
        read_only ? read_only->valueint : 0,
        strdup(volume_id->valuestring)
        );

    return v1_aws_elastic_block_store_volume_source_local_var;
end:
    return NULL;

}
