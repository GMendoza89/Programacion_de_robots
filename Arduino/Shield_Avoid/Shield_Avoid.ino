#include<Robot_Shield_UNO.hpp>


// Clases de control
Differential_Locomotion MyRobot_Motors(0.0275,0.130,90);
Ultrasonic Frontal;
// Variables de control

byte vel_1, vel_2, vel_3;

Servo Servo_Frontal;
char Control;
long int Umbral = 15, Distancia;
long int old_time = 0;
long int present_time;
long int tiempoP;

void setup(){
    MyRobot_Motors.SETUP();
    Frontal.SETUP();
    Serial.begin(115200);
    vel_1 = 200;
    vel_2 = 3*vel_1/4;
    vel_3 = vel_1/2;
    Servo_Frontal.attach(servo_signal);
    Servo_Frontal.write(0);
    Serial.println("Robot OK");
}

void loop(){

//    Distancia = Frontal.getDistance(cm);
//    if(Distancia>Umbral){
//        MyRobot_Motors.MOVE(MOVE_FORWARD,vel_1,vel_1);
//    }else if(Distancia > 30){
//        MyRobot_Motors.MOVE(MOVE_ROTATE_M1,vel_1,vel_1);
//    }else{
//      MyRobot_Motors.MOVE(MOVE_STOP);
//    }
//    Serial.print("Distancia: ");
//    Serial.println(Distancia);

    if(Serial.available()){
      Control = Serial.read();
    }
    switch(Control){
      //Letras a utiliuzar qweasdzxc
      case 'w':
        MyRobot_Motors.MOVE(MOVE_FORWARD,vel_1,vel_1);
        break;
      case'e':
        MyRobot_Motors.MOVE(MOVE_FORWARD,vel_2,vel_3);
        break;
      case'd':
        MyRobot_Motors.MOVE(MOVE_ROTATE_M1,vel_2,vel_2);
        break;
      case'1':
        vel_1 = 50;
        vel_2 = 3*vel_1/4;
        vel_3 = vel_1/2;
      default:
        MyRobot_Motors.MOVE(MOVE_RELEASE);
        break;
    }

}
