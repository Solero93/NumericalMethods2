#ifndef UB_NUMERICALMETHODS2_LINEARSOLVER_H
#define UB_NUMERICALMETHODS2_LINEARSOLVER_H

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class LinearSolver {
public:
    double tolerance;
    double tolFactor; // Stored to optimize calculations
    int numIterations;

    double matrixNorm;
    vector<double> coefficients;

    LinearSolver();

    void setTolerance(const double tolerance);
    void setMatrixNorm(const double matrixNorm);
    void setCoefficients(const vector<double> &coefficients);

    bool isFinished(vector<double> prev, vector<double> curr);
    void calculateTolFactor();
    double calculateNorm(vector<double> vec);
    void run();
    virtual vector<double> algorithm() = 0;

};

#endif //UB_NUMERICALMETHODS2_LINEARSOLVER_H
