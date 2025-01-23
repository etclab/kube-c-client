#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_self_subject_rules_review_spec.h"



v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_create(
    char *_namespace
    ) {
    v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_local_var = malloc(sizeof(v1_self_subject_rules_review_spec_t));
    if (!v1_self_subject_rules_review_spec_local_var) {
        return NULL;
    }
    v1_self_subject_rules_review_spec_local_var->_namespace = _namespace;

    return v1_self_subject_rules_review_spec_local_var;
}


void v1_self_subject_rules_review_spec_free(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    if(NULL == v1_self_subject_rules_review_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_self_subject_rules_review_spec->_namespace) {
        free(v1_self_subject_rules_review_spec->_namespace);
        v1_self_subject_rules_review_spec->_namespace = NULL;
    }
    free(v1_self_subject_rules_review_spec);
}

mazu_cJSON *v1_self_subject_rules_review_spec_convertToJSON(v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_self_subject_rules_review_spec->_namespace
    if(v1_self_subject_rules_review_spec->_namespace) {
    if(mazu_cJSON_AddStringToObject(item, "namespace", v1_self_subject_rules_review_spec->_namespace) == NULL) {
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

v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_parseFromJSON(mazu_cJSON *v1_self_subject_rules_review_specJSON){

    v1_self_subject_rules_review_spec_t *v1_self_subject_rules_review_spec_local_var = NULL;

    // v1_self_subject_rules_review_spec->_namespace
    mazu_cJSON *_namespace = mazu_cJSON_GetObjectItemCaseSensitive(v1_self_subject_rules_review_specJSON, "namespace");
    if (_namespace) { 
    if(!mazu_cJSON_IsString(_namespace) && !mazu_cJSON_IsNull(_namespace))
    {
    goto end; //String
    }
    }


    v1_self_subject_rules_review_spec_local_var = v1_self_subject_rules_review_spec_create (
        _namespace && !mazu_cJSON_IsNull(_namespace) ? strdup(_namespace->valuestring) : NULL
        );

    return v1_self_subject_rules_review_spec_local_var;
end:
    return NULL;

}
