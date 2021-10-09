#include<librobot.hpp>
led led1;
Buttom b1;
void setup() {
  led1.setup();
  b1.setup();
  
}
void loop() {
  //led1.blink(500);
  if(b1.read()){
    led1.on();
  }else{
    led1.off();
    }

}
