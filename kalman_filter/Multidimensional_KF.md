# Multidimensional Gaussian

In our 1 dimensional example, the system state was represented by one variable. In N dimensional systems, the state is a vector with N state variables. In a two dimensional example, the two state variables can be set as the position and velocity of a robot. 

This brings up an important matter. When working in 1 dimension, the state has to be **observable**, meaning that it had to be something that can be measured directly. In multi-dimensional states, there may exist hidden state variables, ones that you cannot measure when the sensors are unavailable. However, you may be able to infer the value from other states and measurements. In our example, the robot location is observable while the velocity is not, making it a hidden variable. However, a robot's position and velocity over time are linked thorough a very simple formula shown below.

<p align="center">
  <img width="500"src="../resources/m_g_5.JPG">
</p>

If initially, the position of the robot is known, but its velocity is not, the estimate of the robot's state would look like so. A Gaussian that is very narrow in x-dimension representing confidence about the robot's location, and a very wide in the x-dot dimension. This is because the robot's velocity is completely unknown. Next, a state prediction can be calculated. 

This is where KF starts to get exciting. Knowing the relationship between the hidden variable and observable variable is key. Let's assume that one iteration of the KF takes one second. Using the formula, we can calculate the posterior state for each possible velocity. For example, if the velocity is 0, the posterior state would be identical to the prior and if the velocity is 1, the posterior will be the second point and so forth. From this we can draw a posterior Gaussian that looks like this. This doesn't yet tell us anything about the velocity. It just graphs the correlation between the velocity and the location of the robot. However, we have the measurement update next.The initial belief was useful to calculate the state prediction but has no additional value. The result of the state prediction can be called a 'Prior Belief' for our measurement update. Let's say that the new measurement suggests a location of X=50. Now, if we apply the measurement update to our prior, we will have a very small posterior centered around x=50.





--- 

This is actually the same thing we did for 1-dimensional. The yellow line is the 'Prior Belief' whereas the green is the 'Measurement'. The 'Posterior Belief' is just a weighted sum of the two and more confident than either the prior or the measurement. Then, the relationship between the two dimensions narrow down to the posterior for the x-dot axis. Continuing iterating through the measurement update and state prediction steps will update the robot's internal state to keep it aligned with where it is in the real world.
