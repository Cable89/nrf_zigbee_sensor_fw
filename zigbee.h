#ifndef ZIGBEE_H
#define ZIGBEE_H

//#include "zboss_api.h"
//#include "zboss_api_core.h"
//#include "zb_mem_config_med.h"
//#include "zb_zcl_reporting.h"
//#include "zb_error_handler.h"
//#include "zigbee_helpers.h"

#include "boards.h"

#include "zb_multi_sensor.h"

#if !defined ZB_ED_ROLE
#error Define ZB_ED_ROLE to compile End Device source code.
#endif

#define IEEE_CHANNEL_MASK                  (1l << ZIGBEE_CHANNEL)               /**< Scan only one, predefined channel to find the coordinator. */
#define ERASE_PERSISTENT_CONFIG            ZB_FALSE                             /**< Do not erase NVRAM to save the network parameters after device reboot or power-off. */
#define ZIGBEE_NETWORK_STATE_LED           BSP_BOARD_LED_2                      /**< LED indicating that light switch successfully joind Zigbee network. */


extern sensor_device_ctx_t m_dev_ctx;

void timers_init(void);
void zigbee_init(void);
static void zb_app_timer_handler(void * context);
void zboss_signal_handler(zb_bufid_t bufid);
void multi_sensor_clusters_attr_init(void);
void configure_attribute_reporting(void);
zb_void_t report_attribute_cb(zb_uint16_t addr, zb_uint8_t ep, zb_uint16_t cluster_id,
        zb_uint16_t attr_id, zb_uint8_t attr_type, zb_uint8_t *value);

#endif // ZIGBEE_H
