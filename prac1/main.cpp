#include <iostream>
#include "jacobi.h"
#include "gauss-seidel.h"
#include "sor.h"
#include "steepest-descent.h"

#define N 1e6
#define TOL 1e-12

using namespace std;

int main() {
    vector<double> coef(N, 0.0);
    for (int i = 0; i < N; i++) {
        coef[i] = (i+1.)/N;
    }

    cout << "\tJacobi algorithm" << endl;
    Jacobi jac = *(new Jacobi());
    jac.setCoefficients(coef);
    jac.setTolerance(TOL);
    jac.setMatrixNorm(2./3.);
    cout << "Solving system: " << endl;
    jac.run();

    cout << "\tGauss-Seidel algorithm" << endl;
    GaussSeidel ga = *(new GaussSeidel());
    ga.setCoefficients(coef);
    ga.setTolerance(TOL);
    ga.setMatrixNorm(2./3.);
    cout << "Solving system: " << endl;
    ga.run();

    cout << "\tSOR algorithm" << endl;
    Sor s = *(new Sor());
    s.setCoefficients(coef);
    s.setTolerance(TOL);
    s.setMatrixNorm(2./3.);
    /*cout << " Finding optimal parameter, please wait...." << endl;
    double bestParamSor = s.findBestParameter(20);*/
    double bestParamSor = 1.1;
    cout << "Solving system with best parameter = " << bestParamSor << " : " << endl;
    s.setOmega(bestParamSor);
    s.run();

    cout << "\tSteepest Descent algorithm" << endl;
    SteepestDescent st = *(new SteepestDescent());
    st.setCoefficients(coef);
    st.setTolerance(TOL);
    st.setMatrixNorm(2./3.);
    /*cout << " Finding optimal parameter, please wait...." << endl;
    double bestParamSteep = st.findBestParameter(20);*/
    double bestParamSteep = 0.9;
    cout << "Solving system with best parameter = " << bestParamSteep << " : " << endl;
    st.setOmega(bestParamSteep);
    st.run();

    return 0;
}