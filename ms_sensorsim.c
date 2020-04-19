#include "sensorsim.h"
#include "ms_sensorsim.h"

sensorsim_cfg_t   m_temperature_sim_cfg;                                 /**< Temperature sensor simulator configuration. */
sensorsim_state_t m_temperature_sim_state;                               /**< Temperature sensor simulator state. */
sensorsim_cfg_t   m_pressure_sim_cfg;                                    /**< Pressure sensor simulator configuration. */
sensorsim_state_t m_pressure_sim_state;                                  /**< Pressure sensor simulator state. */

/**@brief Function for initializing the sensor simulators.
 */
void sensor_simulator_init(void)
{
    m_temperature_sim_cfg.min          = MIN_TEMPERATURE_VALUE;
    m_temperature_sim_cfg.max          = MAX_TEMPERATURE_VALUE;
    m_temperature_sim_cfg.incr         = TEMPERATURE_VALUE_INCREMENT;
    m_temperature_sim_cfg.start_at_max = false;

    sensorsim_init(&m_temperature_sim_state, &m_temperature_sim_cfg);

    m_pressure_sim_cfg.min          = MIN_PRESSURE_VALUE;
    m_pressure_sim_cfg.max          = MAX_PRESSURE_VALUE;
    m_pressure_sim_cfg.incr         = PRESSURE_VALUE_INCREMENT;
    m_pressure_sim_cfg.start_at_max = false;

    sensorsim_init(&m_pressure_sim_state, &m_pressure_sim_cfg);
}

int16_t ms_sensorsim_measure_temperature(void)
{
  return sensorsim_measure(&m_temperature_sim_state, &m_temperature_sim_cfg);
}

int16_t ms_sensorsim_measure_pressure(void)
{
  return sensorsim_measure(&m_pressure_sim_state, &m_pressure_sim_cfg);
}