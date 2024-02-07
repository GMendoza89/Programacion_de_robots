#include"robotic.h"


dcMotor::dcMotor(/* args */)
{
    pinA = 8;
    pinB = 7;
    pinEn = 6;
}
dcMotor::dcMotor(byte A, byte B, byte en)
{
    pinA = A;
    pinB = B;
    pinEn = en;
}

dcMotor::~dcMotor()
{
}
void dcMotor::setup(){
    pinMode(pinA,OUTPUT);
    pinMode(pinB,OUTPUT);
    pinMode(pinEn,OUTPUT);
}
void dcMotor::move(bool direction, byte vel){
    if(!direction){
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB,LOW);
    }else{
        digitalWrite(pinB,HIGH);
        digitalWrite(pinA,LOW);
    }
    analogWrite(pinEn,vel);
}
void dcMotor::stop(){
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
    analogWrite(pinEn,0);
}

//---------------------------------------------- Clase de Robot Diferencial ------------------------------------------

robot_Diff::robot_Diff(/* args */)
{
}
robot_Diff::robot_Diff(float r, float l, uint8_t ra, uint8_t rb, uint8_t ren, uint8_t la, uint8_t lb, uint8_t len){
    tireRadious = r;
    leng = l;
    pinMotorR_A = ra;
    pinMotorR_B = rb;
    pinMotorR_EN = ren;
    pinMotorL_A = la;
    pinMotorL_B = lb;
    pinMotorL_EN = len;

}

robot_Diff::~robot_Diff()
{
}

void robot_Diff::setup(){
    pinMode(pinMotorR_A, OUTPUT);
    pinMode(pinMotorR_B, OUTPUT);
    pinMode(pinMotorR_EN, OUTPUT);
    pinMode(pinMotorL_A, OUTPUT);
    pinMode(pinMotorL_B, OUTPUT);
    pinMode(pinMotorL_EN, OUTPUT);
}
void robot_Diff::moveMotorR(float vr){
    if(vr >= 255.0){
        digitalWrite(pinMotorR_A, HIGH);
        digitalWrite(pinMotorR_B, LOW);
        analogWrite(pinMotorR_EN,255);
    }else if (vr >= 0)
    {   
        digitalWrite(pinMotorR_A, HIGH);
        digitalWrite(pinMotorR_B, LOW);
        analogWrite(pinMotorR_EN,uint8_t(vr));
    }else if (vr > - 255.0)
    {   
        digitalWrite(pinMotorR_A, LOW);
        digitalWrite(pinMotorR_B, HIGH);
        analogWrite(pinMotoR_EN,uint8_t(vr));
    }else{
         digitalWrite(pinMotorR_A, LOW);
        digitalWrite(pinMotorR_B, HIGH);
        analogWrite(pinMotorR_EN,255);

    }
    

}
void robot_Diff::moveMotorL(float vl){
    if(vl >= 255.0){
        digitalWrite(pinMotorL_A, HIGH);
        digitalWrite(pinMotorL_B, LOW);
        analogWrite(pinMotorL_EN,255);
    }else if (vl >= 0)
    {   
        digitalWrite(pinMotorL_A, HIGH);
        digitalWrite(pinMotorL_B, LOW);
        analogWrite(pinMotorL_EN,uint8_t(vr));
    }else if (vl > - 255.0)
    {   
        digitalWrite(pinMotorL_A, LOW);
        digitalWrite(pinMotorL_B, HIGH);
        analogWrite(pinMotorL_EN,uint8_t(vr));
    }else{
         digitalWrite(pinMotorL_A, LOW);
        digitalWrite(pinMotorL_B, HIGH);
        analogWrite(pinMotorL_EN,255);

    }

}

void robot_Diff::void move(float V, float W){
    float VR = V/tireRadious + W*leng/(2*tireRadious);
    float VL = V/tireRadious - W*leng/(2*tireRadious);
    _moveMotorR(VR);
    _moveMotorL(VL);
}

// -------------------------------------------- Clase de un Robot Poliarticulado de 4 grados de libertad

robot_Poli_4::robot_Poli_4(/* args */)
{
}

robot_Poli_4::~robot_Poli_4()
{
}


