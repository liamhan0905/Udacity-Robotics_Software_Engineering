#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find map)/worlds/finalWorldEdit.world" &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find turtlebot_gazebo)/maps/map.yaml" & 
sleep 5
xterm  -e  " roslaunch rvizConfig rvizConfig.launch " &
sleep 5
xterm  -e  " roslaunch add_markers add_markers.launch" &
sleep 5
xterm  -e  " roslaunch pick_objects pick_objects.launch"
