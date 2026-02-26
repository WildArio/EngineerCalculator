#include <stdio.h>
#include "search_equipment.h"

const Motor* search_motor_by_parameter(const Motor motors[], int size, SearchParameter parameter, float value){
    int left = 0;
    int right = size;
    int mid = 0;
    float mid_value = 0;

    while(1) {
        mid = left + (right - left) / 2;
        mid_value = get_field_value(&motors[mid], parameter);

        if (value == mid_value) {
            return &motors[mid];
        }
        else if (left > right) {
            break;
        }
        else if (value > mid_value) {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        };
    };

    return NULL;
};

static float get_field_value(const Motor* motor, SearchParameter parameter) {
    switch(parameter) {
        case FIND_BY_POWER:
            return motor->power_kw;
        case FIND_BY_CURRENT:
            return motor->nominal_current_a;
        default:
            return 0;
    };
};