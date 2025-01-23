#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_spread_constraint.h"



v1_topology_spread_constraint_t *v1_topology_spread_constraint_create(
    v1_label_selector_t *label_selector,
    list_t *match_label_keys,
    int max_skew,
    int min_domains,
    char *node_affinity_policy,
    char *node_taints_policy,
    char *topology_key,
    char *when_unsatisfiable
    ) {
    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = malloc(sizeof(v1_topology_spread_constraint_t));
    if (!v1_topology_spread_constraint_local_var) {
        return NULL;
    }
    v1_topology_spread_constraint_local_var->label_selector = label_selector;
    v1_topology_spread_constraint_local_var->match_label_keys = match_label_keys;
    v1_topology_spread_constraint_local_var->max_skew = max_skew;
    v1_topology_spread_constraint_local_var->min_domains = min_domains;
    v1_topology_spread_constraint_local_var->node_affinity_policy = node_affinity_policy;
    v1_topology_spread_constraint_local_var->node_taints_policy = node_taints_policy;
    v1_topology_spread_constraint_local_var->topology_key = topology_key;
    v1_topology_spread_constraint_local_var->when_unsatisfiable = when_unsatisfiable;

    return v1_topology_spread_constraint_local_var;
}


void v1_topology_spread_constraint_free(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    if(NULL == v1_topology_spread_constraint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_topology_spread_constraint->label_selector) {
        v1_label_selector_free(v1_topology_spread_constraint->label_selector);
        v1_topology_spread_constraint->label_selector = NULL;
    }
    if (v1_topology_spread_constraint->match_label_keys) {
        list_ForEach(listEntry, v1_topology_spread_constraint->match_label_keys) {
            free(listEntry->data);
        }
        list_freeList(v1_topology_spread_constraint->match_label_keys);
        v1_topology_spread_constraint->match_label_keys = NULL;
    }
    if (v1_topology_spread_constraint->node_affinity_policy) {
        free(v1_topology_spread_constraint->node_affinity_policy);
        v1_topology_spread_constraint->node_affinity_policy = NULL;
    }
    if (v1_topology_spread_constraint->node_taints_policy) {
        free(v1_topology_spread_constraint->node_taints_policy);
        v1_topology_spread_constraint->node_taints_policy = NULL;
    }
    if (v1_topology_spread_constraint->topology_key) {
        free(v1_topology_spread_constraint->topology_key);
        v1_topology_spread_constraint->topology_key = NULL;
    }
    if (v1_topology_spread_constraint->when_unsatisfiable) {
        free(v1_topology_spread_constraint->when_unsatisfiable);
        v1_topology_spread_constraint->when_unsatisfiable = NULL;
    }
    free(v1_topology_spread_constraint);
}

mazu_cJSON *v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_topology_spread_constraint->label_selector
    if(v1_topology_spread_constraint->label_selector) {
    mazu_cJSON *label_selector_local_JSON = v1_label_selector_convertToJSON(v1_topology_spread_constraint->label_selector);
    if(label_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "labelSelector", label_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_topology_spread_constraint->match_label_keys
    if(v1_topology_spread_constraint->match_label_keys) {
    mazu_cJSON *match_label_keys = mazu_cJSON_AddArrayToObject(item, "matchLabelKeys");
    if(match_label_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *match_label_keysListEntry;
    list_ForEach(match_label_keysListEntry, v1_topology_spread_constraint->match_label_keys) {
    if(mazu_cJSON_AddStringToObject(match_label_keys, "", (char*)match_label_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_topology_spread_constraint->max_skew
    if (!v1_topology_spread_constraint->max_skew) {
        goto fail;
    }
    if(mazu_cJSON_AddNumberToObject(item, "maxSkew", v1_topology_spread_constraint->max_skew) == NULL) {
    goto fail; //Numeric
    }


    // v1_topology_spread_constraint->min_domains
    if(v1_topology_spread_constraint->min_domains) {
    if(mazu_cJSON_AddNumberToObject(item, "minDomains", v1_topology_spread_constraint->min_domains) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_topology_spread_constraint->node_affinity_policy
    if(v1_topology_spread_constraint->node_affinity_policy) {
    if(mazu_cJSON_AddStringToObject(item, "nodeAffinityPolicy", v1_topology_spread_constraint->node_affinity_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_topology_spread_constraint->node_taints_policy
    if(v1_topology_spread_constraint->node_taints_policy) {
    if(mazu_cJSON_AddStringToObject(item, "nodeTaintsPolicy", v1_topology_spread_constraint->node_taints_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_topology_spread_constraint->topology_key
    if (!v1_topology_spread_constraint->topology_key) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "topologyKey", v1_topology_spread_constraint->topology_key) == NULL) {
    goto fail; //String
    }


    // v1_topology_spread_constraint->when_unsatisfiable
    if (!v1_topology_spread_constraint->when_unsatisfiable) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "whenUnsatisfiable", v1_topology_spread_constraint->when_unsatisfiable) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_topology_spread_constraint_t *v1_topology_spread_constraint_parseFromJSON(mazu_cJSON *v1_topology_spread_constraintJSON){

    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = NULL;

    // define the local variable for v1_topology_spread_constraint->label_selector
    v1_label_selector_t *label_selector_local_nonprim = NULL;

    // define the local list for v1_topology_spread_constraint->match_label_keys
    list_t *match_label_keysList = NULL;

    // v1_topology_spread_constraint->label_selector
    mazu_cJSON *label_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "labelSelector");
    if (label_selector) { 
    label_selector_local_nonprim = v1_label_selector_parseFromJSON(label_selector); //nonprimitive
    }

    // v1_topology_spread_constraint->match_label_keys
    mazu_cJSON *match_label_keys = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "matchLabelKeys");
    if (match_label_keys) { 
    mazu_cJSON *match_label_keys_local = NULL;
    if(!mazu_cJSON_IsArray(match_label_keys)) {
        goto end;//primitive container
    }
    match_label_keysList = list_createList();

    mazu_cJSON_ArrayForEach(match_label_keys_local, match_label_keys)
    {
        if(!mazu_cJSON_IsString(match_label_keys_local))
        {
            goto end;
        }
        list_addElement(match_label_keysList , strdup(match_label_keys_local->valuestring));
    }
    }

    // v1_topology_spread_constraint->max_skew
    mazu_cJSON *max_skew = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "maxSkew");
    if (!max_skew) {
        goto end;
    }

    
    if(!mazu_cJSON_IsNumber(max_skew))
    {
    goto end; //Numeric
    }

    // v1_topology_spread_constraint->min_domains
    mazu_cJSON *min_domains = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "minDomains");
    if (min_domains) { 
    if(!mazu_cJSON_IsNumber(min_domains))
    {
    goto end; //Numeric
    }
    }

    // v1_topology_spread_constraint->node_affinity_policy
    mazu_cJSON *node_affinity_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "nodeAffinityPolicy");
    if (node_affinity_policy) { 
    if(!mazu_cJSON_IsString(node_affinity_policy) && !mazu_cJSON_IsNull(node_affinity_policy))
    {
    goto end; //String
    }
    }

    // v1_topology_spread_constraint->node_taints_policy
    mazu_cJSON *node_taints_policy = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "nodeTaintsPolicy");
    if (node_taints_policy) { 
    if(!mazu_cJSON_IsString(node_taints_policy) && !mazu_cJSON_IsNull(node_taints_policy))
    {
    goto end; //String
    }
    }

    // v1_topology_spread_constraint->topology_key
    mazu_cJSON *topology_key = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "topologyKey");
    if (!topology_key) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(topology_key))
    {
    goto end; //String
    }

    // v1_topology_spread_constraint->when_unsatisfiable
    mazu_cJSON *when_unsatisfiable = mazu_cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "whenUnsatisfiable");
    if (!when_unsatisfiable) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(when_unsatisfiable))
    {
    goto end; //String
    }


    v1_topology_spread_constraint_local_var = v1_topology_spread_constraint_create (
        label_selector ? label_selector_local_nonprim : NULL,
        match_label_keys ? match_label_keysList : NULL,
        max_skew->valuedouble,
        min_domains ? min_domains->valuedouble : 0,
        node_affinity_policy && !mazu_cJSON_IsNull(node_affinity_policy) ? strdup(node_affinity_policy->valuestring) : NULL,
        node_taints_policy && !mazu_cJSON_IsNull(node_taints_policy) ? strdup(node_taints_policy->valuestring) : NULL,
        strdup(topology_key->valuestring),
        strdup(when_unsatisfiable->valuestring)
        );

    return v1_topology_spread_constraint_local_var;
end:
    if (label_selector_local_nonprim) {
        v1_label_selector_free(label_selector_local_nonprim);
        label_selector_local_nonprim = NULL;
    }
    if (match_label_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_label_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_label_keysList);
        match_label_keysList = NULL;
    }
    return NULL;

}
