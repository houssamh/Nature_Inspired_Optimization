#include <vector>

// Loss function
double loss(std::vector<double> x)
{
    return x[0] * x[0] + x[1] * x[1];
}

// Loss function gradient
std::vector<double> grad(std::vector<double> x)
{
    return {2 * x[0], 2 * x[1]};
}