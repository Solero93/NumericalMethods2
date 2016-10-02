//
// Created by Solero93 on 01/10/2016.
//

#include <limits>
#include <cmath>
#include "linearSolver.h"

LinearSolver::LinearSolver(){

}

LinearSolver::LinearSolver(double tol) {
    this->tolerance = tol;
}
/*

// Setters
void LinearSolver::setTolerance(double tolerance) {
    this->tolerance = tolerance;
}
void LinearSolver::setMatrixNorm(double matrixNorm) {
    this->matrixNorm = matrixNorm;
}
void LinearSolver::setAlgorithm(vec<double> (*algorithm)(double tol)) {
    this->algorithm = algorithm;
}
*/

// Methods
void LinearSolver::calculateTolFactor(){
    this->tolFactor = (this->matrixNorm) / (1. - this->matrixNorm);
}

double LinearSolver::calculateNorm(vec<double> matrix){
    double norm = numeric_limits<double>::min();
    double acc;
    for (vec<double>::iterator it = matrix.begin(); it != matrix.end(); it++){
        acc = abs(*it);
        if (acc > norm) {
            norm = acc;
        }
    }
    return norm;
}

bool LinearSolver::isFinished() {
    return (this->tolFactor * (this->calculateNorm(this->currentIterates - this->previousIterates)) < this->tolerance);
}

vec<double> LinearSolver::run(){
    this->calculateTolFactor();
    return (*this->algorithm)();
}