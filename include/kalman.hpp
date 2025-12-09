/*
 * kalman.hpp
 */

class kalman {
public:

    /*
     * A larger value of Q indicates to trust the model less and the actual
     * measurements more. Set R to around the variance of the sensor noise.
     */
    kalman(double Q_, double R_) : Q(Q_), R(R_) {}

    double operator()(double U);

private:

    /*
     * Noise variance.
     */
    double R;

    /*
     * Measurement map scalar.
     * TODO What is this?
     */
    double H = 1.00;

    /*
     * Process variance.
     */
    double Q;

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