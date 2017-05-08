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

void Configuration::initConfig() {
  //log("Reading file: " + _configurationFileName);
}

//void Configuration::log(String message) {
//  if (_printer) {
//    _printer->println("its working");
//  }
//}

