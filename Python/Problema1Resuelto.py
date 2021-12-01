#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 12:38:02 2021

@author: gustavomendoza
"""

import numpy as np
from matplotlib import pyplot as plt

#Construimos la matriz de tranformacion de la matriz de tranformacion desde la base a j1

phi1 = 30*np.pi/180 # para trabanbarlos con las librerias de numpy tenemos que tranfprmarlos a radianes
print(phi1)
rotationMatrix = np.array([[np.cos(phi1),-np.sin(phi1)],
                          [np.sin(phi1),np.cos(phi1)]])
print(rotationMatrix)
translationVector = np.array([[100*np.cos(120*np.pi/180)],
                             [100*np.sin(120*np.pi/180)]])
print(translationVector)
auxMatrix = np.concatenate((rotationMatrix,translationVector),axis=1)
homogeneousMatrix1 = np.concatenate((auxMatrix,[[0,0,1]]),axis=0)
print(homogeneousMatrix1)
phi2 = 0
rotationMatrix2 = np.array([[np.cos(phi2),-np.sin(phi2)],
                          [np.sin(phi2),np.cos(phi2)]])
translationVector2 = np.array([[100*np.cos(0*np.pi/180)],
                             [100*np.sin(0*np.pi/180)]])
auxMatrix = np.concatenate((rotationMatrix2,translationVector2),axis=1)
homogeneousMatrix2 = np.concatenate((auxMatrix,[[0,0,1]]),axis=0)
print(homogeneousMatrix2)

phi3 = -45*np.pi/180
rotationMatrix3 = np.array([[np.cos(phi3),-np.sin(phi3)],
                          [np.sin(phi3),np.cos(phi3)]])
translationVector3 = np.array([[50*np.cos(-45*np.pi/180)],
                             [50*np.sin(-45*np.pi/180)]])
auxMatrix = np.concatenate((rotationMatrix3,translationVector3),axis=1)
homogeneousMatrix3 = np.concatenate((auxMatrix,[[0,0,1]]),axis=0)
print(homogeneousMatrix3)
#Calculamos la tranformacion de la base al actuador

tranformationBaseJ2 = homogeneousMatrix1.dot(homogeneousMatrix2)
print(tranformationBaseJ2)
tranformationBaseEE = tranformationBaseJ2.dot(homogeneousMatrix3)
print(tranformationBaseEE)

objectPosition = np.array([[20],[0],[1]])
objecPositionBase = tranformationBaseEE.dot(objectPosition)
print(objecPositionBase)

#graficamos la uniones del robot
xJ1 = homogeneousMatrix1[0,2]
yJ1 = homogeneousMatrix1[1,2]
xJ2 = tranformationBaseJ2[0,2]
yJ2 = tranformationBaseJ2[1,2]
xEE = tranformationBaseEE[0,2]
yEE = tranformationBaseEE[1,2]
xObject = objecPositionBase[0]
yObject = objecPositionBase[1]

figure, axes = plt.subplots()
plt.plot(0,0, 'o')
plt.plot(xJ1,yJ1, 'o')
plt.plot(xJ2,yJ2, 'o')
plt.plot(xEE,yEE, 'x')
plt.plot(xObject,yObject, 'bo')

#graficamos los brazos
plt.plot([0,xJ1,xJ2,xEE],[0,yJ1,yJ2,yEE])
axes.set_xlim(-150,150)
axes.set_ylim(0,150)
plt.show()

