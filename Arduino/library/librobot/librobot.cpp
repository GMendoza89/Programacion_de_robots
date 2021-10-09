#include<librobot.hpp>

led::led(/* args */)
{
    pin = 13;
}
led::led(byte p)
{
    pin = p;
}
led::~led()
{

}
void led::setup(){
    pinMode(pin,OUTPUT);
}
void led::on(){
    digitalWrite(pin,HIGH);
}
void led::off(){
    digitalWrite(pin,LOW);
}

void led::blink(unsigned int frec){
    digitalWrite(pin,HIGH);
    delay(frec);
    digitalWrite(pin,LOW);
    delay(frec);
}

Buttom::Buttom(/* args */)
{
    pin = 2;
}

Buttom::Buttom(byte p)
{
    pin = p;
}
Buttom::~Buttom()
{
}
void Buttom::setup(){
    pinMode(pin,INPUT);
}
bool Buttom::read(){
    return digitalRead(pin);
}