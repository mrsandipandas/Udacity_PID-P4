#ifndef PID_H
#define PID_H

#include <vector>
#include <limits>
#include <math.h>

class PID {
public:
    /*
    * Errors
    */
    double p_error;
    double i_error;
    double d_error;
    double prev_cte;

    /*
    * Coefficients
    */ 
    double Kp;
    double Ki;
    double Kd;
    
    /**
    * Error counters
    **/
    double minError;
    double maxError;
    
    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
    
    double TwiddleError(double pid_delta[]);
    
    void Twiddle();

};

#endif /* PID_H */
