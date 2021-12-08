#include<Robot_Shield_UNO.hpp>

//variablesglobales para utilizar en las funciones de los encoder

long int step_m1;
long int step_m2;

bool direction_m1; // booleano que indica el signo positivo es en direccion hacia adelante, falso es direccion contraria.
bool direction_m2;

// long int steps_m1; //pasos para estimar la posicion, el signo indica el sentido en que se ha avanzado
//long int step_m2_t;


//Funciones globales para encoder

void step_counter_M1(){
    direction_m1?++step_m1:--step_m1;
}
void step_counter_M2(){
    direction_m2?++step_m2:--step_m2;
}

//------------------------------------ Clase Motor en DC --------------------------------------------------------
dcMotor::dcMotor(bool motor){
    if(motor){
        A = Motor_1_A;
        B = Motor_1_B;
        EN = En_Motor_1;
    }else{
        A = Motor_2_A;
        B = Motor_2_B;
        EN = En_Motor_2;
    }
}
dcMotor::~dcMotor(){

}
void dcMotor::setup(){
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(EN,OUTPUT);
}
void dcMotor::move(int M){
    switch (M)
    {
    case MOVE_RELEASE:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        analogWrite(EN,0);
        break;
    case MOVE_FORWARD:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        analogWrite(EN,128);
        break;
    case MOVE_BACKWARD:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        analogWrite(EN,128);
        break;

    case MOVE_STOP:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        analogWrite(EN,255);
        break;
    
    default:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        analogWrite(EN,0);
        break;
    }
}

void dcMotor::move(int M,byte p){
    switch (M)
    {
    case MOVE_RELEASE:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        analogWrite(EN,0);
        break;
    case MOVE_FORWARD:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        analogWrite(EN,p);
        break;
    case MOVE_BACKWARD:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        analogWrite(EN,p);
        break;

    case MOVE_STOP:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        analogWrite(EN,255);
        break;
    
    default:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        analogWrite(EN,0);
        break;
    }
}
//------------------------------------- Clase del sistema locomotor ----------------------------------------------
Differential_Locomotion::Differential_Locomotion(){
    radius = 0;
    length = 0;
    step_per_radius = 20;
}
Differential_Locomotion::Differential_Locomotion(double r, double l){
    radius = r;
    length = l;
    step_per_radius = 20;
}
Differential_Locomotion::Differential_Locomotion(double r, double l, long int N){
    radius =r;
    length = l;
    step_per_radius = N;
}

Differential_Locomotion::~Differential_Locomotion(){

}
void Differential_Locomotion::SETUP(){
    pinMode(Motor_1_A,OUTPUT);
    pinMode(Motor_1_B,OUTPUT);
    pinMode(Motor_2_A,OUTPUT);
    pinMode(Motor_2_B,OUTPUT);

    pinMode(En_Motor_1,OUTPUT);
    pinMode(En_Motor_2,OUTPUT);
}
void Differential_Locomotion::SETUP_Odom(){
    attachInterrupt(digitalPinToInterrupt(I_Endoder_1),step_counter_M1,FALLING);
    attachInterrupt(digitalPinToInterrupt(I_Endoder_2),step_counter_M2,FALLING); 
    delta_M2_steps = 0; 
    delta_M1_steps = 0;
    M1_steps_past = 0;
    M2_steps_past = 0;                         
    Vm2 = 0; 
    Vm1 = 0; 
    base_Distance = 0;                                                 
    M2_distance=0; 
    M1_distance= 0;
    M2_distance_past=0; 
    M1_distance_past=0;
    x = 0;
    y = 0;
    theta = 0;
}
void Differential_Locomotion::MOVE(int move){

    analogWrite(En_Motor_1,100);
    analogWrite(En_Motor_2,100);
    
    switch (move)
    {
    case MOVE_RELEASE:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    
    case MOVE_FORWARD:
        
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,LOW);
        direction_m1 = true;
        direction_m2 = true;
        break;
    case MOVE_BACKWARD:
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
        direction_m1 = false;
        direction_m2 = false;
        break;
    case MOVE_STOP:       
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,HIGH);
        break;
    case MOVE_ROTATE_M1:       
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
        direction_m1 = true;
        direction_m2 = false;
        break;
    case MOVE_ROTATE_M2:       
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,LOW);
        direction_m1 = false;
        direction_m2 = true;
        break;
    default:
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    }
}
void Differential_Locomotion::MOVE(int move, byte PM1, byte PM2){

    analogWrite(En_Motor_1,PM1);
    analogWrite(En_Motor_2,PM2);
    
    switch (move)
    {
    case MOVE_RELEASE:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    
    case MOVE_FORWARD:
        
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,LOW);
        direction_m1 = true;
        direction_m2 = true;
        break;

    case MOVE_BACKWARD:
        
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
        direction_m1 = false;
        direction_m2 = false;
        break;
    case MOVE_STOP:       
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,HIGH);
        break;
    case MOVE_ROTATE_M1:       
        digitalWrite(Motor_1_A,HIGH);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,HIGH);
        direction_m1 = false;
        direction_m2 = true;
        break;
    case MOVE_ROTATE_M2:       
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,HIGH);
        digitalWrite(Motor_2_A,HIGH);
        digitalWrite(Motor_2_B,LOW);
        break;
    default:
        digitalWrite(Motor_1_A,LOW);
        digitalWrite(Motor_1_B,LOW);
        digitalWrite(Motor_2_A,LOW);
        digitalWrite(Motor_2_B,LOW);
        break;
    }
}
void Differential_Locomotion::Odom(){
    delta_M2_steps = step_m2 - M2_steps_past;                                 // calculo cambio pasos
    delta_M1_steps = step_m1 - M1_steps_past;
    M1_distance = pi*2*radius*(delta_M1_steps/((double)step_per_radius));    // Distancia L
    M2_distance = pi*2*radius*(delta_M2_steps/((double)step_per_radius));    // Distancia R
    base_Distance = (M2_distance+M1_distance)/2;                              // distancia de la base del robot
    x += base_Distance*cos(theta);
    y += base_Distance*sin(theta);
    theta += (M2_distance - M1_distance)/length;
    theta = atan2(sin(theta),cos(theta));
    M2_steps_past = step_m2;
    M1_steps_past = step_m1;
}

void Differential_Locomotion::Vel(){
    Vm2 = 1000*(M2_distance)/Salmple_Time;
    Vm1 = 1000*(M1_distance)/Salmple_Time;
    Serial.print(Vm2);
    Serial.print(",");
    Serial.println(Vm1);
}
double Differential_Locomotion::GetX(){
    return x;
}
double Differential_Locomotion::GetY(){
    return y;
}
double Differential_Locomotion::GetTheta(){
    return theta;
}
double Differential_Locomotion::VelM1(){
    return 1000*(M1_distance)/Salmple_Time;
}
double Differential_Locomotion::VelM2(){
    return 1000*(M2_distance)/Salmple_Time;
}

//------------------------------ Ultrasonic class ------------------------------------------------------------------

Ultrasonic::Ultrasonic(){
    Distance = 0;
    Time = 0;
}
Ultrasonic::~Ultrasonic(){
    
}
void Ultrasonic::SETUP(){
    pinMode(TRIG,OUTPUT);
    pinMode(ECHO,INPUT);
}

float Ultrasonic::getDistance(int units){

    digitalWrite(TRIG,LOW);
    delay(2);
    digitalWrite(TRIG,HIGH);
    delay(10);
    digitalWrite(TRIG,LOW);

    Time = pulseIn(ECHO,HIGH);

    switch (units)
    {
    case mm:
        Distance = Sound_speed_mm*Time/2;    
        break;
    
    case cm:
        Distance = Sound_speed_cm*Time/2;    
        break;

    case m:
        Distance = Sound_speed_m*Time/2;    
        break;

    default:
        Distance = -1;
        break;
    }
    return Distance;
    

}