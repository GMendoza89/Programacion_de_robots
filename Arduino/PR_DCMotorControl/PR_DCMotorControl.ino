#include<robotic.h>
dcMotor Motor1(2,3,5);

void setup(){
    Motor1.setup();
    Motor1.stop();
    Motor1.vel = 0;

}
void loop(){
    Motor1.stop();
    for(int i = 0; i<=255; i++){
        Motor1.move(MOVE_CLOCKWISE,i);
        delay(10);
    }
    Motor1.move(MOVE_CLOCKWISE,255);
    delay(3000)
    for(int i = 255; i>=0; i--){
        Motor1.move(MOVE_CLOCKWISE,i);
        delay(10);
    }
    Motor1.stop();
    delay(3000)
    for(int i = 0; i<=255; i++){
        Motor1.move(MOVE_COUNTERCLOCKWISE,i);
        delay(10);
    }
    Motor1.move(MOVE_COUNTERCLOCKWISE,255);
    delay(3000)
    for(int i = 255; i>=0; i--){
        Motor1.move(MOVE_COUNTERCLOCKWISE,i);
        delay(10);
    }
}