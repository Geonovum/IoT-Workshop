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

# Ons 'Thing': LOLIN Wemos ESP32 C3 v2.1.0

![esp32c3](https://github.com/user-attachments/assets/10de5017-6816-4a8f-a801-416655730d11)

## Technische specificatie

- 4MB Flash geheugen
- 400KB SRAM
- EEPROM Geëmuleerd
- 160 MHz klok snelheid
- 14 IO digitale pins (6 analoog)
- 3.3V (5V VBUS)

# Structuur

Arduino intern:

``` c
main() // begin punt van uitvoering
{
  init(); // initialisatie, wordt maar 1 keer uitgevoerd
  while (true)
  {
    loop(); // loopt voor altijd, geen initialisaties hier
  }
}
```

---

Wat wij zien:

```c
void init()
{
}

void loop()
{
}
```
