#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_match_condition.h"



v1_match_condition_t *v1_match_condition_create(
    char *expression,
    char *name
    ) {
    v1_match_condition_t *v1_match_condition_local_var = malloc(sizeof(v1_match_condition_t));
    if (!v1_match_condition_local_var) {
        return NULL;
    }
    v1_match_condition_local_var->expression = expression;
    v1_match_condition_local_var->name = name;

    return v1_match_condition_local_var;
}


void v1_match_condition_free(v1_match_condition_t *v1_match_condition) {
    if(NULL == v1_match_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_match_condition->expression) {
        free(v1_match_condition->expression);
        v1_match_condition->expression = NULL;
    }
    if (v1_match_condition->name) {
        free(v1_match_condition->name);
        v1_match_condition->name = NULL;
    }
    free(v1_match_condition);
}

mazu_cJSON *v1_match_condition_convertToJSON(v1_match_condition_t *v1_match_condition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_match_condition->expression
    if (!v1_match_condition->expression) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "expression", v1_match_condition->expression) == NULL) {
    goto fail; //String
    }


    // v1_match_condition->name
    if (!v1_match_condition->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_match_condition->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_match_condition_t *v1_match_condition_parseFromJSON(mazu_cJSON *v1_match_conditionJSON){

    v1_match_condition_t *v1_match_condition_local_var = NULL;

    // v1_match_condition->expression
    mazu_cJSON *expression = mazu_cJSON_GetObjectItemCaseSensitive(v1_match_conditionJSON, "expression");
    if (!expression) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1_match_condition->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_match_conditionJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_match_condition_local_var = v1_match_condition_create (
        strdup(expression->valuestring),
        strdup(name->valuestring)
        );

    return v1_match_condition_local_var;
end:
    return NULL;

}
