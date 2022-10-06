from machine import Pin, PWM, ADC
import time

EN = Pin(2, Pin.OUT)
pwm = PWM(EN, freq=1000, duty=512)

A = Pin(4,Pin.OUT)
B = Pin(16,Pin.OUT)

while True:
    # Giramos en una direccion por tres segundos
    A.on()
    B.off()
    pwm.duty(1023) # velocidad al maximo
    time.sleep_ms(3000)
    #detemos 1 segundo
    A.off()
    B.off()
    time.sleep_ms(1000)
    # Invertimos dirección de giro
    A.off()
    B.on()
    pwm.duty(512) # Media velocidad
    time.sleep_ms(3000)
    #detemos 1 segundo
    A.off()
    B.off()
    time.sleep_ms(1000)

