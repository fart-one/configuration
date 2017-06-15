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
  initialized = CONFIGURATION_NOT_INIT;
}

String Configuration::getValue(String key) {
  if ( initialized != CONFIGURATION_INIT) {
    initConfig();
  }
  return _config[key];
}

const char* Configuration::getAsChar(String key) {
	return getValue(key).c_str();
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
  _config = _configJsonBuffer.parseObject(payload);
  if (!_config.success()) {
	  Serial.println("Error: cannot parse json");
  }
  
  SPIFFS.end();
  initialized = CONFIGURATION_INIT;
}


