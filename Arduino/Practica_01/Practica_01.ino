#include<EEPROM.h>


byte data;
byte state;
byte dataOut;
unsigned int dataAddress;
byte instructions;
byte readB = B00000000;
byte readD = B00000000;

void setup() {
  //Configure intputs and outputs pins
  DDRB |= B00111100; // declaracion de salidas en el puerto B
  DDRB &=B11111100; //Declaración de entradas en el puerto 
  DDRD |= B00000100;
  DDRD &=!B11111000;
  //state machine initial position
  state = 0;
  // read total of intructions
  instructions = EEPROM.read(500);
  // initial instruction
  dataAddress = 0;
  Serial.begin(9600);
}

void loop() {
  //check push butom
  if(!digitalRead(5)){
    state = 1;
  }else if(!digitalRead(4)){
    state = 0;    
  }else if(!digitalRead(3)){
    state = 2;    
  }
  
  switch(state){
    case 0: // Stop
      PORTD |= B00000100;
      delay(500);
      PORTD &= B11111011;
      delay(500);
      break;
     case 1: // RUN
      //PORTD = 00000100;
      data = EEPROM.read(dataAddress);
      bitWrite(dataOut,5,bitRead(data,3));
      bitWrite(dataOut,4,bitRead(data,2));
      bitWrite(dataOut,3,bitRead(data,1));
      bitWrite(dataOut,2,bitRead(data,0));
      PORTB = dataOut;
      Serial.print(" Dato: ");
      Serial.println(dataOut);
      Serial.print(" direccion: ");
      Serial.println(dataAddress);
      delay(250);
      if(dataAddress<instructions-1){
        ++dataAddress;
      }else{
        dataAddress = 0;
      }
      break;
    case 2: //Write
      dataAddress = 0;
      instructions = 0;
      Serial.println("inicializando guardado de secuencia");
      while(digitalRead(5)){
        if(!digitalRead(4)){
          Serial.print("Guardando movimiento");
          readB = PORTB;
          readD = PORTD;
          data = 0X00;
          Serial.print(" Dato: ");
          Serial.println(data);
          bitWrite(data,3,!digitalRead(9));
          bitWrite(data,2,!digitalRead(8));
          bitWrite(data,1,!digitalRead(7));
          bitWrite(data,0,!digitalRead(6));
          EEPROM.write(dataAddress,data);
          Serial.print(" Dato: ");
          Serial.println(data);
          Serial.print(" direccion: ");
          Serial.println(dataAddress);
          ++dataAddress;
          ++instructions;
          Serial.print(" Total de intrucciones: ");
          Serial.println(instructions);
          
        }
        //Serial.print("Guardando movimiento");
        delay(10);
   
      }
      EEPROM.write(500,instructions);
      dataAddress = 0;
      state = 1;
      break;
    default:
      PORTB &= !B00111100;
      PORTD &= !B00000100;
      delay(10);
      break;
  }
}
