#include "button_handler.h"

#include "zboss_api.h"
#include "zb_error_handler.h"
#include "zb_multi_sensor.h"
#include "zigbee.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

void button_handler_init(void){
  // Enable interrupt on PORT event.
  NRF_GPIOTE->INTENSET = GPIOTE_INTENSET_PORT_Msk;

  // Configure the button pin for input, pullup, and sense.
  nrf_gpio_cfg(BUTTON, GPIO_PIN_CNF_DIR_Input, GPIO_PIN_CNF_INPUT_Connect, GPIO_PIN_CNF_PULL_Pullup, GPIO_PIN_CNF_DRIVE_S0S1, GPIO_PIN_CNF_SENSE_High); //GPIO_PIN_CNF_SENSE_Low

  // Clear events that might be generated during pin configuration
  NRF_GPIOTE->EVENTS_PORT = 0;
}

void GPIOTE_IRQHandler(void){
  // If event is set
  //NRF_LOG_INFO("GPIOTE_IRQHandler");
  if (NRF_GPIOTE->EVENTS_PORT &= GPIOTE_EVENTS_PORT_EVENTS_PORT_Msk)
    {
        zb_bool_t                  comm_status;
        // Clear event
        //nrf_gpiote_event_clear(NRF_GPIOTE_EVENTS_PORT);
        NRF_GPIOTE->EVENTS_PORT = 0;
        
        // Do stuff here
        nrf_gpio_pin_toggle(USER_LED);

        NRF_LOG_INFO("Button pressed!");

        if(nrf_gpio_pin_read(12) == 0){
          NRF_LOG_INFO("Do factory reset.");
          // Do factory reset (leave network)
          zb_bdb_reset_via_local_action(0);
        }else{

        //bdb_load_factory_new(); // https://devzone.nordicsemi.com/f/nordic-q-a/62305/after-the-steering-is-successful-the-zb_bdb_is_factory_new-interface-returns-true
        if (zb_bdb_is_factory_new()){
          NRF_LOG_INFO("Device is factory new, start commissioning.");
          // Do commissioning
          comm_status = bdb_start_top_level_commissioning(ZB_BDB_NETWORK_STEERING);
          //comm_status = bdb_start_top_level_commissioning(ZB_BDB_FINDING_N_BINDING );
          ZB_COMM_STATUS_CHECK(comm_status);
        } else {
          NRF_LOG_INFO("Do factory reset.");
          // Do factory reset (leave network)
          zb_bdb_reset_via_local_action(0);
        }

        // TODO: Start timer on button press, stop timer on button release, only do action if time is longer that preset time.
        /*
        if !nrf_gpio_pin_read(BUTTON){
          
        }
        */
        }
    }
}
