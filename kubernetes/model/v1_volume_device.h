/*
 * v1_volume_device.h
 *
 * volumeDevice describes a mapping of a raw block device within a container.
 */

#ifndef _v1_volume_device_H_
#define _v1_volume_device_H_

#include <string.h>
#include "../external/mazu_cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_device_t v1_volume_device_t;




typedef struct v1_volume_device_t {
    char *device_path; // string
    char *name; // string

} v1_volume_device_t;

v1_volume_device_t *v1_volume_device_create(
    char *device_path,
    char *name
);

void v1_volume_device_free(v1_volume_device_t *v1_volume_device);

v1_volume_device_t *v1_volume_device_parseFromJSON(mazu_cJSON *v1_volume_deviceJSON);

mazu_cJSON *v1_volume_device_convertToJSON(v1_volume_device_t *v1_volume_device);

#endif /* _v1_volume_device_H_ */

