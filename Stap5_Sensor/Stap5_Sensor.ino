#include <ESP8266WiFi.h>

float lat = 51.9, lng = 4.5, height = 4; // default value, overwrite

#include "helpers/logging.h"
#include "helpers/credentials.h"
#include "helpers/dbSettings.h"
#include "helpers/wifi.h"
#include "helpers/dateTime.h"
#include "helpers/gps.h"

void transmitValue(float value);

// Uncomment the line below, corresponding with the used sensors
//#include "ADXL345.h" // 3-axis Accelerometer 
//#include "HCSR04.h"  // afstand
//#include "AM2320.h"  // temp & humidity
//#include "MAX4466.h" // geluid
//#include "HMC5883.h" // 3-Axis Kompas Magnetometer
//#include "HX711.h"   // weight

void setup()
{
  setupLogging();
  setupGPS();
  setupSensors();

  connect2Wifi(ssid, pass);
}

void transmitValue(float value)
{
  Serial.print("Connecting to SQL Server @");
  Serial.print(server);
  Serial.print(", Port =");
  Serial.println(server_port);
}

void loop()
{
  loopGPS();
  loopSensors();
}