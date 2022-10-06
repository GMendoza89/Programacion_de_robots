# Control de recorrido de un Servo SG 90

from machine import Pin, PWM
import time

servo = PWM(Pin(2))
servo.freq(50) # Pulso de 20 mS

def angle2DC(angle):
    # Para el Servo SG90 0 grados son 0.5 mS o 500 000 de nano segundos
    # la formula para combertir un angulo en un ciclo de trabajo es el siguiente
    # Angulo = A* TimeON + B ecuacionn de una linea recta donde A y B son valores de connfiguracion
    # 0 = a*500000 + B Valor para angulo de 0 ecuaciónn 1
    # 180 = a*2500000 + B el valor del angulo para 180 grados del servo ecuacion 2
    # si restamos la ecuacion 1 a la ecuacion 2 tenemos
    # 180 - 0 = A*(2500000 - 500000) +B - B
    # A = 9/100000
    # substituyendo A en la ecuacion 1 tenemos
    # 0 = (9/100000)500000 + B
    # B = B = 45,
    # Ahora despejando el Tiempo de encendido tenemos
    # TimeON = 100000*(Angle+45)/9
    return int((angle+45)*100000/9)

while True:
    for i in range(0,181):
        servo.duty_ns(angle2DC(i))
        print(i)
        time.sleep_ms(25)
    time.sleep_ms(100)
    for i in range(180,-1,-1):
        servo.duty_ns(angle2DC(i))
        time.sleep_ms(25)
        print(i)


