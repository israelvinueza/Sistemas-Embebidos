/* 
*   Universidad Técnica del Norte
*Facultad de Ingeniería en Ciencias Apicadas
*   Carrera de Telecomunicaciones
*       Sistemas Embebidos
*       
*NOMBRE: Israel Vinueza
*
*DEBER 5.1: Funciones Específicas - Memoria EEPROM
*OBJETIVO:  Realizar la escritura de la memoria EEPROM a travez de un teclado matricial
*/
#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,7,6,5,4);
byte leerdato=0x00;        //variable que lee el dato
byte bandera=0;           //variable que se activa cuando sucede la interrupcion
int direccion=0;          //variable que indica la dirección de la EEPROM
char lectura=0;



void setup() {
pinMode(2,INPUT);                                           //configura una interrupción
attachInterrupt(digitalPinToInterrupt(2),teclado,RISING);  
DDRD=B11111011;   //declara el puerto D como entradas y salidas para recibir los datos del decodificador del teclado
pinMode(3,OUTPUT); //Se apaga el decodificador del teclado
digitalWrite(3,HIGH);
lcd.begin(16,2);  //se inicializa la LCD

}

void loop() {
  if(bandera==1){
    lcd.setCursor(0,0);  //posicion en la pantalla del LCD
    digitalWrite(1,LOW);   //se apaga la LCD
    digitalWrite(3,LOW);    // se enciende el decodificador del teclado
    
   // se decodifican las teclas para convertirlas en caracteres
    DDRD=B00001011;  
    leerdato=PIND&0xF0;
    leerdato=(leerdato<<4)|(leerdato>>4);
    EEPROM.put(direccion,leerdato);
    direccion++;

   //Se apaga el decodificador del teclado
    digitalWrite(3,HIGH);
    DDRD=B11111011;

    decodificar();
  // al presionar el * en el teclado nos muestra los datos guardados en la EEPROM
    if(lectura==1){
      for(direccion=direccion-1;direccion>=0;direccion--){//muestra datos de posicion menor a maoyor de derecha a izquierda en la LCD
        leerdato=EEPROM.read(direccion);//Lee el dato guarado en la EEPROM
        decodificar();
      }
      direccion=0;
      lectura=0;
    }
    bandera=0;
  }

}

void teclado(){//funcion que se ejecuta para activar a interrupcion
  bandera=1;
}

void decodificar(){ //funcion para decodificar el teclado ingresar las teclas
  if(leerdato==0x00){
    lcd.print("1");
  }else 
  if(leerdato==0x01){
    lcd.print("2");
  }else
  if(leerdato==0x02){
    lcd.print("3");
  }else
  if(leerdato==0x03){
    lcd.print("A");
  }else
  if(leerdato==0x04){
    lcd.print("4");
  }else
  if(leerdato==0x05){
    lcd.print("5");
  }else
  if(leerdato==0x06){
    lcd.print("6");
  }else
  if(leerdato==0x07){
    lcd.print("B");
  }else
  if(leerdato==0x08){
    lcd.print("7");
  }else
  if(leerdato==0x09){
    lcd.print("8");
  }else
  if(leerdato==0x0A){
    lcd.print("9");
  }else
  if(leerdato==0x0B){
    lcd.print("C");
  }else
  if(leerdato==0x0C){
    lectura=1;       // Al presionar el asterisco se activa la lextura de la EEPROM
  }else
  if(leerdato==0x0D){
    lcd.print("0");
  }else
  if(leerdato==0x0E){
    lcd.print("=");
  }else
  if(leerdato==0x0F){
    lcd.print("D");
  }else{
    lcd.print("NINGUN REGISTRO");
  } 
}
