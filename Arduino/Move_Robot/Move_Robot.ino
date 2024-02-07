
#include<robotic.h>

robot_Diff WallE(0.13, 0.28, 7,8,5,9,10,6);

void setup(){
    WallE.setup();

}
void loop(){
    WallE.move(19.5,0);

}
