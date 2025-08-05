/*
 * IoT Sensor Project - Step 5: Multi-Sensor Data Collection
 * 
 * This Arduino sketch implements a comprehensive IoT sensor system that:
 * - Connects to WiFi for data transmission
 * - Collects GPS location data
 * - Reads sensor data (currently HCSR04 distance sensor)
 * - Transmits sensor values to a remote server/cloud
 * 
 * Hardware: XIAO ESP32 C3 with various sensors
 * Author: IoT Project
 * Date: aug 2025
 */

// Include helper libraries for different system components
#include "helpers/logging.h"      // Serial communication and logging setup
#include "helpers/arduino_secrets.h"  // WiFi credentials and secrets
#include "helpers/wifi.h"         // WiFi connection management
//#include "helpers/dateTime.h"   // Time synchronization (currently disabled)
#include "helpers/gnss.h"          // GPS location tracking

// Function declaration for data transmission
void transmitValue(float value);

/*
 * SENSOR CONFIGURATION
 * 
 * Uncomment the sensor you want to use. Only one sensor can be active at a time
 * due to pin conflicts and I2C address conflicts.
 */
//#include "ADXL345.h" // 3-axis Accelerometer (I2C - conflicts with HCSR04)
//#include "HCSR04.h"  // Ultrasonic distance sensor (D2/D3 pins)
//#include "AM2320.h"  // Temperature & humidity sensor (I2C - conflicts with HCSR04)
#include "MAX4466.h" // Microphone/sound sensor (A0 pin - no conflicts)
//#include "HMC5883.h" // 3-Axis Compass Magnetometer (I2C - conflicts with HCSR04)
//#include "HX711.h"   // Weight/load cell sensor (D6/D10 pins - no conflicts)

/**
 * Setup function - runs once at startup
 * Initializes all system components in the correct order
 */
void setup()
{
  // Initialize system components
  setupLogging();    // Start serial communication at 115200 baud
  setupGPS();        // Initialize GPS module on pins D4/D5
  setupSensor();     // Initialize the selected sensor
  setupWiFi();       // Start WiFi connection process

  Serial.println("Booted");  // Confirm successful boot
}

/**
 * Transmit sensor value to remote server/cloud
 * 
 * @param value The sensor reading to transmit
 * 
 * This function handles the data transmission logic. Currently it only
 * logs the value, but can be extended to send data via HTTP POST,
 * MQTT, or other protocols.
 */
void transmitValue(float value)
{
  if (WiFi.status() == WL_CONNECTED) {
    // WiFi is connected - ready to transmit data
 //   Serial.printf("Transmitting: %.2f\n", value);
    
    // TODO: Add your data transmission code here
    // Example implementations:
    // - HTTP POST to a web server
    // - MQTT publish to a broker
    // - WebSocket connection
    // - Custom TCP/UDP protocol
  } else {
    // WiFi not connected - log the value for debugging
    Serial.printf("[WiFi] Not connected to Transmit. Value: %.2f\n", value);
  }
}

/**
 * Main loop function - runs continuously
 * 
 * This function implements a non-blocking architecture where each
 * component (WiFi, GPS, sensor) is checked and updated independently.
 * This prevents one component from blocking the others.
 */
void loop()
{
  // Check and update WiFi connection status
  loopWifi();
  
  // Read and process GPS data
  loopGPS();
  
  // Read sensor data and transmit if valid
  loopSensor();
}