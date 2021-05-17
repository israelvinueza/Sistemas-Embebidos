
/* 
*Universidad Técnica del Norte
*Facultad de Ingeniería en Ciencias Apicadas
*Carrera de Telecomunicaciones
*NOMBRE: Israel Vinueza
*
*CAPÍTULO III: Módulos de Comunicación 
*DEBER 4.1: I2C
*Este programa comunica un maestro con 3 esclavos y al precionar el boton 1 o 2 o 3 enciende los leds de cada esclavo.
*
*/

#include <Wire.h>

byte pin[] = {8,9,10};
byte estado = 0;
int ValorSensor = 0;
int input; 
void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  
    if (Serial.available()>0){
      input=Serial.read();
      if(input=='1'){  
       for (int i = 0; i < 4; i++)
    { 
    Wire.beginTransmission(1);  // Transmite al Esclavo 1
    Wire.write(pin[i]);
    Wire.write(estado);    
    Wire.endTransmission();
    }
      if (estado == 0)
  {
    estado = 1;
  }
  else
  {
    estado = 0;
  }
      }
    delay(100);
    
     if(input=='2'){  
     for (int i = 0; i < 4; i++)
    { 
    Wire.beginTransmission(2);  // Transmite al Esclavo 1
    Wire.write(pin[i]);
    Wire.write(estado);    
    Wire.endTransmission();
    }
      if (estado == 0)
  {
    estado = 1;
  }
  else
  {
    estado = 0;
  }
      }


    delay(100);
 
     if(input=='3'){  
     for (int i = 0; i < 4; i++)
    { 
    Wire.beginTransmission(3);  // Transmite al Esclavo 1
    Wire.write(pin[i]);
    Wire.write(estado);    
    Wire.endTransmission();
    }
      if (estado == 0)
  {
    estado = 1;
  }
  else
  {
    estado = 0;
  }
      }
     delay(100); 
      
    }

}
