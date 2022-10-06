# Programa de combersion Analogico digital

from machine import Pin, PWM, ADC
import time

adc = ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

while True:
    print(adc.read())
    time.sleep_ms(50)

