#include <iostream>
#include "jacobi.h"

#define N pow(10,6)
#define TOL pow(10,-12)

using namespace std;

int main() {
    vector<double> coef(N, 0.0);
    for (int i = 0; i < N; i++) {
        coef[i] = (i+1)/N;
    }
    cout << "Algorisme de Jacobi \n SOLUCIÓ DEL SISTEMA:" << endl;
    Jacobi jac = *(new Jacobi());
    jac.setCoefficients(coef);
    jac.setTolerance(TOL);
    jac.setMatrixNorm(2./3.);
    jac.run();

    return 0;
}