#ifndef UB_NUMERICALMETHODS2_SOR_H
#define UB_NUMERICALMETHODS2_SOR_H

#include <cmath>
#include "linearSolver.h"

class Sor : public LinearSolver{
public:
    Sor();

    double omega;

    void setOmega(double omega);
    virtual vector<double> algorithm() override;
};

#endif //UB_NUMERICALMETHODS2_SOR_H
