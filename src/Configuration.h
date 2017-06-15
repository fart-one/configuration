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

class Configuration {
  public:
    Configuration(const char* configurationFileName);
    String getValue(String key);
	const char* getAsChar(String key);
	JsonObject& jsonObject() {
        return _config;
    }
  private:
    int initialized = NOT_INIT;
    const char* _configurationFileName;

    StaticJsonBuffer<512> _configJsonBuffer;
    JsonVariant _config;
    void initConfig();
};

#endif
