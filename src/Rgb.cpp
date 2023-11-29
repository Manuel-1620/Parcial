#include <Rgb.h>


Rgb::Rgb(){
  CambioDeOperacion = 35;
  estadoAnteriorBoton = HIGH;
  estadoPulsador = false;
  BotonRed = 36;
  BotonGreen = 39;
  BotonBlue = 34;
  contadorRed = 0;
  contadorGreen = 0;
  contadorBlue = 0;

}

void Rgb::aumentarContador(int &contador, int pin) {
    contador += 10;
    analogWrite(pin, contador);
    delay(100);
    if (contador > 255) {
      contador = 255;
      analogWrite(pin, contador);
    }
}

void Rgb::disminuirContador(int &contador, int pin) {
    contador -= 10;
    analogWrite(pin, contador);
    delay(100);
    if (contador < 0) {
      contador = 0;
      analogWrite(pin, contador);
    }
}

void Rgb::setup() {
    Serial.begin(9600);
    pinMode(CambioDeOperacion, INPUT_PULLUP);
    pinMode(BotonGreen, INPUT_PULLUP);
    pinMode(BotonRed, INPUT_PULLUP);
    pinMode(BotonBlue, INPUT_PULLUP);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(25, OUTPUT);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(25, LOW);
}

void Rgb::loop() {
    int estadoBoton = digitalRead(CambioDeOperacion);
    int estado1 = digitalRead(BotonRed);
    int estado2 = digitalRead(BotonGreen);
    int estado3 = digitalRead(BotonBlue);

    if (estadoBoton != estadoAnteriorBoton) {
      estadoBoton = digitalRead(CambioDeOperacion);

      if (estadoBoton == 0) {
        if (!estadoPulsador) {
          estadoPulsador = true;
          Serial.println("BAJAR INTENSIDAD");
        } else {
          estadoPulsador = false;
          Serial.println("SUBIR INTENSIDAD");
        }
      }
    }
    if (estado1 == 1 && estadoPulsador == 1) {
      disminuirContador(contadorRed, 32);
    } else if (estado1 == 1 && estadoPulsador == 0) {
      aumentarContador(contadorRed, 32);
    } else if (estado2 == 1 && estadoPulsador == 1) {
      disminuirContador(contadorGreen, 33);
    } else if (estado2 == 1 && estadoPulsador == 0) {
      aumentarContador(contadorGreen, 33);
    } else if (estado3 == 1 && estadoPulsador == 1) {
      disminuirContador(contadorBlue, 25);
    } else if (estado3 == 1 && estadoPulsador == 0) {
      aumentarContador(contadorBlue, 25);
    }

    Serial.println(estadoPulsador);
    Serial.println("Valores");
    Serial.print(contadorRed);
    Serial.print(" ");
    Serial.print(contadorGreen);
    Serial.print(" ");
    Serial.print(contadorBlue);
    Serial.print(" ");
    delay(250);
    estadoAnteriorBoton = estadoBoton;
};
