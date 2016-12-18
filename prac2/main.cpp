#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include "curve-ex12.h"

using namespace std;

#define TOL 1e-15
#define H 1e-2

double curveInitPoint();

vector<vector<double>> continuumMethod(double x_0, double y_0);

vector<double> newtonMethod(double x, double y, double x_0, double y_0);

vector<double> solveSystem(double x, double y, double x_0, double y_0);

int main() {
    double y_0 = curveInitPoint();
    vector<vector<double>> cont = continuumMethod(0.0f, y_0);
}

double curveInitPoint() {
    // Calculate between 0 and 1 (since there's change of sign, we use bisection)
    double t_0 = 0.0f, t_1 = 1.0f, midPoint;
    while ((t_1 - t_0) > TOL) {
        midPoint = (t_0 + t_1) / 2.0f;
        if (F_x0(midPoint) * F_x0(t_0) < 0.0f) {
            t_1 = midPoint;
        } else {
            t_0 = midPoint;
        }
    }
    return midPoint;
}

vector<vector<double>> continuumMethod(double x_0, double y_0) {
    vector<vector<double>> finalPoints;
    vector<double> newtonPoints;
    vector<double> gradPrev(2, 0.0), gradCurr;
    double normGrad, x = x_0, y = y_0;
    do {
        gradCurr = gradF(x, y);
        normGrad = sqrt(pow(gradCurr[0],2) + pow(gradCurr[1],2)) * H;
        if (gradPrev[0] * gradCurr[0] + gradPrev[1] * gradCurr[1] < 0.0f) {
            gradCurr[0] /= -normGrad;
            gradCurr[1] /= -normGrad;
        } else {
            gradCurr[0] /= normGrad;
            gradCurr[1] /= normGrad;
        }
        newtonPoints = newtonMethod(x + gradCurr[0], y + gradCurr[1], x, y);
        finalPoints.push_back(newtonPoints);
        x = newtonPoints[0];
        y = newtonPoints[1];
        gradPrev = gradCurr;
    } while (pow(x, 2) + pow(y - y_0, 2) < pow(H, 2) / 4);
    return finalPoints;
}

vector<double> newtonMethod(double x, double y, double x_0, double y_0) {
    double x_n = x, y_n = y;
    vector<double> h_n;
    while (fabs(F(x_n, y_n)) >= TOL) {
        h_n = solveSystem(x_n, y_n, x_0, y_0);
        x_n += h_n[0];
        y_n += h_n[1];
    }
    return {x_n, y_n};
}

vector<double> solveSystem(double x, double y, double x_0, double y_0) {
    vector<double> grad = gradF(x, y);
    double det = 2.0f * (grad[0] * (y - y_0) - grad[1] * (x - x_0));
    return {
            (-2.0f * (y - y_0) * F(x, y)
             - grad[1] * (pow(H, 2) - pow(x - x_0, 2) - pow((y - y_0), 2))) / det,
            (2.0f * (x - x_0) * F(x, y)
             + grad[0] * (pow(H, 2) - pow(x - x_0, 2) - pow((y - y_0), 2))) / det
    };
}