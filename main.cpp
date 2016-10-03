#include <iostream>
#include "jacobi.h"

#define N pow(10,6)
#define TOL pow(10,-12)

using namespace std;

int main() {
    vector<double> coef;
    for (int i = 0 ; i < N; i++) {
        coef[i] = 1./N;
    }
    Jacobi jac = *(new Jacobi());
    vector<double> a = jac.run();
    for(vector<double>::iterator it = a.begin(); it != a.end(); it++){
        cout << *it << endl;
    }

    return 0;
}