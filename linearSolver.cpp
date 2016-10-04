#include <limits>
#include <cmath>
#include "linearSolver.h"

/*
 * LINEARSOLVER CLASS IMPLEMENT
 */
LinearSolver::LinearSolver(){
}

// Setters
void LinearSolver::setTolerance(double tolerance) {
    this->tolerance = tolerance;
}

void LinearSolver::setMatrixNorm(double matrixNorm) {
    this->matrixNorm = matrixNorm;
}

void LinearSolver::setCoefficients(const vector<double> &coefficients) {
    this->coefficients = coefficients;
}

// Methods
void LinearSolver::calculateTolFactor(){
    this->tolFactor = (this->matrixNorm) / (1. - this->matrixNorm);
}

double LinearSolver::calculateNorm(vector<double> matrix){
    double norm = numeric_limits<double>::min();
    double acc;
    for (vector<double>::iterator it = matrix.begin(); it != matrix.end(); it++){
        acc = abs(*it);
        if (acc > norm) {
            norm = acc;
        }
    }
    return norm;
}

bool LinearSolver::isFinished(vector<double> prev, vector<double> curr) {
    for (int i=0; i<prev.size(); i++) {
        prev[i] -= curr[i]; // Not necessary to create new vector
    }
    return (this->tolFactor * (this->calculateNorm(prev)) < this->tolerance);
}

void LinearSolver::run(){
    this->calculateTolFactor();
    vector<double> result = this->algorithm();
    for (int i=0; i<10; i++){
        cout << result[i] << ", ";
    }
    cout << " .... " << endl;
}