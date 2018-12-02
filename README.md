# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

[//]: # (Image References)

[image1]: ./images/pid.png "PID"

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## PID controller

Description of PID values in PID control

* P (proportional) accounts for current values of the cte (cross track error).

* I (integral) accounts for cumulative sum of all past values of the error. For example, if the current cte is not significant, the integral of the cte will accumulate over time, and the controller will respond by applying a stronger action.

* D (differential) accounts for possible changes of the cte with the previous iteration.

I have used two different PID controllers for the steeering and the throttle. I have graphed the effect of different P, PD, and PID control mechanism on the steering angle displayed below:

![Different steering signals on activating P, PD and PID controller][image1]

In this graph, the controller for the steering oscillates in the beginning and then dampens towards zero. However, whenever there is a sharp turn, the cte increases again and the controller again tries to minimize the cte and as a result it ocssilates again and then tries to dampen with time. This effect continues over and over in the whole track.

## Hyperparameter tuning

I tried to tune the hyper-parameters using Twiddle algorithm as explained in the course. However, my twiddle was not converging to a significant value. And, then I tuned the hyper-parameters manually both for the steering and the throttle to achieve good results.


