# For real nu!

Dit wordt plezant, maar ook een beetje moeilijk - niet echt moeilijk, maar je moet nauwkeurig zijn!

## Eenmalige Registratie

Alvorens we onze observatie kunnen posten naar de server, moeten we eerst ons `Thing` registeren.

### Voorbeeld ADXL-345

```json
{
  "name": "???????",
  "description": "XIAO ESP32 C3",
  "properties": {},
  "Locations": [
    {
      "name": "xxx",
      "description": "yyy",
      "encodingType": "application/vnd.geo+json",
      "location": {
        "type": "Point",
        "coordinates": [
          6.020759,
          50.754699
        ]
      }
    }
  ],
  "Datastreams": [
    {
      "name": "Acceleration DS",
      "description": "Datastream for recording Acceleration",
      "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
      "unitOfMeasurement": {
        "name": "Meter per square second",
        "symbol": "m/s²",
        "definition": "https://qudt.org/vocab/unit/M-PER-SEC2"
      },
      "Sensor": {
        "@iot.id": 1
      },
      "ObservedProperty": {
        "@iot.id": 9
      }
    }
  ]
}
```

We registeren:
- Thing
- Thing's Location
- Datastream (wordt opgebouwd met `Sensor` en `ObservedProperty`)
