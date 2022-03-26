#ifndef FINITEDIFEQSOL_H
#define FINITEDIFEQSOL_H

#include <vector>

using namespace std;

class FiniteDifEqSol
{
public:
  FiniteDifEqSol( const double (*)( double ), const double (*)( double ), const double (*)( double ), int );
  ~FiniteDifEqSol();

  void FiniteDifDiagMatrix();
  vector <double> PrintSolution();
  vector <double> getxinterv();


 private:
  //boundary conditions
  double a; // initial x
  double b; // final x
  double alfa; // y(a) in starting limit
  double beta; // y(b) in the final boundary
  const int N; //number of mesh points, subintervals
  double h;
  
  vector <double> ywSoluSystEq;
  vector <double> xinterv;
 
  const double (*p)(double);
  const double (*q)(double);
  const double (*r)(double);

};
#endif
