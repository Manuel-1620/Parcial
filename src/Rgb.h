#include <Arduino.h>

class Rgb {
private:
  int CambioDeOperacion ;
  bool estadoAnteriorBoton;
  bool estadoPulsador;
  int BotonRed;
  int BotonGreen ;
  int BotonBlue ;
  int contadorRed;
  int contadorGreen;
  int contadorBlue;

public:
  Rgb();
  void aumentarContador(int &contador, int pin);
  void disminuirContador(int &contador, int pin); 
  void setup();
  void loop();
};