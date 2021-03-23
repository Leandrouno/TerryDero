////////////////////////////////////////
//                                    //
// COMEDERO AUTOMATICO BY LEANDROUNO  //
//      25/02/2021 Version 1.0        //  
//                                    //
////////////////////////////////////////

#include <Wire.h>
#include <DS3231.h>
RTClib myRTC;

int rele = A2;
const int pulsador = A3;

void setup () {

    DateTime now = myRTC.now();
    
    Serial.begin(57600);
    Serial.println("iniciando ..."); 
    Wire.begin();
    pinMode(rele, OUTPUT);
    pinMode(pulsador,INPUT_PULLUP);
    digitalWrite(rele, LOW);

    imprimir_fecha();
}

void loop () {
  
    DateTime now = myRTC.now();
    
    if ((now.hour() == 13 && now.minute() == 00 && now.second() == 0) ||
        (now.hour() == 21 && now.minute() == 00 && now.second() == 0)){
        alimentar();      
        delay(1000);
    }

    if(digitalRead(pulsador)==LOW) {
      
      alimentar();
      delay(500);
      
      }      
}

void imprimir_fecha(){

    DateTime now = myRTC.now();
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

  
}

void alimentar () {

    Serial.println("Alimentando");
    imprimir_fecha();
    for (int i =0 ; i <4 ;i++){
        digitalWrite(rele, HIGH);
        delay(200);
        digitalWrite(rele, LOW);
        delay(200);
      }
  
}
