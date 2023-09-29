int led = 3;

class LED
{
  private:
    unsigned int pin;  // pin asignado
  public:
    unsigned int lum; // intensidad variable
    LED(/* args */);
    LED(int p);
    ~LED();
    void attach(int p);
    void setup();
    void on();
    void off();
};

LED::LED(/* args */)
{
  pin = 13;
}
LED::LED(int p)
{
  pin = p;
}

LED::~LED()
{
  
}

void LED::attach(int p){
  pin = p;
}

void LED::setup(){
  pinMode(pin,OUTPUT);
}
void LED::on(){
  digitalWrite(pin,HIGH);
}
void LED::off(){
  digitalWrite(pin,LOW);
}



//-------------------------------------------------------------------------------------------------------------------

LED azul(3);
void setup() {
  azul.setup();

}

void loop() {
  azul.on();
  delay(500);
  azul.off();
  delay(500);
}
