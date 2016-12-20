#include <cmath>
#include "function-ex12.h"

/**
 * Returns F evaluated at a point P
 * @param p
 */
double F(Point p) {
    double x = p.x, y = p.y;
    return ((3 * pow(x, 2)) + (3 * pow(y, 2)) - 1) * (pow(x, 2) + pow(y, 2) - 5) *
           (pow(x, 2) + pow(y, 2) - (3 * x) + 2) + 1;
}

/**
 * Returns gradient of F evaluated at point P
 * @param p
 */
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

/**
 * Returns F with x=0, evaluated at y
 * @param y
 */
double F_x0(double y) {
    return 3 * pow(y, 6) - 10 * pow(y, 4) - 27 * pow(y, 2) + 11;
}

/**
 * Returns derivative of F with x=0 respect to y, evaluated at y
 * @param y
 */
double dF_x0(double y) {
    return 18 * pow(y, 5) - 40 * pow(y, 3) - 54 * y;
}