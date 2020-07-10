## Project

For this project, I gained knowledge in the classic path planning algorithms (Breadth-First Search, Depth-First Search etc) A* as well as probablistic path planning. I combined all the knowledge acquired throughout this course. Official ROS packages (gmapping, turtlebot_teleop, turtlebot_rviz_launchers, turtlebot_gazebo) were used to map the environment. ROS Navigation stack, which is based on the Dijkstra's, a variant of the Uniform Cost Search algorithm was used to plan the robot trajectory from start to goal position. The ROS navigation stack permits the robot to avoid any obstacle on its path by re-planning a new trajectory once the robot encounters them.

Next, a node was added to communicate with the ROS navigation stack and autonomously send successive goals for the robot to reach. Virtual objects were displayed on Rviz for the robot to pickup and drop off. There's an official ROS tutorial on how to display basic shapes on Rviz using visualization_msgs/Marker messages. Last package subscribed to the odometry topic to find the distance between the robot position and the target pickup/dropoff position. Once the robot approached the desired location, I was able to send a command to display or hide the virtual object to mimic the robot picking the object.

Overall, this course was a very fun/challenging introduction to ROS. 

[Demo Video](https://www.youtube.com/watch?v=1ODcRLEMUA0&feature=youtu.be)

![Capture](https://user-images.githubusercontent.com/44885838/87116438-afad3300-c22a-11ea-94e8-d79700bf68a1.JPG)
