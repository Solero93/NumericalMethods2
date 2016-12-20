#include <cmath>
#include "function-ex12.h"

double F(Point p) {
    double x = p.x, y = p.y;
    return ((3 * pow(x, 2)) + (3 * pow(y, 2)) - 1) * (pow(x, 2) + pow(y, 2) - 5) *
           (pow(x, 2) + pow(y, 2) - (3 * x) + 2) + 1;
}

Point gradF(Point p) {
    double x = p.x, y = p.y;
    return {(6 * x) * (pow(x, 2) + pow(y, 2) - 5) * (pow(x, 2) + pow(y, 2) - 3 * x + 2) +
            (3 * pow(x, 2) + 3 * pow(y, 2) - 1) * (2 * x) * (pow(x, 2) + pow(y, 2) - 3 * x + 2) +
            (3 * pow(x, 2) + 3 * pow(y, 2) - 1) * (pow(x, 2) + pow(y, 2) - 5) * (2 * x - 3),

            (6 * y) * (pow(x, 2) + pow(y, 2) - 5) * (pow(x, 2) + pow(y, 2) - 3 * x + 2) +
            (3 * pow(x, 2) + 3 * pow(y, 2) - 1) * (2 * y) * (pow(x, 2) + pow(y, 2) - 3 * x + 2) +
            (3 * pow(x, 2) + 3 * pow(y, 2) - 1) * (pow(x, 2) + pow(y, 2) - 5) * (2 * y)
    };
}

double F_x0(double y) {
    return 3 * pow(y, 6) - 10 * pow(y, 4) - 27 * pow(y, 2) + 11;
}

double dF_x0(double y) {
    return 18 * pow(y, 5) - 40 * pow(y, 3) - 54 * y;
}