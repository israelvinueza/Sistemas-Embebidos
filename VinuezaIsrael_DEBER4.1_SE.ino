/* 
*Universidad Técnica del Norte
*Facultad de Ingeniería en Ciencias Apicadas
*Carrera de Telecomunicaciones
*NOMBRE: Israel Vinueza
*
*CAPÍTULO III: Módulos de Comunicación 
*DEBER 4.1: CAD y PWM
*OBJETIVO: Realizar un sistema en el cual se conecten 2 motores (parecido al diagrama que se utilizo en clase). 
*Los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor.   
*A travez de la activación de un botón y un switch (el funcionamiento de un motor dependerá de la activación de un botón y 
*el otro dependerá de la activación de un switch, a su  elección) entrará en funcionamiento el motor que corresponda 
*y se visualizará en la LCD de ese motor los datos de CAD, Voltaje y PWM.

*/


#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);       //seleccion de pines para la LCD
LiquidCrystal lcd1(A3,A4,7,6,5,4);       //seleccion de pines para la LCD1
int conversor;                          //Variables para adquirir datos del conversor a voltaje
float voltaje;                          //variable de conversion de conversor a voltaje
int dutty;                              //variable para el uso de pwm

int conversor1;                          //Variables para adquirir datos del conversor a voltaje
float voltaje1;                          //variable de conversion de conversor a voltaje
int dutty1;                              //variable para el uso de pwm


const int btn=3;
const int sw=2;
void setup(){
  
  pinMode(btn,INPUT);
  pinMode(sw,INPUT);
//  pinMode(A3,OUTPUT);
//  pinMode(A4,OUTPUT);
  lcd.begin(16,2);                      //inicializa la LCD
  lcd1.begin(16,2);                      //inicializa la LCD

} 

void loop(){
  if(digitalRead(sw)==HIGH){
 conversor=analogRead(A0);              //lectura del canal A0-0-14
 voltaje=(conversor*5.0)/1023.0;        //converson de voltaje
 dutty=conversor/4;                     //cambio la escala para el dutty cicle
 analogWrite(1,dutty);                 //envio del valor al pin 11
 lcd.setCursor(0,0);
 lcd.print("CAD:");
 lcd.setCursor(5,0);
 lcd.print(conversor);
 lcd.setCursor(0,1);
 lcd.print("V:");
 lcd.setCursor(3,1);
 lcd.print(voltaje);
 lcd.setCursor(9,1);
 lcd.print("PWM:"); 
 lcd.setCursor(13,1);
 lcd.print((dutty*100)/255);
 delay(300);  
 lcd.clear();
  }
 if (digitalRead(btn)==LOW){
 conversor1=analogRead(A1);              //lectura del canal A0-0-14
 voltaje1=(conversor1*5.0)/1023.0;        //converson de voltaje
 dutty1=conversor1/4;                     //cambio la escala para el dutty cicle
 analogWrite(0,dutty1);                 //envio del valor al pin 11
 lcd1.setCursor(0,0);
 lcd1.print("CAD:");
 lcd1.setCursor(5,0);
 lcd1.print(conversor1);
 lcd1.setCursor(0,1);
 lcd1.print("V:");
 lcd1.setCursor(3,1);
 lcd1.print(voltaje1);
 lcd1.setCursor(9,1);
 lcd1.print("PWM:"); 
 lcd1.setCursor(13,1);
 lcd1.print((dutty1*100)/255);
 delay(300);  
 lcd1.clear(); 
  }
  else
  { 
 analogWrite(0,LOW); 
 analogWrite(1,LOW);    
  }
  }
