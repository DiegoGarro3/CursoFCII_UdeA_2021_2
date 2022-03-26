#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream> // flujo de archivo
#include <sstream> 

using namespace std;

#include "FiniteDifEqSol.h"

FiniteDifEqSol::FiniteDifEqSol (const double (*pf)( double ), const double (*qf)( double ), const double (*rf)( double ), const int Subintervals)
// Set Dif Eq function coefficients 
// y''(x)=p(x)*y'+q(x)*y+r(x)
 : p(pf), q(qf), r(rf), N(Subintervals)
{
        //getting boundary conditions:
         
	//boundary points
	double x0{0}; // initial x
	double xf{0}; // final x
	//boundary conditions
	double y0{0}; // y(a) in starting limit
	double yf{0}; // y(b) in the final boundary
	//N+1 Subintervals
	//int N=9; //35; //for wave equation //9 for example1; 

	cout << "x0 de la condicion de frontera, a=" << endl;
        cin >> x0;
	cout << "xf de la condicion de frontera, b=" << endl;
        cin >> xf;
	cout << "y0 de la condicion de frontera, alfa=" << endl;
        cin >> y0;
	cout << "yf de la condicion de frontera, beta=" << endl;
        cin >> yf;
        a=x0;
        b=xf;
        alfa=y0;
        beta=yf;
        h = (b-a)/(N+1); //intervals size

        FiniteDifDiagMatrix();
}

FiniteDifEqSol::~FiniteDifEqSol()
{
cout << "Dif Eq Diagonal Matrix Instance Destructed " << endl;
cout << "\n\n";
}

void FiniteDifEqSol::FiniteDifDiagMatrix()
{
        // Aw=b Matrix Equation
        // the coefficients of the diagonal matrix A a,b and c are the tridiagonal coefs of A and d are the entries of b for each row
        // this is, each entry corresponds to each row.
        vector <double> bSystEqRows(N+1);
        vector <double> cSystEqRows(N+1);
        vector <double> dSystEqRows(N+1);
        vector <double> aSystEqRows(N+1); // function coeffiecients of the equation system obtained from the differential equation in the x-mesh./ matrix equation, each row is a vector's entry 

        vector <double> wSoluSystEq(N+1);
        ywSoluSystEq=wSoluSystEq; // set the private variable for solutions as a N+1 length vector

        //######### first row, row for x1 #########
	double x = a+h;
	//in A
	double a1 = 2 + pow(h,2)*q(x);
	double b1 = -1+(h/2)*p(x);
	//in b
	double d1 =-pow(h,2)*r(x)+(1+(h/2)*p(x))*alfa;
	aSystEqRows[1]=a1;
	bSystEqRows[1]=b1;
	dSystEqRows[1]=d1;


	// due to mesh points
	//A from Aw=b, is the y solution of the differential equation
	for (int i=2; i<=N-1; i++){ // ### for each row ###

	  x=a+i*h; //subintervals of mesh points
	  //in A
	  aSystEqRows[i] = 2+pow(h,2)*q(x);
	  bSystEqRows[i] = (h/2)*p(x)-1;
	  cSystEqRows[i] = -(1+(h/2)*p(x));
	  //in b
	  dSystEqRows[i] = -pow(h,2)*r(x);
	}
         
        //#### last row ####
	x = b-h;
	aSystEqRows[N] = 2+pow(h,2)*q(x);
	cSystEqRows[N] = -(1+(h/2)*p(x));
	dSystEqRows[N] = -pow(h,2)*r(x)+(1-(h/2)*p(x))*beta;
	  
	//#### then we solve the tridiagonal matrix equation/ system of equations ####
	// with LU factorization of the tridiagonal matrix
        // we first solve Lz=b for z, after that we solve Ux=z for x, then the solution is w=x

        vector <double> lj(N+1);
	vector <double> uj(N+1);
	vector <double> zj(N+1);

        // to solve Lz=b for z
	double l1 = a1;
    	double u1 = b1/a1;
	double z1 = d1/l1;
	lj[1]=l1;
	uj[1]=u1;
	zj[1]=z1;

	for (int j=2; j<=N-1; j++){
	  lj[j]=aSystEqRows[j]-cSystEqRows[j]*uj[j-1];
          uj[j]=bSystEqRows[j]/lj[j];
	  zj[j]=(dSystEqRows[j]-cSystEqRows[j]*zj[j-1])/lj[j];
        }
	
	lj[N]=aSystEqRows[N]-cSystEqRows[N]*uj[N-1];
	zj[N]=(dSystEqRows[N]-cSystEqRows[N]*zj[N-1])/lj[N];
        
        //after last z we solve Ux=z from the last to the first term, due to the zeros of the matrix U from A=LU

	ywSoluSystEq[0]=alfa;
	ywSoluSystEq[N+1]=beta;
	ywSoluSystEq[N]=zj[N];
	for (int irev=N-1; irev>=1; irev--){ ywSoluSystEq[irev]= zj[irev] - uj[irev]*ywSoluSystEq[irev+1]; }
}

vector <double> FiniteDifEqSol::PrintSolution()
{
        double x;
        //crea un archivo donde guardar los datos
 	ofstream SolutionofDE( "SolutionDifEq.dat", ios::out );
 	SolutionofDE << fixed << "xi" << setw(15) << "y(xi)" << endl;
        cout << fixed << setw(20) << left << "xi" << setw(20) << left << "y(xi)" << endl;
	for (int ii=0; ii<=N+1; ii++){ 
          x = a + ii*h; 
          xinterv.push_back(x);
          cout << fixed  << setw(20)<< left << x << setw(20) << left << ywSoluSystEq[ii] << endl; 
          SolutionofDE << fixed  << x << setw(15) << ywSoluSystEq[ii] << endl;
        }
	return ywSoluSystEq; 
}
vector <double> FiniteDifEqSol::getxinterv()
{ return xinterv;
}
