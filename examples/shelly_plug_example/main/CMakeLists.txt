idf_component_register(SRCS "main.cpp"
                    INCLUDE_DIRS "."
                    REQUIRES "elrebo-de__shelly_plug"
                             "78__esp-wifi-connect"
                             "elrebo-de__wifi_manager"
                             "sachin42__httpclient"
                             "nvs_flash"
                             "esp_timer"
                             "stream")
