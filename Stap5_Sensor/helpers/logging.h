#pragma once

void setupLogging()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Booting...");
}
