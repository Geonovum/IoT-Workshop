//  RCWL-1604 PIN layout  (left to right)
//  ==================================================
//   top view  DESCRIPTION     COLOR
//       +---+
//       |o  |       GND        Black
//       |o  |           
//       |o  |       VCC        RED
//       +---+
////
// Observed Properties:
// - Color
//
// Unit of Measure:
// - ???

#include <TCS3210.h>

#define S0_PIN D0
#define S1_PIN D1
#define S2_PIN D2
#define S3_PIN D3
#define DATA_PIN D4
#define OE_PIN D5 // pulled LOW by us

// Create an instance of the TCS3200 class
TCS3210 TCS(S0_PIN, S1_PIN, S2_PIN, S3_PIN, OE_PIN, DATA_PIN);

void setupSensor() {
  Serial.println("[TCS3200] Initializing...]");
  TCS.begin();
}

void loopSensor() {

  TCS.selectNone();
  Serial.print(TCS.getFrequency());
  Serial.print("\t");

  TCS.selectRed();
  Serial.print(TCS.getFrequency());
  Serial.print("\t");

  TCS.selectGreen();
  Serial.print(TCS.getFrequency());
  Serial.print("\t");

  TCS.selectBlue();
  Serial.print(TCS.getFrequency());
  Serial.print("\n");

  delay (100);
}
