#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_cel_device_selector.h"



v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector_create(
    char *expression
    ) {
    v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector_local_var = malloc(sizeof(v1alpha3_cel_device_selector_t));
    if (!v1alpha3_cel_device_selector_local_var) {
        return NULL;
    }
    v1alpha3_cel_device_selector_local_var->expression = expression;

    return v1alpha3_cel_device_selector_local_var;
}


void v1alpha3_cel_device_selector_free(v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector) {
    if(NULL == v1alpha3_cel_device_selector){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_cel_device_selector->expression) {
        free(v1alpha3_cel_device_selector->expression);
        v1alpha3_cel_device_selector->expression = NULL;
    }
    free(v1alpha3_cel_device_selector);
}

mazu_cJSON *v1alpha3_cel_device_selector_convertToJSON(v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha3_cel_device_selector->expression
    if (!v1alpha3_cel_device_selector->expression) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "expression", v1alpha3_cel_device_selector->expression) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector_parseFromJSON(mazu_cJSON *v1alpha3_cel_device_selectorJSON){

    v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector_local_var = NULL;

    // v1alpha3_cel_device_selector->expression
    mazu_cJSON *expression = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_cel_device_selectorJSON, "expression");
    if (!expression) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(expression))
    {
    goto end; //String
    }


    v1alpha3_cel_device_selector_local_var = v1alpha3_cel_device_selector_create (
        strdup(expression->valuestring)
        );

    return v1alpha3_cel_device_selector_local_var;
end:
    return NULL;

}
