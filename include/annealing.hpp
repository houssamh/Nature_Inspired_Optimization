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
    double temperatureInitial = 4;      // Initial temperature
    double temperatureMinimal = 0.0001; // Minimal temperature for the cooling
    double *xn;                         // The solution
    double alpha = 0.9;                 // Cooling rate
    void optimize();                    // Optimization function
    double maxStepLength = 0.001;       // Maximal step length

private:
    double temperature; // Actual temperature
};
