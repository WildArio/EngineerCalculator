#ifndef SEARCH_H
#define SEARCH_H

#include "motor_data.h"

typedef enum SearchParameter {
    FIND_BY_POWER,
    FIND_BY_CURRENT
} SearchParameter;

typedef struct MotorSearchResults {
    int found_index;
    const Motor* motor;
    int searched_standard_value;
} SearchResults;

SearchResults search_nearest_motor(const Motor motors[], int size, SearchParameter parameter, float value);

static float get_field_value(const Motor* motor, SearchParameter param);

#endif