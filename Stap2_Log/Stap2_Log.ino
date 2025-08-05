#include <WiFi.h>
#include "helpers/mac.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  uint64_t chipid = ESP.getEfuseMac();  //The chip ID is essentially its MAC address(length: 6 bytes).
  Serial.println(mac2String((byte*)&chipid));
  // lookup MAC detail with https://macaddress.io
}

void loop() {
}