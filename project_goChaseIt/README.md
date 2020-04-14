## Project 2

For this project, the student must create two ROS packages. One package that contains all the information about the robot, and the other package that holds two nodes to control the robot. 

This client node will subscribe to the robot’s camera images and analyze them to determine the position of the white ball. Once the ball position is determined, the client node will request a service from the drive_bot server node to drive the robot toward the ball. The robot can drive either left, right or forward, depending on the robot position inside the image.

[Demo Video](https://www.youtube.com/watch?v=pIeEySf6vsw)


![111](https://user-images.githubusercontent.com/44885838/79080960-f643cd80-7ccd-11ea-860d-1738a64936d8.JPG)
