Using nRF5_SDK_for_Thread_and_Zigbee_v4.0.0_dc7186b
path: nRF5_SDK_for_Thread_and_Zigbee_v4.0.0_dc7186b\examples\zigbee\experimental\




Zigbee2mqtt zigbee-herdsman-converter entry
```
{
    zigbeeModel: ['NRF_Multisensor'],
    model: 'NRF example multisensor',
    vendor: 'Nordic Semoconductor',
    description: 'Example nRF sensor',
    supports: 'temperature, pressure',
    fromZigbee: [fz.temperature],
    toZigbee: [],
    meta: {configureKey: 1},
    configure: async (device, coordinatorendpoint) => {
        const endpoint = device.getEndpoint(10);
        const binds = ['msTemperatureMeasurement'];
        await bind(endpoint, coordinatorEndpoint, binds);
        await configureReporting.temperature(endpoint);
    },
},
```