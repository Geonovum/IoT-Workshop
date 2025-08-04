# XIAO ESP32 C3 Pin Mapping for IoT Sensors

## Available Pins on XIAO ESP32 C3

### Digital Pins
- **D0** (GPIO0) - Available
- **D1** (GPIO1) - I2C SCL (used by I2C sensors)
- **D2** (GPIO2) - HCSR04 Trig
- **D3** (GPIO3) - HCSR04 Echo
- **D4** (GPIO4) - GPS RX
- **D5** (GPIO5) - GPS TX
- **D6** (GPIO6) - HX711 Data
- **D10** (GPIO10) - HX711 Clock

### Analog Pins
- **A0** (GPIO0) - MAX4466 Sound Sensor

### I2C Pins (Shared)
- **D1** (GPIO1) - SCL
- **D2** (GPIO2) - SDA (conflicts with HCSR04 Trig)

## Current Sensor Pin Assignments

### Active Sensors
1. **HCSR04 Distance Sensor**
   - Trig: D2
   - Echo: D3

2. **GPS Module**
   - RX: D4
   - TX: D5

3. **HX711 Weight Sensor**
   - Data: D6
   - Clock: D10

### I2C Sensors (can be used simultaneously)
- **ADXL345 Accelerometer** - Uses I2C (D1/D2)
- **AM2320 Temperature/Humidity** - Uses I2C (D1/D2)
- **MAX4466 Sound Sensor** - Uses A0

## Pin Conflicts to Avoid

⚠️ **D2 is used by both HCSR04 Trig and I2C SDA**
- Solution: Use external I2C multiplexer or choose different sensors

## Available Pins for Future Sensors
- **D0** - Available for digital sensors
- **A0** - Available for analog sensors (when MAX4466 not used)

## Recommendations

1. **For I2C sensors**: Use I2C multiplexer if you need multiple I2C sensors
2. **For digital sensors**: Use D0 for additional digital sensors
3. **For analog sensors**: A0 is available when MAX4466 is not used
4. **GPS**: Consider using hardware UART if available for better performance

## Troubleshooting

- If I2C sensors don't work, check if HCSR04 is using D2
- If GPS doesn't work, verify D4/D5 connections
- If distance sensor doesn't work, check D2/D3 connections 