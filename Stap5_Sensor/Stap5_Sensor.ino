float lat = 51.9, lng = 4.5, height = 4; // default value, overwrite

#include "helpers/logging.h"
#include "helpers/arduino_secrets.h"
#include "helpers/wifi.h"
//#include "helpers/dateTime.h"
#include "helpers/gps.h"

void transmitValue(float value);

// Uncomment the line below, corresponding with the used sensors
//#include "sensors/ADXL345.h" // 3-axis Accelerometer 
#include "sensors/HCSR04.h"  // afstand
//#include "sensors/AM2320.h"  // temp & humidity
//#include "sensors/MAX4466.h" // geluid
//#include "sensors/HMC5883.h" // 3-Axis Kompas Magnetometer
//#include "sensors/HX711.h"   // weight

void setup()
{
  setupLogging();
  setupGPS();
  setupSensor();

  connect2Wifi(SECRET_SSID, SECRET_PASS);
}

void transmitValue(float value)
{
}

void loop()
{
  loopWifi();
  loopGPS();
  loopSensor();
}