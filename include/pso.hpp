/*
Particle swarm optimization
*/
#include "optimization.hpp"
#include "functionsGrad.hpp"
#include <random>
#include <vector>

class pso : public optimization
{
public:
    int dim;             // Dimension of the solution
    int pNumber;         // Particle number
    double *xn;          // The solution
    double *bInf;        // inferior limit of the domain
    double *bSup;        // inferior limit of the domain
    double c1 = 1.7;     // Cognitive coefficient, for example between 1.5 and 2.
    double c2 = 1.7;     // Social coefficient, for example between 1.5 and 2.
    double weigth = 0.7; // Inertia weight, for example between 0.4 and 0.9
    void optimize();
};