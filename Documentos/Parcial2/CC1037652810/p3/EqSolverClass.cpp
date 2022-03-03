#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <functional>
#include <math.h>
#include <vector>

#include "EqSolver.h"

using namespace std;

// el constructor inicializa las variables privadas
EqSystemSolver::EqSystemSolver(vector < vector<double> > Matrix, vector <double> eq)
{

 systemofeq=Matrix;
 b=eq;
 
 double initialx=0, step=1, convergdifcriterion=0; //static

 size_t systemvectsize=systemofeq.size();
 for (size_t i=1; i<=systemvectsize; i++){ //to set initial guess and the other private vectors
	 cout << "Introdusca el valor inicial de la variable " << i << endl;
	 cin >> initialx;
	 initialval.push_back(initialx);
         xsvalues.push_back(0);
         sucdifconverge.push_back(100);

 }

 cout<< setprecision(6)<< fixed;
 cout<<"Enter tolerable error: ";
 cin>>convergdifcriterion;
 e=convergdifcriterion;

}
EqSystemSolver::~EqSystemSolver(){
	cout<< "Class constructor deleted\n" << endl;
}

vector <double> EqSystemSolver::Jacobi()
{  
  size_t systemvectsize=systemofeq.size();
  cout << systemvectsize << endl;
  int k=1; //step
  int N=100; //maximum number of iterations
  cout << fixed << left << setw(15) << "x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "x4" << setw(25) << "how many var converged?" << endl;
  while ( k<=N){ //Maximum number of steps

    for (int i=0; i<systemvectsize; i++){ //over the number fo variables
      //to do the summatory of the equation
      double sumatoria=0;
      for (int j=0; j<systemvectsize; j++){
        if (j!=i){  
              sumatoria=sumatoria+systemofeq[i][j]*initialval[j];
        }
      } //end summatory  

      xsvalues[i]=(1/systemofeq[i][i])*(b[i]-sumatoria);
      sucdifconverge[i]=fabs(xsvalues[i]-initialval[i]);
      cout  << fixed << setw(15) << left << xsvalues[i]; 
    } //all x_i values of k+1 iteration calculated


    int whichconv=0; // how many converged?
    for (int ii=0; ii<sucdifconverge.size(); ii++) { if (sucdifconverge[ii]<e){ whichconv=whichconv+1; } } //end if, then end for
    cout << fixed << setw(25) << left << whichconv << endl;
    
    if (whichconv==sucdifconverge.size() ){
          cout << "converged under the specific tolerance"  <<  endl; 
          cout << "number of iterations/steps: " << k << endl; 
          return xsvalues; 
    } 

    k=k+1;//step
    for (int jj=0; jj<systemvectsize; jj++){initialval[jj]=xsvalues[jj];}//set X0 for the next iteration/step
  } //end while
  cout << "the system didn't converged" << endl; 
  return xsvalues;
}


vector <double> EqSystemSolver::Relaxation()
{  
  size_t systemvectsize=systemofeq.size();
  int k=1; //step
  int N=100; //maximum number of iterations
  double w=1.25; //parameter of the SOR (Relaxation method)
  cout << fixed << left << setw(15) << "x1" << setw(15) << "x2" << setw(15) << "x3" << setw(15) << "x4" << setw(25) << "how many var converged?" << endl;
while ( k<=N){ //Maximum number of steps

    for (int i=0; i<systemvectsize; i++){ //over the number fo variables
      //to do the summatory of the equation
      double sumatoria=0;
      for (int j=0; j<systemvectsize; j++){
        if (j>=0 && j<=i-1){  
              sumatoria=sumatoria+systemofeq[i][j]*xsvalues[j];
        }
        if (j>=i+1 && j<systemvectsize){ //till  systemvectsize-1 'cause it starts in 0
              sumatoria=sumatoria+systemofeq[i][j]*initialval[j];
        }
      } //end summatory  

      xsvalues[i]=(1-w)*initialval[i]+(1/systemofeq[i][i])*w*(b[i]-sumatoria);
      sucdifconverge[i]=fabs(xsvalues[i]-initialval[i]);
      cout  << fixed << setw(15) << left << xsvalues[i]; 
    } //all x_i values of k+1 iteration calculated


    int whichconv=0; // how many converged?
    for (int ii=0; ii<sucdifconverge.size(); ii++) { if (sucdifconverge[ii]<e){ whichconv=whichconv+1; } } //end if, then end for
    cout << fixed << setw(25) << left << whichconv << endl;
    
    if (whichconv==sucdifconverge.size() ){
          cout << "converged under the specific tolerance"  <<  endl; 
          cout << "number of iterations/steps: " << k << endl; 
          return xsvalues; 
    } 

    k=k+1;//step
    for (int jj=0; jj<systemvectsize; jj++){initialval[jj]=xsvalues[jj];}//set X0 for the next iteration/step
  } //end while
  cout << "the system didn't converged" << endl; 
  return xsvalues;
}

