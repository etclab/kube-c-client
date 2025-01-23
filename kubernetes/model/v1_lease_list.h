/*
 * v1_lease_list.h
 *
 * LeaseList is a list of Lease objects.
 */

#ifndef _v1_lease_list_H_
#define _v1_lease_list_H_

#include <string.h>
#include "../external/mazu_cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_lease_list_t v1_lease_list_t;

#include "v1_lease.h"
#include "v1_list_meta.h"



typedef struct v1_lease_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1_lease_list_t;

v1_lease_list_t *v1_lease_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_lease_list_free(v1_lease_list_t *v1_lease_list);

v1_lease_list_t *v1_lease_list_parseFromJSON(mazu_cJSON *v1_lease_listJSON);

mazu_cJSON *v1_lease_list_convertToJSON(v1_lease_list_t *v1_lease_list);

#endif /* _v1_lease_list_H_ */

