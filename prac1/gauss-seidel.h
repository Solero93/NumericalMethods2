#ifndef UB_NUMERICALMETHODS2_GAUSS_SEIDEL_H
#define UB_NUMERICALMETHODS2_GAUSS_SEIDEL_H

#include <cmath>
#include "linearSolver.h"

class GaussSeidel: public LinearSolver{
public:
    GaussSeidel();
    virtual vector<double> algorithm() override;
};

#endif //UB_NUMERICALMETHODS2_GAUSS_SEIDEL_H
