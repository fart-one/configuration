# Configuration Library

This project is meant to be use as parsing tool. It simply parse json from SPIFFS.

## Getting Started

Clone this repository into %ARDUINO_HOME_DIR%/libraries, and restart Arduino IDE.
New library should appear in Sketch -> attach library.

### Prequisites

As mentioned library needs some dependencies, in particular :
 *  [ArduinoJson](https://github.com/bblanchon/ArduinoJson) - Json library for Arduino
 *  [FileSystem](https://github.com/esp8266/arduino-esp8266fs-plugin) - File system for ESP8266
 
### Usage
Declare configuration globally:
```
Configuration conf("/config.json");
setup() {
..your code
}

loop() {
...your code
}
```

And now you can use it as follow:

```
conf.getValue("SSID");
```

Be aware this will return string, so in special cases when char array is needed use :
```
conf.getValue("SSID").c_str();
```
