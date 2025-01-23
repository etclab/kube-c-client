#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_iscsi_persistent_volume_source.h"



v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_create(
    int chap_auth_discovery,
    int chap_auth_session,
    char *fs_type,
    char *initiator_name,
    char *iqn,
    char *iscsi_interface,
    int lun,
    list_t *portals,
    int read_only,
    v1_secret_reference_t *secret_ref,
    char *target_portal
    ) {
    v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_local_var = malloc(sizeof(v1_iscsi_persistent_volume_source_t));
    if (!v1_iscsi_persistent_volume_source_local_var) {
        return NULL;
    }
    v1_iscsi_persistent_volume_source_local_var->chap_auth_discovery = chap_auth_discovery;
    v1_iscsi_persistent_volume_source_local_var->chap_auth_session = chap_auth_session;
    v1_iscsi_persistent_volume_source_local_var->fs_type = fs_type;
    v1_iscsi_persistent_volume_source_local_var->initiator_name = initiator_name;
    v1_iscsi_persistent_volume_source_local_var->iqn = iqn;
    v1_iscsi_persistent_volume_source_local_var->iscsi_interface = iscsi_interface;
    v1_iscsi_persistent_volume_source_local_var->lun = lun;
    v1_iscsi_persistent_volume_source_local_var->portals = portals;
    v1_iscsi_persistent_volume_source_local_var->read_only = read_only;
    v1_iscsi_persistent_volume_source_local_var->secret_ref = secret_ref;
    v1_iscsi_persistent_volume_source_local_var->target_portal = target_portal;

    return v1_iscsi_persistent_volume_source_local_var;
}


void v1_iscsi_persistent_volume_source_free(v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source) {
    if(NULL == v1_iscsi_persistent_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_iscsi_persistent_volume_source->fs_type) {
        free(v1_iscsi_persistent_volume_source->fs_type);
        v1_iscsi_persistent_volume_source->fs_type = NULL;
    }
    if (v1_iscsi_persistent_volume_source->initiator_name) {
        free(v1_iscsi_persistent_volume_source->initiator_name);
        v1_iscsi_persistent_volume_source->initiator_name = NULL;
    }
    if (v1_iscsi_persistent_volume_source->iqn) {
        free(v1_iscsi_persistent_volume_source->iqn);
        v1_iscsi_persistent_volume_source->iqn = NULL;
    }
    if (v1_iscsi_persistent_volume_source->iscsi_interface) {
        free(v1_iscsi_persistent_volume_source->iscsi_interface);
        v1_iscsi_persistent_volume_source->iscsi_interface = NULL;
    }
    if (v1_iscsi_persistent_volume_source->portals) {
        list_ForEach(listEntry, v1_iscsi_persistent_volume_source->portals) {
            free(listEntry->data);
        }
        list_freeList(v1_iscsi_persistent_volume_source->portals);
        v1_iscsi_persistent_volume_source->portals = NULL;
    }
    if (v1_iscsi_persistent_volume_source->secret_ref) {
        v1_secret_reference_free(v1_iscsi_persistent_volume_source->secret_ref);
        v1_iscsi_persistent_volume_source->secret_ref = NULL;
    }
    if (v1_iscsi_persistent_volume_source->target_portal) {
        free(v1_iscsi_persistent_volume_source->target_portal);
        v1_iscsi_persistent_volume_source->target_portal = NULL;
    }
    free(v1_iscsi_persistent_volume_source);
}

mazu_cJSON *v1_iscsi_persistent_volume_source_convertToJSON(v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_iscsi_persistent_volume_source->chap_auth_discovery
    if(v1_iscsi_persistent_volume_source->chap_auth_discovery) {
    if(mazu_cJSON_AddBoolToObject(item, "chapAuthDiscovery", v1_iscsi_persistent_volume_source->chap_auth_discovery) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->chap_auth_session
    if(v1_iscsi_persistent_volume_source->chap_auth_session) {
    if(mazu_cJSON_AddBoolToObject(item, "chapAuthSession", v1_iscsi_persistent_volume_source->chap_auth_session) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->fs_type
    if(v1_iscsi_persistent_volume_source->fs_type) {
    if(mazu_cJSON_AddStringToObject(item, "fsType", v1_iscsi_persistent_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_iscsi_persistent_volume_source->initiator_name
    if(v1_iscsi_persistent_volume_source->initiator_name) {
    if(mazu_cJSON_AddStringToObject(item, "initiatorName", v1_iscsi_persistent_volume_source->initiator_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_iscsi_persistent_volume_source->iqn
    if (!v1_iscsi_persistent_volume_source->iqn) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "iqn", v1_iscsi_persistent_volume_source->iqn) == NULL) {
    goto fail; //String
    }


    // v1_iscsi_persistent_volume_source->iscsi_interface
    if(v1_iscsi_persistent_volume_source->iscsi_interface) {
    if(mazu_cJSON_AddStringToObject(item, "iscsiInterface", v1_iscsi_persistent_volume_source->iscsi_interface) == NULL) {
    goto fail; //String
    }
    }


    // v1_iscsi_persistent_volume_source->lun
    if (!v1_iscsi_persistent_volume_source->lun) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "lun", v1_iscsi_persistent_volume_source->lun) == NULL) {
    goto fail; //Numeric
    }


    // v1_iscsi_persistent_volume_source->portals
    if(v1_iscsi_persistent_volume_source->portals) {
    mazu_cJSON *portals = mazu_cJSON_AddArrayToObject(item, "portals");
    if(portals == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *portalsListEntry;
    list_ForEach(portalsListEntry, v1_iscsi_persistent_volume_source->portals) {
    if(mazu_cJSON_AddStringToObject(portals, "", (char*)portalsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_iscsi_persistent_volume_source->read_only
    if(v1_iscsi_persistent_volume_source->read_only) {
    if(mazu_cJSON_AddBoolToObject(item, "readOnly", v1_iscsi_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_iscsi_persistent_volume_source->secret_ref
    if(v1_iscsi_persistent_volume_source->secret_ref) {
    mazu_cJSON *secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_iscsi_persistent_volume_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_iscsi_persistent_volume_source->target_portal
    if (!v1_iscsi_persistent_volume_source->target_portal) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "targetPortal", v1_iscsi_persistent_volume_source->target_portal) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_parseFromJSON(mazu_cJSON *v1_iscsi_persistent_volume_sourceJSON){

    v1_iscsi_persistent_volume_source_t *v1_iscsi_persistent_volume_source_local_var = NULL;

    // define the local list for v1_iscsi_persistent_volume_source->portals
    list_t *portalsList = NULL;

    // define the local variable for v1_iscsi_persistent_volume_source->secret_ref
    v1_secret_reference_t *secret_ref_local_nonprim = NULL;

    // v1_iscsi_persistent_volume_source->chap_auth_discovery
    mazu_cJSON *chap_auth_discovery = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "chapAuthDiscovery");
    if (chap_auth_discovery) { 
    if(!mazu_cJSON_IsBool(chap_auth_discovery))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_persistent_volume_source->chap_auth_session
    mazu_cJSON *chap_auth_session = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "chapAuthSession");
    if (chap_auth_session) { 
    if(!mazu_cJSON_IsBool(chap_auth_session))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_persistent_volume_source->fs_type
    mazu_cJSON *fs_type = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!mazu_cJSON_IsString(fs_type) && !mazu_cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_iscsi_persistent_volume_source->initiator_name
    mazu_cJSON *initiator_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "initiatorName");
    if (initiator_name) { 
    if(!mazu_cJSON_IsString(initiator_name) && !mazu_cJSON_IsNull(initiator_name))
    {
    goto end; //String
    }
    }

    // v1_iscsi_persistent_volume_source->iqn
    mazu_cJSON *iqn = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "iqn");
    if (!iqn) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(iqn))
    {
    goto end; //String
    }

    // v1_iscsi_persistent_volume_source->iscsi_interface
    mazu_cJSON *iscsi_interface = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "iscsiInterface");
    if (iscsi_interface) { 
    if(!mazu_cJSON_IsString(iscsi_interface) && !mazu_cJSON_IsNull(iscsi_interface))
    {
    goto end; //String
    }
    }

    // v1_iscsi_persistent_volume_source->lun
    mazu_cJSON *lun = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "lun");
    if (!lun) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(lun))
    {
    goto end; //Numeric
    }

    // v1_iscsi_persistent_volume_source->portals
    mazu_cJSON *portals = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "portals");
    if (portals) { 
    mazu_cJSON *portals_local = NULL;
    if(!mazu_cJSON_IsArray(portals)) {
        goto end;//primitive container
    }
    portalsList = list_createList();

    mazu_cJSON_ArrayForEach(portals_local, portals)
    {
        if(!mazu_cJSON_IsString(portals_local))
        {
            goto end;
        }
        list_addElement(portalsList , strdup(portals_local->valuestring));
    }
    }

    // v1_iscsi_persistent_volume_source->read_only
    mazu_cJSON *read_only = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!mazu_cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_iscsi_persistent_volume_source->secret_ref
    mazu_cJSON *secret_ref = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "secretRef");
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(secret_ref); //nonprimitive
    }

    // v1_iscsi_persistent_volume_source->target_portal
    mazu_cJSON *target_portal = mazu_cJSON_GetObjectItemCaseSensitive(v1_iscsi_persistent_volume_sourceJSON, "targetPortal");
    if (!target_portal) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(target_portal))
    {
    goto end; //String
    }


    v1_iscsi_persistent_volume_source_local_var = v1_iscsi_persistent_volume_source_create (
        chap_auth_discovery ? chap_auth_discovery->valueint : 0,
        chap_auth_session ? chap_auth_session->valueint : 0,
        fs_type && !mazu_cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        initiator_name && !mazu_cJSON_IsNull(initiator_name) ? strdup(initiator_name->valuestring) : NULL,
        strdup(iqn->valuestring),
        iscsi_interface && !mazu_cJSON_IsNull(iscsi_interface) ? strdup(iscsi_interface->valuestring) : NULL,
        lun->valuedouble,
        portals ? portalsList : NULL,
        read_only ? read_only->valueint : 0,
        secret_ref ? secret_ref_local_nonprim : NULL,
        strdup(target_portal->valuestring)
        );

    return v1_iscsi_persistent_volume_source_local_var;
end:
    if (portalsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portalsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portalsList);
        portalsList = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
