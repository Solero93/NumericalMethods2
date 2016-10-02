#include <iostream>
#include "jacobi.h"

#define N pow(10,6)
#define TOL pow(10,-12)

using namespace std;

int main() {
    vec<double> coef;
    for (int i = 0 ; i < N; i++) {
        coef[i] = 1./N;
    }



    return 0;
}