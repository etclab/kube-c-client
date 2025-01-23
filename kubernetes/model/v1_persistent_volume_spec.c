#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_spec.h"



v1_persistent_volume_spec_t *v1_persistent_volume_spec_create(
    list_t *access_modes,
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store,
    v1_azure_disk_volume_source_t *azure_disk,
    v1_azure_file_persistent_volume_source_t *azure_file,
    list_t* capacity,
    v1_ceph_fs_persistent_volume_source_t *cephfs,
    v1_cinder_persistent_volume_source_t *cinder,
    v1_object_reference_t *claim_ref,
    v1_csi_persistent_volume_source_t *csi,
    v1_fc_volume_source_t *fc,
    v1_flex_persistent_volume_source_t *flex_volume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk,
    v1_glusterfs_persistent_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *host_path,
    v1_iscsi_persistent_volume_source_t *iscsi,
    v1_local_volume_source_t *local,
    list_t *mount_options,
    v1_nfs_volume_source_t *nfs,
    v1_volume_node_affinity_t *node_affinity,
    char *persistent_volume_reclaim_policy,
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk,
    v1_portworx_volume_source_t *portworx_volume,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_persistent_volume_source_t *rbd,
    v1_scale_io_persistent_volume_source_t *scale_io,
    char *storage_class_name,
    v1_storage_os_persistent_volume_source_t *storageos,
    char *volume_attributes_class_name,
    char *volume_mode,
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume
    ) {
    v1_persistent_volume_spec_t *v1_persistent_volume_spec_local_var = malloc(sizeof(v1_persistent_volume_spec_t));
    if (!v1_persistent_volume_spec_local_var) {
        return NULL;
    }
    v1_persistent_volume_spec_local_var->access_modes = access_modes;
    v1_persistent_volume_spec_local_var->aws_elastic_block_store = aws_elastic_block_store;
    v1_persistent_volume_spec_local_var->azure_disk = azure_disk;
    v1_persistent_volume_spec_local_var->azure_file = azure_file;
    v1_persistent_volume_spec_local_var->capacity = capacity;
    v1_persistent_volume_spec_local_var->cephfs = cephfs;
    v1_persistent_volume_spec_local_var->cinder = cinder;
    v1_persistent_volume_spec_local_var->claim_ref = claim_ref;
    v1_persistent_volume_spec_local_var->csi = csi;
    v1_persistent_volume_spec_local_var->fc = fc;
    v1_persistent_volume_spec_local_var->flex_volume = flex_volume;
    v1_persistent_volume_spec_local_var->flocker = flocker;
    v1_persistent_volume_spec_local_var->gce_persistent_disk = gce_persistent_disk;
    v1_persistent_volume_spec_local_var->glusterfs = glusterfs;
    v1_persistent_volume_spec_local_var->host_path = host_path;
    v1_persistent_volume_spec_local_var->iscsi = iscsi;
    v1_persistent_volume_spec_local_var->local = local;
    v1_persistent_volume_spec_local_var->mount_options = mount_options;
    v1_persistent_volume_spec_local_var->nfs = nfs;
    v1_persistent_volume_spec_local_var->node_affinity = node_affinity;
    v1_persistent_volume_spec_local_var->persistent_volume_reclaim_policy = persistent_volume_reclaim_policy;
    v1_persistent_volume_spec_local_var->photon_persistent_disk = photon_persistent_disk;
    v1_persistent_volume_spec_local_var->portworx_volume = portworx_volume;
    v1_persistent_volume_spec_local_var->quobyte = quobyte;
    v1_persistent_volume_spec_local_var->rbd = rbd;
    v1_persistent_volume_spec_local_var->scale_io = scale_io;
    v1_persistent_volume_spec_local_var->storage_class_name = storage_class_name;
    v1_persistent_volume_spec_local_var->storageos = storageos;
    v1_persistent_volume_spec_local_var->volume_attributes_class_name = volume_attributes_class_name;
    v1_persistent_volume_spec_local_var->volume_mode = volume_mode;
    v1_persistent_volume_spec_local_var->vsphere_volume = vsphere_volume;

    return v1_persistent_volume_spec_local_var;
}


void v1_persistent_volume_spec_free(v1_persistent_volume_spec_t *v1_persistent_volume_spec) {
    if(NULL == v1_persistent_volume_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_spec->access_modes) {
        list_ForEach(listEntry, v1_persistent_volume_spec->access_modes) {
            free(listEntry->data);
        }
        list_freeList(v1_persistent_volume_spec->access_modes);
        v1_persistent_volume_spec->access_modes = NULL;
    }
    if (v1_persistent_volume_spec->aws_elastic_block_store) {
        v1_aws_elastic_block_store_volume_source_free(v1_persistent_volume_spec->aws_elastic_block_store);
        v1_persistent_volume_spec->aws_elastic_block_store = NULL;
    }
    if (v1_persistent_volume_spec->azure_disk) {
        v1_azure_disk_volume_source_free(v1_persistent_volume_spec->azure_disk);
        v1_persistent_volume_spec->azure_disk = NULL;
    }
    if (v1_persistent_volume_spec->azure_file) {
        v1_azure_file_persistent_volume_source_free(v1_persistent_volume_spec->azure_file);
        v1_persistent_volume_spec->azure_file = NULL;
    }
    if (v1_persistent_volume_spec->capacity) {
        list_ForEach(listEntry, v1_persistent_volume_spec->capacity) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_persistent_volume_spec->capacity);
        v1_persistent_volume_spec->capacity = NULL;
    }
    if (v1_persistent_volume_spec->cephfs) {
        v1_ceph_fs_persistent_volume_source_free(v1_persistent_volume_spec->cephfs);
        v1_persistent_volume_spec->cephfs = NULL;
    }
    if (v1_persistent_volume_spec->cinder) {
        v1_cinder_persistent_volume_source_free(v1_persistent_volume_spec->cinder);
        v1_persistent_volume_spec->cinder = NULL;
    }
    if (v1_persistent_volume_spec->claim_ref) {
        v1_object_reference_free(v1_persistent_volume_spec->claim_ref);
        v1_persistent_volume_spec->claim_ref = NULL;
    }
    if (v1_persistent_volume_spec->csi) {
        v1_csi_persistent_volume_source_free(v1_persistent_volume_spec->csi);
        v1_persistent_volume_spec->csi = NULL;
    }
    if (v1_persistent_volume_spec->fc) {
        v1_fc_volume_source_free(v1_persistent_volume_spec->fc);
        v1_persistent_volume_spec->fc = NULL;
    }
    if (v1_persistent_volume_spec->flex_volume) {
        v1_flex_persistent_volume_source_free(v1_persistent_volume_spec->flex_volume);
        v1_persistent_volume_spec->flex_volume = NULL;
    }
    if (v1_persistent_volume_spec->flocker) {
        v1_flocker_volume_source_free(v1_persistent_volume_spec->flocker);
        v1_persistent_volume_spec->flocker = NULL;
    }
    if (v1_persistent_volume_spec->gce_persistent_disk) {
        v1_gce_persistent_disk_volume_source_free(v1_persistent_volume_spec->gce_persistent_disk);
        v1_persistent_volume_spec->gce_persistent_disk = NULL;
    }
    if (v1_persistent_volume_spec->glusterfs) {
        v1_glusterfs_persistent_volume_source_free(v1_persistent_volume_spec->glusterfs);
        v1_persistent_volume_spec->glusterfs = NULL;
    }
    if (v1_persistent_volume_spec->host_path) {
        v1_host_path_volume_source_free(v1_persistent_volume_spec->host_path);
        v1_persistent_volume_spec->host_path = NULL;
    }
    if (v1_persistent_volume_spec->iscsi) {
        v1_iscsi_persistent_volume_source_free(v1_persistent_volume_spec->iscsi);
        v1_persistent_volume_spec->iscsi = NULL;
    }
    if (v1_persistent_volume_spec->local) {
        v1_local_volume_source_free(v1_persistent_volume_spec->local);
        v1_persistent_volume_spec->local = NULL;
    }
    if (v1_persistent_volume_spec->mount_options) {
        list_ForEach(listEntry, v1_persistent_volume_spec->mount_options) {
            free(listEntry->data);
        }
        list_freeList(v1_persistent_volume_spec->mount_options);
        v1_persistent_volume_spec->mount_options = NULL;
    }
    if (v1_persistent_volume_spec->nfs) {
        v1_nfs_volume_source_free(v1_persistent_volume_spec->nfs);
        v1_persistent_volume_spec->nfs = NULL;
    }
    if (v1_persistent_volume_spec->node_affinity) {
        v1_volume_node_affinity_free(v1_persistent_volume_spec->node_affinity);
        v1_persistent_volume_spec->node_affinity = NULL;
    }
    if (v1_persistent_volume_spec->persistent_volume_reclaim_policy) {
        free(v1_persistent_volume_spec->persistent_volume_reclaim_policy);
        v1_persistent_volume_spec->persistent_volume_reclaim_policy = NULL;
    }
    if (v1_persistent_volume_spec->photon_persistent_disk) {
        v1_photon_persistent_disk_volume_source_free(v1_persistent_volume_spec->photon_persistent_disk);
        v1_persistent_volume_spec->photon_persistent_disk = NULL;
    }
    if (v1_persistent_volume_spec->portworx_volume) {
        v1_portworx_volume_source_free(v1_persistent_volume_spec->portworx_volume);
        v1_persistent_volume_spec->portworx_volume = NULL;
    }
    if (v1_persistent_volume_spec->quobyte) {
        v1_quobyte_volume_source_free(v1_persistent_volume_spec->quobyte);
        v1_persistent_volume_spec->quobyte = NULL;
    }
    if (v1_persistent_volume_spec->rbd) {
        v1_rbd_persistent_volume_source_free(v1_persistent_volume_spec->rbd);
        v1_persistent_volume_spec->rbd = NULL;
    }
    if (v1_persistent_volume_spec->scale_io) {
        v1_scale_io_persistent_volume_source_free(v1_persistent_volume_spec->scale_io);
        v1_persistent_volume_spec->scale_io = NULL;
    }
    if (v1_persistent_volume_spec->storage_class_name) {
        free(v1_persistent_volume_spec->storage_class_name);
        v1_persistent_volume_spec->storage_class_name = NULL;
    }
    if (v1_persistent_volume_spec->storageos) {
        v1_storage_os_persistent_volume_source_free(v1_persistent_volume_spec->storageos);
        v1_persistent_volume_spec->storageos = NULL;
    }
    if (v1_persistent_volume_spec->volume_attributes_class_name) {
        free(v1_persistent_volume_spec->volume_attributes_class_name);
        v1_persistent_volume_spec->volume_attributes_class_name = NULL;
    }
    if (v1_persistent_volume_spec->volume_mode) {
        free(v1_persistent_volume_spec->volume_mode);
        v1_persistent_volume_spec->volume_mode = NULL;
    }
    if (v1_persistent_volume_spec->vsphere_volume) {
        v1_vsphere_virtual_disk_volume_source_free(v1_persistent_volume_spec->vsphere_volume);
        v1_persistent_volume_spec->vsphere_volume = NULL;
    }
    free(v1_persistent_volume_spec);
}

mazu_cJSON *v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_t *v1_persistent_volume_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_persistent_volume_spec->access_modes
    if(v1_persistent_volume_spec->access_modes) {
    mazu_cJSON *access_modes = mazu_cJSON_AddArrayToObject(item, "accessModes");
    if(access_modes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *access_modesListEntry;
    list_ForEach(access_modesListEntry, v1_persistent_volume_spec->access_modes) {
    if(mazu_cJSON_AddStringToObject(access_modes, "", (char*)access_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_persistent_volume_spec->aws_elastic_block_store
    if(v1_persistent_volume_spec->aws_elastic_block_store) {
    mazu_cJSON *aws_elastic_block_store_local_JSON = v1_aws_elastic_block_store_volume_source_convertToJSON(v1_persistent_volume_spec->aws_elastic_block_store);
    if(aws_elastic_block_store_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "awsElasticBlockStore", aws_elastic_block_store_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->azure_disk
    if(v1_persistent_volume_spec->azure_disk) {
    mazu_cJSON *azure_disk_local_JSON = v1_azure_disk_volume_source_convertToJSON(v1_persistent_volume_spec->azure_disk);
    if(azure_disk_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "azureDisk", azure_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->azure_file
    if(v1_persistent_volume_spec->azure_file) {
    mazu_cJSON *azure_file_local_JSON = v1_azure_file_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->azure_file);
    if(azure_file_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "azureFile", azure_file_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->capacity
    if(v1_persistent_volume_spec->capacity) {
    mazu_cJSON *capacity = mazu_cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    mazu_cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1_persistent_volume_spec->capacity) {
    list_ForEach(capacityListEntry, v1_persistent_volume_spec->capacity) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)capacityListEntry->data;
        if(mazu_cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_persistent_volume_spec->cephfs
    if(v1_persistent_volume_spec->cephfs) {
    mazu_cJSON *cephfs_local_JSON = v1_ceph_fs_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->cephfs);
    if(cephfs_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "cephfs", cephfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->cinder
    if(v1_persistent_volume_spec->cinder) {
    mazu_cJSON *cinder_local_JSON = v1_cinder_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->cinder);
    if(cinder_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "cinder", cinder_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->claim_ref
    if(v1_persistent_volume_spec->claim_ref) {
    mazu_cJSON *claim_ref_local_JSON = v1_object_reference_convertToJSON(v1_persistent_volume_spec->claim_ref);
    if(claim_ref_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "claimRef", claim_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->csi
    if(v1_persistent_volume_spec->csi) {
    mazu_cJSON *csi_local_JSON = v1_csi_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->csi);
    if(csi_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "csi", csi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->fc
    if(v1_persistent_volume_spec->fc) {
    mazu_cJSON *fc_local_JSON = v1_fc_volume_source_convertToJSON(v1_persistent_volume_spec->fc);
    if(fc_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "fc", fc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->flex_volume
    if(v1_persistent_volume_spec->flex_volume) {
    mazu_cJSON *flex_volume_local_JSON = v1_flex_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->flex_volume);
    if(flex_volume_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "flexVolume", flex_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->flocker
    if(v1_persistent_volume_spec->flocker) {
    mazu_cJSON *flocker_local_JSON = v1_flocker_volume_source_convertToJSON(v1_persistent_volume_spec->flocker);
    if(flocker_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "flocker", flocker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->gce_persistent_disk
    if(v1_persistent_volume_spec->gce_persistent_disk) {
    mazu_cJSON *gce_persistent_disk_local_JSON = v1_gce_persistent_disk_volume_source_convertToJSON(v1_persistent_volume_spec->gce_persistent_disk);
    if(gce_persistent_disk_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "gcePersistentDisk", gce_persistent_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->glusterfs
    if(v1_persistent_volume_spec->glusterfs) {
    mazu_cJSON *glusterfs_local_JSON = v1_glusterfs_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->glusterfs);
    if(glusterfs_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "glusterfs", glusterfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->host_path
    if(v1_persistent_volume_spec->host_path) {
    mazu_cJSON *host_path_local_JSON = v1_host_path_volume_source_convertToJSON(v1_persistent_volume_spec->host_path);
    if(host_path_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "hostPath", host_path_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->iscsi
    if(v1_persistent_volume_spec->iscsi) {
    mazu_cJSON *iscsi_local_JSON = v1_iscsi_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->iscsi);
    if(iscsi_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "iscsi", iscsi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->local
    if(v1_persistent_volume_spec->local) {
    mazu_cJSON *local_local_JSON = v1_local_volume_source_convertToJSON(v1_persistent_volume_spec->local);
    if(local_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "local", local_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->mount_options
    if(v1_persistent_volume_spec->mount_options) {
    mazu_cJSON *mount_options = mazu_cJSON_AddArrayToObject(item, "mountOptions");
    if(mount_options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mount_optionsListEntry;
    list_ForEach(mount_optionsListEntry, v1_persistent_volume_spec->mount_options) {
    if(mazu_cJSON_AddStringToObject(mount_options, "", (char*)mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_persistent_volume_spec->nfs
    if(v1_persistent_volume_spec->nfs) {
    mazu_cJSON *nfs_local_JSON = v1_nfs_volume_source_convertToJSON(v1_persistent_volume_spec->nfs);
    if(nfs_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "nfs", nfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->node_affinity
    if(v1_persistent_volume_spec->node_affinity) {
    mazu_cJSON *node_affinity_local_JSON = v1_volume_node_affinity_convertToJSON(v1_persistent_volume_spec->node_affinity);
    if(node_affinity_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "nodeAffinity", node_affinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->persistent_volume_reclaim_policy
    if(v1_persistent_volume_spec->persistent_volume_reclaim_policy) {
    if(mazu_cJSON_AddStringToObject(item, "persistentVolumeReclaimPolicy", v1_persistent_volume_spec->persistent_volume_reclaim_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->photon_persistent_disk
    if(v1_persistent_volume_spec->photon_persistent_disk) {
    mazu_cJSON *photon_persistent_disk_local_JSON = v1_photon_persistent_disk_volume_source_convertToJSON(v1_persistent_volume_spec->photon_persistent_disk);
    if(photon_persistent_disk_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "photonPersistentDisk", photon_persistent_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->portworx_volume
    if(v1_persistent_volume_spec->portworx_volume) {
    mazu_cJSON *portworx_volume_local_JSON = v1_portworx_volume_source_convertToJSON(v1_persistent_volume_spec->portworx_volume);
    if(portworx_volume_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "portworxVolume", portworx_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->quobyte
    if(v1_persistent_volume_spec->quobyte) {
    mazu_cJSON *quobyte_local_JSON = v1_quobyte_volume_source_convertToJSON(v1_persistent_volume_spec->quobyte);
    if(quobyte_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "quobyte", quobyte_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->rbd
    if(v1_persistent_volume_spec->rbd) {
    mazu_cJSON *rbd_local_JSON = v1_rbd_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->rbd);
    if(rbd_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "rbd", rbd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->scale_io
    if(v1_persistent_volume_spec->scale_io) {
    mazu_cJSON *scale_io_local_JSON = v1_scale_io_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->scale_io);
    if(scale_io_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "scaleIO", scale_io_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->storage_class_name
    if(v1_persistent_volume_spec->storage_class_name) {
    if(mazu_cJSON_AddStringToObject(item, "storageClassName", v1_persistent_volume_spec->storage_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->storageos
    if(v1_persistent_volume_spec->storageos) {
    mazu_cJSON *storageos_local_JSON = v1_storage_os_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->storageos);
    if(storageos_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "storageos", storageos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->volume_attributes_class_name
    if(v1_persistent_volume_spec->volume_attributes_class_name) {
    if(mazu_cJSON_AddStringToObject(item, "volumeAttributesClassName", v1_persistent_volume_spec->volume_attributes_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->volume_mode
    if(v1_persistent_volume_spec->volume_mode) {
    if(mazu_cJSON_AddStringToObject(item, "volumeMode", v1_persistent_volume_spec->volume_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->vsphere_volume
    if(v1_persistent_volume_spec->vsphere_volume) {
    mazu_cJSON *vsphere_volume_local_JSON = v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_persistent_volume_spec->vsphere_volume);
    if(vsphere_volume_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "vsphereVolume", vsphere_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_persistent_volume_spec_t *v1_persistent_volume_spec_parseFromJSON(mazu_cJSON *v1_persistent_volume_specJSON){

    v1_persistent_volume_spec_t *v1_persistent_volume_spec_local_var = NULL;

    // define the local list for v1_persistent_volume_spec->access_modes
    list_t *access_modesList = NULL;

    // define the local variable for v1_persistent_volume_spec->aws_elastic_block_store
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->azure_disk
    v1_azure_disk_volume_source_t *azure_disk_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->azure_file
    v1_azure_file_persistent_volume_source_t *azure_file_local_nonprim = NULL;

    // define the local map for v1_persistent_volume_spec->capacity
    list_t *capacityList = NULL;

    // define the local variable for v1_persistent_volume_spec->cephfs
    v1_ceph_fs_persistent_volume_source_t *cephfs_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->cinder
    v1_cinder_persistent_volume_source_t *cinder_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->claim_ref
    v1_object_reference_t *claim_ref_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->csi
    v1_csi_persistent_volume_source_t *csi_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->fc
    v1_fc_volume_source_t *fc_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->flex_volume
    v1_flex_persistent_volume_source_t *flex_volume_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->flocker
    v1_flocker_volume_source_t *flocker_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->gce_persistent_disk
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->glusterfs
    v1_glusterfs_persistent_volume_source_t *glusterfs_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->host_path
    v1_host_path_volume_source_t *host_path_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->iscsi
    v1_iscsi_persistent_volume_source_t *iscsi_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->local
    v1_local_volume_source_t *local_local_nonprim = NULL;

    // define the local list for v1_persistent_volume_spec->mount_options
    list_t *mount_optionsList = NULL;

    // define the local variable for v1_persistent_volume_spec->nfs
    v1_nfs_volume_source_t *nfs_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->node_affinity
    v1_volume_node_affinity_t *node_affinity_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->photon_persistent_disk
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->portworx_volume
    v1_portworx_volume_source_t *portworx_volume_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->quobyte
    v1_quobyte_volume_source_t *quobyte_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->rbd
    v1_rbd_persistent_volume_source_t *rbd_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->scale_io
    v1_scale_io_persistent_volume_source_t *scale_io_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->storageos
    v1_storage_os_persistent_volume_source_t *storageos_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->vsphere_volume
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume_local_nonprim = NULL;

    // v1_persistent_volume_spec->access_modes
    mazu_cJSON *access_modes = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "accessModes");
    if (access_modes) { 
    mazu_cJSON *access_modes_local = NULL;
    if(!mazu_cJSON_IsArray(access_modes)) {
        goto end;//primitive container
    }
    access_modesList = list_createList();

    mazu_cJSON_ArrayForEach(access_modes_local, access_modes)
    {
        if(!mazu_cJSON_IsString(access_modes_local))
        {
            goto end;
        }
        list_addElement(access_modesList , strdup(access_modes_local->valuestring));
    }
    }

    // v1_persistent_volume_spec->aws_elastic_block_store
    mazu_cJSON *aws_elastic_block_store = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "awsElasticBlockStore");
    if (aws_elastic_block_store) { 
    aws_elastic_block_store_local_nonprim = v1_aws_elastic_block_store_volume_source_parseFromJSON(aws_elastic_block_store); //nonprimitive
    }

    // v1_persistent_volume_spec->azure_disk
    mazu_cJSON *azure_disk = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "azureDisk");
    if (azure_disk) { 
    azure_disk_local_nonprim = v1_azure_disk_volume_source_parseFromJSON(azure_disk); //nonprimitive
    }

    // v1_persistent_volume_spec->azure_file
    mazu_cJSON *azure_file = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "azureFile");
    if (azure_file) { 
    azure_file_local_nonprim = v1_azure_file_persistent_volume_source_parseFromJSON(azure_file); //nonprimitive
    }

    // v1_persistent_volume_spec->capacity
    mazu_cJSON *capacity = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "capacity");
    if (capacity) { 
    mazu_cJSON *capacity_local_map = NULL;
    if(!mazu_cJSON_IsObject(capacity) && !mazu_cJSON_IsNull(capacity))
    {
        goto end;//primitive map container
    }
    if(mazu_cJSON_IsObject(capacity))
    {
        capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        mazu_cJSON_ArrayForEach(capacity_local_map, capacity)
        {
            mazu_cJSON *localMapObject = capacity_local_map;
            if(!mazu_cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(capacityList , localMapKeyPair);
        }
    }
    }

    // v1_persistent_volume_spec->cephfs
    mazu_cJSON *cephfs = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "cephfs");
    if (cephfs) { 
    cephfs_local_nonprim = v1_ceph_fs_persistent_volume_source_parseFromJSON(cephfs); //nonprimitive
    }

    // v1_persistent_volume_spec->cinder
    mazu_cJSON *cinder = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "cinder");
    if (cinder) { 
    cinder_local_nonprim = v1_cinder_persistent_volume_source_parseFromJSON(cinder); //nonprimitive
    }

    // v1_persistent_volume_spec->claim_ref
    mazu_cJSON *claim_ref = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "claimRef");
    if (claim_ref) { 
    claim_ref_local_nonprim = v1_object_reference_parseFromJSON(claim_ref); //nonprimitive
    }

    // v1_persistent_volume_spec->csi
    mazu_cJSON *csi = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "csi");
    if (csi) { 
    csi_local_nonprim = v1_csi_persistent_volume_source_parseFromJSON(csi); //nonprimitive
    }

    // v1_persistent_volume_spec->fc
    mazu_cJSON *fc = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "fc");
    if (fc) { 
    fc_local_nonprim = v1_fc_volume_source_parseFromJSON(fc); //nonprimitive
    }

    // v1_persistent_volume_spec->flex_volume
    mazu_cJSON *flex_volume = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "flexVolume");
    if (flex_volume) { 
    flex_volume_local_nonprim = v1_flex_persistent_volume_source_parseFromJSON(flex_volume); //nonprimitive
    }

    // v1_persistent_volume_spec->flocker
    mazu_cJSON *flocker = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "flocker");
    if (flocker) { 
    flocker_local_nonprim = v1_flocker_volume_source_parseFromJSON(flocker); //nonprimitive
    }

    // v1_persistent_volume_spec->gce_persistent_disk
    mazu_cJSON *gce_persistent_disk = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "gcePersistentDisk");
    if (gce_persistent_disk) { 
    gce_persistent_disk_local_nonprim = v1_gce_persistent_disk_volume_source_parseFromJSON(gce_persistent_disk); //nonprimitive
    }

    // v1_persistent_volume_spec->glusterfs
    mazu_cJSON *glusterfs = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "glusterfs");
    if (glusterfs) { 
    glusterfs_local_nonprim = v1_glusterfs_persistent_volume_source_parseFromJSON(glusterfs); //nonprimitive
    }

    // v1_persistent_volume_spec->host_path
    mazu_cJSON *host_path = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "hostPath");
    if (host_path) { 
    host_path_local_nonprim = v1_host_path_volume_source_parseFromJSON(host_path); //nonprimitive
    }

    // v1_persistent_volume_spec->iscsi
    mazu_cJSON *iscsi = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "iscsi");
    if (iscsi) { 
    iscsi_local_nonprim = v1_iscsi_persistent_volume_source_parseFromJSON(iscsi); //nonprimitive
    }

    // v1_persistent_volume_spec->local
    mazu_cJSON *local = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "local");
    if (local) { 
    local_local_nonprim = v1_local_volume_source_parseFromJSON(local); //nonprimitive
    }

    // v1_persistent_volume_spec->mount_options
    mazu_cJSON *mount_options = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "mountOptions");
    if (mount_options) { 
    mazu_cJSON *mount_options_local = NULL;
    if(!mazu_cJSON_IsArray(mount_options)) {
        goto end;//primitive container
    }
    mount_optionsList = list_createList();

    mazu_cJSON_ArrayForEach(mount_options_local, mount_options)
    {
        if(!mazu_cJSON_IsString(mount_options_local))
        {
            goto end;
        }
        list_addElement(mount_optionsList , strdup(mount_options_local->valuestring));
    }
    }

    // v1_persistent_volume_spec->nfs
    mazu_cJSON *nfs = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "nfs");
    if (nfs) { 
    nfs_local_nonprim = v1_nfs_volume_source_parseFromJSON(nfs); //nonprimitive
    }

    // v1_persistent_volume_spec->node_affinity
    mazu_cJSON *node_affinity = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "nodeAffinity");
    if (node_affinity) { 
    node_affinity_local_nonprim = v1_volume_node_affinity_parseFromJSON(node_affinity); //nonprimitive
    }

    // v1_persistent_volume_spec->persistent_volume_reclaim_policy
    mazu_cJSON *persistent_volume_reclaim_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "persistentVolumeReclaimPolicy");
    if (persistent_volume_reclaim_policy) { 
    if(!mazu_cJSON_IsString(persistent_volume_reclaim_policy) && !mazu_cJSON_IsNull(persistent_volume_reclaim_policy))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->photon_persistent_disk
    mazu_cJSON *photon_persistent_disk = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "photonPersistentDisk");
    if (photon_persistent_disk) { 
    photon_persistent_disk_local_nonprim = v1_photon_persistent_disk_volume_source_parseFromJSON(photon_persistent_disk); //nonprimitive
    }

    // v1_persistent_volume_spec->portworx_volume
    mazu_cJSON *portworx_volume = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "portworxVolume");
    if (portworx_volume) { 
    portworx_volume_local_nonprim = v1_portworx_volume_source_parseFromJSON(portworx_volume); //nonprimitive
    }

    // v1_persistent_volume_spec->quobyte
    mazu_cJSON *quobyte = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "quobyte");
    if (quobyte) { 
    quobyte_local_nonprim = v1_quobyte_volume_source_parseFromJSON(quobyte); //nonprimitive
    }

    // v1_persistent_volume_spec->rbd
    mazu_cJSON *rbd = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "rbd");
    if (rbd) { 
    rbd_local_nonprim = v1_rbd_persistent_volume_source_parseFromJSON(rbd); //nonprimitive
    }

    // v1_persistent_volume_spec->scale_io
    mazu_cJSON *scale_io = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "scaleIO");
    if (scale_io) { 
    scale_io_local_nonprim = v1_scale_io_persistent_volume_source_parseFromJSON(scale_io); //nonprimitive
    }

    // v1_persistent_volume_spec->storage_class_name
    mazu_cJSON *storage_class_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "storageClassName");
    if (storage_class_name) { 
    if(!mazu_cJSON_IsString(storage_class_name) && !mazu_cJSON_IsNull(storage_class_name))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->storageos
    mazu_cJSON *storageos = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "storageos");
    if (storageos) { 
    storageos_local_nonprim = v1_storage_os_persistent_volume_source_parseFromJSON(storageos); //nonprimitive
    }

    // v1_persistent_volume_spec->volume_attributes_class_name
    mazu_cJSON *volume_attributes_class_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "volumeAttributesClassName");
    if (volume_attributes_class_name) { 
    if(!mazu_cJSON_IsString(volume_attributes_class_name) && !mazu_cJSON_IsNull(volume_attributes_class_name))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->volume_mode
    mazu_cJSON *volume_mode = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "volumeMode");
    if (volume_mode) { 
    if(!mazu_cJSON_IsString(volume_mode) && !mazu_cJSON_IsNull(volume_mode))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->vsphere_volume
    mazu_cJSON *vsphere_volume = mazu_cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "vsphereVolume");
    if (vsphere_volume) { 
    vsphere_volume_local_nonprim = v1_vsphere_virtual_disk_volume_source_parseFromJSON(vsphere_volume); //nonprimitive
    }


    v1_persistent_volume_spec_local_var = v1_persistent_volume_spec_create (
        access_modes ? access_modesList : NULL,
        aws_elastic_block_store ? aws_elastic_block_store_local_nonprim : NULL,
        azure_disk ? azure_disk_local_nonprim : NULL,
        azure_file ? azure_file_local_nonprim : NULL,
        capacity ? capacityList : NULL,
        cephfs ? cephfs_local_nonprim : NULL,
        cinder ? cinder_local_nonprim : NULL,
        claim_ref ? claim_ref_local_nonprim : NULL,
        csi ? csi_local_nonprim : NULL,
        fc ? fc_local_nonprim : NULL,
        flex_volume ? flex_volume_local_nonprim : NULL,
        flocker ? flocker_local_nonprim : NULL,
        gce_persistent_disk ? gce_persistent_disk_local_nonprim : NULL,
        glusterfs ? glusterfs_local_nonprim : NULL,
        host_path ? host_path_local_nonprim : NULL,
        iscsi ? iscsi_local_nonprim : NULL,
        local ? local_local_nonprim : NULL,
        mount_options ? mount_optionsList : NULL,
        nfs ? nfs_local_nonprim : NULL,
        node_affinity ? node_affinity_local_nonprim : NULL,
        persistent_volume_reclaim_policy && !mazu_cJSON_IsNull(persistent_volume_reclaim_policy) ? strdup(persistent_volume_reclaim_policy->valuestring) : NULL,
        photon_persistent_disk ? photon_persistent_disk_local_nonprim : NULL,
        portworx_volume ? portworx_volume_local_nonprim : NULL,
        quobyte ? quobyte_local_nonprim : NULL,
        rbd ? rbd_local_nonprim : NULL,
        scale_io ? scale_io_local_nonprim : NULL,
        storage_class_name && !mazu_cJSON_IsNull(storage_class_name) ? strdup(storage_class_name->valuestring) : NULL,
        storageos ? storageos_local_nonprim : NULL,
        volume_attributes_class_name && !mazu_cJSON_IsNull(volume_attributes_class_name) ? strdup(volume_attributes_class_name->valuestring) : NULL,
        volume_mode && !mazu_cJSON_IsNull(volume_mode) ? strdup(volume_mode->valuestring) : NULL,
        vsphere_volume ? vsphere_volume_local_nonprim : NULL
        );

    return v1_persistent_volume_spec_local_var;
end:
    if (access_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, access_modesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(access_modesList);
        access_modesList = NULL;
    }
    if (aws_elastic_block_store_local_nonprim) {
        v1_aws_elastic_block_store_volume_source_free(aws_elastic_block_store_local_nonprim);
        aws_elastic_block_store_local_nonprim = NULL;
    }
    if (azure_disk_local_nonprim) {
        v1_azure_disk_volume_source_free(azure_disk_local_nonprim);
        azure_disk_local_nonprim = NULL;
    }
    if (azure_file_local_nonprim) {
        v1_azure_file_persistent_volume_source_free(azure_file_local_nonprim);
        azure_file_local_nonprim = NULL;
    }
    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    if (cephfs_local_nonprim) {
        v1_ceph_fs_persistent_volume_source_free(cephfs_local_nonprim);
        cephfs_local_nonprim = NULL;
    }
    if (cinder_local_nonprim) {
        v1_cinder_persistent_volume_source_free(cinder_local_nonprim);
        cinder_local_nonprim = NULL;
    }
    if (claim_ref_local_nonprim) {
        v1_object_reference_free(claim_ref_local_nonprim);
        claim_ref_local_nonprim = NULL;
    }
    if (csi_local_nonprim) {
        v1_csi_persistent_volume_source_free(csi_local_nonprim);
        csi_local_nonprim = NULL;
    }
    if (fc_local_nonprim) {
        v1_fc_volume_source_free(fc_local_nonprim);
        fc_local_nonprim = NULL;
    }
    if (flex_volume_local_nonprim) {
        v1_flex_persistent_volume_source_free(flex_volume_local_nonprim);
        flex_volume_local_nonprim = NULL;
    }
    if (flocker_local_nonprim) {
        v1_flocker_volume_source_free(flocker_local_nonprim);
        flocker_local_nonprim = NULL;
    }
    if (gce_persistent_disk_local_nonprim) {
        v1_gce_persistent_disk_volume_source_free(gce_persistent_disk_local_nonprim);
        gce_persistent_disk_local_nonprim = NULL;
    }
    if (glusterfs_local_nonprim) {
        v1_glusterfs_persistent_volume_source_free(glusterfs_local_nonprim);
        glusterfs_local_nonprim = NULL;
    }
    if (host_path_local_nonprim) {
        v1_host_path_volume_source_free(host_path_local_nonprim);
        host_path_local_nonprim = NULL;
    }
    if (iscsi_local_nonprim) {
        v1_iscsi_persistent_volume_source_free(iscsi_local_nonprim);
        iscsi_local_nonprim = NULL;
    }
    if (local_local_nonprim) {
        v1_local_volume_source_free(local_local_nonprim);
        local_local_nonprim = NULL;
    }
    if (mount_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mount_optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mount_optionsList);
        mount_optionsList = NULL;
    }
    if (nfs_local_nonprim) {
        v1_nfs_volume_source_free(nfs_local_nonprim);
        nfs_local_nonprim = NULL;
    }
    if (node_affinity_local_nonprim) {
        v1_volume_node_affinity_free(node_affinity_local_nonprim);
        node_affinity_local_nonprim = NULL;
    }
    if (photon_persistent_disk_local_nonprim) {
        v1_photon_persistent_disk_volume_source_free(photon_persistent_disk_local_nonprim);
        photon_persistent_disk_local_nonprim = NULL;
    }
    if (portworx_volume_local_nonprim) {
        v1_portworx_volume_source_free(portworx_volume_local_nonprim);
        portworx_volume_local_nonprim = NULL;
    }
    if (quobyte_local_nonprim) {
        v1_quobyte_volume_source_free(quobyte_local_nonprim);
        quobyte_local_nonprim = NULL;
    }
    if (rbd_local_nonprim) {
        v1_rbd_persistent_volume_source_free(rbd_local_nonprim);
        rbd_local_nonprim = NULL;
    }
    if (scale_io_local_nonprim) {
        v1_scale_io_persistent_volume_source_free(scale_io_local_nonprim);
        scale_io_local_nonprim = NULL;
    }
    if (storageos_local_nonprim) {
        v1_storage_os_persistent_volume_source_free(storageos_local_nonprim);
        storageos_local_nonprim = NULL;
    }
    if (vsphere_volume_local_nonprim) {
        v1_vsphere_virtual_disk_volume_source_free(vsphere_volume_local_nonprim);
        vsphere_volume_local_nonprim = NULL;
    }
    return NULL;

}
