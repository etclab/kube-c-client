/*
 * v1_pod_ip.h
 *
 * PodIP represents a single IP address allocated to the pod.
 */

#ifndef _v1_pod_ip_H_
#define _v1_pod_ip_H_

#include <string.h>
#include "../external/mazu_cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_ip_t v1_pod_ip_t;




typedef struct v1_pod_ip_t {
    char *ip; // string

} v1_pod_ip_t;

v1_pod_ip_t *v1_pod_ip_create(
    char *ip
);

void v1_pod_ip_free(v1_pod_ip_t *v1_pod_ip);

v1_pod_ip_t *v1_pod_ip_parseFromJSON(mazu_cJSON *v1_pod_ipJSON);

mazu_cJSON *v1_pod_ip_convertToJSON(v1_pod_ip_t *v1_pod_ip);

#endif /* _v1_pod_ip_H_ */

