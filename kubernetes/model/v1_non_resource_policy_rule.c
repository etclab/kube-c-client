#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_non_resource_policy_rule.h"



v1_non_resource_policy_rule_t *v1_non_resource_policy_rule_create(
    list_t *non_resource_urls,
    list_t *verbs
    ) {
    v1_non_resource_policy_rule_t *v1_non_resource_policy_rule_local_var = malloc(sizeof(v1_non_resource_policy_rule_t));
    if (!v1_non_resource_policy_rule_local_var) {
        return NULL;
    }
    v1_non_resource_policy_rule_local_var->non_resource_urls = non_resource_urls;
    v1_non_resource_policy_rule_local_var->verbs = verbs;

    return v1_non_resource_policy_rule_local_var;
}


void v1_non_resource_policy_rule_free(v1_non_resource_policy_rule_t *v1_non_resource_policy_rule) {
    if(NULL == v1_non_resource_policy_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_non_resource_policy_rule->non_resource_urls) {
        list_ForEach(listEntry, v1_non_resource_policy_rule->non_resource_urls) {
            free(listEntry->data);
        }
        list_freeList(v1_non_resource_policy_rule->non_resource_urls);
        v1_non_resource_policy_rule->non_resource_urls = NULL;
    }
    if (v1_non_resource_policy_rule->verbs) {
        list_ForEach(listEntry, v1_non_resource_policy_rule->verbs) {
            free(listEntry->data);
        }
        list_freeList(v1_non_resource_policy_rule->verbs);
        v1_non_resource_policy_rule->verbs = NULL;
    }
    free(v1_non_resource_policy_rule);
}

mazu_cJSON *v1_non_resource_policy_rule_convertToJSON(v1_non_resource_policy_rule_t *v1_non_resource_policy_rule) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_non_resource_policy_rule->non_resource_urls
    if (!v1_non_resource_policy_rule->non_resource_urls) {
        goto fail;
    }
    mazu_cJSON *non_resource_urls = mazu_cJSON_AddArrayToObject(item, "nonResourceURLs");
    if(non_resource_urls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *non_resource_urlsListEntry;
    list_ForEach(non_resource_urlsListEntry, v1_non_resource_policy_rule->non_resource_urls) {
    if(mazu_cJSON_AddStringToObject(non_resource_urls, "", (char*)non_resource_urlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_non_resource_policy_rule->verbs
    if (!v1_non_resource_policy_rule->verbs) {
        goto fail;
    }
    mazu_cJSON *verbs = mazu_cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_non_resource_policy_rule->verbs) {
    if(mazu_cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
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

v1_non_resource_policy_rule_t *v1_non_resource_policy_rule_parseFromJSON(mazu_cJSON *v1_non_resource_policy_ruleJSON){

    v1_non_resource_policy_rule_t *v1_non_resource_policy_rule_local_var = NULL;

    // define the local list for v1_non_resource_policy_rule->non_resource_urls
    list_t *non_resource_urlsList = NULL;

    // define the local list for v1_non_resource_policy_rule->verbs
    list_t *verbsList = NULL;

    // v1_non_resource_policy_rule->non_resource_urls
    mazu_cJSON *non_resource_urls = mazu_cJSON_GetObjectItemCaseSensitive(v1_non_resource_policy_ruleJSON, "nonResourceURLs");
    if (!non_resource_urls) {
        goto end;
    }

    
    mazu_cJSON *non_resource_urls_local = NULL;
    if(!mazu_cJSON_IsArray(non_resource_urls)) {
        goto end;//primitive container
    }
    non_resource_urlsList = list_createList();

    mazu_cJSON_ArrayForEach(non_resource_urls_local, non_resource_urls)
    {
        if(!mazu_cJSON_IsString(non_resource_urls_local))
        {
            goto end;
        }
        list_addElement(non_resource_urlsList , strdup(non_resource_urls_local->valuestring));
    }

    // v1_non_resource_policy_rule->verbs
    mazu_cJSON *verbs = mazu_cJSON_GetObjectItemCaseSensitive(v1_non_resource_policy_ruleJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    
    mazu_cJSON *verbs_local = NULL;
    if(!mazu_cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_createList();

    mazu_cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!mazu_cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1_non_resource_policy_rule_local_var = v1_non_resource_policy_rule_create (
        non_resource_urlsList,
        verbsList
        );

    return v1_non_resource_policy_rule_local_var;
end:
    if (non_resource_urlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, non_resource_urlsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(non_resource_urlsList);
        non_resource_urlsList = NULL;
    }
    if (verbsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, verbsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(verbsList);
        verbsList = NULL;
    }
    return NULL;

}
