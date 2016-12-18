#include "curve-ex12.h"

double F(double x, double y) {
    return ((3 * pow(x, 2)) + (3 * pow(y, 2)) - 1) * (pow(x, 2) + pow(y, 2) - 5) *
           (pow(x, 2) + pow(y, 2) - (3 * x) + 2) + 1;
}

vector<double> gradF(double x, double y) {
    return {
            18 * pow(x, 5)
            - 45 * pow(x, 4)
            + 4 * pow(x, 3) * (9 * pow(y, 2) - 10)
            - 18 * pow(x, 2) * (3 * pow(y, 2) - 8)
            + 2 * x * (9 * pow(y, 4) - 20 * pow(y, 2) - 27)
            - 9 * pow(y, 4)
            + 48 * pow(y, 2)
            - 15,

            2 * y *
            (9 * pow(x, 4)
             - 18 * pow(x, 3)
             + 2 * pow(x, 2) * (9 * pow(y, 2) - 10)
             - 6 * x * (3 * pow(y, 2) - 8)
             + 9 * pow(y, 4)
             - 20 * pow(y, 2)
             - 27)
    };
}

double F_x0(double y) {
    return 3 * pow(y, 6) - 10 * pow(y, 4) - 27 * pow(y, 2) + 11;
}
