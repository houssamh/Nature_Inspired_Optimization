
/*
Gradient descent method
*/

#include "gradientDescent.hpp"

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

        vector<double> gradient = grad(xvector); // Objective function gradient
        double fValue = objective(xvector);      // Objective function value

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