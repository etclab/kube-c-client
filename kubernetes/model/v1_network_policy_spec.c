#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_spec.h"



v1_network_policy_spec_t *v1_network_policy_spec_create(
    list_t *egress,
    list_t *ingress,
    v1_label_selector_t *pod_selector,
    list_t *policy_types
    ) {
    v1_network_policy_spec_t *v1_network_policy_spec_local_var = malloc(sizeof(v1_network_policy_spec_t));
    if (!v1_network_policy_spec_local_var) {
        return NULL;
    }
    v1_network_policy_spec_local_var->egress = egress;
    v1_network_policy_spec_local_var->ingress = ingress;
    v1_network_policy_spec_local_var->pod_selector = pod_selector;
    v1_network_policy_spec_local_var->policy_types = policy_types;

    return v1_network_policy_spec_local_var;
}


void v1_network_policy_spec_free(v1_network_policy_spec_t *v1_network_policy_spec) {
    if(NULL == v1_network_policy_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_spec->egress) {
        list_ForEach(listEntry, v1_network_policy_spec->egress) {
            v1_network_policy_egress_rule_free(listEntry->data);
        }
        list_freeList(v1_network_policy_spec->egress);
        v1_network_policy_spec->egress = NULL;
    }
    if (v1_network_policy_spec->ingress) {
        list_ForEach(listEntry, v1_network_policy_spec->ingress) {
            v1_network_policy_ingress_rule_free(listEntry->data);
        }
        list_freeList(v1_network_policy_spec->ingress);
        v1_network_policy_spec->ingress = NULL;
    }
    if (v1_network_policy_spec->pod_selector) {
        v1_label_selector_free(v1_network_policy_spec->pod_selector);
        v1_network_policy_spec->pod_selector = NULL;
    }
    if (v1_network_policy_spec->policy_types) {
        list_ForEach(listEntry, v1_network_policy_spec->policy_types) {
            free(listEntry->data);
        }
        list_freeList(v1_network_policy_spec->policy_types);
        v1_network_policy_spec->policy_types = NULL;
    }
    free(v1_network_policy_spec);
}

mazu_cJSON *v1_network_policy_spec_convertToJSON(v1_network_policy_spec_t *v1_network_policy_spec) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_network_policy_spec->egress
    if(v1_network_policy_spec->egress) {
    mazu_cJSON *egress = mazu_cJSON_AddArrayToObject(item, "egress");
    if(egress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *egressListEntry;
    if (v1_network_policy_spec->egress) {
    list_ForEach(egressListEntry, v1_network_policy_spec->egress) {
    mazu_cJSON *itemLocal = v1_network_policy_egress_rule_convertToJSON(egressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(egress, itemLocal);
    }
    }
    }


    // v1_network_policy_spec->ingress
    if(v1_network_policy_spec->ingress) {
    mazu_cJSON *ingress = mazu_cJSON_AddArrayToObject(item, "ingress");
    if(ingress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ingressListEntry;
    if (v1_network_policy_spec->ingress) {
    list_ForEach(ingressListEntry, v1_network_policy_spec->ingress) {
    mazu_cJSON *itemLocal = v1_network_policy_ingress_rule_convertToJSON(ingressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(ingress, itemLocal);
    }
    }
    }


    // v1_network_policy_spec->pod_selector
    if (!v1_network_policy_spec->pod_selector) {
        goto fail;
    }
    mazu_cJSON *pod_selector_local_JSON = v1_label_selector_convertToJSON(v1_network_policy_spec->pod_selector);
    if(pod_selector_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "podSelector", pod_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_network_policy_spec->policy_types
    if(v1_network_policy_spec->policy_types) {
    mazu_cJSON *policy_types = mazu_cJSON_AddArrayToObject(item, "policyTypes");
    if(policy_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *policy_typesListEntry;
    list_ForEach(policy_typesListEntry, v1_network_policy_spec->policy_types) {
    if(mazu_cJSON_AddStringToObject(policy_types, "", (char*)policy_typesListEntry->data) == NULL)
    {
        goto fail;
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

v1_network_policy_spec_t *v1_network_policy_spec_parseFromJSON(mazu_cJSON *v1_network_policy_specJSON){

    v1_network_policy_spec_t *v1_network_policy_spec_local_var = NULL;

    // define the local list for v1_network_policy_spec->egress
    list_t *egressList = NULL;

    // define the local list for v1_network_policy_spec->ingress
    list_t *ingressList = NULL;

    // define the local variable for v1_network_policy_spec->pod_selector
    v1_label_selector_t *pod_selector_local_nonprim = NULL;

    // define the local list for v1_network_policy_spec->policy_types
    list_t *policy_typesList = NULL;

    // v1_network_policy_spec->egress
    mazu_cJSON *egress = mazu_cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "egress");
    if (egress) { 
    mazu_cJSON *egress_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(egress)){
        goto end; //nonprimitive container
    }

    egressList = list_createList();

    mazu_cJSON_ArrayForEach(egress_local_nonprimitive,egress )
    {
        if(!mazu_cJSON_IsObject(egress_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_egress_rule_t *egressItem = v1_network_policy_egress_rule_parseFromJSON(egress_local_nonprimitive);

        list_addElement(egressList, egressItem);
    }
    }

    // v1_network_policy_spec->ingress
    mazu_cJSON *ingress = mazu_cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "ingress");
    if (ingress) { 
    mazu_cJSON *ingress_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(ingress)){
        goto end; //nonprimitive container
    }

    ingressList = list_createList();

    mazu_cJSON_ArrayForEach(ingress_local_nonprimitive,ingress )
    {
        if(!mazu_cJSON_IsObject(ingress_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_ingress_rule_t *ingressItem = v1_network_policy_ingress_rule_parseFromJSON(ingress_local_nonprimitive);

        list_addElement(ingressList, ingressItem);
    }
    }

    // v1_network_policy_spec->pod_selector
    mazu_cJSON *pod_selector = mazu_cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "podSelector");
    if (!pod_selector) {
        goto end;
    }

    
    pod_selector_local_nonprim = v1_label_selector_parseFromJSON(pod_selector); //nonprimitive

    // v1_network_policy_spec->policy_types
    mazu_cJSON *policy_types = mazu_cJSON_GetObjectItemCaseSensitive(v1_network_policy_specJSON, "policyTypes");
    if (policy_types) { 
    mazu_cJSON *policy_types_local = NULL;
    if(!mazu_cJSON_IsArray(policy_types)) {
        goto end;//primitive container
    }
    policy_typesList = list_createList();

    mazu_cJSON_ArrayForEach(policy_types_local, policy_types)
    {
        if(!mazu_cJSON_IsString(policy_types_local))
        {
            goto end;
        }
        list_addElement(policy_typesList , strdup(policy_types_local->valuestring));
    }
    }


    v1_network_policy_spec_local_var = v1_network_policy_spec_create (
        egress ? egressList : NULL,
        ingress ? ingressList : NULL,
        pod_selector_local_nonprim,
        policy_types ? policy_typesList : NULL
        );

    return v1_network_policy_spec_local_var;
end:
    if (egressList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, egressList) {
            v1_network_policy_egress_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(egressList);
        egressList = NULL;
    }
    if (ingressList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ingressList) {
            v1_network_policy_ingress_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ingressList);
        ingressList = NULL;
    }
    if (pod_selector_local_nonprim) {
        v1_label_selector_free(pod_selector_local_nonprim);
        pod_selector_local_nonprim = NULL;
    }
    if (policy_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, policy_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(policy_typesList);
        policy_typesList = NULL;
    }
    return NULL;

}
