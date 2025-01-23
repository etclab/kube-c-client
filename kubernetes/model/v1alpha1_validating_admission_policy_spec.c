#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_validating_admission_policy_spec.h"



v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_create(
    list_t *audit_annotations,
    char *failure_policy,
    list_t *match_conditions,
    v1alpha1_match_resources_t *match_constraints,
    v1alpha1_param_kind_t *param_kind,
    list_t *validations,
    list_t *variables
    ) {
    v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_local_var = malloc(sizeof(v1alpha1_validating_admission_policy_spec_t));
    if (!v1alpha1_validating_admission_policy_spec_local_var) {
        return NULL;
    }
    v1alpha1_validating_admission_policy_spec_local_var->audit_annotations = audit_annotations;
    v1alpha1_validating_admission_policy_spec_local_var->failure_policy = failure_policy;
    v1alpha1_validating_admission_policy_spec_local_var->match_conditions = match_conditions;
    v1alpha1_validating_admission_policy_spec_local_var->match_constraints = match_constraints;
    v1alpha1_validating_admission_policy_spec_local_var->param_kind = param_kind;
    v1alpha1_validating_admission_policy_spec_local_var->validations = validations;
    v1alpha1_validating_admission_policy_spec_local_var->variables = variables;

    return v1alpha1_validating_admission_policy_spec_local_var;
}


void v1alpha1_validating_admission_policy_spec_free(v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec) {
    if(NULL == v1alpha1_validating_admission_policy_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_validating_admission_policy_spec->audit_annotations) {
        list_ForEach(listEntry, v1alpha1_validating_admission_policy_spec->audit_annotations) {
            v1alpha1_audit_annotation_free(listEntry->data);
        }
        list_freeList(v1alpha1_validating_admission_policy_spec->audit_annotations);
        v1alpha1_validating_admission_policy_spec->audit_annotations = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->failure_policy) {
        free(v1alpha1_validating_admission_policy_spec->failure_policy);
        v1alpha1_validating_admission_policy_spec->failure_policy = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->match_conditions) {
        list_ForEach(listEntry, v1alpha1_validating_admission_policy_spec->match_conditions) {
            v1alpha1_match_condition_free(listEntry->data);
        }
        list_freeList(v1alpha1_validating_admission_policy_spec->match_conditions);
        v1alpha1_validating_admission_policy_spec->match_conditions = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->match_constraints) {
        v1alpha1_match_resources_free(v1alpha1_validating_admission_policy_spec->match_constraints);
        v1alpha1_validating_admission_policy_spec->match_constraints = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->param_kind) {
        v1alpha1_param_kind_free(v1alpha1_validating_admission_policy_spec->param_kind);
        v1alpha1_validating_admission_policy_spec->param_kind = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->validations) {
        list_ForEach(listEntry, v1alpha1_validating_admission_policy_spec->validations) {
            v1alpha1_validation_free(listEntry->data);
        }
        list_freeList(v1alpha1_validating_admission_policy_spec->validations);
        v1alpha1_validating_admission_policy_spec->validations = NULL;
    }
    if (v1alpha1_validating_admission_policy_spec->variables) {
        list_ForEach(listEntry, v1alpha1_validating_admission_policy_spec->variables) {
            v1alpha1_variable_free(listEntry->data);
        }
        list_freeList(v1alpha1_validating_admission_policy_spec->variables);
        v1alpha1_validating_admission_policy_spec->variables = NULL;
    }
    free(v1alpha1_validating_admission_policy_spec);
}

mazu_cJSON *v1alpha1_validating_admission_policy_spec_convertToJSON(v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha1_validating_admission_policy_spec->audit_annotations
    if(v1alpha1_validating_admission_policy_spec->audit_annotations) {
    mazu_cJSON *audit_annotations = mazu_cJSON_AddArrayToObject(item, "auditAnnotations");
    if(audit_annotations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *audit_annotationsListEntry;
    if (v1alpha1_validating_admission_policy_spec->audit_annotations) {
    list_ForEach(audit_annotationsListEntry, v1alpha1_validating_admission_policy_spec->audit_annotations) {
    mazu_cJSON *itemLocal = v1alpha1_audit_annotation_convertToJSON(audit_annotationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(audit_annotations, itemLocal);
    }
    }
    }


    // v1alpha1_validating_admission_policy_spec->failure_policy
    if(v1alpha1_validating_admission_policy_spec->failure_policy) {
    if(mazu_cJSON_AddStringToObject(item, "failurePolicy", v1alpha1_validating_admission_policy_spec->failure_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_validating_admission_policy_spec->match_conditions
    if(v1alpha1_validating_admission_policy_spec->match_conditions) {
    mazu_cJSON *match_conditions = mazu_cJSON_AddArrayToObject(item, "matchConditions");
    if(match_conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_conditionsListEntry;
    if (v1alpha1_validating_admission_policy_spec->match_conditions) {
    list_ForEach(match_conditionsListEntry, v1alpha1_validating_admission_policy_spec->match_conditions) {
    mazu_cJSON *itemLocal = v1alpha1_match_condition_convertToJSON(match_conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(match_conditions, itemLocal);
    }
    }
    }


    // v1alpha1_validating_admission_policy_spec->match_constraints
    if(v1alpha1_validating_admission_policy_spec->match_constraints) {
    mazu_cJSON *match_constraints_local_JSON = v1alpha1_match_resources_convertToJSON(v1alpha1_validating_admission_policy_spec->match_constraints);
    if(match_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "matchConstraints", match_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_validating_admission_policy_spec->param_kind
    if(v1alpha1_validating_admission_policy_spec->param_kind) {
    mazu_cJSON *param_kind_local_JSON = v1alpha1_param_kind_convertToJSON(v1alpha1_validating_admission_policy_spec->param_kind);
    if(param_kind_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "paramKind", param_kind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_validating_admission_policy_spec->validations
    if(v1alpha1_validating_admission_policy_spec->validations) {
    mazu_cJSON *validations = mazu_cJSON_AddArrayToObject(item, "validations");
    if(validations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *validationsListEntry;
    if (v1alpha1_validating_admission_policy_spec->validations) {
    list_ForEach(validationsListEntry, v1alpha1_validating_admission_policy_spec->validations) {
    mazu_cJSON *itemLocal = v1alpha1_validation_convertToJSON(validationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(validations, itemLocal);
    }
    }
    }


    // v1alpha1_validating_admission_policy_spec->variables
    if(v1alpha1_validating_admission_policy_spec->variables) {
    mazu_cJSON *variables = mazu_cJSON_AddArrayToObject(item, "variables");
    if(variables == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *variablesListEntry;
    if (v1alpha1_validating_admission_policy_spec->variables) {
    list_ForEach(variablesListEntry, v1alpha1_validating_admission_policy_spec->variables) {
    mazu_cJSON *itemLocal = v1alpha1_variable_convertToJSON(variablesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(variables, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_parseFromJSON(mazu_cJSON *v1alpha1_validating_admission_policy_specJSON){

    v1alpha1_validating_admission_policy_spec_t *v1alpha1_validating_admission_policy_spec_local_var = NULL;

    // define the local list for v1alpha1_validating_admission_policy_spec->audit_annotations
    list_t *audit_annotationsList = NULL;

    // define the local list for v1alpha1_validating_admission_policy_spec->match_conditions
    list_t *match_conditionsList = NULL;

    // define the local variable for v1alpha1_validating_admission_policy_spec->match_constraints
    v1alpha1_match_resources_t *match_constraints_local_nonprim = NULL;

    // define the local variable for v1alpha1_validating_admission_policy_spec->param_kind
    v1alpha1_param_kind_t *param_kind_local_nonprim = NULL;

    // define the local list for v1alpha1_validating_admission_policy_spec->validations
    list_t *validationsList = NULL;

    // define the local list for v1alpha1_validating_admission_policy_spec->variables
    list_t *variablesList = NULL;

    // v1alpha1_validating_admission_policy_spec->audit_annotations
    mazu_cJSON *audit_annotations = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "auditAnnotations");
    if (audit_annotations) { 
    mazu_cJSON *audit_annotations_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(audit_annotations)){
        goto end; //nonprimitive container
    }

    audit_annotationsList = list_createList();

    mazu_cJSON_ArrayForEach(audit_annotations_local_nonprimitive,audit_annotations )
    {
        if(!mazu_cJSON_IsObject(audit_annotations_local_nonprimitive)){
            goto end;
        }
        v1alpha1_audit_annotation_t *audit_annotationsItem = v1alpha1_audit_annotation_parseFromJSON(audit_annotations_local_nonprimitive);

        list_addElement(audit_annotationsList, audit_annotationsItem);
    }
    }

    // v1alpha1_validating_admission_policy_spec->failure_policy
    mazu_cJSON *failure_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "failurePolicy");
    if (failure_policy) { 
    if(!mazu_cJSON_IsString(failure_policy) && !mazu_cJSON_IsNull(failure_policy))
    {
    goto end; //String
    }
    }

    // v1alpha1_validating_admission_policy_spec->match_conditions
    mazu_cJSON *match_conditions = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "matchConditions");
    if (match_conditions) { 
    mazu_cJSON *match_conditions_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(match_conditions)){
        goto end; //nonprimitive container
    }

    match_conditionsList = list_createList();

    mazu_cJSON_ArrayForEach(match_conditions_local_nonprimitive,match_conditions )
    {
        if(!mazu_cJSON_IsObject(match_conditions_local_nonprimitive)){
            goto end;
        }
        v1alpha1_match_condition_t *match_conditionsItem = v1alpha1_match_condition_parseFromJSON(match_conditions_local_nonprimitive);

        list_addElement(match_conditionsList, match_conditionsItem);
    }
    }

    // v1alpha1_validating_admission_policy_spec->match_constraints
    mazu_cJSON *match_constraints = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "matchConstraints");
    if (match_constraints) { 
    match_constraints_local_nonprim = v1alpha1_match_resources_parseFromJSON(match_constraints); //nonprimitive
    }

    // v1alpha1_validating_admission_policy_spec->param_kind
    mazu_cJSON *param_kind = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "paramKind");
    if (param_kind) { 
    param_kind_local_nonprim = v1alpha1_param_kind_parseFromJSON(param_kind); //nonprimitive
    }

    // v1alpha1_validating_admission_policy_spec->validations
    mazu_cJSON *validations = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "validations");
    if (validations) { 
    mazu_cJSON *validations_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(validations)){
        goto end; //nonprimitive container
    }

    validationsList = list_createList();

    mazu_cJSON_ArrayForEach(validations_local_nonprimitive,validations )
    {
        if(!mazu_cJSON_IsObject(validations_local_nonprimitive)){
            goto end;
        }
        v1alpha1_validation_t *validationsItem = v1alpha1_validation_parseFromJSON(validations_local_nonprimitive);

        list_addElement(validationsList, validationsItem);
    }
    }

    // v1alpha1_validating_admission_policy_spec->variables
    mazu_cJSON *variables = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha1_validating_admission_policy_specJSON, "variables");
    if (variables) { 
    mazu_cJSON *variables_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(variables)){
        goto end; //nonprimitive container
    }

    variablesList = list_createList();

    mazu_cJSON_ArrayForEach(variables_local_nonprimitive,variables )
    {
        if(!mazu_cJSON_IsObject(variables_local_nonprimitive)){
            goto end;
        }
        v1alpha1_variable_t *variablesItem = v1alpha1_variable_parseFromJSON(variables_local_nonprimitive);

        list_addElement(variablesList, variablesItem);
    }
    }


    v1alpha1_validating_admission_policy_spec_local_var = v1alpha1_validating_admission_policy_spec_create (
        audit_annotations ? audit_annotationsList : NULL,
        failure_policy && !mazu_cJSON_IsNull(failure_policy) ? strdup(failure_policy->valuestring) : NULL,
        match_conditions ? match_conditionsList : NULL,
        match_constraints ? match_constraints_local_nonprim : NULL,
        param_kind ? param_kind_local_nonprim : NULL,
        validations ? validationsList : NULL,
        variables ? variablesList : NULL
        );

    return v1alpha1_validating_admission_policy_spec_local_var;
end:
    if (audit_annotationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, audit_annotationsList) {
            v1alpha1_audit_annotation_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(audit_annotationsList);
        audit_annotationsList = NULL;
    }
    if (match_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_conditionsList) {
            v1alpha1_match_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_conditionsList);
        match_conditionsList = NULL;
    }
    if (match_constraints_local_nonprim) {
        v1alpha1_match_resources_free(match_constraints_local_nonprim);
        match_constraints_local_nonprim = NULL;
    }
    if (param_kind_local_nonprim) {
        v1alpha1_param_kind_free(param_kind_local_nonprim);
        param_kind_local_nonprim = NULL;
    }
    if (validationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, validationsList) {
            v1alpha1_validation_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(validationsList);
        validationsList = NULL;
    }
    if (variablesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, variablesList) {
            v1alpha1_variable_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(variablesList);
        variablesList = NULL;
    }
    return NULL;

}
