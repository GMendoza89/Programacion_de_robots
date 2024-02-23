import coppeliaRobots as CP
import time

if __name__ == "__main__":
    robot = CP.PioneerP3DX(0.1,0.5)
    robot.connect(19999)
    robot.robotInit()
    if(robot.robotHandle != 0):
        print("Wall-E se esta moviendo")
        robot.getRobotPose()
        print("Pose del robot: ")
        print(robot.robotPosition)
        print(robot.robotOrientation)
        vertices = 4
        i = 0
        while(i < vertices):
            robot.move(0.1,0.0)
            time.sleep(10)
            robot.move(0.0,0.1)
            time.sleep(2.65)
            i += 1
    
        robot.Stop()
        robot.getRobotPose()
        print("Pose del robot: ")
        print(robot.robotPosition)
        print(robot.robotOrientation)
