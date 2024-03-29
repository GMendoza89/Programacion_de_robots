import sim
import math as mt
import numpy as np




#Definiendo variables del Agente

class PioneerP3DX:
    def __init__(self, controlKp, controlKo):
        self.R = 0.1
        self.L = 0.335
        self.Kp = controlKp
        self.Ko = controlKo
        self.returnCode = []
        self.robotHandle = []
        self.robotLeftMotor = []
        self.robotRightMotor = []
        self.clientID = []
        self.ultrasonicSensors = []
        self.ultrasonicSensorsValue = np.zeros((16),dtype=bool)
        self.ultrasonicSensorsMeasure = np.zeros((16))
        self.robotPosition = []
        self.robotOrientation = []

    
    def connect(self,port):
        sim.simxFinish(-1) # just in case, close all opened connections
        self.clientID=sim.simxStart('127.0.0.1',port,True,True,2000,5) # Conectarse
        if self.clientID == 0: print("conectado al puerto", port)
        else: print("No se pudo conectar verifique simulador")
        return self.clientID

    def getRobotHandle(self):
        self.returnCode, self.robotHandle = sim.simxGetObjectHandle(self.clientID,'Pioneer_p3dx',sim.simx_opmode_blocking)
        print(self.robotHandle)

    def getMotorsHandle(self):
        # Obteniendo handle del motor izquierdo
        self.returnCode, self.robotLeftMotor = sim.simxGetObjectHandle(self.clientID,'Pioneer_p3dx_leftMotor',sim.simx_opmode_blocking) 
        # Obteniedo Handle de Motor Derecho           
        self.returnCode, self.robotRightMotor = sim.simxGetObjectHandle(self.clientID,'Pioneer_p3dx_rightMotor',sim.simx_opmode_blocking)
        print(self.robotLeftMotor)
        print(self.robotRightMotor) 
    def robotInit(self):
        self.getRobotHandle()
        self.getMotorsHandle()
        self.getUltrasonicSensorshandle()

    
    def getUltrasonicSensorshandle(self):
        for i0 in range(1,17):
            returnCode,sensorI = sim.simxGetObjectHandle(self.clientID, "Pioneer_p3dx_ultrasonicSensor"+str(i0), sim.simx_opmode_blocking)
            self.ultrasonicSensors.append(sensorI)

    def initUltrasonicSensors(self):
        for i0 in range(16):
            returnCode, stateCode, point, detectedObject,detectSurNormVect = sim.simxReadProximitySensor(self.clientID, self.ultrasonicSensors[i0], sim.simx_opmode_streaming)
            
    def getMesaurament(self):
        for i0 in range(16):
            returnCode, stateCode, point, detectedObject,detectSurNormVect = sim.simxReadProximitySensor(self.clientID, self.ultrasonicSensors[i0], sim.simx_opmode_streaming)
            self.ultrasonicSensorsValue[i0] = stateCode
            self.ultrasonicSensorsMeasure[i0] = np.linalg.norm(point)
    def evita(self):
        returnCode = sim.simxSetJointTargetVelocity(clientID, self.robotRightMotor, -0.3, sim.simx_opmode_streaming)
        returnCode = sim.simxSetJointTargetVelocity(clientID, self.robotLeftMotor, 0.3, sim.simx_opmode_streaming)
        
    def follow(self):
        returnCode = sim.simxSetJointTargetVelocity(clientID, self.robotRightMotor, 0.3, sim.simx_opmode_streaming)
        returnCode = sim.simxSetJointTargetVelocity(clientID, self.robotLeftMotor, 0.3, sim.simx_opmode_streaming)
    
    def angleDifferential(self,phiRobot,phi):
        theta = mt.acos(mt.cos(phiRobot)*mt.cos(phi)+mt.sin(phiRobot)*mt.sin(phi))
        direction = mt.cos(phiRobot)*mt.sin(phi) - mt.cos(phi)*mt.sin(phiRobot)
        return mt.copysign(theta, direction)
    
    def getRobotPose(self):
        self.returnCode, self.robotPosition = sim.simxGetObjectPosition(self.clientID, self.robotHandle, -1, sim.simx_opmode_blocking)
        self.returnCode, self.robotOrientation = sim.simxGetObjectOrientation(self.clientID, self.robotHandle, -1, sim.simx_opmode_blocking)

    def getDistanceError(self,point):
        return mt.sqrt((point[0] - self.robotPosition[0])**2 + (point[1] - self.robotPosition[1])**2)

    def move(self,velocity, angularVelocity):
        velocityL = velocity/self.R - angularVelocity*self.L/(2*self.R)
        velocityR = velocity/self.R + angularVelocity*self.L/(2*self.R)
        self.returnCode = sim.simxSetJointTargetVelocity(self.clientID, self.robotRightMotor, velocityR, sim.simx_opmode_streaming)
        self.returnCode = sim.simxSetJointTargetVelocity(self.clientID, self.robotLeftMotor, velocityL, sim.simx_opmode_streaming)
    def Stop(self):
        self.returnCode = sim.simxSetJointTargetVelocity(self.clientID, self.robotRightMotor, 0, sim.simx_opmode_streaming)
        self.returnCode = sim.simxSetJointTargetVelocity(self.clientID, self.robotLeftMotor, 0, sim.simx_opmode_streaming)
    def goToAPoint(self,point):
        self.getRobotPose()
        print("Punto Objetivo: "+str(point))
        distanceError = self.getDistanceError(point)
        print(distanceError)
        while distanceError > 0.05:
            self.getRobotPose()
            distanceError = self.getDistanceError(point)
            angle = mt.atan2(point[1] - self.robotPosition[1],point[0] - self.robotPosition[0])
            angleError = self.angleDifferential(self.robotOrientation[2],angle)
            velocity = self.Kp*distanceError
            angularVelocity = self.Ko*angleError
            self.move(velocity,angularVelocity)
        self.Stop()
            

    



if __name__ == "__main__":
    robot = PioneerP3DX(0.1,0.5)
    robot.connect(19999)
    robot.robotInit()
    robot.goToAPoint([0,0,0])
