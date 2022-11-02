#include<EEPROM.h>

byte valor;
int index;
int indexMemory = 1022;
int indexValue = 10;

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

Serial.print("Secuencia Guardada");
  EEPROM.get(1022,indexValue);
  index = 0;
  DDRB |= B00000111;// declarando pines 8 9 y 10 como salidas

}

void loop() {
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
  

}
