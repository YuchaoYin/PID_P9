# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

### The Effect of PID

* P: Proportional Term
 * The proportional parameter decides how strong the system reacts for a given error. That means if the proportional gain is too high, we will have a more sensitive controller and it will cause overshooting and oscillation.
 
* I: Integral Term
 * The integral term can be used to eliminate biases. 
 
* D: Derivative Term
 * The derivative term calculates the slope of error overtime, thus it contributes to stability of the system by eliminating oscillations.
 
### Implemented PID Controller
* PID controller for speed. 
 * Since driving with high velocity is not safe, I tried to use another PID controller to limit the velocity. The target speed is 20 km/h. The speed error is fed into the PID controller and the throttle is the output. This modual improves the performance.
 
* PID controller for steer angle
 * the range of steer angle is limited between -1 and 1.
 * the final PID parameters were tuned manually. First set integral and derivative to 0 and only tune the proportional gain. Then I started to change derivative term, this term reduce the overshooting problem. In the end the integral term is set to 0.001, since our system does not have too much bias. The whole procedure is listed as follows:
 
 
    | P       | I           | D  |
    | ------------- |:-------------:| -----:|
    | 0.01      |0.0 | 0.0 |
    | 0.05      | 0.0      |   0.0 |
    | 0.08 | 0.0      |   0.0 |
    | 0.12 | 0.0 |0.0|
    |0.12|0.0|1.0|
    |0.12|0.0|2.0|
    |0.12|0.0|4.0|
    |0.12|0.1|4.0|
    |0.12|0.001|4.0|
