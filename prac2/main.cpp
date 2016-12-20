#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "function-ex12.h"

using namespace std;

#define TOL_BISECT 1e-5 // Tolerance for bisection method
#define TOL 1e-12 // General tolerance < 1e-10
#define D 1e-2 // Distance between points on curve

Point curveInitPoint();
vector<Point> continuumMethod(Point initP);
Point newtonMethod(Point currP, Point initP);

int main() {
    // Calculate initial point on curve
    Point initP = curveInitPoint();

    // Calculate points on curve that are separated by a distance of D
    vector<Point> cont = continuumMethod(initP);

    // Write points to file to plot them with gnuplot
    ofstream resultFile;
    resultFile.open("results.txt");
    for (Point p : cont) {
        resultFile << setprecision(11) << p.x << ", " << setprecision(11) << p.y << "\n";
    }
    resultFile.close();
    return 0;
}

/**
 * Calculates set of points on curve separated by a distance D
 * @param initP - point to begin with on curve
 */
vector<Point> continuumMethod(Point initP) {
    vector<Point> finalPoints;
    Point currP = initP;
    Point gradPrev = {0.0, 0.0}, gradCurr;
    double normGrad;
    do {
        // Calculate tangent vector
        // Which is orthogonal to the gradient
        gradCurr = gradF(currP);
        gradCurr = {gradCurr.y, -gradCurr.x};

        // Make tangent vector have a norm of D (normalize and multiply by D)
        // Since we're searching for points at a distance D
        normGrad = sqrt(pow(gradCurr.x, 2) + pow(gradCurr.y, 2));
        gradCurr = {D * gradCurr.x / normGrad, D * gradCurr.y / normGrad};

        // To avoid going back and forth
        // Control the direction by looking at the angle between consequent gradients
        if (gradPrev.x * gradCurr.x + gradPrev.y * gradCurr.y < 0.0f)
            gradCurr = {-gradCurr.x, -gradCurr.y};

        // Obtain the next point on the curve using Newton Method
        currP = newtonMethod(
                {currP.x + gradCurr.x, currP.y + gradCurr.y},
                {currP.x, currP.y});

        // Add found point to the result vector and continue
        finalPoints.push_back(currP);
        gradPrev = gradCurr;

        // Do this while we don't go back to the same place
    } while (pow(currP.x - initP.x, 2) + pow(currP.y - initP.y, 2) > pow(D, 2) / 4);
    return finalPoints;
}

/**
 * Given an initial point, computes another 0 of the curve separated by a distance D
 * @param iterP - initial point
 * @param initP - known solution
 */
Point newtonMethod(Point iterP, Point initP) {
    Point currP = iterP;
    Point grad, height;
    double yDiff, xDiff, det;

    // While we're not at a 0
    while (fabs(F(currP)) >= TOL) {
        // Solve system of equations to find Newton's method's height to add to the next iterate
        grad = gradF(currP);
        yDiff = currP.y - initP.y;
        xDiff = currP.x - initP.x;
        det = 2.0f * (grad.x * yDiff - grad.y * xDiff);
        height = {
                (-2.0f * yDiff * F(currP)
                 - (grad.y * (pow(D, 2) - pow(xDiff, 2) - pow(yDiff, 2)))) / det,
                (2.0f * xDiff * F(currP)
                 + (grad.x * (pow(D, 2) - pow(xDiff, 2) - pow(yDiff, 2)))) / det
        };
        // Find next iterate by doing x_n+1 = x_n + h_n
        currP = {currP.x + height.x, currP.y + height.y};
    }
    return currP;
}

/**
 * Letting x=0, find a suitable "y" to begin with
 */
Point curveInitPoint() {
    // Calculate a 0 of the function between y=2 and y=3
    // Since there's change of sign, we use bisection
    double t_0 = 2.0f, t_1 = 3.0f, point, f_point;
    do {
        point = (t_0 + t_1) / 2.0f;
        f_point = F_x0(point);
        if (f_point * F_x0(t_0) < 0.0f) {
            t_1 = point;
        } else {
            t_0 = point;
        }
    } while (fabs(t_0 - t_1) > TOL_BISECT);
    // Since we are near enough, we use Newton-Raphson to accelerate
    do {
        point -= f_point / dF_x0(point);
        f_point = F_x0(point);
    } while (fabs(f_point) > TOL);

    return {0.0, point};
}