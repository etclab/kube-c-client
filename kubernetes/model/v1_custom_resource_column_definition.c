#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_column_definition.h"



v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_create(
    char *description,
    char *format,
    char *json_path,
    char *name,
    int priority,
    char *type
    ) {
    v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_local_var = malloc(sizeof(v1_custom_resource_column_definition_t));
    if (!v1_custom_resource_column_definition_local_var) {
        return NULL;
    }
    v1_custom_resource_column_definition_local_var->description = description;
    v1_custom_resource_column_definition_local_var->format = format;
    v1_custom_resource_column_definition_local_var->json_path = json_path;
    v1_custom_resource_column_definition_local_var->name = name;
    v1_custom_resource_column_definition_local_var->priority = priority;
    v1_custom_resource_column_definition_local_var->type = type;

    return v1_custom_resource_column_definition_local_var;
}


void v1_custom_resource_column_definition_free(v1_custom_resource_column_definition_t *v1_custom_resource_column_definition) {
    if(NULL == v1_custom_resource_column_definition){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_column_definition->description) {
        free(v1_custom_resource_column_definition->description);
        v1_custom_resource_column_definition->description = NULL;
    }
    if (v1_custom_resource_column_definition->format) {
        free(v1_custom_resource_column_definition->format);
        v1_custom_resource_column_definition->format = NULL;
    }
    if (v1_custom_resource_column_definition->json_path) {
        free(v1_custom_resource_column_definition->json_path);
        v1_custom_resource_column_definition->json_path = NULL;
    }
    if (v1_custom_resource_column_definition->name) {
        free(v1_custom_resource_column_definition->name);
        v1_custom_resource_column_definition->name = NULL;
    }
    if (v1_custom_resource_column_definition->type) {
        free(v1_custom_resource_column_definition->type);
        v1_custom_resource_column_definition->type = NULL;
    }
    free(v1_custom_resource_column_definition);
}

mazu_cJSON *v1_custom_resource_column_definition_convertToJSON(v1_custom_resource_column_definition_t *v1_custom_resource_column_definition) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_custom_resource_column_definition->description
    if(v1_custom_resource_column_definition->description) {
    if(mazu_cJSON_AddStringToObject(item, "description", v1_custom_resource_column_definition->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_column_definition->format
    if(v1_custom_resource_column_definition->format) {
    if(mazu_cJSON_AddStringToObject(item, "format", v1_custom_resource_column_definition->format) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_column_definition->json_path
    if (!v1_custom_resource_column_definition->json_path) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "jsonPath", v1_custom_resource_column_definition->json_path) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_column_definition->name
    if (!v1_custom_resource_column_definition->name) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "name", v1_custom_resource_column_definition->name) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_column_definition->priority
    if(v1_custom_resource_column_definition->priority) {
    if(mazu_cJSON_AddNumberToObject(item, "priority", v1_custom_resource_column_definition->priority) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_custom_resource_column_definition->type
    if (!v1_custom_resource_column_definition->type) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "type", v1_custom_resource_column_definition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_parseFromJSON(mazu_cJSON *v1_custom_resource_column_definitionJSON){

    v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_local_var = NULL;

    // v1_custom_resource_column_definition->description
    mazu_cJSON *description = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "description");
    if (description) { 
    if(!mazu_cJSON_IsString(description) && !mazu_cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_column_definition->format
    mazu_cJSON *format = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "format");
    if (format) { 
    if(!mazu_cJSON_IsString(format) && !mazu_cJSON_IsNull(format))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_column_definition->json_path
    mazu_cJSON *json_path = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "jsonPath");
    if (!json_path) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(json_path))
    {
    goto end; //String
    }

    // v1_custom_resource_column_definition->name
    mazu_cJSON *name = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_custom_resource_column_definition->priority
    mazu_cJSON *priority = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "priority");
    if (priority) { 
    if(!mazu_cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    }

    // v1_custom_resource_column_definition->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(v1_custom_resource_column_definitionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_custom_resource_column_definition_local_var = v1_custom_resource_column_definition_create (
        description && !mazu_cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        format && !mazu_cJSON_IsNull(format) ? strdup(format->valuestring) : NULL,
        strdup(json_path->valuestring),
        strdup(name->valuestring),
        priority ? priority->valuedouble : 0,
        strdup(type->valuestring)
        );

    return v1_custom_resource_column_definition_local_var;
end:
    return NULL;

}
