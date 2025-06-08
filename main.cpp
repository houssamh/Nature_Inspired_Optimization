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
    op.xn = x;
    op.optimize();
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
    double solx, soly;
    ps.xn = x;
    ps.optimize();
    solx = ps.xn[0];
    soly = ps.xn[1];
    cout << "pso solx= " << solx << endl;
    cout << "pso soly= " << solx << endl;
}