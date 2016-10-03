#ifndef UB_NUMERICALMETHODS2_LINEARSOLVER_H
#define UB_NUMERICALMETHODS2_LINEARSOLVER_H

#include <vector>
#include <stdexcept>

using namespace std;

vector<double> operator+(const vector<double>& lhs, const vector<double>& rhs);
vector<double> operator-(const vector<double>& lhs, const vector<double>& rhs);
vector<double> operator*(const double& lhs, const vector<double>& rhs);

class LinearSolver {
public:
    double tolerance;
    double tolFactor; // Stored to optimize calculations

    double matrixNorm;
    vector<double> coefficients;
    vector<double> currentIterates;
    vector<double> previousIterates;

    LinearSolver();

    void setTolerance(double tolerance);
    void setMatrixNorm(double matrixNorm);
    void setCoefficients(const vector<double> &coefficients);

    bool isFinished();
    void calculateTolFactor();
    double calculateNorm(std::vector<double> vec);
    vector<double> run();
    virtual vector<double> algorithm() = 0;

};

#endif //UB_NUMERICALMETHODS2_LINEARSOLVER_H
