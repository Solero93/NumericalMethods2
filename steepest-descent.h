#ifndef UB_NUMERICALMETHODS2_STEEPEST_DESCENT_H
#define UB_NUMERICALMETHODS2_STEEPEST_DESCENT_H

#include <cmath>
#include "linearSolver.h"

class SteepestDescent: public LinearSolver{
public:
    SteepestDescent();

    double omega;

    void setOmega(const double omega);
    virtual vector<double> algorithm() override;
    vector<double> multiplyByA(vector<double> p);

    vector<double> gradient(vector<double> x);

    double findBestParameter(int numPartitions);
};

#endif //UB_NUMERICALMETHODS2_STEEPEST_DESCENT_H
