#include "jacobi.h"

Jacobi::Jacobi() : LinearSolver() {
}

vector<double> Jacobi::algorithm() {
    vector<double> a = *(new vector<double>);
    vector<double> b = *(new vector<double>);
    return a-b;
}
