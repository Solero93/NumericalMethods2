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

    cout << "Algorisme de SOR" << endl;
    Sor s = *(new Sor());
    s.setCoefficients(coef);
    s.setTolerance(TOL);
    s.setMatrixNorm(2./3.);
    cout << " Finding optimal parameter, please wait...." << endl;
    /*double bestParam = s.findBestParameter(20);
    cout << "Solving system with best parameter: " << endl;
    s.setOmega(bestParam);
    s.run();*/
    s.setOmega(1.);
    s.run();

    cout << "Algorisme de Steepest Descent" << endl;
    SteepestDescent st = *(new SteepestDescent());
    st.setCoefficients(coef);
    st.setTolerance(TOL);
    st.setMatrixNorm(2./3.);
/*    cout << " Finding optimal parameter, please wait...." << endl;
    double bestParam = s.findBestParameter(20);
*/    cout << "Solving system with best parameter: " << endl;
    st.setOmega(1.);
    st.run();


    return 0;
}