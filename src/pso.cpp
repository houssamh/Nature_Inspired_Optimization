/*
Particle swarm optimization
*/

#include "pso.hpp"

void pso::optimize()
{
    // Initialization
    vector<double> x(pNumber * dim, 0.);        // Actual positions of the pNumber particles strored in an array
    vector<double> pBest(pNumber * dim, 0.);    // Best positions of the pNumber particles
    vector<double> velocity(pNumber * dim, 0.); // Actual velocities of the pNumber particles
    vector<double> globalBest(dim, 0.);         // Global best position
    vector<double> xp(dim, 0);                  // Actual position for a given particle
    vector<double> pb(dim, 0);                  // Actual best position for a given particle
    random_device rand;
    mt19937 generator(rand());
    uniform_real_distribution<> UnifDistribution1(0, 1);
    for (int p = 0; p < pNumber; p++) // Loop on the particles
    {
        for (int i = 0; i < dim; i++) // Loop on the dimensions
        {
            uniform_real_distribution<> UnifDistribution(*(bInf + i), *(bSup + i)); // random value
            x[i + p * dim] = UnifDistribution(generator);
            pBest[i + p * dim] = x[i + p * dim];
            xp[i] = x[i + p * dim];
            if (p == 0) // Initialise the global best position to the first particle
            {
                globalBest[i] = pBest[i];
            }
        }
        if (objective(xp) < objective(globalBest))
        {
            globalBest = xp; // xp is the global best position
        }
    }
    cout << " " << endl;
    cout << "PSO algorithm" << endl;
    for (int iter = 0; iter < iterNumber; iter++)
    {
        for (int p = 0; p < pNumber; p++) // Loop on the particles
        {
            for (int i = 0; i < dim; i++)
            {
                double r1 = UnifDistribution1(generator);
                double r2 = UnifDistribution1(generator);
                // Update velocity
                velocity[i + p * dim] = weigth * velocity[i + p * dim] + c1 * r1 * (pBest[i + p * dim] - x[i + p * dim]) + c2 * r2 * (globalBest[i] - x[i + p * dim]);
                x[i + p * dim] += velocity[i + p * dim]; //  Update position
                xp[i] = x[i + p * dim];
                pb[i] = pBest[i + p * dim];
            }
            if (objective(xp) < objective(pb))
            {
                pb = xp; // xp is the best position
            }
            for (int i = 0; i < dim; i++)
            {
                pBest[i + p * dim] = pb[i]; // Store the best solution
            }
            if (objective(pb) < objective(globalBest))
            {
                globalBest = pb; // xp is the global best position
            }
        }
        double fValue = objective(globalBest); // Objective function value
        iterationShortMessage(iter, fValue);
    }
    for (int i = 0; i < dim; i++)
    {
        *(xn + i) = globalBest[i]; // The solution xn is the global best position
    }
}
