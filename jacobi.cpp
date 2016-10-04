#include "jacobi.h"

Jacobi::Jacobi() : LinearSolver() {
}

vector<double> Jacobi::algorithm() {
    int n = coefficients.size();
    vector<double> previousIterates = vector<double> (n, 0.0);
    vector<double> currentIterates = vector<double> (n, 1.0);

    while(!(this->isFinished(previousIterates, currentIterates))) {
        previousIterates = currentIterates;

        currentIterates[0] = (-(previousIterates[2] + previousIterates[n-2]) + coefficients[0]) / 3;
        currentIterates[1] = (-(previousIterates[3] + previousIterates[n-1]) + coefficients[1]) / 3;
        for (int i=2; i<n-2; i++){
            currentIterates[i] = (-(previousIterates[i-2] + previousIterates[i+2]) + coefficients[i]) / 3;
        }
        currentIterates[n-2] = (-(previousIterates[0] + previousIterates[n-4]) + coefficients[n-2]) / 3;
        currentIterates[n-1] = (-(previousIterates[1] + previousIterates[n-3]) + coefficients[n-1]) / 3;
    }

    return currentIterates;
}
