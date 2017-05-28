/*
 * Configuration.h - Library for reading ESP configuration from JSON file from FS
 */
#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"
#include <ArduinoJson.h>
#include <string>
#include <map>

#define stringify( name ) # name
enum KEYS {
    SSID,
    WIFI_PASSWORD,
    MQTT_SERVER,
    MQTT_USER,
    MQTT_PASSWORD,
    OFFICE_ID
};

static std::map< KEYS, const char * > tag = {
	{SSID, "SSID"},
	{WIFI_PASSWORD, "wifiPassword"},
	{MQTT_SERVER, "mqttServer"},
	{MQTT_USER, "mqttUser"},
	{MQTT_PASSWORD, "mqttPassword"},
	{OFFICE_ID, "officeId"}
};

class Configuration {
  public:
    Configuration(const char* configurationFileName);
    String getValue(String key);
  private:
    //not accesible
    const char* _configurationFileName;
    StaticJsonBuffer<256> _configJsonBuffer;
    JsonObject* config;

    void initConfig();
};

#endif
