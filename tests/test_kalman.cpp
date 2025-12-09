/*
 * test_kalman.cpp
 */

#include <iostream>
#include <random>

#include "../include/kalman.hpp"

/*
 * The number of sensor readings to generate.
 */
const int VALS = 1e3;

/*
 * Sensor noise variance.
 */
const double EPS_SIGMA = 0.2;

int main() {
    std::normal_distribution<double> dist(0, EPS_SIGMA);
    std::default_random_engine rng(std::random_device{}());
    std::vector<double> vals(VALS);
    for (int i = 0; i < VALS; i++) {
        double eps = dist(rng);
        vals.at(i) = i * 0.01 + eps;
    }
    kalman k(1e-5, EPS_SIGMA);
    for (int i = 0; i < VALS; i++) {
        double val = vals.at(i);
//        std::cout << "(" << (i * 0.01) << ", " << val << ")" << std::endl;
        std::cout << "(" << (i * 0.01) << ", " << k(val) << ")" << std::endl;
    }
}