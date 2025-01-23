#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_audit_annotation.h"



v1beta1_audit_annotation_t *v1beta1_audit_annotation_create(
    char *key,
    char *value_expression
    ) {
    v1beta1_audit_annotation_t *v1beta1_audit_annotation_local_var = malloc(sizeof(v1beta1_audit_annotation_t));
    if (!v1beta1_audit_annotation_local_var) {
        return NULL;
    }
    v1beta1_audit_annotation_local_var->key = key;
    v1beta1_audit_annotation_local_var->value_expression = value_expression;

    return v1beta1_audit_annotation_local_var;
}


void v1beta1_audit_annotation_free(v1beta1_audit_annotation_t *v1beta1_audit_annotation) {
    if(NULL == v1beta1_audit_annotation){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_audit_annotation->key) {
        free(v1beta1_audit_annotation->key);
        v1beta1_audit_annotation->key = NULL;
    }
    if (v1beta1_audit_annotation->value_expression) {
        free(v1beta1_audit_annotation->value_expression);
        v1beta1_audit_annotation->value_expression = NULL;
    }
    free(v1beta1_audit_annotation);
}

mazu_cJSON *v1beta1_audit_annotation_convertToJSON(v1beta1_audit_annotation_t *v1beta1_audit_annotation) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta1_audit_annotation->key
    if (!v1beta1_audit_annotation->key) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "key", v1beta1_audit_annotation->key) == NULL) {
    goto fail; //String
    }


    // v1beta1_audit_annotation->value_expression
    if (!v1beta1_audit_annotation->value_expression) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "valueExpression", v1beta1_audit_annotation->value_expression) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_audit_annotation_t *v1beta1_audit_annotation_parseFromJSON(mazu_cJSON *v1beta1_audit_annotationJSON){

    v1beta1_audit_annotation_t *v1beta1_audit_annotation_local_var = NULL;

    // v1beta1_audit_annotation->key
    mazu_cJSON *key = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_audit_annotationJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1beta1_audit_annotation->value_expression
    mazu_cJSON *value_expression = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_audit_annotationJSON, "valueExpression");
    if (!value_expression) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(value_expression))
    {
    goto end; //String
    }


    v1beta1_audit_annotation_local_var = v1beta1_audit_annotation_create (
        strdup(key->valuestring),
        strdup(value_expression->valuestring)
        );

    return v1beta1_audit_annotation_local_var;
end:
    return NULL;

}
