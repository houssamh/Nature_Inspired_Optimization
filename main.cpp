#include "metaheuristic.hpp"
#include <iostream>
using namespace std;

int main()
{
    // gradientDescent m1;
    gradientDescent op;
    op.errorTolerance = 1e-3;
    op.dim = 2;
    double x[2] = {0.1, 0.1};
    double solx, soly;
    op.xn = x;
    op.optimize();
    solx = op.xn[0];
    soly = op.xn[1];
    cout << "gradient descent solx= " << solx << endl;
    cout << "gradient descent soly= " << solx << endl;
    // pso
    pso ps;
    ps.dim = 2;
    ps.pNumber = 10;
    ps.iterNumber = 200;
    double pinf[2] = {-1, -1};
    double psup[2] = {1, 1};
    ps.bInf = pinf;
    ps.bSup = psup;
    ps.c1 = 1.7;
    ps.c2 = 1.7;
    ps.weigth = 0.7;
    ps.xn = x;
    ps.optimize();
    solx = ps.xn[0];
    soly = ps.xn[1];
    cout << "pso solx= " << solx << endl;
    cout << "pso soly= " << solx << endl;
    // simulated Annealing
    simulatedAnnealing sAn;
    sAn.dim = 2;
    sAn.xn = x;
    sAn.optimize();
    solx = sAn.xn[0];
    soly = sAn.xn[1];
    cout << "SimAn solx= " << solx << endl;
    cout << "SimAn soly= " << solx << endl;
}