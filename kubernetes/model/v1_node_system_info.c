#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_system_info.h"



v1_node_system_info_t *v1_node_system_info_create(
    char *architecture,
    char *boot_id,
    char *container_runtime_version,
    char *kernel_version,
    char *kube_proxy_version,
    char *kubelet_version,
    char *machine_id,
    char *operating_system,
    char *os_image,
    char *system_uuid
    ) {
    v1_node_system_info_t *v1_node_system_info_local_var = malloc(sizeof(v1_node_system_info_t));
    if (!v1_node_system_info_local_var) {
        return NULL;
    }
    v1_node_system_info_local_var->architecture = architecture;
    v1_node_system_info_local_var->boot_id = boot_id;
    v1_node_system_info_local_var->container_runtime_version = container_runtime_version;
    v1_node_system_info_local_var->kernel_version = kernel_version;
    v1_node_system_info_local_var->kube_proxy_version = kube_proxy_version;
    v1_node_system_info_local_var->kubelet_version = kubelet_version;
    v1_node_system_info_local_var->machine_id = machine_id;
    v1_node_system_info_local_var->operating_system = operating_system;
    v1_node_system_info_local_var->os_image = os_image;
    v1_node_system_info_local_var->system_uuid = system_uuid;

    return v1_node_system_info_local_var;
}


void v1_node_system_info_free(v1_node_system_info_t *v1_node_system_info) {
    if(NULL == v1_node_system_info){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_system_info->architecture) {
        free(v1_node_system_info->architecture);
        v1_node_system_info->architecture = NULL;
    }
    if (v1_node_system_info->boot_id) {
        free(v1_node_system_info->boot_id);
        v1_node_system_info->boot_id = NULL;
    }
    if (v1_node_system_info->container_runtime_version) {
        free(v1_node_system_info->container_runtime_version);
        v1_node_system_info->container_runtime_version = NULL;
    }
    if (v1_node_system_info->kernel_version) {
        free(v1_node_system_info->kernel_version);
        v1_node_system_info->kernel_version = NULL;
    }
    if (v1_node_system_info->kube_proxy_version) {
        free(v1_node_system_info->kube_proxy_version);
        v1_node_system_info->kube_proxy_version = NULL;
    }
    if (v1_node_system_info->kubelet_version) {
        free(v1_node_system_info->kubelet_version);
        v1_node_system_info->kubelet_version = NULL;
    }
    if (v1_node_system_info->machine_id) {
        free(v1_node_system_info->machine_id);
        v1_node_system_info->machine_id = NULL;
    }
    if (v1_node_system_info->operating_system) {
        free(v1_node_system_info->operating_system);
        v1_node_system_info->operating_system = NULL;
    }
    if (v1_node_system_info->os_image) {
        free(v1_node_system_info->os_image);
        v1_node_system_info->os_image = NULL;
    }
    if (v1_node_system_info->system_uuid) {
        free(v1_node_system_info->system_uuid);
        v1_node_system_info->system_uuid = NULL;
    }
    free(v1_node_system_info);
}

mazu_cJSON *v1_node_system_info_convertToJSON(v1_node_system_info_t *v1_node_system_info) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_node_system_info->architecture
    if (!v1_node_system_info->architecture) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "architecture", v1_node_system_info->architecture) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->boot_id
    if (!v1_node_system_info->boot_id) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "bootID", v1_node_system_info->boot_id) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->container_runtime_version
    if (!v1_node_system_info->container_runtime_version) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "containerRuntimeVersion", v1_node_system_info->container_runtime_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->kernel_version
    if (!v1_node_system_info->kernel_version) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kernelVersion", v1_node_system_info->kernel_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->kube_proxy_version
    if (!v1_node_system_info->kube_proxy_version) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kubeProxyVersion", v1_node_system_info->kube_proxy_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->kubelet_version
    if (!v1_node_system_info->kubelet_version) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "kubeletVersion", v1_node_system_info->kubelet_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->machine_id
    if (!v1_node_system_info->machine_id) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "machineID", v1_node_system_info->machine_id) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->operating_system
    if (!v1_node_system_info->operating_system) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "operatingSystem", v1_node_system_info->operating_system) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->os_image
    if (!v1_node_system_info->os_image) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "osImage", v1_node_system_info->os_image) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->system_uuid
    if (!v1_node_system_info->system_uuid) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "systemUUID", v1_node_system_info->system_uuid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_node_system_info_t *v1_node_system_info_parseFromJSON(mazu_cJSON *v1_node_system_infoJSON){

    v1_node_system_info_t *v1_node_system_info_local_var = NULL;

    // v1_node_system_info->architecture
    mazu_cJSON *architecture = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "architecture");
    if (!architecture) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(architecture))
    {
    goto end; //String
    }

    // v1_node_system_info->boot_id
    mazu_cJSON *boot_id = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "bootID");
    if (!boot_id) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(boot_id))
    {
    goto end; //String
    }

    // v1_node_system_info->container_runtime_version
    mazu_cJSON *container_runtime_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "containerRuntimeVersion");
    if (!container_runtime_version) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(container_runtime_version))
    {
    goto end; //String
    }

    // v1_node_system_info->kernel_version
    mazu_cJSON *kernel_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kernelVersion");
    if (!kernel_version) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kernel_version))
    {
    goto end; //String
    }

    // v1_node_system_info->kube_proxy_version
    mazu_cJSON *kube_proxy_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kubeProxyVersion");
    if (!kube_proxy_version) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kube_proxy_version))
    {
    goto end; //String
    }

    // v1_node_system_info->kubelet_version
    mazu_cJSON *kubelet_version = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kubeletVersion");
    if (!kubelet_version) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(kubelet_version))
    {
    goto end; //String
    }

    // v1_node_system_info->machine_id
    mazu_cJSON *machine_id = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "machineID");
    if (!machine_id) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(machine_id))
    {
    goto end; //String
    }

    // v1_node_system_info->operating_system
    mazu_cJSON *operating_system = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "operatingSystem");
    if (!operating_system) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(operating_system))
    {
    goto end; //String
    }

    // v1_node_system_info->os_image
    mazu_cJSON *os_image = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "osImage");
    if (!os_image) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(os_image))
    {
    goto end; //String
    }

    // v1_node_system_info->system_uuid
    mazu_cJSON *system_uuid = mazu_cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "systemUUID");
    if (!system_uuid) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(system_uuid))
    {
    goto end; //String
    }


    v1_node_system_info_local_var = v1_node_system_info_create (
        strdup(architecture->valuestring),
        strdup(boot_id->valuestring),
        strdup(container_runtime_version->valuestring),
        strdup(kernel_version->valuestring),
        strdup(kube_proxy_version->valuestring),
        strdup(kubelet_version->valuestring),
        strdup(machine_id->valuestring),
        strdup(operating_system->valuestring),
        strdup(os_image->valuestring),
        strdup(system_uuid->valuestring)
        );

    return v1_node_system_info_local_var;
end:
    return NULL;

}
