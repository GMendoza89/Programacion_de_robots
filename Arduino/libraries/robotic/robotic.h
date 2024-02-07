/*
    Nombre: robotic.h
*/

#ifndef ROBOTIC_H
#define ROBOTIC_H

#include<Arduino.h>
#include<Servo.h>


#define MOVE_CLOCKWISE 0
#define MOVE_COUNTERCLOCKWISE 1

class dcMotor{
private:
    byte pinA;
    byte pinB;
    byte pinEn;

public:
    byte vel;
    dcMotor(/* args */);
    dcMotor(byte A, byte B, byte en);
    ~dcMotor();
    void setup();
    void attach(byte A, byte B, byte En);
    void move(bool direction, byte vel);
    void stop();
};

class robot_Diff
{
private:
    float tireRadious;
    float leng;
    uint8_t pinMotorR_A;
    uint8_t pinMotorR_B;
    uint8_t pinMotorR_EN;
    uint8_t pinMotorL_A;
    uint8_t pinMotorL_B;
    uint8_t pinMotorL_EN;
    void _moveMotorR(float vr);
    void _moveMotorL(float vl);
public:
    robot_Diff(/* args */);
    robot_Diff(float r, float l, uint8_t ra, uint8_t rb, uint8_t ren, uint8_t la, uint8_t lb, uint8_t len);
    ~robot_Diff();
    void setup();
    void move(float V, float W);
};

class robot_Poli_4
{
private:
    Servo Base;
    Servo J1;
    Servo J2;
    Servo EE;

public:
    robot_Poli_4(/* args */);
    ~robot_Poli_4();
};

class robot_Poli_5
{
private:
    Servo Base;
    Servo J1;
    Servo J2;
    Servo J3;
    Servo EE;

public:
    robot_Poli_5(/* args */);
    ~robot_Poli_5();
};

#endif