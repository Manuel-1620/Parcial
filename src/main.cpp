#include <Arduino.h>
#include <Rgb.h>

Rgb colores;
void setup() {
  colores.setup(); 
}

void loop() {
  colores.loop();
}