# What is Arduino

# Structuur

``` c
main()
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
