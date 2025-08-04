#pragma once

#include <TinyGPSPlus.h> // https://github.com/mikalhart/TinyGPSPlus
#include <SoftwareSerial.h>

float lat = 51.9, lng = 4.5, height = 4; // default value, overwrite

// Updated pin definitions for XIAO ESP32 C3
const uint8_t RXPin = D4;  // Changed from D5
const uint8_t TXPin = D5;  // Changed from D6
const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

// GPS timeout variables
extern unsigned long lastGPSUpdate;
bool gpsTimeoutReported = false;

void setupGPS()
{
  ss.begin(GPSBaud);
  Serial.println("GPS initialized");
}

void loopGPS()
{
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {
      // GPS data was successfully parsed
      if (gps.location.isUpdated()) {
        lat = gps.location.lat();
        lng = gps.location.lng();
        lastGPSUpdate = millis();
        gpsTimeoutReported = false; // Reset timeout flag
        
        Serial.printf("GPS: Lat=%.6f, Lng=%.6f\n", lat, lng);
      }
    }
  }
  
  // Check for GPS timeout (30 seconds without update)
  if (!gpsTimeoutReported && (millis() - lastGPSUpdate > 30000)) {
    Serial.println("GPS timeout - using default coordinates");
    gpsTimeoutReported = true;
  }
}
