# structure
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
