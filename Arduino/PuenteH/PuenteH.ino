// Programa para controlar motores con puente H 
int Pin_EN = 3;
int Pin_A = 4;
int Pin_B = 4;

void setup() {
  pinMode(Pin_EN, OUTPUT);
  pinMode(Pin_A, OUTPUT);
  pinMode(Pin_B, OUTPUT);
  
  
}

void loop() {
  digitalWrite(Pin_A,HIGH);
  digitalWrite(Pin_B,LOW);
  analogWrite(Pin_EN,255);
  delay(3000);
  digitalWrite(Pin_A,LOW);
  digitalWrite(Pin_B,LOW);
  analogWrite(Pin_EN,255);
  delay(1000);
  digitalWrite(Pin_A,LOW);
  digitalWrite(Pin_B,HIGH);
  analogWrite(Pin_EN,127);
  delay(3000);
  digitalWrite(Pin_A,LOW);
  digitalWrite(Pin_B,LOW);
  analogWrite(Pin_EN,255);
  delay(1000);

}
