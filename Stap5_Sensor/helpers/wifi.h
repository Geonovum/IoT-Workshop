#pragma once

#include <WiFi.h>

// WiFi connection status tracking
extern bool wifiConnected;
extern unsigned long wifiStartTime;

void setupWiFi()
{
    // Non-blocking WiFi connection
    wifiStartTime = millis();
    WiFi.begin(SECRET_SSID, SECRET_PASS);
    Serial.println("Attempting to connect to WiFi...");
}

void loopWifi() { 
  // Check WiFi connection status
  if (!wifiConnected && WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.println("WiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else if (wifiConnected && WiFi.status() != WL_CONNECTED) {
    wifiConnected = false;
    Serial.println("WiFi connection lost!");
  }

  // Reconnect if connection is lost for too long
  if (!wifiConnected && (millis() - wifiStartTime > 60000)) { // 1 minute
    Serial.println("Attempting WiFi reconnection...");
    WiFi.disconnect();
    WiFi.begin(SECRET_SSID, SECRET_PASS);
    wifiStartTime = millis();
  }
}