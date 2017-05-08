/*
 * Configuration.h - Library for reading ESP configuration from JSON file from FS
 */
#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"
#include <ArduinoJson.h>

class Configuration {
  public:
    Configuration(const char* configurationFileName);
   // Configuration(const char* configurationFileName, Print &print);
    const char* getWifiSSID();
    const char* getWifiPassword();
    const char* getMqttServer();
    const char* getMqttUser();
    const char* getMqttPassword();
    const char* getOfficeId();
  private:
    //accesible by getter method
    const char* _wifiSSID;
    const char* _wifiPassword;
    const char* _mqttServer;
    const char* _mqttUser;
    const char* _mqttPassword;
    const char* _officeId;

    //not accesible
    const char* _configurationFileName;
    StaticJsonBuffer<256> _configJsonBuffer;
    //Print& _printer;

    //private methods
    //void log(String message);
    void initConfig();
};

#endif
