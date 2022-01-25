#include <string>
#include <functional>
#include <cmath>

using namespace std;

#include "DifEqSolver.h"
 
double foo(double x, double y) {
    return (y-pow(x,2)+1);
}

int main()
{ 
  //#define fu(x,y) (2*x)
  DifEqSolver DiffEq(&foo);
  DiffEq.integrationcomparison();

  return 0;
}
