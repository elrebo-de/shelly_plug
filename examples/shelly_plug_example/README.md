## Shelly Plug Example

This example demonstrates how to utilize the `shelly_plug` component to use the shelly plug.

## Hardware

* A shelly plug with an IP address in the connected WLAN is needed in this example.

## Build and Flash

Build the project and flash it to the board, then run the monitor tool to view the serial output:

* Run `. <directory with ESP-IDF version>/export.sh` to set IDF environment
* Run `idf.py set-target esp32xx` to set target chip
* Run `idf.py -p PORT flash monitor` to build, flash and monitor the project

(To exit the serial monitor, type `Ctrl-]` (or on a Mac `Ctrl-Option-6`).

See the Getting Started Guide for all the steps to configure and use the ESP-IDF to build projects.

## Example Output

```
I (5833) WifiStation: Got IP: 192.168.178.113
I (5833) esp_netif_handlers: sta ip: 192.168.178.113, mask: 255.255.255.0, gw: 192.168.178.1
I (30653) shellyWozi: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=false
I (30673) shellyWozi: HTTP GET code: 200
I (30673) shellyWozi: HTTP GET successful. Response:
I (31683) shellyWozi: {"was_on":false}
I (31683) shellyWozi: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=true&toggle_after=5
I (31703) shellyWozi: HTTP GET code: 200
I (31703) shellyWozi: HTTP GET successful. Response:
I (32703) shellyWozi: {"was_on":false}
I (42703) shellyWozi: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=true
I (42723) shellyWozi: HTTP GET code: 200
I (42723) shellyWozi: HTTP GET successful. Response:
I (43723) shellyWozi: {"was_on":false}
I (48723) shellyWozi: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=false
I (48743) shellyWozi: HTTP GET code: 200
I (48743) shellyWozi: HTTP GET successful. Response:
I (49743) shellyWozi: {"was_on":true}
I (54743) shellyWozi: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=true
I (54763) shellyWozi: HTTP GET code: 200
I (54763) shellyWozi: HTTP GET successful. Response:
I (55763) shellyWozi: {"was_on":false}
I (60763) shellyWozi: ShellyPlug Command: http://192.168.178.102/rpc/Switch.Set?id=0&on=false
I (60783) shellyWozi: HTTP GET code: 200
I (60783) shellyWozi: HTTP GET successful. Response:
I (61783) shellyWozi: {"was_on":true}
I (61783) main_task: Returned from app_main()
```