#include"PR_robotlib.hpp"


LED::LED(){
      pin = 13;
      toggleTime = 500;
    }
LED::LED(uint8_t p){
      pin = p;
      toggleTime = 500;
    }
LED::LED(uint8_t p, unsigned int tT){
      pin = p;
      toggleTime = tT;
    }

LED::~LED(){}

void LED::SETUP(){
      pinMode(pin,OUTPUT);
    }
void LED::attach(uint8_t p){
      pin = p;
    }
void LED::on(){
      digitalWrite(pin,1);
    }
void LED::off(){
      digitalWrite(pin,0);
    }
void LED::toggle(){
      digitalWrite(pin,1);
      delay(toggleTime);
      digitalWrite(pin,0);
      delay(toggleTime);
    }

HCSR04::HCSR04()
{
    pinTrigger = 2;
    pinEcho = 3;

}
HCSR04::HCRS04(uint8_t trig, uint8_t echo){
    pinTrigger = trig;
    pinEcho = echo;
}

HCSR04::~HCSR04()
{
}

void HCSR04::setup(){
    pinMode(pinTrigger,OUTPUT);
    pinMode(pinEcho,INPUT);
}
void HCSR04::attach(uint8_t trig, uint8_t echo){
    pinTrigger = trig;
    pinEcho = echo;
    pinMode(pinTrigger,OUTPUT);
    pinMode(pinEcho,INPUT);
}

float HCSR04::getDistance(int unit){
    digitalWrite(pinTrigger,LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigger,LOW);
    delayMicroseconds(10);
    digitalWrite(pinTrigger,LOW);
    
    Time = pulseIn(pinEcho,HIGH);

    switch(unit){
        case 0: // mm
            Distance = (SPEED_OF_SOUND_MM*float(Time))/2.0;
            break;
        case 1: // cm
            Distance = (SPEED_OF_SOUND_CM*float(Time))/2.0;
            break;
        case 2: // m
            Distance = (SPEED_OF_SOUND_M*float(Time))/2.0;
            break;
        case 3: // Km
            Distance = (SPEED_OF_SOUND_KM*float(Time))/2.0;
            break;
        case 4: // in
            Distance = (SPEED_OF_SOUND_INCHES*float(Time))/2.0;
            break;
        case 5: // FT
            Distance = (SPEED_OF_SOUND_FT*float(Time))/2.0;
            break;
        case 6: // YT
            Distance = (SPEED_OF_SOUND_YT*float(Time))/2.0;
            break;
        case 7: // Miles
            Distance = (SPEED_OF_SOUND_MILES*float(Time))/2.0;
            break;
        default:
            Distance = (SPEED_OF_SOUND_M*float(Time))/2.0;
            break;

    }
    return Distance;
}