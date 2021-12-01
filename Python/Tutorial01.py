#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
CCreado el dia 18 de noviembre de 2021

@author: Ing Gustavo David Mendoza Pinto
"""
import sim
#import numpy as np

def connect(port):
#establece la coneccion con coppelia sim
#port debe coincidir con el puerto de conexion de copelia sim
    sim.simxFinish(-1) # just in case, close all opened connections
    clientID=sim.simxStart('127.0.0.1',port,True,True,2000,5) # Conectarse
    if clientID == 0: print("conectado al puerto", port)
    else: print("No se pudo conectar verifique simulador")
    return clientID

clientID = connect(19999)

returnCode,handle=sim.simxGetObjectHandle(clientID,'Pioneer_p3dx',sim.simx_opmode_blocking)
robot = handle
print(robot)
#Obtener handle de los motores
#handle del motor izquierdo
returnCode,robotLeftMotor=sim.simxGetObjectHandle(clientID,'Pioneer_p3dx_leftMotor',sim.simx_opmode_blocking)
print(robotLeftMotor)
#handle del motor Derecho
returnCode,robotRightMotor=sim.simxGetObjectHandle(clientID,'Pioneer_p3dx_rightMotor',sim.simx_opmode_blocking)
print(robotRightMotor)

returnCode,robotPosition = sim.simxGetObjectPosition(clientID, robot, -1, sim.simx_opmode_blocking)
print(robotPosition)

returnCode = sim.simxSetJointTargetVelocity(clientID, robotRightMotor, 1, sim.simx_opmode_streaming)
returnCode = sim.simxSetJointTargetVelocity(clientID, robotLeftMotor, 1, sim.simx_opmode_streaming)











