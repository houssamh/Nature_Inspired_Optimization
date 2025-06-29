/*
Simulated Annealing
*/
#include "optimization.hpp"
#include <cmath>
#include "functionsGrad.hpp"
#include <random>
#include <vector>

class simulatedAnnealing : public optimization
{
public:
    int dim;
    double temperatureInitial = 600; // Initial temperature
    double temperatureMinimal = 300; // Minimal temperature for the cooling
    double *xn;                      // The solution
    double alpha = 0.9;              // Cooling rate
    void optimize();                 // Optimization function
    double maxStepLength = 0.01;     // Maximal step length

private:
    double temperature; // Actual temperature
};
