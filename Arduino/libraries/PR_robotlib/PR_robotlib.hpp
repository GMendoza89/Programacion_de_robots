
#ifndef PR_ROBOTLIB_HPP
#define PR_ROBOTLIB_HPP
#include<Arduino.h>

#define SPEED_OF_SOUND_M = 0.000344             # speed of sound in meters over µS
#define SPEED_OF_SOUND_CM = 0.0344              # speed of sound in centimeters over µS
#define SPEED_OF_SOUND_MM = 0.344               # speed of sound in millimeters over µS
#define SPEED_OF_SOUND_KM = 0.000000344         # speed of sound in kilometers over µS
#define SPEED_OF_SOUND_INCHES = 0.01354         # speed of sound in inches over µS
#define SPEED_OF_SOUND_FT = 0.001128            # speed of sound in foot over µS
#define SPEED_OF_SOUND_YT = 0.000376            # speed of sound in yards over µS
#define SPEED_OF_SOUND_MILES = .000000213       # speed of sound in miles over µS


class LED{
  private:
    uint8_t pin; 
  public:
    unsigned int toggleTime;
    LED();
    LED(uint8_t p);
    LED(uint8_t p, unsigned int tT);
    ~LED();
    void SETUP();
    void attach(uint8_t p);
    void on();
    void off();
    void toggle();
};

class HCSR04
{
private:
    uint8_t pinTrigger;
    uint8_t pinEcho;
    float Distance;
    unsigned int Time;

public:
    HCSR04();
    HCRS04(uint8_t trig, uint8_t echo);
    ~HCSR04();
    void setup();
    void attach(uint8_t trig, uint8_t echo);
    float getDistance(int unit);
};





#endif