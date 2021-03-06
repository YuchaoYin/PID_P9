#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    p_error = 0.0;
    d_error = 0.0;
    i_error = 0.0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

}

double PID::TotalError() {
    return - Kp_*p_error - Kd_*d_error - Ki_*i_error;
}

