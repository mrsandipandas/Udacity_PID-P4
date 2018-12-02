#include "PID.h"
#include <iostream>
/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = d_error = i_error = 0.0;
    
    // Previous cross track error.
    prev_cte = 0.0;

    minError = std::numeric_limits<double>::min();
    maxError = std::numeric_limits<double>::max();
}

void PID::UpdateError(double cte) {
    // Proportional error
    p_error = cte;

    // Integral error
    i_error += cte;

    // Diferential error
    d_error = cte - prev_cte;
    prev_cte = cte;

    if ( cte < maxError ) {
        maxError = cte;
    }
}

double PID::TotalError() {
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}

double PID::TwiddleError(double pid_delta[]) {
    //std::cout << p_error << ", " << i_error << ", " << d_error << std::endl;
    return -pid_delta[0] * p_error - pid_delta[2] * d_error - pid_delta[1] * i_error;
}

void PID::Twiddle() {
    double p[] = { 0, 0, 0 };
    double dp[] = { 1.0, 1.0, 1.0 };
    double err, best_err;
    best_err = maxError;
    int maxItr = 200;
    int itrCount = 0;
    while ((dp[0] + dp[1] + dp[2]) > 0.001) {
        itrCount ++;
        for (int i=0; i<3; i++) {
            p[i] += dp[i];
            err = TwiddleError(p);

            if (err*err < best_err*best_err) {  // There was some improvement
                best_err = err;
                dp[i] *= 1.1;
            }
            else {  // There was no improvement
                p[i] -= 2*dp[i] ; // Go into the other direction
                err = TwiddleError(p);

                if (err < best_err) {  // There was an improvement
                    best_err = err;
                    dp[i] *= 1.1;
                }
                else { // There was no improvement
                    p[i] += dp[i];
                    // As there was no improvement, the step size in either
                    // direction, the step size might simply be too big.
                    dp[i] *= 0.9;
                }
            }
        }
    }
    std::cout << "***The paramenters found so far are: "<< p[0] << ", " << p[1] << ", "<< p[2] << std::endl; 
}