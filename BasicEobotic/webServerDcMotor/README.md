# DC motor controller


## surcuit design


```
ESP32              Motor Driver (L298N / TB6612FNG)
  --------            -------------------------------
  3.3V      ──────────>  VCC (logic)
  GND       ──────────>  GND
  GPIO 4    ──────────>  STBY
  GPIO 25   ──────────>  AIN1
  GPIO 26   ──────────>  AIN2
  GPIO 33   ──────────>  PWMA
  9V Battery + ───────>  VM (motor power)
  9V Battery - ───────>  GND (shared)
  Motor +    ──────────>  AO1
  Motor -    ──────────>  AO2
``` 