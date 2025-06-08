/*
Optimization methods classes
*/
#include "optimization.hpp"
#include <cmath>
#include <iostream>
#include "functionsGrad.hpp"
#include <random>
#include <vector>
using namespace std;
/*
public: All public and protected members of Optimization
remain public and protected in this class
*/
/*
Gradient descent method
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

// Warning the maximum iteration number was reached
void gradientDescent::maxIterWarning()
{
    cout << "Maximum iteration number, " << iterNumber << ",was reached" << endl;
}

void gradientDescent::optimize()
{
    int iter = 0;
    vector<double> xvector(dim);
    for (int i = 0; i < dim; i++)
    {
        xvector[i] = *(xn + i);
    }
    cout << " " << endl;
    cout << "Gradient descent algorithm" << endl;
    while ((iter < iterNumber) && (error > errorTolerance))
    {
        error = 0;

        vector<double> gradient = grad(xvector); // Loss function gradient
        double fValue = loss(xvector);           // Loss function value

        for (int i = 0; i < dim; i++)
        {
            double diff = xvector[i];
            xvector[i] -= stepSize * gradient[i]; // Update x
            diff -= xvector[i];
            if (fabs(diff) > error)
            {
                error = fabs(diff); // Max absolute error
            }
        }
        iterationMessage(iter, fValue);
        iter += 1;
    }
    for (int i = 0; i < dim; i++)
    {
        *(xn + i) = xvector[i];
    }
    if (iter == iterNumber)
    {
        maxIterWarning();
    }
    if ((iter < iterNumber) && (error < errorTolerance)) // Converged ?
    {
        convergenceMessage();
    }
    errorMessage();
}

/*
Particle swarm optimization
*/
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
        if (loss(xp) < loss(globalBest))
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
            if (loss(xp) < loss(pb))
            {
                pb = xp; // xp is the global best position
            }
            if (loss(pb) < loss(globalBest))
            {
                globalBest = xp; // xp is the global best position
            }
        }
        double fValue = loss(globalBest); // Loss function value
        iterationMessage(iter, fValue);
    }
    for (int i = 0; i < dim; i++)
    {
        *(xn + i) = globalBest[i]; // The solution xn is the global best position
    }
}
