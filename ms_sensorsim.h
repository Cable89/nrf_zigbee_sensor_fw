#ifndef MULTISENSOR_SENSORSIM_H__
#define MULTISENSOR_SENSORSIM_H__

#include "sensorsim.h"

#define MIN_TEMPERATURE_VALUE              0                                    /**< Minimum temperature value as returned by the simulated measurement function. */
#define MAX_TEMPERATURE_VALUE              4000                                 /**< Maximum temperature value as returned by the simulated measurement function. */
#define TEMPERATURE_VALUE_INCREMENT        50                                   /**< Value by which the temperature value is incremented/decremented for each call to the simulated measurement function. */
#define MIN_PRESSURE_VALUE                 700                                  /**< Minimum pressure value as returned by the simulated measurement function. */
#define MAX_PRESSURE_VALUE                 1100                                 /**< Maximum pressure value as returned by the simulated measurement function. */
#define PRESSURE_VALUE_INCREMENT           5                                    /**< Value by which the temperature value is incremented/decremented for each call to the simulated measurement function. */

void sensor_simulator_init(void);
int16_t ms_sensorsim_measure_temperature(void);
int16_t ms_sensorsim_measure_pressure(void);

#endif // MULTISENSOR_SENSORSIM_H__