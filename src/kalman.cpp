/*
 * kalman.cpp
 */

#include "../include/kalman.hpp"

double kalman::operator()(double U) {
    K = (P * H) / (H * P * H + R);
    U_hat = U_hat + K * (U - H * U_hat);
    P = (1 - K * H) * P + Q;
    return U_hat;
}