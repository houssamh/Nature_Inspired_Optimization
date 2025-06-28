/*
Gradient descent method
*/
#include "optimization.hpp"
#include <cmath>
#include "functionsGrad.hpp"
#include <random>
#include <vector>
/*
public: All public and protected members of Optimization
remain public and protected in this class
*/

class gradientDescent : public optimization
{
public:
    int dim;                // Space dimension
    double stepSize = 0.01; // Step size of the gradient descent
    double *xn;             // The solution
    void optimize();        // To optimize

private:
    void maxIterWarning();
};