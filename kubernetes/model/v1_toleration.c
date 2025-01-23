#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_toleration.h"



v1_toleration_t *v1_toleration_create(
    char *effect,
    char *key,
    char *_operator,
    long toleration_seconds,
    char *value
    ) {
    v1_toleration_t *v1_toleration_local_var = malloc(sizeof(v1_toleration_t));
    if (!v1_toleration_local_var) {
        return NULL;
    }
    v1_toleration_local_var->effect = effect;
    v1_toleration_local_var->key = key;
    v1_toleration_local_var->_operator = _operator;
    v1_toleration_local_var->toleration_seconds = toleration_seconds;
    v1_toleration_local_var->value = value;

    return v1_toleration_local_var;
}


void v1_toleration_free(v1_toleration_t *v1_toleration) {
    if(NULL == v1_toleration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_toleration->effect) {
        free(v1_toleration->effect);
        v1_toleration->effect = NULL;
    }
    if (v1_toleration->key) {
        free(v1_toleration->key);
        v1_toleration->key = NULL;
    }
    if (v1_toleration->_operator) {
        free(v1_toleration->_operator);
        v1_toleration->_operator = NULL;
    }
    if (v1_toleration->value) {
        free(v1_toleration->value);
        v1_toleration->value = NULL;
    }
    free(v1_toleration);
}

mazu_cJSON *v1_toleration_convertToJSON(v1_toleration_t *v1_toleration) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_toleration->effect
    if(v1_toleration->effect) {
    if(mazu_cJSON_AddStringToObject(item, "effect", v1_toleration->effect) == NULL) {
    goto fail; //String
    }
    }


    // v1_toleration->key
    if(v1_toleration->key) {
    if(mazu_cJSON_AddStringToObject(item, "key", v1_toleration->key) == NULL) {
    goto fail; //String
    }
    }


    // v1_toleration->_operator
    if(v1_toleration->_operator) {
    if(mazu_cJSON_AddStringToObject(item, "operator", v1_toleration->_operator) == NULL) {
    goto fail; //String
    }
    }


    // v1_toleration->toleration_seconds
    if(v1_toleration->toleration_seconds) {
    if(mazu_cJSON_AddNumberToObject(item, "tolerationSeconds", v1_toleration->toleration_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_toleration->value
    if(v1_toleration->value) {
    if(mazu_cJSON_AddStringToObject(item, "value", v1_toleration->value) == NULL) {
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

v1_toleration_t *v1_toleration_parseFromJSON(mazu_cJSON *v1_tolerationJSON){

    v1_toleration_t *v1_toleration_local_var = NULL;

    // v1_toleration->effect
    mazu_cJSON *effect = mazu_cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "effect");
    if (effect) { 
    if(!mazu_cJSON_IsString(effect) && !mazu_cJSON_IsNull(effect))
    {
    goto end; //String
    }
    }

    // v1_toleration->key
    mazu_cJSON *key = mazu_cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "key");
    if (key) { 
    if(!mazu_cJSON_IsString(key) && !mazu_cJSON_IsNull(key))
    {
    goto end; //String
    }
    }

    // v1_toleration->_operator
    mazu_cJSON *_operator = mazu_cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "operator");
    if (_operator) { 
    if(!mazu_cJSON_IsString(_operator) && !mazu_cJSON_IsNull(_operator))
    {
    goto end; //String
    }
    }

    // v1_toleration->toleration_seconds
    mazu_cJSON *toleration_seconds = mazu_cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "tolerationSeconds");
    if (toleration_seconds) { 
    if(!mazu_cJSON_IsNumber(toleration_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_toleration->value
    mazu_cJSON *value = mazu_cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "value");
    if (value) { 
    if(!mazu_cJSON_IsString(value) && !mazu_cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    v1_toleration_local_var = v1_toleration_create (
        effect && !mazu_cJSON_IsNull(effect) ? strdup(effect->valuestring) : NULL,
        key && !mazu_cJSON_IsNull(key) ? strdup(key->valuestring) : NULL,
        _operator && !mazu_cJSON_IsNull(_operator) ? strdup(_operator->valuestring) : NULL,
        toleration_seconds ? toleration_seconds->valuedouble : 0,
        value && !mazu_cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return v1_toleration_local_var;
end:
    return NULL;

}
