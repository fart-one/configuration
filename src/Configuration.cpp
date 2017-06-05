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
  if ( initialized != INIT) {
    initConfig();
    Serial.println("INITIALIZED");
  }
  return _config[key];
}

const char* Configuration::getAsChar(String key) {
	return getValue(key).c_str();
}

void Configuration::initConfig() {
  String payload;
  Serial.println("Starting initialization.");
  Serial.println(_configurationFileName);
  SPIFFS.begin();
  
  if (SPIFFS.exists(_configurationFileName)) {
	  Serial.println('Loading file');
	  Serial.println(_configurationFileName);
	  File file = SPIFFS.open(_configurationFileName, "r");
	  if (file) {
		  payload = file.readString();
		  Serial.println(payload);
	  }
	  file.close();
  }
  _config = _configJsonBuffer.parseObject(payload);
  if (!_config.success()) {
	  Serial.println("Error: cannot parse json");
  }
  Serial.println("Got config");
  
  SPIFFS.end();
  initialized = INIT;
  Serial.print("Initialized: ");
  Serial.println(initialized);
  Serial.print("SSID: ");
  const char* tmp = _config["SSID"];
  Serial.println(tmp);
}


