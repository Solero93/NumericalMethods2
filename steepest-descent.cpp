//
// Created by Solero93 on 12/10/2016.
//

#include <numeric>
#include "steepest-descent.h"

SteepestDescent::SteepestDescent() : LinearSolver(){
}

void SteepestDescent::setOmega(double omega) {
    this->omega = omega;
}

vector<double> SteepestDescent::algorithm() {
    int n = coefficients.size();
    vector<double> previousIterates = vector<double>(n, 0.0);
    vector<double> currentIterates = vector<double>(n, 1.0);

    double alpha;
    vector<double> grad, prod;

    while (!(this->isFinished(previousIterates, currentIterates))) {
        previousIterates = currentIterates;

        grad = gradient(previousIterates);
        prod = multiplyByA(grad);
        alpha = inner_product(grad.begin(), grad.end(), grad.begin(), 0.0) / inner_product(grad.begin(), grad.end(), prod.begin(), 0.0);

        for (int i=0; i<n; i++){
            currentIterates[i] = previousIterates[i] - this->omega*alpha*grad[i];
        }

        numIterations++;
    }
    return currentIterates;
}

vector<double> SteepestDescent::multiplyByA(vector<double> p){
    int n = coefficients.size();
    vector<double> result = vector<double> (n, 0.0);
    result[0] = 3*p[0] + p[2] + p[n-2];
    result[1] = 3*p[1] + p[3] + p[n-1];
    for (int i=2; i<n-2; i++){
        result[i] = p[i-2] + 3*p[i] + p[i+2];
    }
    result[n-2] = p[0] + p[n-4] + 3*p[n-2];
    result[n-1] = p[1] + p[n-3] + 3*p[n-1];
    return result;
}

vector<double> SteepestDescent::gradient(vector<double> x){
    int n = coefficients.size();
    vector<double> result = vector<double> (n, 0.0);
    result[0] = 3*x[0] + x[2] + x[n-2] - 1./n;
    result[1] = 3*x[1] + x[3] + x[n-1] - 2./n;
    for (int i=2; i<n-2; i++){
        result[i] = x[i-2] + 3*x[i] + x[i+2] - ((double)i)/n;
    }
    result[n-2] = x[0] + x[n-4] + 3*x[n-2] - (n-1)/n;
    result[n-1] = x[1] + x[n-3] + 3*x[n-1] - 1.;
    return result;
}
