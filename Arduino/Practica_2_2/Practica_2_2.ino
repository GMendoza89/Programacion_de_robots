#include<EEPROM.h>

byte valor;
int index;
int indexMemory = 1022;
// int indexValue = 10;
int indexValue;
byte state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);



////
//EEPROM.put(1022,indexValue);
//EEPROM.write(0,4);
//EEPROM.write(1,6);
//EEPROM.write(2,7);
//EEPROM.write(3,3);
//EEPROM.write(4,1);
//EEPROM.write(5,0);
//EEPROM.write(6,1);
//EEPROM.write(7,3);
//EEPROM.write(8,7);
//EEPROM.write(9,6);

  Serial.print("CONFIGURACION INICIAL");
  DDRB |= B00000111;// declarando pines 8 9 y 10 como salidas
  DDRD &= B00001111;// Declarando pines 7, 6, 5, 4 como entrada
  EEPROM.get(1022,indexValue);
  index = 0;
  state = 0;

  Serial.println(index);
  Serial.println(indexValue);
  Serial.println(state);
  
  
}

void loop() {
  //Serial.print("Secuencial de lectura de estado");

  if(!digitalRead(7)){ // Boton RUN
    state = 1;
    Serial.println("RUN");
  }else if(!digitalRead(6)){ //Boton STOP
    state = 0;
    Serial.println("STOP");
  }else if(!digitalRead(4)){ //BotonWRITE
    state = 2;
    Serial.println("WRITE");
  }


  if(state == 1){
    valor = EEPROM.read(index);
    PORTB = valor;
    Serial.print("Indice [ ");
    Serial.print(index);
    Serial.print(" ] = ");
    Serial.println(valor);
    index++;
    if(index >= indexValue){
      index = 0; 
    }
    delay(250);

  }else if(state == 2){
    index = 0;
    indexValue = 1;
    valor = 0;
    while(digitalRead(4)){
      if(!digitalRead(7)){ // Boton RUN
          valor = valor+1;
        }else if(!digitalRead(6)){ //Boton STOP
          valor = valor -1;
        }else if(!digitalRead(5)){ //Boton STOP
          EEPROM.write(index,valor);
          index += 1;
          indexValue +=1;
        }
        PORTB = valor;
        Serial.println(valor);
        delay(1000);
    }
    EEPROM.put(1022,indexValue);
    index = 0;
    state = 1;
//    delay(1000);

  }else{
    Serial.print("STOP");
    delay(250);
  }
}