#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_rule.h"



v1_ingress_rule_t *v1_ingress_rule_create(
    char *host,
    v1_http_ingress_rule_value_t *http
    ) {
    v1_ingress_rule_t *v1_ingress_rule_local_var = malloc(sizeof(v1_ingress_rule_t));
    if (!v1_ingress_rule_local_var) {
        return NULL;
    }
    v1_ingress_rule_local_var->host = host;
    v1_ingress_rule_local_var->http = http;

    return v1_ingress_rule_local_var;
}


void v1_ingress_rule_free(v1_ingress_rule_t *v1_ingress_rule) {
    if(NULL == v1_ingress_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_rule->host) {
        free(v1_ingress_rule->host);
        v1_ingress_rule->host = NULL;
    }
    if (v1_ingress_rule->http) {
        v1_http_ingress_rule_value_free(v1_ingress_rule->http);
        v1_ingress_rule->http = NULL;
    }
    free(v1_ingress_rule);
}

mazu_cJSON *v1_ingress_rule_convertToJSON(v1_ingress_rule_t *v1_ingress_rule) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_ingress_rule->host
    if(v1_ingress_rule->host) {
    if(mazu_cJSON_AddStringToObject(item, "host", v1_ingress_rule->host) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_rule->http
    if(v1_ingress_rule->http) {
    mazu_cJSON *http_local_JSON = v1_http_ingress_rule_value_convertToJSON(v1_ingress_rule->http);
    if(http_local_JSON == NULL) {
    goto fail; //model
    }
    mazu_cJSON_AddItemToObject(item, "http", http_local_JSON);
    if(item->child == NULL) {
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

v1_ingress_rule_t *v1_ingress_rule_parseFromJSON(mazu_cJSON *v1_ingress_ruleJSON){

    v1_ingress_rule_t *v1_ingress_rule_local_var = NULL;

    // define the local variable for v1_ingress_rule->http
    v1_http_ingress_rule_value_t *http_local_nonprim = NULL;

    // v1_ingress_rule->host
    mazu_cJSON *host = mazu_cJSON_GetObjectItemCaseSensitive(v1_ingress_ruleJSON, "host");
    if (host) { 
    if(!mazu_cJSON_IsString(host) && !mazu_cJSON_IsNull(host))
    {
    goto end; //String
    }
    }

    // v1_ingress_rule->http
    mazu_cJSON *http = mazu_cJSON_GetObjectItemCaseSensitive(v1_ingress_ruleJSON, "http");
    if (http) { 
    http_local_nonprim = v1_http_ingress_rule_value_parseFromJSON(http); //nonprimitive
    }


    v1_ingress_rule_local_var = v1_ingress_rule_create (
        host && !mazu_cJSON_IsNull(host) ? strdup(host->valuestring) : NULL,
        http ? http_local_nonprim : NULL
        );

    return v1_ingress_rule_local_var;
end:
    if (http_local_nonprim) {
        v1_http_ingress_rule_value_free(http_local_nonprim);
        http_local_nonprim = NULL;
    }
    return NULL;

}
