#ifndef UB_NUMERICALMETHODS2_LINEARSOLVER_H
#define UB_NUMERICALMETHODS2_LINEARSOLVER_H

#endif //UB_NUMERICALMETHODS2_LINEARSOLVER_H

#include <vector>
#include <stdexcept>

#define vec vector

using namespace std;

class LinearSolver {
public:
    double tolerance;
    double tolFactor; // Stored to optimize calculations

    double matrixNorm;
    vec<double> coefficients;
    vec<double> currentIterates;
    vec<double> previousIterates;
    vec<double>* algorithm;

    void setTolerance(double tolerance);
    void setMatrixNorm(double matrixNorm);
    void setOmega(double omega);
    void setCalcula(double calcula);
    void setAlgorithm(vec<double> *algorithm);

    LinearSolver();

    bool isFinished();
    void calculateTolFactor();
    double calculateNorm(std::vector<double> vec);
    vec<double> run();
};

vector<double> operator+(const vector<double>& lhs, const vector<double>& rhs){	// return type is a vector of integers
    if(lhs.size() != rhs.size()){	// Vectors must be the same size in order to add them!
        throw std::runtime_error("Can't add two vectors of different sizes!");
    }
    vector<double> result;	// Declaring the resulting vector, result
    for(int i=0; i < lhs.size(); i++){	// adding each element of the result vector
        result.push_back(lhs.at(i) + rhs.at(i));	// by adding each element of the two together
    }
    return result;	// returning the vector "result"
}

vector<double> operator-(const vector<double>& lhs, const vector<double>& rhs){	// return type is a vector of integers
    if(lhs.size() != rhs.size()){	// Vectors must be the same size in order to add them!
        throw std::runtime_error("Can't substract two vectors of different sizes!");
    }
    vector<double> result;	// Declaring the resulting vector, result
    for(int i=0; i < lhs.size(); i++){	// adding each element of the result vector
        result.push_back(lhs.at(i) - rhs.at(i));	// by adding each element of the two together
    }
    return result;	// returning the vector "result"
}

vector<double> operator*(const double& lhs, const vector<double>& rhs){	// return type is a vector of integers
    vector<double> result;	// Declaring the resulting vector, result
    for(int i=0; i < rhs.size(); i++){	// adding each element of the result vector
        result.push_back(lhs * rhs.at(i));	// by adding each element of the two together
    }
    return result;	// returning the vector "result"
}