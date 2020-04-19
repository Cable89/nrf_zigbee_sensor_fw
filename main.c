#include "zboss_api.h"
//#include "zboss_api_core.h"
//#include "zb_mem_config_med.h"
//#include "zb_zcl_reporting.h"
//#include "zb_error_handler.h"
//#include "zigbee_helpers.h"
//#include "app_timer.h"
#include "bsp.h"
//#include "boards.h"
//#include "sensorsim.h"
#include "ms_sensorsim.h"
#include "zigbee.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "zb_multi_sensor.h"


/**@brief Function for initializing the nrf log module.
 */
static void log_init(void)
{
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

/**@brief Function for initializing LEDs.
 */
static zb_void_t leds_init(void)
{
    ret_code_t error_code;

    /* Initialize LEDs and buttons - use BSP to control them. */
    error_code = bsp_init(BSP_INIT_LEDS, NULL);
    APP_ERROR_CHECK(error_code);

    bsp_board_leds_off();
}

/**@brief Function for application main entry.
 */
int main(void)
{
    ret_code_t     err_code;

    /* Initialize loging system and GPIOs. */
    timers_init();
    log_init();
    sensor_simulator_init();
    leds_init();

    zigbee_init();

    //configure_attribute_reporting();
    
    NRF_LOG_INFO("Sensor model ID: %s)", SENSOR_INIT_BASIC_MODEL_ID);

    while(1)
    {
        zboss_main_loop_iteration();
        UNUSED_RETURN_VALUE(NRF_LOG_PROCESS());
    }
}
