# Shelly Plug component

This repository contains an ESP-IDF component for the Shelly Plug. It runs on
any ESP32 processor and is built using the ESP-IDF build system in version 6.0.

The component is implemented as C++ class `ShellyPlug`.

It depends on ESP Component sachin42/httpclient.
The example depends on ESP component 78/esp-wifi-connect for the Wifi connection.

Because there are incompatibilities of httpclient with ESP-IDF version 6.0 it is
added as a component to the example.

Because there are incompatibilities of esp-wifi-connect with ESP-IDF version 6.0 it is
added as a component to the example.

## Connecting the component

The constructor of class `ShellyPlug` has two parameters:

| Parameter    | Type of Parameter | Usage                             |
|:-------------|:------------------|:----------------------------------|
| tag          | std::string       | the tag to be used in the ESP log |
| ipAddr       | std::string       | the IP Address of the Shelly Plug |

Currently only a http connection to an IP address can be used.

# Usage

The Shelly Plug can be switched on/off with method `Switch` and method `Toggle` of class `ShellyPlug`.

The method `Switch` has two variants. One simply sets the new `switchState`, the second variant uses a second parameter 
`toggleAfter` which toggles back the switchState of the plug after the given nr of seconds.

## API
The API of the component is located in the include directory ```include/shelly_plug.hpp``` and defines the
C++ class ```ShellyPlug```

```C
class ShellyPlug {
public:
    ShellyPlug(std::string tag, std::string ipAddr);
    virtual ~ShellyPlug();
    void Toggle();
    void Switch(bool switchState);
    void Switch(bool switchState, uint16_t toggleAfter);

private:	
    std::string tag = "ShellyPlug";
    bool switchState; // the switch state of the shelly plug
    std::string ipAddr;
    HTTPClient *shellyPlug;
};
```

# License

This component is provided under the Apache 2.0 license.
