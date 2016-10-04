#include "gauss-seidel.h"

GaussSeidel::GaussSeidel() : LinearSolver() {
}

vector<double> GaussSeidel::algorithm() {
    int n = coefficients.size();
    vector<double> previousIterates = vector<double> (n, 0.0);
    vector<double> currentIterates = vector<double> (n, 1.0);

    while(!(this->isFinished(previousIterates, currentIterates))) {
        previousIterates = currentIterates;

        currentIterates[0] = 1./3 * ( -(previousIterates[2] + previousIterates[n-2]) + coefficients[0]);
        currentIterates[1] = 1./3 * ( -(previousIterates[3] + previousIterates[n-1]) + coefficients[1]);
        for (int i=2; i<n-2; i++){
            currentIterates[i] = 1./3 * ( -(currentIterates[i-2] + previousIterates[i+2]) + coefficients[i]);
        }
        currentIterates[n-2] = 1./3 * ( -(currentIterates[0] + currentIterates[n-4]) + coefficients[n-2]);
        currentIterates[n-1] = 1./3 * ( -(currentIterates[1] + currentIterates[n-3]) + coefficients[n-1]);
    }

    return currentIterates;
}