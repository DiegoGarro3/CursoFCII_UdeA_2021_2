#include <string>
#include <functional>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

#include "EqSolver.h"
 


int main()
{  
  vector <vector <double>> systemofeq= {{10,-1,2,0},{-1,11,-1,3},{2,-1,10,-1},{0,3,-1,8}};
  vector <double> b={6,25,-11,15};
  vector <double> sol={0,0,0,0};


  {
  EqSystemSolver system1(systemofeq,b);
  cout << "\nJacobi Method"  << endl;
  sol=system1.Jacobi();
  }

  {
  EqSystemSolver system2(systemofeq,b);
  cout << "\nSuccessive over-relaxation Method"  << endl;
  sol=system2.Relaxation();
  }

  cout << "El metodo Successive Over-Relaxation converge con la tolerancia esperada y con w=1.25 en menos iteraciones que el metodo de Jacobi, esto se ve cada vez más a medida que el error de tolerancia es menor." << endl;

  return 0;
}
