/*
 * GPS Module Test and Data Display
 * 
 * This sketch demonstrates how to use the TinyGPSPlus library to read
 * GPS data from a GPS module connected to an ESP32-C3.
 * 
 * Hardware Setup:
 * - GPS Module connected to D7 (RX) and D6 (TX)
 * - Baud rate: 9600
 * 
 * Features:
 * - Displays satellite count, HDOP, coordinates, altitude, speed, course
 * - Shows distance and direction to a reference point (Amersfoort)
 * - Monitors GPS data quality and connection status
 */

#include <TinyGPSPlus.h>
#include "helper.h"

// GPS Module Pin Configuration
#define RXPin D7          // GPS module TX connects to ESP32 D7 (RX)
#define TXPin D6          // GPS module RX connects to ESP32 D6 (TX) - optional
static const uint32_t GPSBaud = 9600;  // Standard GPS baud rate

// Reference coordinates for Amersfoort, Netherlands
static const double AMERSFOORT_LAT = 52.1561113;
static const double AMERSFOORT_LON = 5.3878266;

// The TinyGPSPlus object for parsing GPS data
TinyGPSPlus gps;

// Forward declaration of smartDelay function
static void smartDelay(unsigned long ms);

void setup()
{
  // Initialize serial communication for debugging
  Serial.begin(115200);
  while(!Serial) {
    // Wait for serial connection (useful for USB debugging)
  }
  Serial.println(F("GPS Module Test Starting..."));
  Serial.println(F("================================"));

  // Initialize GPS serial communication
  Serial1.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
  Serial.println(F("GPS Serial1 initialized"));

  // Display header information
  Serial.println(F("TinyGPSPlus Library Test"));
  Serial.print(F("Library Version: ")); 
  Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("Author: Mikal Hart"));
  Serial.println();
  
  // Print column headers for GPS data display
  Serial.println(F("GPS Data Display Format:"));
  Serial.println(F("Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
  Serial.println(F("           (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to Amersfoort  ---  RX    RX        Fail"));
  Serial.println(F("----------------------------------------------------------------------------------------------------------------------------------------"));
}

void loop()
{
  // Display GPS satellite information
  printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
  
  // Display Horizontal Dilution of Precision (HDOP) - lower is better
  printFloat(gps.hdop.hdop(), gps.hdop.isValid(), 6, 1);
  
  // Display latitude and longitude
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  
  // Display location age (how old the fix is)
  printInt(gps.location.age(), gps.location.isValid(), 5);
  
  // Display date and time from GPS
  printDateTime(gps.date, gps.time);
  
  // Display altitude in meters
  printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
  
  // Display course (heading) in degrees
  printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
  
  // Display speed in km/h
  printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
  
  // Display cardinal direction (N, NE, E, SE, S, SW, W, NW)
  printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : "*** ", 6);

  // Calculate distance to Amersfoort in kilometers
  unsigned long distanceKmToAmersfoort =
    (unsigned long)TinyGPSPlus::distanceBetween(
      gps.location.lat(),
      gps.location.lng(),
      AMERSFOORT_LAT, 
      AMERSFOORT_LON) / 1000;
  printInt(distanceKmToAmersfoort, gps.location.isValid(), 9);

  // Calculate course (bearing) to Amersfoort
  double courseToAmersfoort =
    TinyGPSPlus::courseTo(
      gps.location.lat(),
      gps.location.lng(),
      AMERSFOORT_LAT, 
      AMERSFOORT_LON);

  printFloat(courseToAmersfoort, gps.location.isValid(), 7, 2);

  // Display cardinal direction to Amersfoort
  const char *cardinalToAmersfoort = TinyGPSPlus::cardinal(courseToAmersfoort);
  printStr(gps.location.isValid() ? cardinalToAmersfoort : "*** ", 6);

  // Display GPS data quality metrics
  printInt(gps.charsProcessed(), true, 6);        // Total characters processed
  printInt(gps.sentencesWithFix(), true, 10);     // Sentences with valid fix
  printInt(gps.failedChecksum(), true, 9);        // Failed checksum count
  
  Serial.println();  // End of data line
  
  // Smart delay that feeds GPS data while waiting
  smartDelay(1000);

  // Check if GPS is receiving data (after 5 seconds)
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("WARNING: No GPS data received - check wiring and connections"));
    Serial.println(F("Make sure GPS module is powered and connected to D7 (RX)"));
  }
}

/**
 * Custom delay function that ensures GPS data is continuously processed
 * This prevents the GPS buffer from overflowing and ensures fresh data
 * 
 * @param ms Number of milliseconds to delay
 */
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    // Process any available GPS data while waiting
    while (Serial1.available()) {
      gps.encode(Serial1.read());
    }
  } while (millis() - start < ms);
}
