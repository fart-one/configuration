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
  initConfig();
}

String Configuration::getValue(String key) {
  return config -> operator[](key);
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
  
  JsonObject& root = _configJsonBuffer.parseObject(payload);
  config = &root;
  
  SPIFFS.end();
}


