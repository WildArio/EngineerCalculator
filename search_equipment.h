#ifndef SEARCH_H
#define SEARCH_H

#include "motor_data.h"

typedef enum SearchParameter {
    FIND_BY_POWER,
    FIND_BY_CURRENT
} SearchParameter;

const Motor* search_motor_by_parameter(const Motor motors[], int size, SearchParameter parameter, float value);

static float get_field_value(const Motor* motor, SearchParameter param);

#endif