#ifndef FUNCTIONSGRAD_HPP
#define FUNCTIONSGRAD_HPP

#include <vector>

// Objective function
double objective(std::vector<double> x);
// Objective function gradient
std::vector<double> grad(std::vector<double> x);

#endif // FUNCTIONSGRAD_HPP