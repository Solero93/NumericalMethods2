#include <iostream>
#include <vector>
#include <cmath>
#include "curve-ex12.h"

using namespace std;

#define TOL 1e-10

double curvePoint();

int main() {
    cout << curvePoint() << endl;
}

double curvePoint() {
    // Calculate between 0 and 1 (since there's change of sign, we use bisection)
    double y0 = 0.0f, y1 = 1.0f, midPoint;
    while ((y1-y0) > TOL) {
        midPoint = (y0 + y1) / 2.0f;
        if (F_x0(midPoint) * F_x0(y0) < 0.0f) {
            y1 = midPoint;
        } else {
            y0 = midPoint;
        }
    }
    return midPoint;
}