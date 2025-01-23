/*
 * v1_pod_dns_config_option.h
 *
 * PodDNSConfigOption defines DNS resolver options of a pod.
 */

#ifndef _v1_pod_dns_config_option_H_
#define _v1_pod_dns_config_option_H_

#include <string.h>
#include "../external/mazu_cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_dns_config_option_t v1_pod_dns_config_option_t;




typedef struct v1_pod_dns_config_option_t {
    char *name; // string
    char *value; // string

} v1_pod_dns_config_option_t;

v1_pod_dns_config_option_t *v1_pod_dns_config_option_create(
    char *name,
    char *value
);

void v1_pod_dns_config_option_free(v1_pod_dns_config_option_t *v1_pod_dns_config_option);

v1_pod_dns_config_option_t *v1_pod_dns_config_option_parseFromJSON(mazu_cJSON *v1_pod_dns_config_optionJSON);

mazu_cJSON *v1_pod_dns_config_option_convertToJSON(v1_pod_dns_config_option_t *v1_pod_dns_config_option);

#endif /* _v1_pod_dns_config_option_H_ */

