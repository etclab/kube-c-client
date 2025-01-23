#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_match_condition.h"



v1beta1_match_condition_t *v1beta1_match_condition_create(
    char *expression,
    char *name
    ) {
    v1beta1_match_condition_t *v1beta1_match_condition_local_var = malloc(sizeof(v1beta1_match_condition_t));
    if (!v1beta1_match_condition_local_var) {
        return NULL;
    }
    v1beta1_match_condition_local_var->expression = expression;
    v1beta1_match_condition_local_var->name = name;

    return v1beta1_match_condition_local_var;
}


void v1beta1_match_condition_free(v1beta1_match_condition_t *v1beta1_match_condition) {
    if(NULL == v1beta1_match_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_match_condition->expression) {
        free(v1beta1_match_condition->expression);
        v1beta1_match_condition->expression = NULL;
    }
    if (v1beta1_match_condition->name) {
        free(v1beta1_match_condition->name);
        v1beta1_match_condition->name = NULL;
    }
    free(v1beta1_match_condition);
}

mazu_cJSON *v1beta1_match_condition_convertToJSON(v1beta1_match_condition_t *v1beta1_match_condition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1beta1_match_condition->expression
    if (!v1beta1_match_condition->expression) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "expression", v1beta1_match_condition->expression) == NULL) {
    goto fail; //String
    }


    // v1beta1_match_condition->name
    if (!v1beta1_match_condition->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1beta1_match_condition->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_match_condition_t *v1beta1_match_condition_parseFromJSON(mazu_cJSON *v1beta1_match_conditionJSON){

    v1beta1_match_condition_t *v1beta1_match_condition_local_var = NULL;

    // v1beta1_match_condition->expression
    mazu_cJSON *expression = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_match_conditionJSON, "expression");
    if (!expression) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1beta1_match_condition->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1beta1_match_conditionJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }


    v1beta1_match_condition_local_var = v1beta1_match_condition_create (
        strdup(expression->valuestring),
        strdup(name->valuestring)
        );

    return v1beta1_match_condition_local_var;
end:
    return NULL;

}
