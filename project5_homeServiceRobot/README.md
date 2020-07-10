## Project

For this project, I learned more in depth about the theory and math behind mapping and SLAM. At the end, I learned to implement a G mapping ROS package based on the grid based FastSLAM algorithm to map the environment and estimate the robot path. 

At first, I assumed exact robot poses and learned how static environment could be mapped using occupancy grid mapping algorithm. The occupancy grid mapping decomposes the world into grid cells and implement binary Bayes filter to estimate the occupancy of the cells. However, in the real environment, poses as well as the map is unknown. 

This is where SLAM comes in. First, I learned about the two essential features of the SLAM problem (onlineSLAM vs. offlineSLAM and continues nature vs. discrete nature) The continues nature of SLAM is a problem because of the high dimension of the posterior whereas the discrete nature poses another challenge in that it creates a large number of correspondence values that exist.

I then learned about FastSLAM which uses particle filter approach along with a low-dimensional extended Kalman filter to estimate to solve the SLAM problem. Next, I learned the difference between OnlineSLAM and  FullSLAM/OfflineSLAM and how Grid-based mapping addresses both problems. Grid-based FastSLAM uses MCL algorithm along with the occupancy grid mapping algorithm.

[Demo Video](https://www.youtube.com/watch?v=1ODcRLEMUA0&feature=youtu.be)
