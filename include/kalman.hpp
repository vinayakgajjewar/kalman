/*
 * kalman.hpp
 */

class kalman {
public:
    double operator()(double U);
private:
    /*
     * Noise covariance.
     */
    double R = 40;

    /*
     * Measurement map scalar.
     * TODO What is this?
     */
    double H = 1.00;

    /*
     * Initial estimated covariance.
     */
    double Q = 10;

    /*
     * Initial error covariance.
     */
    double P = 0;

    /*
     * Initial estimated state.
     */
    double U_hat = 0;

    /*
     * Initial Kalman gain.
     */
    double K = 0;
};