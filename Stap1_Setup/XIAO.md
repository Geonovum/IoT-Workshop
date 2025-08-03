# What is Arduino

![Arduino316](https://github.com/user-attachments/assets/8df9108e-2fce-4fc7-b660-835722d35bab)

- Origineel voor kunst installaties
- Basic computer
- Standard way of programming: C

## Technische specificatie

- 32KB Flash geheugen
- 2KB SRAM
- 1KB EEPROM
- 16 MHz klok snelheid
- 14 IO digitale pins (6 analoog)
- 5V

# Ons 'Thing': Seeed Studio XIAO ESP32 C3

<img width="500" height="636" alt="board-pic" src="https://github.com/user-attachments/assets/cfa799da-872b-4a6b-b5ff-d1169de54596" />

## Technische specificatie

- 4MB Flash geheugen
- 400KB SRAM
- EEPROM Geëmuleerd
- 160 MHz klok snelheid
- 11 IO digitale pins (4 analoog)
- 3.3V (5V VBUS)
- WiFi & Bluetooth

# Structuur

Arduino intern:

``` c
main() // begin punt van uitvoering
{
  setup(); // initialisatie, wordt maar 1 keer uitgevoerd
  while (true)
  {
    loop(); // loopt voor altijd, geen initialisaties hier
  }
}
```

---

Wat wij zien:

```c
void setup()
{
}

void loop()
{
}
```

[Ga naar ArduinoIDE](ArduinoIDE.md)
