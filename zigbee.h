#ifndef ZIGBEE_H
#define ZIGBEE_H

//#include "zboss_api.h"
//#include "zboss_api_core.h"
//#include "zb_mem_config_med.h"
//#include "zb_zcl_reporting.h"
//#include "zb_error_handler.h"
//#include "zigbee_helpers.h"

#include "zb_multi_sensor.h"

extern sensor_device_ctx_t m_dev_ctx;

void multi_sensor_clusters_attr_init(void);


#endif // ZIGBEE_H
