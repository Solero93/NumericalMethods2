#include <limits>
#include <cmath>
#include "linearSolver.h"

/*
 * OPERATOR OVERRIDES
 */
vector<double> operator+(const vector<double>& lhs, const vector<double>& rhs){	// return type is a vector of integers
    if(lhs.size() != rhs.size()){	// Vectors must be the same size in order to add them!
        throw std::runtime_error("Can't add two vectors of different sizes!");
    }
    vector<double> result;	// Declaring the resulting vector, result
    for(int i=0; i < lhs.size(); i++){	// adding each element of the result vector
        result.push_back(lhs.at(i) + rhs.at(i));	// by adding each element of the two together
    }
    return result;	// returning the vector "result"
}

vector<double> operator-(const vector<double>& lhs, const vector<double>& rhs){	// return type is a vector of integers
    if(lhs.size() != rhs.size()){	// Vectors must be the same size in order to add them!
        throw std::runtime_error("Can't substract two vectors of different sizes!");
    }
    vector<double> result;	// Declaring the resulting vector, result
    for(int i=0; i < lhs.size(); i++){	// adding each element of the result vector
        result.push_back(lhs.at(i) - rhs.at(i));	// by adding each element of the two together
    }
    return result;	// returning the vector "result"
}

vector<double> operator*(const double& lhs, const vector<double>& rhs){	// return type is a vector of integers
    vector<double> result;	// Declaring the resulting vector, result
    for(int i=0; i < rhs.size(); i++){	// adding each element of the result vector
        result.push_back(lhs * rhs.at(i));	// by adding each element of the two together
    }
    return result;	// returning the vector "result"
}

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
    return (this->tolFactor * (this->calculateNorm(curr - prev)) < this->tolerance);
}

void LinearSolver::run(){
    this->calculateTolFactor();
    vector<double> result = this->algorithm();
    for (int i=0; i<10; i++){
        cout << result[i] << ", ";
    }
    cout << " .... " << endl;
}