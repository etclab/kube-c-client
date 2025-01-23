#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_dns_config.h"



v1_pod_dns_config_t *v1_pod_dns_config_create(
    list_t *nameservers,
    list_t *options,
    list_t *searches
    ) {
    v1_pod_dns_config_t *v1_pod_dns_config_local_var = malloc(sizeof(v1_pod_dns_config_t));
    if (!v1_pod_dns_config_local_var) {
        return NULL;
    }
    v1_pod_dns_config_local_var->nameservers = nameservers;
    v1_pod_dns_config_local_var->options = options;
    v1_pod_dns_config_local_var->searches = searches;

    return v1_pod_dns_config_local_var;
}


void v1_pod_dns_config_free(v1_pod_dns_config_t *v1_pod_dns_config) {
    if(NULL == v1_pod_dns_config){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_dns_config->nameservers) {
        list_ForEach(listEntry, v1_pod_dns_config->nameservers) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_dns_config->nameservers);
        v1_pod_dns_config->nameservers = NULL;
    }
    if (v1_pod_dns_config->options) {
        list_ForEach(listEntry, v1_pod_dns_config->options) {
            v1_pod_dns_config_option_free(listEntry->data);
        }
        list_freeList(v1_pod_dns_config->options);
        v1_pod_dns_config->options = NULL;
    }
    if (v1_pod_dns_config->searches) {
        list_ForEach(listEntry, v1_pod_dns_config->searches) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_dns_config->searches);
        v1_pod_dns_config->searches = NULL;
    }
    free(v1_pod_dns_config);
}

mazu_cJSON *v1_pod_dns_config_convertToJSON(v1_pod_dns_config_t *v1_pod_dns_config) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_pod_dns_config->nameservers
    if(v1_pod_dns_config->nameservers) {
    mazu_cJSON *nameservers = mazu_cJSON_AddArrayToObject(item, "nameservers");
    if(nameservers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *nameserversListEntry;
    list_ForEach(nameserversListEntry, v1_pod_dns_config->nameservers) {
    if(mazu_cJSON_AddStringToObject(nameservers, "", (char*)nameserversListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_pod_dns_config->options
    if(v1_pod_dns_config->options) {
    mazu_cJSON *options = mazu_cJSON_AddArrayToObject(item, "options");
    if(options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *optionsListEntry;
    if (v1_pod_dns_config->options) {
    list_ForEach(optionsListEntry, v1_pod_dns_config->options) {
    mazu_cJSON *itemLocal = v1_pod_dns_config_option_convertToJSON(optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    mazu_cJSON_AddItemToArray(options, itemLocal);
    }
    }
    }


    // v1_pod_dns_config->searches
    if(v1_pod_dns_config->searches) {
    mazu_cJSON *searches = mazu_cJSON_AddArrayToObject(item, "searches");
    if(searches == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *searchesListEntry;
    list_ForEach(searchesListEntry, v1_pod_dns_config->searches) {
    if(mazu_cJSON_AddStringToObject(searches, "", (char*)searchesListEntry->data) == NULL)
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

v1_pod_dns_config_t *v1_pod_dns_config_parseFromJSON(mazu_cJSON *v1_pod_dns_configJSON){

    v1_pod_dns_config_t *v1_pod_dns_config_local_var = NULL;

    // define the local list for v1_pod_dns_config->nameservers
    list_t *nameserversList = NULL;

    // define the local list for v1_pod_dns_config->options
    list_t *optionsList = NULL;

    // define the local list for v1_pod_dns_config->searches
    list_t *searchesList = NULL;

    // v1_pod_dns_config->nameservers
    mazu_cJSON *nameservers = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_dns_configJSON, "nameservers");
    if (nameservers) { 
    mazu_cJSON *nameservers_local = NULL;
    if(!mazu_cJSON_IsArray(nameservers)) {
        goto end;//primitive container
    }
    nameserversList = list_createList();

    mazu_cJSON_ArrayForEach(nameservers_local, nameservers)
    {
        if(!mazu_cJSON_IsString(nameservers_local))
        {
            goto end;
        }
        list_addElement(nameserversList , strdup(nameservers_local->valuestring));
    }
    }

    // v1_pod_dns_config->options
    mazu_cJSON *options = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_dns_configJSON, "options");
    if (options) { 
    mazu_cJSON *options_local_nonprimitive = NULL;
    if(!mazu_cJSON_IsArray(options)){
        goto end; //nonprimitive container
    }

    optionsList = list_createList();

    mazu_cJSON_ArrayForEach(options_local_nonprimitive,options )
    {
        if(!mazu_cJSON_IsObject(options_local_nonprimitive)){
            goto end;
        }
        v1_pod_dns_config_option_t *optionsItem = v1_pod_dns_config_option_parseFromJSON(options_local_nonprimitive);

        list_addElement(optionsList, optionsItem);
    }
    }

    // v1_pod_dns_config->searches
    mazu_cJSON *searches = mazu_cJSON_GetObjectItemCaseSensitive(v1_pod_dns_configJSON, "searches");
    if (searches) { 
    mazu_cJSON *searches_local = NULL;
    if(!mazu_cJSON_IsArray(searches)) {
        goto end;//primitive container
    }
    searchesList = list_createList();

    mazu_cJSON_ArrayForEach(searches_local, searches)
    {
        if(!mazu_cJSON_IsString(searches_local))
        {
            goto end;
        }
        list_addElement(searchesList , strdup(searches_local->valuestring));
    }
    }


    v1_pod_dns_config_local_var = v1_pod_dns_config_create (
        nameservers ? nameserversList : NULL,
        options ? optionsList : NULL,
        searches ? searchesList : NULL
        );

    return v1_pod_dns_config_local_var;
end:
    if (nameserversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, nameserversList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(nameserversList);
        nameserversList = NULL;
    }
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            v1_pod_dns_config_option_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(optionsList);
        optionsList = NULL;
    }
    if (searchesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, searchesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(searchesList);
        searchesList = NULL;
    }
    return NULL;

}
