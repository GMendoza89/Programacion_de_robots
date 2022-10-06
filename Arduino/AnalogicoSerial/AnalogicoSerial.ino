int puertoAnalogico = A0;
int valorAnalogico = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  valorAnalogico = analogRead(puertoAnalogico);

  Serial.print("Valor leido en el puerto analogico ");
  Serial.print(puertoAnalogico);
  Serial.print(": ");
  Serial.println(valorAnalogico);
  delay(500);

}
