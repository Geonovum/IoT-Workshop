#pragma once

#include <WiFi.h>

// WiFi connection status tracking
extern bool wifiConnected;
extern unsigned long wifiStartTime;

void setupWiFi() {
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
    Serial.print("MAC address: ");
    Serial.println(mac2String((byte *)&chipid));
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

String mac2String(byte ar[]) {
  String s;
  for (byte i = 0; i < 6; ++i) {
    char buf[3];
    sprintf(buf, "%02X", ar[i]); // J-M-L: slight modification, added the 0 in
                                 // the format for padding
    s += buf;
    if (i < 5)
      s += ':';
  }
  return s;
}
