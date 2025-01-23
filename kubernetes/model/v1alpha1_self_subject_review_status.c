#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_self_subject_review_status.h"



v1alpha1_self_subject_review_status_t *v1alpha1_self_subject_review_status_create(
    v1_user_info_t *user_info
    ) {
    v1alpha1_self_subject_review_status_t *v1alpha1_self_subject_review_status_local_var = malloc(sizeof(v1alpha1_self_subject_review_status_t));
    if (!v1alpha1_self_subject_review_status_local_var) {
        return NULL;
    }
    v1alpha1_self_subject_review_status_local_var->user_info = user_info;

    return v1alpha1_self_subject_review_status_local_var;
}


void v1alpha1_self_subject_review_status_free(v1alpha1_self_subject_review_status_t *v1alpha1_self_subject_review_status) {
    if(NULL == v1alpha1_self_subject_review_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_self_subject_review_status->user_info) {
        v1_user_info_free(v1alpha1_self_subject_review_status->user_info);
        v1alpha1_self_subject_review_status->user_info = NULL;
    }
    free(v1alpha1_self_subject_review_status);
}

mazu_cJSON *v1alpha1_self_subject_review_status_convertToJSON(v1alpha1_self_subject_review_status_t *v1alpha1_self_subject_review_status) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_self_subject_review_status->user_info
    if(v1alpha1_self_subject_review_status->user_info) {
    mazu_cJSON *user_info_local_JSON = v1_user_info_convertToJSON(v1alpha1_self_subject_review_status->user_info);
    if(user_info_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "userInfo", user_info_local_JSON);
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

v1alpha1_self_subject_review_status_t *v1alpha1_self_subject_review_status_parseFromJSON(mazu_cJSON *v1alpha1_self_subject_review_statusJSON){

    v1alpha1_self_subject_review_status_t *v1alpha1_self_subject_review_status_local_var = NULL;

    // define the local variable for v1alpha1_self_subject_review_status->user_info
    v1_user_info_t *user_info_local_nonprim = NULL;

    // v1alpha1_self_subject_review_status->user_info
    mazu_cJSON *user_info = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_self_subject_review_statusJSON, "userInfo");
    if (user_info) { 
    user_info_local_nonprim = v1_user_info_parseFromJSON(user_info); //nonprimitive
    }


    v1alpha1_self_subject_review_status_local_var = v1alpha1_self_subject_review_status_create (
        user_info ? user_info_local_nonprim : NULL
        );

    return v1alpha1_self_subject_review_status_local_var;
end:
    if (user_info_local_nonprim) {
        v1_user_info_free(user_info_local_nonprim);
        user_info_local_nonprim = NULL;
    }
    return NULL;

}
