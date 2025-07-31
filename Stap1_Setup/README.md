# What is Arduino

# Structuur
----------------------------------------------------
-  ```void setup(){}```
     -  init 
     - only runs once
- ```void loop(){}```
  - runs indefinitly
  - **do** **not** initialize here
 ``` c
main()
{
  init();
  while (true)
  {
    loop();
  }
}
```

---

Wat wij zien:

```c

init()
{
}

loop()
{
}
```
