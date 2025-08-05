#pragma once

#include <TinyGPSPlus.h> // https://github.com/mikalhart/TinyGPSPlus

float lat = 51.9, lng = 4.5, height = 4; // default value, overwrite

// Updated pin definitions for XIAO ESP32 C3
const uint8_t RXPin = D4;  // Changed from D5
const uint8_t TXPin = D5;  // Changed from D6
const uint32_t GNSSBaud = 9600;

#define SERIALGNSS Serial1

TinyGPSPlus gnss;

// GPS timeout variables
unsigned long lastGNSSUpdate = 0;    // Timestamp of last GPS data update
bool gnssTimeoutReported = false;

void setupGNSS()
{
  Serial.println("[GNSS] initializing...");
  SERIALGNSS.begin(GNSSBaud, SERIAL_8N1, RXPin, TXPin);
  Serial.println("[GNSS] initialized");
}

void loopGNSS()
{
  while (SERIALGNSS.available() > 0) {
    if (gnss.encode(SERIALGNSS.read())) {
      // GPS data was successfully parsed
      if (gnss.location.isUpdated()) {
        lat = gnss.location.lat();
        lng = gnss.location.lng();
        lastGPSUpdate = millis();
        gpsTimeoutReported = false; // Reset timeout flag
        
        Serial.printf("[GNSS] Lat=%.6f, Lng=%.6f\n", lat, lng);
      }
    }
  }
  
  // Check for GPS timeout (30 seconds without update)
  if (!gnssTimeoutReported && (millis() - lastGNSSUpdate > 30000)) {
    Serial.println("[GNSS] Timeout - using default coordinates");
    gnssTimeoutReported = true;
  }
}
