#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 11:06:39 2021

@author: gustavomendoza
"""

import numpy as np
import math as mt
from matplotlib import pyplot as plt

#calculo de la matriz de tranformacion homogenea base J1
phi1 = 30*np.pi/180
theta1 = 120*np.pi/180
longitd1 = 100
matrizRotacion1 = np.array([[np.cos(phi1), -np.sin(phi1)],
                            [np.sin(phi1), np.cos(phi1)]])
matrizTraslacion1 = np.array([[longitd1*np.cos(theta1)],
                              [longitd1*np.sin(theta1)]])
matrixAuxiliar = np.concatenate((matrizRotacion1,matrizTraslacion1), axis=1)
matrizTranformacionBaseJ1 = np.concatenate((matrixAuxiliar,[[0,0,1]]),axis=0)
print(matrizTranformacionBaseJ1)


#calculo de la matriz de tranformacion homogenea J1 a J2
phi2 = 0*np.pi/180
theta2 = 0*np.pi/180
longitd2 = 100
matrizRotacion2 = np.array([[np.cos(phi2), -np.sin(phi2)],
                            [np.sin(phi2), np.cos(phi2)]])
matrizTraslacion2 = np.array([[longitd2*np.cos(theta2)],
                              [longitd2*np.sin(theta2)]])
matrixAuxiliar = np.concatenate((matrizRotacion2,matrizTraslacion2), axis=1)
matrizTranformacionJ1J2 = np.concatenate((matrixAuxiliar,[[0,0,1]]),axis=0)
#print(matrizTranformacionJ1J2)

#alculo de la matriz de tranformacion homogenea J1 a ee
phi3 = -45*np.pi/180
theta3 = -45*np.pi/180
longitd3 = 50
matrizRotacion3 = np.array([[np.cos(phi3), -np.sin(phi3)],
                            [np.sin(phi3), np.cos(phi3)]])
matrizTraslacion3 = np.array([[longitd3*np.cos(theta3)],
                              [longitd3*np.sin(theta3)]])
matrixAuxiliar = np.concatenate((matrizRotacion3,matrizTraslacion3), axis=1)
matrizTranformacionJ2ee = np.concatenate((matrixAuxiliar,[[0,0,1]]),axis=0)
#print(matrizTranformacionJ2ee)

matrizTranformacionBaseJ2 = matrizTranformacionBaseJ1.dot(matrizTranformacionJ1J2)
#print(matrizTranformacionBaseJ2)

matrizTransformacionBaseEe = matrizTranformacionBaseJ2.dot(matrizTranformacionJ2ee)
#print(matrizTransformacionBaseEe)

eeObjeto = np.array([[20],
                     [0],
                     [1]])
posicionObjeto = matrizTransformacionBaseEe.dot(eeObjeto)
#Coordenadas de puntos de interes
xJ1 = matrizTranformacionBaseJ1[0,2]
yJ1 = matrizTranformacionBaseJ1[1,2]
xJ2 = matrizTranformacionBaseJ2[0,2]
yJ2 = matrizTranformacionBaseJ2[1,2]
xEe = matrizTransformacionBaseEe[0,2]
yEe = matrizTransformacionBaseEe[1,2]
xObjeto = posicionObjeto[0]
yObjeto  = posicionObjeto[1]


print(posicionObjeto)
#Graficar la figura del robot
figure,axes = plt.subplots()
plt.plot(0,0, 'o')
plt.plot(xJ1,yJ1, 'o')
plt.plot(xJ2,yJ2, 'o')
plt.plot(xEe,yEe, 'o')
plt.plot(xObjeto,yObjeto, 'bo')
plt.plot([0,xJ1,xJ2,xEe],[0,yJ1,yJ2,yEe])

axes.set_xlim([-150, 150])
axes.set_ylim([0, 150])
plt.show()

#Distancia entre dos puntos
distancia = mt.sqrt((xObjeto-xEe)**2 +(yObjeto - yEe)**2)
print(distancia)


