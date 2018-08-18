# Model Predictive Control

## Project Base: 
Using Model Predictive Control (MPC), this project involves writing a C++ program that can drive a simulated car around a virtual track using specific waypoints from the track itself. 
The simulated car's actuators have a 100ms latency (delay) that must be accounted for as well as part of the MPC calculation.

## Compilation
The code compiles with warnings which were mostly already in the original code. The warnings are about comparing signed and unsigned integers.

## Implementation

### Project Steps

* Fitting a line based on road waypoints and evaluating the current state based on that polynomial line.
* Implementing the MPC calculation, including setting variables and constraints
* Calculating actuator values from the MPC calc based on current state
* Accounting for latency (I used a predicted state 100ms in the future to replace the actual current state in the calculation)
* Calculating steering angle & throttle/brake based on the actuator values
* Setting timestep length and duration
* Testing/tuning of above implementations on Udacity simulator

And we have two actuators:
* Steer value: controls (By using some transforms implying the constant Lf) the steering of the front wheels and thus the orientation of the car.
* Throttle: controls acceleration and braking, changes to the linear velocity.

The equations for the update between two timesteps *t* and *t-1* separated by *dt* is as follows:

![Update Equations](https://github.com/ManjunathGasthi/SDCND/blob/master/SDCND_Term2/CarND-MPC-Project/images/updateequations_mpc.png "Update equations")

In the project the equations are applied in car coordinates and set all inputs to the angle reference used in class, which is sometimes different than the reference used by the simulator. This allows to keep all signs in the equation the same as in class, but requires to make sure that the signs for steering are taking care of before returning to the simulator. The function *f(x)* is the grade 3 polynomial aproximation of the waypoints trajectory in car coordinates.

### Timestep length and elapsed duration

The values used in the MPC quizzes are used as starting point. After that, the values are tuned for performance, taking into account as well response time and length of the predicted trajectory. The interval *dt=0.1* is deemed as appropiate resolution for this simulation. *N* is then adjusted to be able to cover a distance enough to plan a recovery trajectory from most mistakes the model makes, but still within adequate response time. Thus *N=10* is chosen. In my particular hardware values *N>30* will cause fatal delays bigger than the project limitation of 100ms delay.

### Model Predictive Control with Latency

Two strategies were tried out to deal with latency:
* The original kinematic equations depend upon the actuations from the previous time step, but with a delay of 100ms (which happens to be the time step interval) the actuations are applied with another time step later.
* Cost penalizing the combination of velocity and delta was coded to get controlled cornering.

### Polynomial fitting and MPC preprocessing
Each timestep the waypoints received from the simulator were transformed to car coordinates **after** updating the step with the latency *dt=100ms*. Then a polynomial of 3rd degree is fitted to the points. Since there are always six waypoints, it is always possible to fit a 3rd degree polynomial. The coefficients are passed to the MPC module to perform *cte* and *epsi* calculations.

The required preprocessing is thus:
* Updating the stated based on the latency.
* Convert variables to the right units and convention.
* Transform all coordinates into car coordinates.

### Output Images:
![output1](https://github.com/ManjunathGasthi/SDCND/blob/master/SDCND_Term2/CarND-MPC-Project/images/mpc1.PNG)
![output2](https://github.com/ManjunathGasthi/SDCND/blob/master/SDCND_Term2/CarND-MPC-Project/images/mpc2.PNG)
![output3](https://github.com/ManjunathGasthi/SDCND/blob/master/SDCND_Term2/CarND-MPC-Project/images/mpc3.PNG)

