#ifndef OPTIMIZATION_HPP
#define OPTIMIZATION_HPP
/*
Optimization class for common properties
*/
#include <iostream>
using namespace std;

class optimization
{
public:
    double error = 1.;             // Error x_{n+1} -x_{n}
    double errorTolerance = 1.e-3; // Error tolerance
    int iterNumber = 100;          // Maximum iteration number

protected:
    void errorMessage();
    void convergenceMessage();
    void iterationMessage(int, double);
};

// Write messages
void optimization::errorMessage()
{
    cout << "The error is equal to " << error << endl;
}
void optimization::convergenceMessage()
{
    cout << "Converged " << endl;
}
void optimization::iterationMessage(int iter, double valueLoss)
{
    cout << "iteration = " << iter << ", Loss =" << valueLoss << ", error = " << error << endl;
}

#endif // OPTIMIZATION_HPP