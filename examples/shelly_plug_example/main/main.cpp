/*
 * Example program to use the Shelly Plug with elrebo-de/shelly_plug
 */

#include <string>
#include "shelly_plug.hpp"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/clk_tree_defs.h"

#include "nvs_flash.h"
#include "ssid_manager.h"
#include "wifi_station.h"
#include "wifi_configuration_ap.h"

static const char *tag = "ShellyPlug";

extern "C" void app_main(void)
{
      // Initialize the default event loop
      ESP_ERROR_CHECK(esp_event_loop_create_default());

      // Initialize NVS flash for Wi-Fi configuration
      esp_err_t ret = nvs_flash_init();
      if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
          ESP_ERROR_CHECK(nvs_flash_erase());
          ret = nvs_flash_init();
      }
      ESP_ERROR_CHECK(ret);

      // Get the Wi-Fi configuration
      auto& ssid_list = SsidManager::GetInstance().GetSsidList();
      if (ssid_list.empty()) {
          // Start the Wi-Fi configuration AP
          auto& ap = WifiConfigurationAp::GetInstance();
          ap.SetSsidPrefix("ESP32");
          ap.SetLanguage("de-DE");
          ap.Start();
          return;
      }

      // Otherwise, connect to the Wi-Fi network
      WifiStation::GetInstance().Start();

      vTaskDelay(30000 / portTICK_PERIOD_MS);


    /* Configure the ShellyPlug */
    {
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
}
