# XIAO ESP32 C3 pin mapping voor IOT sensors 

## beschikbaare pins op de  XIAO ESP32 C3

###  Pins
|Arduino pin|Secundaire functie|
|-----------|------------------|
|D0         |A0                |
|D1         |A1                |
|D2         |A2                |
|D3         |~~A3~~            |
|D4         |SDA               |
|D5         |SCL               |
|D6         |TX                |
|D7         |RX                |
|D8         |SCK               |
|D9         |MISO              |
|D8         |MOSI              |


<img width="1280" height="720" alt="pinout" src="https://github.com/user-attachments/assets/a6064d04-ae5c-48ec-a730-a7bcbca52d6e" />

#   Sensor pins
##  HCSR04 afstands sensor Sensor
- Trig: D2
- Echo: D3
## GPS Module
- RX: D4
- TX: D5
## HX711 gewichts sensor
- Data: D6
- Clock: D10

## I2C Sensors
- ADXL345 Accelerometer - D1/D2
- AM2320 Temperature/Humidity - D1/D2
## analog sensors 
- MAX4466 Sound Sensor - A0
# Gevaren
- 3V3 sensors
- **niet aan vbus**
- wanneer aangesloten laten checken!


