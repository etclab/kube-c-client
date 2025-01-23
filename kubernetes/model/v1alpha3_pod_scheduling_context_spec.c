#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_pod_scheduling_context_spec.h"



v1alpha3_pod_scheduling_context_spec_t *v1alpha3_pod_scheduling_context_spec_create(
    list_t *potential_nodes,
    char *selected_node
    ) {
    v1alpha3_pod_scheduling_context_spec_t *v1alpha3_pod_scheduling_context_spec_local_var = malloc(sizeof(v1alpha3_pod_scheduling_context_spec_t));
    if (!v1alpha3_pod_scheduling_context_spec_local_var) {
        return NULL;
    }
    v1alpha3_pod_scheduling_context_spec_local_var->potential_nodes = potential_nodes;
    v1alpha3_pod_scheduling_context_spec_local_var->selected_node = selected_node;

    return v1alpha3_pod_scheduling_context_spec_local_var;
}


void v1alpha3_pod_scheduling_context_spec_free(v1alpha3_pod_scheduling_context_spec_t *v1alpha3_pod_scheduling_context_spec) {
    if(NULL == v1alpha3_pod_scheduling_context_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_pod_scheduling_context_spec->potential_nodes) {
        list_ForEach(listEntry, v1alpha3_pod_scheduling_context_spec->potential_nodes) {
            free(listEntry->data);
        }
        list_freeList(v1alpha3_pod_scheduling_context_spec->potential_nodes);
        v1alpha3_pod_scheduling_context_spec->potential_nodes = NULL;
    }
    if (v1alpha3_pod_scheduling_context_spec->selected_node) {
        free(v1alpha3_pod_scheduling_context_spec->selected_node);
        v1alpha3_pod_scheduling_context_spec->selected_node = NULL;
    }
    free(v1alpha3_pod_scheduling_context_spec);
}

mazu_cJSON *v1alpha3_pod_scheduling_context_spec_convertToJSON(v1alpha3_pod_scheduling_context_spec_t *v1alpha3_pod_scheduling_context_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1alpha3_pod_scheduling_context_spec->potential_nodes
    if(v1alpha3_pod_scheduling_context_spec->potential_nodes) {
    mazu_cJSON *potential_nodes = mazu_cJSON_AddArrayToObject(item, "potentialNodes");
    if(potential_nodes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *potential_nodesListEntry;
    list_ForEach(potential_nodesListEntry, v1alpha3_pod_scheduling_context_spec->potential_nodes) {
    if(mazu_cJSON_AddStringToObject(potential_nodes, "", (char*)potential_nodesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1alpha3_pod_scheduling_context_spec->selected_node
    if(v1alpha3_pod_scheduling_context_spec->selected_node) {
    if(mazu_cJSON_AddStringToObject(item, "selectedNode", v1alpha3_pod_scheduling_context_spec->selected_node) == NULL) {
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

v1alpha3_pod_scheduling_context_spec_t *v1alpha3_pod_scheduling_context_spec_parseFromJSON(mazu_cJSON *v1alpha3_pod_scheduling_context_specJSON){

    v1alpha3_pod_scheduling_context_spec_t *v1alpha3_pod_scheduling_context_spec_local_var = NULL;

    // define the local list for v1alpha3_pod_scheduling_context_spec->potential_nodes
    list_t *potential_nodesList = NULL;

    // v1alpha3_pod_scheduling_context_spec->potential_nodes
    mazu_cJSON *potential_nodes = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_context_specJSON, "potentialNodes");
    if (potential_nodes) { 
    mazu_cJSON *potential_nodes_local = NULL;
    if(!mazu_cJSON_IsArray(potential_nodes)) {
        goto end;//primitive container
    }
    potential_nodesList = list_createList();

    mazu_cJSON_ArrayForEach(potential_nodes_local, potential_nodes)
    {
        if(!mazu_cJSON_IsString(potential_nodes_local))
        {
            goto end;
        }
        list_addElement(potential_nodesList , strdup(potential_nodes_local->valuestring));
    }
    }

    // v1alpha3_pod_scheduling_context_spec->selected_node
    mazu_cJSON *selected_node = mazu_cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_context_specJSON, "selectedNode");
    if (selected_node) { 
    if(!mazu_cJSON_IsString(selected_node) && !mazu_cJSON_IsNull(selected_node))
    {
    goto end; //String
    }
    }


    v1alpha3_pod_scheduling_context_spec_local_var = v1alpha3_pod_scheduling_context_spec_create (
        potential_nodes ? potential_nodesList : NULL,
        selected_node && !mazu_cJSON_IsNull(selected_node) ? strdup(selected_node->valuestring) : NULL
        );

    return v1alpha3_pod_scheduling_context_spec_local_var;
end:
    if (potential_nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, potential_nodesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(potential_nodesList);
        potential_nodesList = NULL;
    }
    return NULL;

}
