#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_os.h"



v1_pod_os_t *v1_pod_os_create(
    char *name
    ) {
    v1_pod_os_t *v1_pod_os_local_var = malloc(sizeof(v1_pod_os_t));
    if (!v1_pod_os_local_var) {
        return NULL;
    }
    v1_pod_os_local_var->name = name;

    return v1_pod_os_local_var;
}


void v1_pod_os_free(v1_pod_os_t *v1_pod_os) {
    if(NULL == v1_pod_os){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_os->name) {
        free(v1_pod_os->name);
        v1_pod_os->name = NULL;
    }
    free(v1_pod_os);
}

mazu_cJSON *v1_pod_os_convertToJSON(v1_pod_os_t *v1_pod_os) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_os->name
    if (!v1_pod_os->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_pod_os->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_os_t *v1_pod_os_parseFromJSON(mazu_cJSON *v1_pod_osJSON){

    v1_pod_os_t *v1_pod_os_local_var = NULL;

    // v1_pod_os->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_osJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_pod_os_local_var = v1_pod_os_create (
        strdup(name->valuestring)
        );

    return v1_pod_os_local_var;
end:
    return NULL;

}
