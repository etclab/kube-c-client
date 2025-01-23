#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_failure_policy_on_exit_codes_requirement.h"



v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_create(
    char *container_name,
    char *_operator,
    list_t *values
    ) {
    v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_local_var = malloc(sizeof(v1_pod_failure_policy_on_exit_codes_requirement_t));
    if (!v1_pod_failure_policy_on_exit_codes_requirement_local_var) {
        return NULL;
    }
    v1_pod_failure_policy_on_exit_codes_requirement_local_var->container_name = container_name;
    v1_pod_failure_policy_on_exit_codes_requirement_local_var->_operator = _operator;
    v1_pod_failure_policy_on_exit_codes_requirement_local_var->values = values;

    return v1_pod_failure_policy_on_exit_codes_requirement_local_var;
}


void v1_pod_failure_policy_on_exit_codes_requirement_free(v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement) {
    if(NULL == v1_pod_failure_policy_on_exit_codes_requirement){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_failure_policy_on_exit_codes_requirement->container_name) {
        free(v1_pod_failure_policy_on_exit_codes_requirement->container_name);
        v1_pod_failure_policy_on_exit_codes_requirement->container_name = NULL;
    }
    if (v1_pod_failure_policy_on_exit_codes_requirement->_operator) {
        free(v1_pod_failure_policy_on_exit_codes_requirement->_operator);
        v1_pod_failure_policy_on_exit_codes_requirement->_operator = NULL;
    }
    if (v1_pod_failure_policy_on_exit_codes_requirement->values) {
        list_ForEach(listEntry, v1_pod_failure_policy_on_exit_codes_requirement->values) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_failure_policy_on_exit_codes_requirement->values);
        v1_pod_failure_policy_on_exit_codes_requirement->values = NULL;
    }
    free(v1_pod_failure_policy_on_exit_codes_requirement);
}

mazu_cJSON *v1_pod_failure_policy_on_exit_codes_requirement_convertToJSON(v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_failure_policy_on_exit_codes_requirement->container_name
    if(v1_pod_failure_policy_on_exit_codes_requirement->container_name) {
    if(mazu_cJSON_AddStringToObject(item, "containerName", v1_pod_failure_policy_on_exit_codes_requirement->container_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_failure_policy_on_exit_codes_requirement->_operator
    if (!v1_pod_failure_policy_on_exit_codes_requirement->_operator) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "operator", v1_pod_failure_policy_on_exit_codes_requirement->_operator) == NULL) {
    goto fail; //String
    }


    // v1_pod_failure_policy_on_exit_codes_requirement->values
    if (!v1_pod_failure_policy_on_exit_codes_requirement->values) {
        goto fail;
    }
    mazu_cJSON *values = mazu_cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_pod_failure_policy_on_exit_codes_requirement->values) {
    if(mazu_cJSON_AddNumberToObject(values, "", *(double *)valuesListEntry->data) == NULL)
    {
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

v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_parseFromJSON(mazu_cJSON *v1_pod_failure_policy_on_exit_codes_requirementJSON){

    v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_local_var = NULL;

    // define the local list for v1_pod_failure_policy_on_exit_codes_requirement->values
    list_t *valuesList = NULL;

    // v1_pod_failure_policy_on_exit_codes_requirement->container_name
    mazu_cJSON *container_name = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_exit_codes_requirementJSON, "containerName");
    if (container_name) { 
    if(!mazu_cJSON_IsString(container_name) && !mazu_cJSON_IsNull(container_name))
    {
    goto end; //String
    }
    }

    // v1_pod_failure_policy_on_exit_codes_requirement->_operator
    mazu_cJSON *_operator = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_exit_codes_requirementJSON, "operator");
    if (!_operator) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(_operator))
    {
    goto end; //String
    }

    // v1_pod_failure_policy_on_exit_codes_requirement->values
    mazu_cJSON *values = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_exit_codes_requirementJSON, "values");
    if (!values) {
        goto end;
    }

    
    mazu_cJSON *values_local = NULL;
    if(!mazu_cJSON_IsArray(values)) {
        goto end;//primitive container
    }
    valuesList = list_createList();

    mazu_cJSON_ArrayForEach(values_local, values)
    {
        if(!mazu_cJSON_IsNumber(values_local))
        {
            goto end;
        }
        double *values_local_value = (double *)calloc(1, sizeof(double));
        if(!values_local_value)
        {
            goto end;
        }
        *values_local_value = values_local->valuedouble;
        list_addElement(valuesList , values_local_value);
    }


    v1_pod_failure_policy_on_exit_codes_requirement_local_var = v1_pod_failure_policy_on_exit_codes_requirement_create (
        container_name && !mazu_cJSON_IsNull(container_name) ? strdup(container_name->valuestring) : NULL,
        strdup(_operator->valuestring),
        valuesList
        );

    return v1_pod_failure_policy_on_exit_codes_requirement_local_var;
end:
    if (valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valuesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valuesList);
        valuesList = NULL;
    }
    return NULL;

}
