#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

double F(double x, double y) {
    return (3*x*x + 3*y*y - 1)*(x*x + y*y - 5)*(x*x + y*y - 3*x +2) + 1;
}

vector<double> gradF(double x, double y) {
    vector<double> result(2,0.0);
    result[0] =
            18*pow(x,5)
            - 45*pow(x,4)
            + 4*pow(x,3)*(9*pow(y,2) - 10)
            - 18*pow(x,2)*(3*pow(y,2) - 8)
            + 2*x*(9*pow(y,4) - 20*pow(y,2) - 27)
            - 9*pow(y,4)
            + 48*pow(y,2)
            - 15;
    result[1] = 2*y*
            (9*pow(x,4)
             - 18*pow(x,3)
             + 2*pow(x,2)*(9*pow(y,2) - 10)
             - 6*x*(3*pow(y,2) - 8)
             - 9*pow(y,4)
             - 20*pow(y,2)
             - 27);
    return result;
}

