#ifndef UB_NUMERICALMETHODS2_JACOBI_H
#define UB_NUMERICALMETHODS2_JACOBI_H

#include <cmath>
#include "linearSolver.h"

class Jacobi : public LinearSolver{
public:
    Jacobi();
    virtual vector<double> algorithm() override;
};

#endif //UB_NUMERICALMETHODS2_JACOBI_H