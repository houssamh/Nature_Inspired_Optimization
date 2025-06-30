/*
Simulated Annealing
*/

#include "annealing.hpp"

void simulatedAnnealing::optimize()
{
    // Random generator
    random_device rand;
    mt19937 generator(rand());
    uniform_real_distribution<> UnifDistribution1(0, 1);
    uniform_real_distribution<> UnifDistribution2(-1, 1);
    // Initialization
    vector<double> xvector(dim);         // The solution array
    vector<double> xvectorNeighbor(dim); // A Neighbor of the actual position or the solution
    vector<double> step(dim);            // Step in order to obtain a neighbor
    double deltaE;                       // delta of the objective function between two iterations
    double randPoint;                    // A random point value between [0,1]
    double threesholdProb;               // if randPoint < threesholdProb => Accept the position or the solution
    double normSquare;
    for (int i = 0; i < dim; i++)
    {
        xvector[i] = *(xn + i);
    }
    temperature = temperatureInitial;

    while (temperature > temperatureMinimal) // Cooling procedure
    {
        cout << " " << endl;
        cout << "Temperature = " << temperature << endl;
        for (int iter = 0; iter < iterNumber; iter++) // Trying to find a minimum for each temperature
        {
            error = 0;
            deltaE = -objective(xvector);
            // Create a neighbor of the actual position
            normSquare = 0; // Norm of the neighbor step
            for (int i = 0; i < dim; i++)
            {
                step[i] = UnifDistribution2(generator); // random step
                normSquare += step[i] * step[i];
            }
            normSquare = sqrt(normSquare); // Step norm

            for (int i = 0; i < dim; i++)
            {
                // The step is normalized
                xvectorNeighbor[i] = xvector[i] + UnifDistribution1(generator) * maxStepLength * step[i] / normSquare;
            }

            deltaE += objective(xvectorNeighbor); // Delta E: Energy difference
            if (deltaE < 0)                       // The energy is reduced
            {
                xvector = xvectorNeighbor;
            }
            else
            {
                randPoint = UnifDistribution1(generator);
                threesholdProb = exp(-deltaE / temperature);
                if (randPoint < threesholdProb)
                {
                    xvector = xvectorNeighbor; // Accept the new solution even if the energy is increasing
                }
            }
            double fValue = objective(xvector); // Objective function value
            iterationShortMessage(iter, fValue);
        }

        temperature = alpha * temperature; // Reduce the temperature (Cooling)
    }
    for (int i = 0; i < dim; i++)
    {
        *(xn + i) = xvector[i]; // The solution xn
    }
}