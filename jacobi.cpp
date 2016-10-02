//
// Created by Solero93 on 01/10/2016.
//

#include "jacobi.h"

Jacobi::Jacobi(double tol) : LinearSolver(tol) {
    this->algorithm = jacobiAlgorithm();
}

vec<double> jacobiAlgorithm() {
    int n =
}