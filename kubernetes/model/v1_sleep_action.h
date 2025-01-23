/*
 * v1_sleep_action.h
 *
 * SleepAction describes a \&quot;sleep\&quot; action.
 */

#ifndef _v1_sleep_action_H_
#define _v1_sleep_action_H_

#include <string.h>
#include "../external/mazu_cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_sleep_action_t v1_sleep_action_t;




typedef struct v1_sleep_action_t {
    long seconds; //numeric

} v1_sleep_action_t;

v1_sleep_action_t *v1_sleep_action_create(
    long seconds
);

void v1_sleep_action_free(v1_sleep_action_t *v1_sleep_action);

v1_sleep_action_t *v1_sleep_action_parseFromJSON(mazu_cJSON *v1_sleep_actionJSON);

mazu_cJSON *v1_sleep_action_convertToJSON(v1_sleep_action_t *v1_sleep_action);

#endif /* _v1_sleep_action_H_ */

