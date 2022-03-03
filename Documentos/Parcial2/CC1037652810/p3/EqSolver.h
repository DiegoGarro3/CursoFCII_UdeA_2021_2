#ifndef EQSOLVER_H
#define EQSOLVER_H

#include <string>

#include <vector>

using namespace std;

class EqSystemSolver
{
public:
  EqSystemSolver(vector < vector<double> >, vector <double> );
  ~EqSystemSolver();
  vector <double> Jacobi();
  vector <double> Relaxation();


 private:
  double e;//step
  vector <double> initialval;
  vector <double> xsvalues;
  vector <double> sucdifconverge;
  vector < vector <double> > systemofeq;
  vector <double> b;
};
#endif
