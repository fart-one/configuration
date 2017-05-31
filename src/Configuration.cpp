/*
 * Configuration.cpp - Implementation for Configuration.h library.
 * Using:
 *  -> JSON using: https://github.com/bblanchon/ArduinoJson
 *  -> config upload: https://github.com/esp8266/arduino-esp8266fs-plugin
 */
#include "Arduino.h"
#include "Configuration.h"
#include <ArduinoJson.h>
#include <FS.h>

Configuration::Configuration(const char* configurationFileName) {
  _configurationFileName = configurationFileName;
  initialized = NOT_INIT;
}

String Configuration::getValue(String key) {
  Serial.println("getKey");
  if ( initialized != INIT) {
    Serial.println("INITIALIZED");
    initConfig();
  }

  Serial.println("Fetching by key");
  Serial.println(key);
  //Serial.println(tag[key]);
  //return _config[this->tag[key]];
  return _config[key];
}

void Configuration::initConfig() {
  String payload;
  
  SPIFFS.begin();
  
  if (SPIFFS.exists(_configurationFileName)) {
	  File file = SPIFFS.open(_configurationFileName, "r");
	  if (file) {
		  payload = file.readString();
	  }
	  file.close();
  }
  const char* json = "{\"SSID\" : \"myValue\"}";
  Serial.println(json);
  _config = _configJsonBuffer.parseObject(json);
  Serial.println("Got config");
  
  SPIFFS.end();
  initialized = INIT;
  Serial.println("Initialized: ");
  Serial.println(initialized);
}

std::map< KEYS, const char * > tag = {
  {SSID, "SSID"},
  {WIFI_PASSWORD, "wifiPassword"},
  {MQTT_SERVER, "mqttServer"},
  {MQTT_USER, "mqttUser"},
  {MQTT_PASSWORD, "mqttPassword"},
  {OFFICE_ID, "officeId"}
};


