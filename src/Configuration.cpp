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
  //_printer = Serial;
  initConfig();
}

/*Configuration::Configuration(const char* configurationFileName, Print &print) {
  _configurationFileName = configurationFileName;
  //_printer = &print;
  init();
}*/

const char* Configuration::getWifiSSID() {
	return _wifiSSID;
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
  } else {
	  //TODO Serial.println()
  }
  
  JsonObject& root = _configJsonBuffer.parseObject(payload);
  
  SPIFFS.end();
  
  _wifiSSID = root["SSID"];
  _wifiPassword = root["wifiPassword"];
  _mqttServer = root["mqttServer"];
  _mqttUser = root["mqttUser"];
  _mqttPassword = root["mqttPassword"];
  _officeId = root["officeId"];
}

//void Configuration::log(String message) {
//  if (_printer) {
//    _printer->println("its working");
//  }
//}

