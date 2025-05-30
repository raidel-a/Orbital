#ifndef WATCHY_H
#define WATCHY_H

#include <Arduino.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Arduino_JSON.h>
#include <GxEPD2_BW.h>
#include <Wire.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "DSEG7_Classic_Bold_53.h"
#include "Display.h"
#include "WatchyRTC.h"
#include "BLE.h"
#include "bma.h"
#include "config.h"
#include "esp_chip_info.h"

typedef struct weatherData {
  int8_t temperature;
  int16_t weatherConditionCode;
  bool isMetric;
  String weatherDescription;
  bool external;
  tmElements_t sunrise;
  tmElements_t sunset;
} weatherData;

typedef struct watchySettings {
  // Weather Settings
  String cityID;
  String lat;
  String lon;
  String weatherAPIKey;
  String weatherURL;
  String weatherUnit;
  String weatherLang;
  int8_t weatherUpdateInterval;
  // NTP Settings
  String ntpServer;
  int gmtOffset;
  //
  
  uint8_t vibrateOClock;
  // uint8_t vibrateLength;
} watchySettings;

class Watchy {
public:
  static WatchyRTC RTC;
  static GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> display;
  tmElements_t currentTime;
  watchySettings settings;

public:
  explicit Watchy(const watchySettings &s) : settings(s) {} // constructor
  void init(String datetime = "");
  void deepSleep();
  float getBatteryVoltage();
  uint8_t getBoardRevision();
  void vibMotor(uint8_t intervalMs = 100, uint8_t length = 20);

  virtual void handleButtonPress();
  void showMenu(byte menuIndex, bool partialRefresh);
  void showFastMenu(byte menuIndex);
  void showAbout();
  void showBuzz(byte menuIndex, bool partialRefresh);
  void showAccelerometer();
  void showUpdateFW();
  void showSyncNTP();
  bool syncNTP();
  bool syncNTP(long gmt);
  bool syncNTP(long gmt, String ntpServer);
  void setTime();
  void setupWifi();
  bool connectWiFi();
  weatherData getWeatherData();
  void updateFWBegin();
  

  void showWatchFace(bool partialRefresh);
  virtual void drawWatchFace(); // override this method for different watch
                                // faces

private:
  void _bmaConfig();
  static void _configModeCallback(WiFiManager *myWiFiManager);
  static uint16_t _readRegister(uint8_t address, uint8_t reg, uint8_t *data,
                                uint16_t len);
  static uint16_t _writeRegister(uint8_t address, uint8_t reg, uint8_t *data,
                                 uint16_t len);
  weatherData _getWeatherData(String cityID, String lat, String lon, String units, String lang,
                             String url, String apiKey, uint8_t updateInterval);                                 
};

extern RTC_DATA_ATTR int guiState;
extern RTC_DATA_ATTR int menuIndex;
extern RTC_DATA_ATTR BMA423 sensor;
extern RTC_DATA_ATTR bool WIFI_CONFIGURED;
extern RTC_DATA_ATTR bool BLE_CONFIGURED;

#endif
