#include <Arduino.h>
#include <IOXESP32Motor.h>

void setup() {
  M1.begin();
  M2.begin();
}

void loop() {
  M1.forward();
  M2.backward();
  delay(1000);
  M1.stop();
  M2.stop();
  delay(1000);
}
