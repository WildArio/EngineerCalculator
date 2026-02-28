#include <stdio.h>
#include <math.h>
#include "search_equipment.h"

#define EPSILON 0.001
#define EXACT_MATCH 1
#define CLOSEST_MATCH 0
#define NOT_FOUND -1

SearchResults search_nearest_motor(const Motor motors[], int size, SearchParameter parameter, float value) {
    
    SearchResults search_result = {NOT_FOUND, NULL, NOT_FOUND};

    if (motors == NULL || size <= 0) {
        return search_result;
    }
    
    int left = 0;
    int right = size - 1;
    int best_index = 0;
    float min_diff = fabs(get_field_value(&motors[0], parameter) - value);
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        float mid_value = get_field_value(&motors[mid], parameter);

        if (fabs(value - mid_value) < EPSILON) {
            search_result.found_index = mid;
            search_result.motor = &motors[mid];
            search_result.searched_standard_value = EXACT_MATCH;

            return search_result;
        }

        float diff = fabs(mid_value - value);

        if (diff < min_diff) {
            min_diff = diff;
            best_index = mid;
        }

        if (value > mid_value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    search_result.found_index = best_index;
    search_result.motor = &motors[best_index];
    search_result.searched_standard_value = CLOSEST_MATCH;

    return search_result;
}

static float get_field_value(const Motor* motor, SearchParameter parameter) {
    if (!motor) return 0;
    
    switch(parameter) {
        case FIND_BY_POWER:
            return motor->power_kw;
        case FIND_BY_CURRENT:
            return motor->nominal_current_a;
        default:
            return 0;
    }
};