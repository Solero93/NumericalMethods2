#include <limits>
#include "sor.h"

Sor::Sor() : LinearSolver() {
}

void Sor::setOmega(const double omega) {
    this->omega = omega;
}

vector<double> Sor::algorithm() {
    int n = coefficients.size();
    vector<double> previousIterates = vector<double> (n, 0.0);
    vector<double> currentIterates = vector<double> (n, 1.0);

    while(!(this->isFinished(previousIterates, currentIterates))) {
        previousIterates = currentIterates;

        currentIterates[0] = previousIterates[0] +
                (this->omega / 3) * (-(3*previousIterates[0] + previousIterates[2] + previousIterates[n-2]) + coefficients[0]);
        currentIterates[1] = previousIterates[1] +
                (this->omega / 3) * (-(3*previousIterates[1] + previousIterates[3] + previousIterates[n-1]) + coefficients[1]);
        for (int i=2; i<n-2; i++){
            currentIterates[i] = previousIterates[i] +
                    (this->omega / 3) * (-(currentIterates[i-2] + 3*previousIterates[i] + previousIterates[i+2]) + coefficients[i]);
        }
        currentIterates[n-2] = previousIterates[n-2] +
                (this->omega / 3) * (-(currentIterates[0] + currentIterates[n-4] + 3*previousIterates[n-2]) + coefficients[n-2]);
        currentIterates[n-1] = previousIterates[n-1] +
                (this->omega / 3) * (-(currentIterates[1] + currentIterates[n-3] + 3*previousIterates[n-1]) + coefficients[n-1]);

        numIterations++;
    }

    return currentIterates;
}

double Sor::findBestParameter(int numPartitions) {
    int minIters = numeric_limits<int>::max();
    double bestParam;
    for (int i=1; i<numPartitions; i++){
        this->numIterations = 0;
        this->setOmega((2.*i)/numPartitions);
        this->calculateTolFactor();
        this->algorithm();
        if (this->numIterations < minIters) {
            minIters = this->numIterations;
            bestParam = (2.*i)/numPartitions;
        }
    }
    this->numIterations = minIters;
    cout << " SOR found the best parameter was: " << bestParam << " and completed the task in " << numIterations << " iterations";
    return bestParam;
}
