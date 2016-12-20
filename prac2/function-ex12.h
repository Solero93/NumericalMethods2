#ifndef NEWTONMETHOD_FUNCTION_EX12_H
#define NEWTONMETHOD_FUNCTION_EX12_H

class Point {
public :
    double x, y;
};

double F(Point p);

Point gradF(Point p);

double F_x0(double y);

double dF_x0(double y);

#endif //NEWTONMETHOD_FUNCTION_EX12_H
