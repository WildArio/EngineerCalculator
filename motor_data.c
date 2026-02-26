#include <stdio.h>
#include "motor_data.h"

static const Motor MOTORS_DATA[] = {
    {0.75, },
    {1.1, },
    {1.5, },
    {2.2, },
    {3.0,},
    {4.0, },
    {5.5, },
    {7.5, },
    {11.0, },
    {15.0, },
    {18.5, },
    {22.0, },
    {30.0, },
    {37.0, },
    {45.0, },
    {55.0, },
    {75.0, },
    {90.0, },
    {110.0, },
    {132.0, },
    {160.0, },
    {200.0, },
    {250.0, },
    {315.0, },
    {355.0, }
};

int motor_get_count(void);

const Motor* motor_get_by_power(float power_kw);

const Motor* motor_get_by_current(float current_a);