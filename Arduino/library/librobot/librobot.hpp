/*
*   Name: Libreria de componentes de Robot

*   Description: Componentes para operar un robot
*   Autor: Ing. Gustavo David Mendoza Pinto
*
*
*/
#ifndef LIBROBOT
#define LIBROBOT


#include<Arduino.h>

class led
{
private:
    /* data */
    byte pin;
public:
    led(/* args */);
    led(byte p);
    ~led();

    void on();
    void off();
    void setup();
    void blink(unsigned int frec);

};

class Buttom
{
private:
    byte pin;
public:
    Buttom(/* args */);
    Buttom(byte p);
    ~Buttom();

    void setup();
    bool read();
};





#endif