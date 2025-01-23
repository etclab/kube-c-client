#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "events_v1_event.h"



events_v1_event_t *events_v1_event_create(
    char *action,
    char *api_version,
    int deprecated_count,
    char *deprecated_first_timestamp,
    char *deprecated_last_timestamp,
    v1_event_source_t *deprecated_source,
    char *event_time,
    char *kind,
    v1_object_meta_t *metadata,
    char *note,
    char *reason,
    v1_object_reference_t *regarding,
    v1_object_reference_t *related,
    char *reporting_controller,
    char *reporting_instance,
    events_v1_event_series_t *series,
    char *type
    ) {
    events_v1_event_t *events_v1_event_local_var = malloc(sizeof(events_v1_event_t));
    if (!events_v1_event_local_var) {
        return NULL;
    }
    events_v1_event_local_var->action = action;
    events_v1_event_local_var->api_version = api_version;
    events_v1_event_local_var->deprecated_count = deprecated_count;
    events_v1_event_local_var->deprecated_first_timestamp = deprecated_first_timestamp;
    events_v1_event_local_var->deprecated_last_timestamp = deprecated_last_timestamp;
    events_v1_event_local_var->deprecated_source = deprecated_source;
    events_v1_event_local_var->event_time = event_time;
    events_v1_event_local_var->kind = kind;
    events_v1_event_local_var->metadata = metadata;
    events_v1_event_local_var->note = note;
    events_v1_event_local_var->reason = reason;
    events_v1_event_local_var->regarding = regarding;
    events_v1_event_local_var->related = related;
    events_v1_event_local_var->reporting_controller = reporting_controller;
    events_v1_event_local_var->reporting_instance = reporting_instance;
    events_v1_event_local_var->series = series;
    events_v1_event_local_var->type = type;

    return events_v1_event_local_var;
}


void events_v1_event_free(events_v1_event_t *events_v1_event) {
    if(NULL == events_v1_event){
        return ;
    }
    listEntry_t *listEntry;
    if (events_v1_event->action) {
        free(events_v1_event->action);
        events_v1_event->action = NULL;
    }
    if (events_v1_event->api_version) {
        free(events_v1_event->api_version);
        events_v1_event->api_version = NULL;
    }
    if (events_v1_event->deprecated_first_timestamp) {
        free(events_v1_event->deprecated_first_timestamp);
        events_v1_event->deprecated_first_timestamp = NULL;
    }
    if (events_v1_event->deprecated_last_timestamp) {
        free(events_v1_event->deprecated_last_timestamp);
        events_v1_event->deprecated_last_timestamp = NULL;
    }
    if (events_v1_event->deprecated_source) {
        v1_event_source_free(events_v1_event->deprecated_source);
        events_v1_event->deprecated_source = NULL;
    }
    if (events_v1_event->event_time) {
        free(events_v1_event->event_time);
        events_v1_event->event_time = NULL;
    }
    if (events_v1_event->kind) {
        free(events_v1_event->kind);
        events_v1_event->kind = NULL;
    }
    if (events_v1_event->metadata) {
        v1_object_meta_free(events_v1_event->metadata);
        events_v1_event->metadata = NULL;
    }
    if (events_v1_event->note) {
        free(events_v1_event->note);
        events_v1_event->note = NULL;
    }
    if (events_v1_event->reason) {
        free(events_v1_event->reason);
        events_v1_event->reason = NULL;
    }
    if (events_v1_event->regarding) {
        v1_object_reference_free(events_v1_event->regarding);
        events_v1_event->regarding = NULL;
    }
    if (events_v1_event->related) {
        v1_object_reference_free(events_v1_event->related);
        events_v1_event->related = NULL;
    }
    if (events_v1_event->reporting_controller) {
        free(events_v1_event->reporting_controller);
        events_v1_event->reporting_controller = NULL;
    }
    if (events_v1_event->reporting_instance) {
        free(events_v1_event->reporting_instance);
        events_v1_event->reporting_instance = NULL;
    }
    if (events_v1_event->series) {
        events_v1_event_series_free(events_v1_event->series);
        events_v1_event->series = NULL;
    }
    if (events_v1_event->type) {
        free(events_v1_event->type);
        events_v1_event->type = NULL;
    }
    free(events_v1_event);
}

mazu_cJSON *events_v1_event_convertToJSON(events_v1_event_t *events_v1_event) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // events_v1_event->action
    if(events_v1_event->action) {
    if(mazu_cJSON_AddStringToObject(item, "action", events_v1_event->action) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->api_version
    if(events_v1_event->api_version) {
    if(mazu_cJSON_AddStringToObject(item, "apiVersion", events_v1_event->api_version) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->deprecated_count
    if(events_v1_event->deprecated_count) {
    if(mazu_cJSON_AddNumberToObject(item, "deprecatedCount", events_v1_event->deprecated_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // events_v1_event->deprecated_first_timestamp
    if(events_v1_event->deprecated_first_timestamp) {
    if(mazu_cJSON_AddStringToObject(item, "deprecatedFirstTimestamp", events_v1_event->deprecated_first_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // events_v1_event->deprecated_last_timestamp
    if(events_v1_event->deprecated_last_timestamp) {
    if(mazu_cJSON_AddStringToObject(item, "deprecatedLastTimestamp", events_v1_event->deprecated_last_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // events_v1_event->deprecated_source
    if(events_v1_event->deprecated_source) {
    mazu_cJSON *deprecated_source_local_JSON = v1_event_source_convertToJSON(events_v1_event->deprecated_source);
    if(deprecated_source_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "deprecatedSource", deprecated_source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // events_v1_event->event_time
    if (!events_v1_event->event_time) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "eventTime", events_v1_event->event_time) == NULL) {
    goto fail; //Date-Time
    }


    // events_v1_event->kind
    if(events_v1_event->kind) {
    if(mazu_cJSON_AddStringToObject(item, "kind", events_v1_event->kind) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->metadata
    if(events_v1_event->metadata) {
    mazu_cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(events_v1_event->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // events_v1_event->note
    if(events_v1_event->note) {
    if(mazu_cJSON_AddStringToObject(item, "note", events_v1_event->note) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->reason
    if(events_v1_event->reason) {
    if(mazu_cJSON_AddStringToObject(item, "reason", events_v1_event->reason) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->regarding
    if(events_v1_event->regarding) {
    mazu_cJSON *regarding_local_JSON = v1_object_reference_convertToJSON(events_v1_event->regarding);
    if(regarding_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "regarding", regarding_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // events_v1_event->related
    if(events_v1_event->related) {
    mazu_cJSON *related_local_JSON = v1_object_reference_convertToJSON(events_v1_event->related);
    if(related_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "related", related_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // events_v1_event->reporting_controller
    if(events_v1_event->reporting_controller) {
    if(mazu_cJSON_AddStringToObject(item, "reportingController", events_v1_event->reporting_controller) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->reporting_instance
    if(events_v1_event->reporting_instance) {
    if(mazu_cJSON_AddStringToObject(item, "reportingInstance", events_v1_event->reporting_instance) == NULL) {
    goto fail; //String
    }
    }


    // events_v1_event->series
    if(events_v1_event->series) {
    mazu_cJSON *series_local_JSON = events_v1_event_series_convertToJSON(events_v1_event->series);
    if(series_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "series", series_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // events_v1_event->type
    if(events_v1_event->type) {
    if(mazu_cJSON_AddStringToObject(item, "type", events_v1_event->type) == NULL) {
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

events_v1_event_t *events_v1_event_parseFromJSON(mazu_cJSON *events_v1_eventJSON){

    events_v1_event_t *events_v1_event_local_var = NULL;

    // define the local variable for events_v1_event->deprecated_source
    v1_event_source_t *deprecated_source_local_nonprim = NULL;

    // define the local variable for events_v1_event->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for events_v1_event->regarding
    v1_object_reference_t *regarding_local_nonprim = NULL;

    // define the local variable for events_v1_event->related
    v1_object_reference_t *related_local_nonprim = NULL;

    // define the local variable for events_v1_event->series
    events_v1_event_series_t *series_local_nonprim = NULL;

    // events_v1_event->action
    mazu_cJSON *action = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "action");
    if (action) { 
    if(!mazu_cJSON_IsString(action) && !mazu_cJSON_IsNull(action))
    {
    goto end; //String
    }
    }

    // events_v1_event->api_version
    mazu_cJSON *api_version = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "apiVersion");
    if (api_version) { 
    if(!mazu_cJSON_IsString(api_version) && !mazu_cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // events_v1_event->deprecated_count
    mazu_cJSON *deprecated_count = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "deprecatedCount");
    if (deprecated_count) { 
    if(!mazu_cJSON_IsNumber(deprecated_count))
    {
    goto end; //Numeric
    }
    }

    // events_v1_event->deprecated_first_timestamp
    mazu_cJSON *deprecated_first_timestamp = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "deprecatedFirstTimestamp");
    if (deprecated_first_timestamp) { 
    if(!mazu_cJSON_IsString(deprecated_first_timestamp) && !mazu_cJSON_IsNull(deprecated_first_timestamp))
    {
    goto end; //DateTime
    }
    }

    // events_v1_event->deprecated_last_timestamp
    mazu_cJSON *deprecated_last_timestamp = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "deprecatedLastTimestamp");
    if (deprecated_last_timestamp) { 
    if(!mazu_cJSON_IsString(deprecated_last_timestamp) && !mazu_cJSON_IsNull(deprecated_last_timestamp))
    {
    goto end; //DateTime
    }
    }

    // events_v1_event->deprecated_source
    mazu_cJSON *deprecated_source = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "deprecatedSource");
    if (deprecated_source) { 
    deprecated_source_local_nonprim = v1_event_source_parseFromJSON(deprecated_source); //nonprimitive
    }

    // events_v1_event->event_time
    mazu_cJSON *event_time = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "eventTime");
    if (!event_time) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(event_time) && !mazu_cJSON_IsNull(event_time))
    {
    goto end; //DateTime
    }

    // events_v1_event->kind
    mazu_cJSON *kind = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "kind");
    if (kind) { 
    if(!mazu_cJSON_IsString(kind) && !mazu_cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // events_v1_event->metadata
    mazu_cJSON *metadata = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // events_v1_event->note
    mazu_cJSON *note = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "note");
    if (note) { 
    if(!mazu_cJSON_IsString(note) && !mazu_cJSON_IsNull(note))
    {
    goto end; //String
    }
    }

    // events_v1_event->reason
    mazu_cJSON *reason = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "reason");
    if (reason) { 
    if(!mazu_cJSON_IsString(reason) && !mazu_cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // events_v1_event->regarding
    mazu_cJSON *regarding = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "regarding");
    if (regarding) { 
    regarding_local_nonprim = v1_object_reference_parseFromJSON(regarding); //nonprimitive
    }

    // events_v1_event->related
    mazu_cJSON *related = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "related");
    if (related) { 
    related_local_nonprim = v1_object_reference_parseFromJSON(related); //nonprimitive
    }

    // events_v1_event->reporting_controller
    mazu_cJSON *reporting_controller = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "reportingController");
    if (reporting_controller) { 
    if(!mazu_cJSON_IsString(reporting_controller) && !mazu_cJSON_IsNull(reporting_controller))
    {
    goto end; //String
    }
    }

    // events_v1_event->reporting_instance
    mazu_cJSON *reporting_instance = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "reportingInstance");
    if (reporting_instance) { 
    if(!mazu_cJSON_IsString(reporting_instance) && !mazu_cJSON_IsNull(reporting_instance))
    {
    goto end; //String
    }
    }

    // events_v1_event->series
    mazu_cJSON *series = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "series");
    if (series) { 
    series_local_nonprim = events_v1_event_series_parseFromJSON(series); //nonprimitive
    }

    // events_v1_event->type
    mazu_cJSON *type = mazu_cJSON_GetObjectItemCaseSensitive(events_v1_eventJSON, "type");
    if (type) { 
    if(!mazu_cJSON_IsString(type) && !mazu_cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    events_v1_event_local_var = events_v1_event_create (
        action && !mazu_cJSON_IsNull(action) ? strdup(action->valuestring) : NULL,
        api_version && !mazu_cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        deprecated_count ? deprecated_count->valuedouble : 0,
        deprecated_first_timestamp && !mazu_cJSON_IsNull(deprecated_first_timestamp) ? strdup(deprecated_first_timestamp->valuestring) : NULL,
        deprecated_last_timestamp && !mazu_cJSON_IsNull(deprecated_last_timestamp) ? strdup(deprecated_last_timestamp->valuestring) : NULL,
        deprecated_source ? deprecated_source_local_nonprim : NULL,
        strdup(event_time->valuestring),
        kind && !mazu_cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        note && !mazu_cJSON_IsNull(note) ? strdup(note->valuestring) : NULL,
        reason && !mazu_cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        regarding ? regarding_local_nonprim : NULL,
        related ? related_local_nonprim : NULL,
        reporting_controller && !mazu_cJSON_IsNull(reporting_controller) ? strdup(reporting_controller->valuestring) : NULL,
        reporting_instance && !mazu_cJSON_IsNull(reporting_instance) ? strdup(reporting_instance->valuestring) : NULL,
        series ? series_local_nonprim : NULL,
        type && !mazu_cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return events_v1_event_local_var;
end:
    if (deprecated_source_local_nonprim) {
        v1_event_source_free(deprecated_source_local_nonprim);
        deprecated_source_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (regarding_local_nonprim) {
        v1_object_reference_free(regarding_local_nonprim);
        regarding_local_nonprim = NULL;
    }
    if (related_local_nonprim) {
        v1_object_reference_free(related_local_nonprim);
        related_local_nonprim = NULL;
    }
    if (series_local_nonprim) {
        events_v1_event_series_free(series_local_nonprim);
        series_local_nonprim = NULL;
    }
    return NULL;

}
