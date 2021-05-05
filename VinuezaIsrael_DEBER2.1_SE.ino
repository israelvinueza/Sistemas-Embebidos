/* 
*Universidad Técnica del Norte
*Facultad de Ingeniería en Ciencias Apicadas
*Carrera de Telecomunicaciones

*CAPÍTULO II: PUERTOS DIGITALES
*DEBER 1: Manejo de puertos configudaros como salidas
*OBJETIVO: Encender y apagar leds de manera sincrónica mediante el uso de diferentes tipos de variables
*NOMBRE: Israel Vinueza
*/
                                
const int ledred = 10;               // variable constante
const int ledblue = 11;               // variable constante
const int ledgreen = 12;               // variable constante
const int ledyellow = 13;               // variable constante

void setup() 
{
  pinMode (ledred,OUTPUT); //declaro el pin 10 como salida
  pinMode (ledblue,OUTPUT); //declaro el pin 11 como salida
  pinMode (ledgreen,OUTPUT); //declaro el pin 12 como salida
  pinMode (ledyellow,OUTPUT); //declaro el pin 13 como salida
}

void loop() 
{
    digitalWrite(ledred,HIGH);        // Envía 5v al pin 10
    delay(1000);                      // el microcontrolador se detiene 1 segundo
     digitalWrite(ledred,LOW);        // Envía 0v al pin 10
    delay(1000);                     // el microcontrolador se detiene 1 segundo
    
    digitalWrite(ledblue,HIGH);       // Envía 5v al pin 11
    delay(1000);                      // el microcontrolador se detiene 1 segundo
    digitalWrite(ledblue,LOW);       // Envía 0v al pin 11
    delay(1000);                      // el microcontrolador se detiene 1 segundo
    
    digitalWrite(ledgreen,HIGH);      // Envía 5v al pin 12
    delay(1000);                     // el microcontrolador se detiene 1 segundo
    digitalWrite(ledgreen,LOW);       // Envía 0v al pin 12
    delay(1000);                      // el microcontrolador se detiene 1 segundo

    digitalWrite(ledyellow,HIGH);    // Envía 5v al pin 13
    delay(1000);                     // el microcontrolador se detiene 1 segundo
    digitalWrite(ledyellow,LOW);       // Envía 0v al pin 13
    delay(1000);                      // el microcontrolador se detiene 1 segundo

    
}
