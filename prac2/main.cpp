#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "function-ex12.h"

using namespace std;

#define TOL_BISECT 1e-5
#define TOL 1e-12
#define D 1e-2

Point curveInitPoint();

vector<Point> continuumMethod(Point initP);

Point newtonMethod(Point currP, Point initP);

int main() {
    Point initP = curveInitPoint();
    vector<Point> cont = continuumMethod(initP);
    ofstream resultFile;
    resultFile.open("results.txt");
    for (Point p : cont) {
        resultFile << p.x << ", " << p.y << "\n";
    }
    resultFile.close();
    return 0;
}

Point curveInitPoint() {
    // Calculate between 0 and 1 (since there's change of sign, we use bisection)
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
    // Since we are near enough, we do Newton-Raphson
    do {
        point -= F_x0(point) / dF_x0(point);
        f_point = F_x0(point);
    } while (fabs(f_point) > TOL);

    return {0.0, point};
}

vector<Point> continuumMethod(Point initP) {
    vector<Point> finalPoints;
    Point currP = initP;
    Point gradPrev = {0.0, 0.0}, gradCurr;
    double normGrad;

    do {
        gradCurr = gradF(currP);
        gradCurr = {gradCurr.y, -gradCurr.x}; // Orthogonal to gradient

        normGrad = sqrt(pow(gradCurr.x, 2) + pow(gradCurr.y, 2));

        gradCurr = {D * gradCurr.x / normGrad, D * gradCurr.y / normGrad};
        if (gradPrev.x * gradCurr.x + gradPrev.y * gradCurr.y < 0.0f)
            gradCurr = {-gradCurr.x, -gradCurr.y};

        currP = newtonMethod(
                {currP.x + gradCurr.x, currP.y + gradCurr.y},
                {currP.x, currP.y});
        finalPoints.push_back(currP);
        gradPrev = gradCurr;
    } while (pow(currP.x - initP.x, 2) + pow(currP.y - initP.y, 2) > pow(D, 2) / 4);
    return finalPoints;
}

Point newtonMethod(Point iterP, Point initP) {
    Point currP = iterP;
    Point grad, height;
    double yDiff, xDiff, det;
    while (fabs(F(currP)) >= TOL) {
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
        currP = {currP.x + height.x, currP.y + height.y};
    }
    return currP;
}