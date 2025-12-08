/*
 * test_kalman.cpp
 */

#include <cmath>
#include <iostream>
#include <random>

#include "../include/kalman.hpp"

const int VALS = 1e3;
const double EPS_SIGMA = 0.2;

int main() {
    std::normal_distribution<double> dist(0, EPS_SIGMA);
    std::default_random_engine rng(42);
    std::vector<double> vals(VALS);
    for (int i = 0; i < VALS; i++) {
        double eps = dist(rng);
        vals.at(i) = sin(i * 0.01) + eps;
    }
    kalman k;
    for (int i = 0; i < VALS; i++) {
        double val = vals.at(i);
//        std::cout << "(" << (i * 0.01) << ", " <<  val << ")" << std::endl;
        std::cout << "(" << (i * 0.01) << ", " <<  k(val) << ")" << std::endl;
    }
}