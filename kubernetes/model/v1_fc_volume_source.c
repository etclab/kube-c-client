#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_fc_volume_source.h"



v1_fc_volume_source_t *v1_fc_volume_source_create(
    char *fs_type,
    int lun,
    int read_only,
    list_t *target_wwns,
    list_t *wwids
    ) {
    v1_fc_volume_source_t *v1_fc_volume_source_local_var = malloc(sizeof(v1_fc_volume_source_t));
    if (!v1_fc_volume_source_local_var) {
        return NULL;
    }
    v1_fc_volume_source_local_var->fs_type = fs_type;
    v1_fc_volume_source_local_var->lun = lun;
    v1_fc_volume_source_local_var->read_only = read_only;
    v1_fc_volume_source_local_var->target_wwns = target_wwns;
    v1_fc_volume_source_local_var->wwids = wwids;

    return v1_fc_volume_source_local_var;
}


void v1_fc_volume_source_free(v1_fc_volume_source_t *v1_fc_volume_source) {
    if(NULL == v1_fc_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_fc_volume_source->fs_type) {
        free(v1_fc_volume_source->fs_type);
        v1_fc_volume_source->fs_type = NULL;
    }
    if (v1_fc_volume_source->target_wwns) {
        list_ForEach(listEntry, v1_fc_volume_source->target_wwns) {
            free(listEntry->data);
        }
        list_freeList(v1_fc_volume_source->target_wwns);
        v1_fc_volume_source->target_wwns = NULL;
    }
    if (v1_fc_volume_source->wwids) {
        list_ForEach(listEntry, v1_fc_volume_source->wwids) {
            free(listEntry->data);
        }
        list_freeList(v1_fc_volume_source->wwids);
        v1_fc_volume_source->wwids = NULL;
    }
    free(v1_fc_volume_source);
}

mazu_cJSON *v1_fc_volume_source_convertToJSON(v1_fc_volume_source_t *v1_fc_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_fc_volume_source->fs_type
    if(v1_fc_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_fc_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_fc_volume_source->lun
    if(v1_fc_volume_source->lun) {
    if(mazu_cJSON_AddNumberToObject(item, "lun", v1_fc_volume_source->lun) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_fc_volume_source->read_only
    if(v1_fc_volume_source->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_fc_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_fc_volume_source->target_wwns
    if(v1_fc_volume_source->target_wwns) {
    mazu_cJSON *target_wwns = mazu_cJSON_AddArrayToObject(item, "targetWWNs");
    if(target_wwns == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *target_wwnsListEntry;
    list_ForEach(target_wwnsListEntry, v1_fc_volume_source->target_wwns) {
    if(mazu_cJSON_AddStringToObject(target_wwns, "", (char*)target_wwnsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_fc_volume_source->wwids
    if(v1_fc_volume_source->wwids) {
    mazu_cJSON *wwids = mazu_cJSON_AddArrayToObject(item, "wwids");
    if(wwids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *wwidsListEntry;
    list_ForEach(wwidsListEntry, v1_fc_volume_source->wwids) {
    if(mazu_cJSON_AddStringToObject(wwids, "", (char*)wwidsListEntry->data) == NULL)
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

v1_fc_volume_source_t *v1_fc_volume_source_parseFromJSON(mazu_cJSON *v1_fc_volume_sourceJSON){

    v1_fc_volume_source_t *v1_fc_volume_source_local_var = NULL;

    // define the local list for v1_fc_volume_source->target_wwns
    list_t *target_wwnsList = NULL;

    // define the local list for v1_fc_volume_source->wwids
    list_t *wwidsList = NULL;

    // v1_fc_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_fc_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_fc_volume_source->lun
    mazu_cJSON *lun = mazu_cJSON_GetObjectItemCaseSensitive(v1_fc_volume_sourceJSON, "lun");
    if (lun) { 
    if(!mazu_cJSON_IsNumber(lun))
    {
    goto end; //Numeric
    }
    }

    // v1_fc_volume_source->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_fc_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_fc_volume_source->target_wwns
    mazu_cJSON *target_wwns = mazu_cJSON_GetObjectItemCaseSensitive(v1_fc_volume_sourceJSON, "targetWWNs");
    if (target_wwns) { 
    mazu_cJSON *target_wwns_local = NULL;
    if(!mazu_cJSON_IsArray(target_wwns)) {
        goto end;//primitive container
    }
    target_wwnsList = list_createList();

    mazu_cJSON_ArrayForEach(target_wwns_local, target_wwns)
    {
        if(!mazu_cJSON_IsString(target_wwns_local))
        {
            goto end;
        }
        list_addElement(target_wwnsList , strdup(target_wwns_local->valuestring));
    }
    }

    // v1_fc_volume_source->wwids
    mazu_cJSON *wwids = mazu_cJSON_GetObjectItemCaseSensitive(v1_fc_volume_sourceJSON, "wwids");
    if (wwids) { 
    mazu_cJSON *wwids_local = NULL;
    if(!mazu_cJSON_IsArray(wwids)) {
        goto end;//primitive container
    }
    wwidsList = list_createList();

    mazu_cJSON_ArrayForEach(wwids_local, wwids)
    {
        if(!mazu_cJSON_IsString(wwids_local))
        {
            goto end;
        }
        list_addElement(wwidsList , strdup(wwids_local->valuestring));
    }
    }


    v1_fc_volume_source_local_var = v1_fc_volume_source_create (
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        lun ? lun->valuedouble : 0,
        read_only ? read_only->valueint : 0,
        target_wwns ? target_wwnsList : NULL,
        wwids ? wwidsList : NULL
        );

    return v1_fc_volume_source_local_var;
end:
    if (target_wwnsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, target_wwnsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(target_wwnsList);
        target_wwnsList = NULL;
    }
    if (wwidsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, wwidsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(wwidsList);
        wwidsList = NULL;
    }
    return NULL;

}
