#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point {
public :
    double x, y;
};

#define TOL_BISECT 1e-5
#define TOL 1e-12
#define D 1e-2

double F(Point p);

Point gradF(Point p);

double F_x0(double y);

double dF_x0(double y);

Point curveInitPoint();

vector<Point> continuumMethod(Point initP);

Point newtonMethod(Point currP, Point initP);

Point solveSystem(Point currP, Point initP);

int main() {
    Point initP = curveInitPoint();
    vector<Point> cont = continuumMethod(initP);
    for(Point p : cont) {
        cout << p.x << ", " << p.y << endl;
    }
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
    } while(fabs(f_point) > TOL);

    return {0.0, point};
}

vector<Point> continuumMethod(Point initP) {
    vector<Point> finalPoints;
    Point currP = initP;
    Point gradPrev = {0.0, 0.0}, gradCurr;
    double normGrad;

    do {
        gradCurr = gradF(currP);
        //gradCurr = {gradCurr.y, -gradCurr.x}; // Projectem a la tangent
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
    Point height;
    while (fabs(F(currP)) >= TOL) {
        height = solveSystem(currP, initP);
        currP = {currP.x + height.x, currP.y + height.y};
    }
    return currP;
}

Point solveSystem(Point currP, Point initP) {
    Point grad = gradF(currP);
    double yDiff = currP.y - initP.y, xDiff = currP.x - initP.x;
    double det = 2.0f * (grad.x * yDiff - grad.y * xDiff);
    return {
            (-2.0f * yDiff * F(currP)
             - (grad.y * (pow(D, 2) - pow(xDiff, 2) - pow(yDiff, 2)))) / det,
            (2.0f * xDiff * F(currP)
             + (grad.x * (pow(D, 2) - pow(xDiff, 2) - pow(yDiff, 2)))) / det
    };
}

double F(Point p) {
    double x = p.x, y = p.y;
    return ((3 * pow(x, 2)) + (3 * pow(y, 2)) - 1) * (pow(x, 2) + pow(y, 2) - 5) *
         (pow(x, 2) + pow(y, 2) - (3 * x) + 2) + 1;
}

Point gradF(Point p) {
    double x = p.x, y = p.y;
    return {(6 * x) * (x * x + y * y - 5) * (x * x + y * y - 3 * x + 2) +
	      (3 * x * x + 3 * y * y - 1) * (2 * x) * (x * x + y * y - 3 * x + 2) +
	    (3 * x * x + 3 * y * y - 1) * (x * x + y * y - 5) * (2 * x - 3),

            (6 * y) * (x * x + y * y - 5) * (x * x + y * y - 3 * x + 2) +
	      (3 * x * x + 3 * y * y - 1) * (2 * y) * (x * x + y * y - 3 * x + 2) +
	      (3 * x * x + 3 * y * y - 1) * (x * x + y * y - 5) * (2 * y)
    };
    /*return {
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
    };*/
}

double F_x0(double y) {
    return 3 * pow(y, 6) - 10 * pow(y, 4) - 27 * pow(y, 2) + 11;
}

double dF_x0(double y) {
    return 18 * pow(y, 5) - 40 * pow(y, 3) - 54 * y;
}