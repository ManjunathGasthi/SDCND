#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp=Kp;
  Ki=Ki;
  Kd=Kd;
  d_error = 0;
  p_error = 0;
  i_error = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::Signal() {
  return - d_error * Kd - p_error * Kp - i_error * Ki;
}

double PID::TotalError() {
}

