
/*
Optimization functions for common properties
*/

#include "optimization.hpp"

// Write messages
void optimization::errorMessage()
{
    cout << "The error is equal to " << error << endl;
}
void optimization::convergenceMessage()
{
    cout << "Converged " << endl;
}
void optimization::iterationMessage(int iter, double valueObjective)
{
    cout << "iteration = " << iter << ", Objective =" << valueObjective << ", error = " << error << endl;
}