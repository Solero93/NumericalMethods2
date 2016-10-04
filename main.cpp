#include <iostream>
#include "jacobi.h"
#include "gauss-seidel.h"
#include "sor.h"

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

    cout << "Algorisme de Gauss-Seidel \n SOLUCIÓ DEL SISTEMA:" << endl;
    GaussSeidel ga = *(new GaussSeidel());
    ga.setCoefficients(coef);
    ga.setTolerance(TOL);
    ga.setMatrixNorm(2./3.);
    ga.run();

    cout << "Algorisme de SOR \n SOLUCIÓ DEL SISTEMA:" << endl;
    Sor s = *(new Sor());
    s.setCoefficients(coef);
    s.setTolerance(TOL);
    s.setMatrixNorm(2./3.);
    s.setOmega(1);
    s.run();

    return 0;
}