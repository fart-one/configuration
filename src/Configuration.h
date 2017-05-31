/*
 * Configuration.h - Library for reading ESP configuration from JSON file from FS
 */
#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"
#include <ArduinoJson.h>
#include <string>
#include <map>


#define NOT_INIT 0
#define INIT 2

enum KEYS {
    SSID,
    WIFI_PASSWORD,
    MQTT_SERVER,
    MQTT_USER,
    MQTT_PASSWORD,
    OFFICE_ID
};

class Configuration {
  public:
    Configuration(const char* configurationFileName);
    String getValue(String key);
  private:
    int initialized = NOT_INIT;
    std::map< String, const char * > tag;
    const char* _configurationFileName;

    StaticJsonBuffer<256> _configJsonBuffer;
    JsonVariant _config;
    void initConfig();
    JsonObject& jsonObject() {
        return _config;
    }
};

#endif
