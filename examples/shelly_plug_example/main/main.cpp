/*
 * Example program to use the Shelly Plug with elrebo-de/shelly_plug
 */

#include <string>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//#include "soc/clk_tree_defs.h"

#include "wifi_manager.hpp"
#include "shelly_plug.hpp"

static const char *tag = "ShellyPlug";

extern "C" void app_main(void)
{
    Wifi wifi( std::string("WifiManager"), // tag for ESP_LOGx
               std::string("ESP32"),       // ssid_prefix for configuration access point
               std::string("de-DE")        // language for configuration access point
             );

    /* Configure the ShellyPlug */
    std::string ipAddrShellyPlug = std::string("192.168.178.102");

    ShellyPlug shellyWozi(std::string("shellyWozi"), ipAddrShellyPlug);

    if (shellyWozi.GetLastHttpCode() != HTTP_CODE_OK) {
        ESP_LOGI(tag, "No Shelly Plug at IPAddr %s", ipAddrShellyPlug.c_str());
    }
    else {
        shellyWozi.Switch(true, (uint16_t) 5);
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        shellyWozi.Switch(true);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        shellyWozi.Switch(false);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        shellyWozi.Toggle();
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        shellyWozi.Toggle();
    }
}
