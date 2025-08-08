const int potPin = A0;  //pin A0 to read analog input

void setupSensor() {
  pinMode(potPin, INPUT);  //Optional
}

void loopSensor() {
  delay(100);

  auto value = analogRead(potPin);      //Read and save analog value from potentiometer
  value = map(value, 0, 4094, 0, 255);  //Map value 0-1023 to 0-255 (PWM)

  // Serial.print("level: ");
  // Serial.println(value);

  transmitValue(value);
}
