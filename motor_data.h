#ifndef MOTOR_DATA_H
#define MOTOR_DATA_H

typedef struct Motor
{
    float power_kw;                 // Motor power in kilowatts
    float nominal_current_a;        // Motor nominal current in amperes
    float voltage_380v;             // Motor voltage (always 380V)
    float cos_phi;                  // Motor power coefficient
    float efficiency_percent;        // Motor efficiency in percent
    float start_torque_ratio;        // Starting torque / nominal torque (Mпуск/Мн)
    float max_torque_ratio;          // Maximum torque / nominal torque (Ммах/Мн)
    float start_current_ratio;       // Starting current / nominal current (Iпуск/Iн)
} Motor;

/**
 * Returns the amount of motors in data list.
 * @return count for motors (0 if database is empty).
 */
int motor_get_count(void);

/**
 * Finds motor with closest power to given value.
 * @param power_kw target power in kilowatts.
 * @return pointer to Motor or NULL if database is empty.
 */
const Motor* motor_get_by_power(float power_kw);

/**
 * Finds motor with closest current to given value.
 * @param current_a target current in amperes.
 * @return pointer to Motor or NULL if database is empty.
 */
const Motor* motor_get_by_current(float current_a);

#endif
