
#include <Wire.h>
 
void setup() {
  // Pines en modo salida
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
 
  // Unimos este dispositivo al bus I2C con dirección 1 (Esclavo 1)
  Wire.begin(1);
 
  // Registramos el evento al recibir datos
  Wire.onReceive(llegaDato);
 

}
 
void loop() {
  delay(30);
}
 
// Función que se ejecuta siempre que se reciben datos del maestro
// siempre que en el master se ejecute la sentencia endTransmission
// recibirá toda la información que hayamos pasado a través de la sentencia Wire.write
void llegaDato() {
 
  int pinOut = 0;
  int estado = 0;
 
  // Si hay dos bytes disponibles
 if (Wire.available() == 2)
   pinOut = Wire.read();
 if (Wire.available() == 1) 
    estado = Wire.read();

 
  // Activamos/desactivamos salida
  digitalWrite((pinOut),estado);
}
