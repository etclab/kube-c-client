#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_validation.h"



v1alpha1_validation_t *v1alpha1_validation_create(
    char *expression,
    char *message,
    char *message_expression,
    char *reason
    ) {
    v1alpha1_validation_t *v1alpha1_validation_local_var = malloc(sizeof(v1alpha1_validation_t));
    if (!v1alpha1_validation_local_var) {
        return NULL;
    }
    v1alpha1_validation_local_var->expression = expression;
    v1alpha1_validation_local_var->message = message;
    v1alpha1_validation_local_var->message_expression = message_expression;
    v1alpha1_validation_local_var->reason = reason;

    return v1alpha1_validation_local_var;
}


void v1alpha1_validation_free(v1alpha1_validation_t *v1alpha1_validation) {
    if(NULL == v1alpha1_validation){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_validation->expression) {
        free(v1alpha1_validation->expression);
        v1alpha1_validation->expression = NULL;
    }
    if (v1alpha1_validation->message) {
        free(v1alpha1_validation->message);
        v1alpha1_validation->message = NULL;
    }
    if (v1alpha1_validation->message_expression) {
        free(v1alpha1_validation->message_expression);
        v1alpha1_validation->message_expression = NULL;
    }
    if (v1alpha1_validation->reason) {
        free(v1alpha1_validation->reason);
        v1alpha1_validation->reason = NULL;
    }
    free(v1alpha1_validation);
}

mazu_cJSON *v1alpha1_validation_convertToJSON(v1alpha1_validation_t *v1alpha1_validation) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_validation->expression
    if (!v1alpha1_validation->expression) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "expression", v1alpha1_validation->expression) == NULL) {
    goto fail; //String
    }


    // v1alpha1_validation->message
    if(v1alpha1_validation->message) {
    if(mazu_cJSON_AddStringToObject(item, "message", v1alpha1_validation->message) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_validation->message_expression
    if(v1alpha1_validation->message_expression) {
    if(mazu_cJSON_AddStringToObject(item, "messageExpression", v1alpha1_validation->message_expression) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_validation->reason
    if(v1alpha1_validation->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", v1alpha1_validation->reason) == NULL) {
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

v1alpha1_validation_t *v1alpha1_validation_parseFromJSON(mazu_cJSON *v1alpha1_validationJSON){

    v1alpha1_validation_t *v1alpha1_validation_local_var = NULL;

    // v1alpha1_validation->expression
    mazu_cJSON *expression = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validationJSON, "expression");
    if (!expression) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1alpha1_validation->message
    mazu_cJSON *message = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validationJSON, "message");
    if (message) { 
    if(!mazu_cJSON_IsString(message) && !mazu_cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1alpha1_validation->message_expression
    mazu_cJSON *message_expression = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validationJSON, "messageExpression");
    if (message_expression) { 
    if(!mazu_cJSON_IsString(message_expression) && !mazu_cJSON_IsNull(message_expression))
    {
    goto end; //String
    }
    }

    // v1alpha1_validation->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validationJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    v1alpha1_validation_local_var = v1alpha1_validation_create (
        strdup(expression->valuestring),
        message && !mazu_cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        message_expression && !mazu_cJSON_IsNull(message_expression) ? strdup(message_expression->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL
        );

    return v1alpha1_validation_local_var;
end:
    return NULL;

}
