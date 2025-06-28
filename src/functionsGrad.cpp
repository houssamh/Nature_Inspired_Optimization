#include "functionsGrad.hpp"

// Objective function
double objective(std::vector<double> x)
{
    return x[0] * x[0] + x[1] * x[1];
}

// Objective function gradient
std::vector<double> grad(std::vector<double> x)
{
    return {2 * x[0], 2 * x[1]};
}