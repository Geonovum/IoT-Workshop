//  MB-090 PIN layout  (left to right)
//  ==================================================
//   top view  DESCRIPTION     COLOR
//       +---+
//       |o  |       GND        Black
//       +---+
////
// Observed Properties:
// - bending angle
//
// Unit of Measure:
// - bpm

// Resistance (Kohm) will increase when bending angle increases

// Note: do not forget the 10Kohm resistor
// 3.3V --- Alpha MB090 bending sensor --- Analog pin (e.g. GPIO3) --- 10kΩ resistor --- GND

const uint8_t measurePin = A0; // analoge uitgang van versterkt microfoon signaal

const float vcc = 3.3f; // VCC

void setupSensor() {
  pinMode(measurePin, INPUT);

  Serial.println("[MB090] Alpha MB090 bending sensor ready");
}

void loopSensor() {
 // delay(200);
  
  auto value = analogRead(measurePin);

 // Serial.print("level: ");
 // Serial.println(value);

  // Optional: convert to voltage
  float voltage = value * (vcc / 4095.0);

  Serial.print("ADC Value: ");
  Serial.print(value);
  Serial.print(" - Voltage: ");
  Serial.println(voltage, 3);


//  transmitValue(value);
}
