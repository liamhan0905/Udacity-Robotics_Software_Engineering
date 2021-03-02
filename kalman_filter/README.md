# Kalman Filter

## Overview
Kalman Filter(KF) is an estimation algorithm that is very prominent in controls. It is used to estimate the value of a variable (e.g. position, velocity, temperature etc) in real-time as the data is being collected. It can take data with lot of uncertainty or noise in the measurement and provide a very accurate estimate in a fast manner.



<img src="../resources/filter.JPG" align="center" width="100">

The KF takes in an initial assumption and noisy measurement as an input and filters out the noisy/uncertainty data. And eventually it distills desired state.

--- 
## Example
Let's say there's an underwater robot measuring pressure as it swims through water. Pressure increases linearly with depth. In real life scenario, the sensor measurement will <span style="color:red">**NOT**</span> be accurate. There may be fluctuation in the water causing fluctuation in pressure as well as electrical noise from the sensor itself.

![underwater robot](../resources/underwater_robot.JPG)

As pressure sensor starts collecting data, the KF begins to narrow in and estimate the actual pressure. In addition to the sensor readings, the KF also takes into account the uncertainty of the sensor readings which are specific to the sensor and the environment it is operating in. 

![underwater robot](../resources/underwater_robot_plot.JPG)

---
## How does it work?
Iteration of two steps: <span style="color:yellow">**Measurement Update**</span> and <span style="color:yellow">**State Prediction**</span>. After couple iterations, the estimate will converge on the real value.

- Measurement Update: Use recorded measurement to update the state
- State Prediction: Use the information we currently have about the current state to predict what the future state will be. Initial guess is used for the start.