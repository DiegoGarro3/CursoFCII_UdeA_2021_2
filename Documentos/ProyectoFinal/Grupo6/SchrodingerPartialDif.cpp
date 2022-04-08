#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream> // flujo de archivo
#include <sstream> 
#include <complex>

using namespace std;

#include "EqSolver.h"

void Print( vector <vector <complex <double>>> &psit, int Nx){
ofstream Solution( "Solution.dat", ios::app ); //the app (append parameter) writes at the end of the file without overwriting its information

         vector < vector < double> > modpsi; 
         for (int ix=0; ix<Nx; ix++){
           vector < double> modpsir;
           for (int jy=0; jy<Nx; jy++){ 
            double wfreal=real(psit[ix][jy]);
            double wfimag=imag(psit[ix][jy]);
            double mod=sqrt( pow(wfreal,2) + pow(wfimag,2) );
            modpsir.push_back(mod);
            //cout << fixed  << setw(20)<< left << mod;
            Solution << fixed  << setw(20)<< left << mod;
           }
           //cout << endl;
           Solution << endl;

           modpsi.push_back(modpsir);
         } 
         cout << "nextt" << endl;
         Solution << "nextt" << endl;


        }


vector <vector <complex<double>>> psi0( vector <vector <double>> x, vector <vector <double>> y, double x0, double y0, double sigma,double  k, double L, double Dy)
{
    /*
    Proposed wave function for the initial time t=0.
    Initial position: (x0, y0)
    Default parameters:
        - sigma = 0.5 -> Gaussian dispersion.
        - k = 15*np.pi -> Proportional to the momentum.
        
    Note: if Dy=0.1 use np.exp(-1j*k*(x-x0)), if Dy=0.05 use 
          np.exp(1j*k*(x-x0)) so that the particle will move 
          to the right.
    */

         int Nx = (L/Dy) + 1; // Number of points on the x axis.
         vector < vector <complex<double> > > psi;
         //reshape psi_vector as a spatial matrix
         for (int ix=0; ix<Nx; ix++){ 
           vector <complex<double>> psir;
           for (int iy=0; iy<Nx; iy++){ 
            complex <double> ei(0,-k*(x[ix][iy]-x0));
            complex <double> psigauss = exp(-(1/2)*( pow((x[ix][iy]-x0),2) + pow((y[ix][iy]-y0),2) )/pow(sigma,2) )*exp(ei);
            psir.push_back(psigauss);
           }
          psi.push_back(psir);

         }
    
         return psi;
}


vector <vector <complex<double>>> doubleSlit_interaction(vector <vector <complex<double>>>psi, int j0, int j1, int i0, int i1, int i2, int i3, double L, double Dy)
{  
    /*
    Function responsible of the interaction of the psi wave function with the 
    double slit in the case of rigid walls.
    
    The indices j0, j1, i0, i1, i2, i3 define the extent of the double slit. 
    slit. 
    
    Input parameters:
        
        psi -> Numpy array with the values of the wave function at each point 
               in 2D space.
    
        Indices that parameterize the double slit in the space of 
        points:
        
            Horizontal axis.
                j0 -> Left edge.
                j1 -> Right edge.
                
            Vertical axis.
                i0 -> Lower edge of the lower slit.
                i1 -> Upper edge of the lower slit.
                i2 -> Lower edge of upper slit.
                i3 -> Upper edge of upper slit.
    Returns the array with the wave function values at each point in 2D space 
    updated with the interaction with the double slit of rigid walls.
    */
    
    // We cancel the wave function inside the walls of the double slit.

    int Nx = (L/Dy) + 1; // Number of points on the x axis.
    for (int ix=0; ix<=i3; ix++){ for (int iy=j0; iy<=j1; iy++){ psi[iy][ix] = 0;}}
    for (int ix=i2; ix<=i1; ix++){ for (int iy=j0; iy<=j1; iy++){ psi[iy][ix] = 0;}}
    for (int ix=i0; ix<=Nx-1; ix++){ for (int iy=j0; iy<=j1; iy++){ psi[iy][ix] = 0;}}

    
    return psi;
}

int main(){
        
        // Ax=My=b Matrix Equation x is wavefunction for time t+h and y is wavefunction for time t
        double L = 5.; //8 // Well of width L. Shafts from 0 to +L.
        double Dy = 1.5; // Spatial step size.
        double Dt = pow(Dy,2)/4.; // Temporal step size.
        int Nx = (L/Dy) + 1; // Number of points on the x axis.
        int Ny = (L/Dy) + 1; // Number of points on the y axis.
        int Nt = 500; //500 // Number of time steps. 
        complex <double> delt(0,2*pow(Dy,2));
        complex <double> rx = -Dt/delt; // Constant to simplify expressions.
        complex <double> ry = -Dt/delt; // Constant to simplify expressions.
        int N = (Nx-2)*(Ny-2); // Number of unknown wf points in space, i = 1,...,Nx-2 and j = 1,...,Ny-2 cause 0 and Ny-1 are boundary conditions, unknown wavefunction points in space is a vector of length N, A Matrix is NxN
        cout << "Nx " << Nx << endl; 
        cout << "N " << N << endl; 
        //Initial position of the center of the Gaussian wave function.
        double x0 = L/5.;
        double y0 = L/2.;

        //Parameters of the double slit.
        double w = 0.2; // Width of the walls of the double slit.
        double s = 0.8; // Separation between the edges of the slits.
        double a = 0.4; // Aperture of the slits.

        //Indices that parameterize the double slit in the space of points.
        //Horizontal axis.
        int j0 = (1/(2*Dy)*(L-w)); // Left edge.
        int j1 = (1/(2*Dy)*(L+w)); // Right edge.
        //Eje vertical.
        int i0 = (1/(2*Dy)*(L+s) + a/Dy); // Lower edge of the lower slit.
        int i1 = (1/(2*Dy)*(L+s));        // Upper edge of the lower slit.
        int i2 = (1/(2*Dy)*(L-s));        // Lower edge of the upper slit.
        int i3 = (1/(2*Dy)*(L-s) - a/Dy); // Upper edge of the upper slit.

        //initialize potential matrix
        vector < vector < complex < double> > > v;
        for (int ik=0; ik<Nx; ik++){ 
          vector < complex < double > > vr;
          for (int jk=0; jk<Nx; jk++){vr.push_back(0);} 
          v.push_back(vr);} //set matrix size

        cout << "init v" << endl;
        vector < vector < complex <double> > > A;
        vector <vector <complex <double>> > M;
        //initialize matrixes A and M, Ax=My=b
        for (int ik=0; ik<=N-1; ik++){ //N values each row
          //cout << "row " << ik << endl;
          vector < complex <double> > Ar;
          vector < complex <double> > Mr;
          for (int jk=0; jk<=N-1; jk++){//cout << "column " << jk << endl; 
            Ar.push_back(0); Mr.push_back(0);} 
          A.push_back(Ar);M.push_back(Mr);} //set matrix size

        cout << "before A" << endl;
        //construct A and M matrix
        for (int k=0; k<=N-1; k++){

          // k is the index of a VECTOR, the number of wavefunction points in space  
          // defined as k = (j-1)*(Ny-2) + (i-1) //cambiar i por j
          int i = 1 + k%(Ny-2);  //row //index for spatial coordinates
          int j = 1 + floor( k/(Ny-2) ); //column

	   // Main central diagonal.
           complex <double> adiag( 1., imag(2.*rx + 2.*ry) + imag(Dt/2.*v[i][j]) );    
           complex <double> mdiag( 1., imag(- 2.*rx - 2.*ry) - imag(Dt/2.*v[i][j]) );
           cout << "diag" << endl;
	   A[k][k] = adiag;
	   M[k][k] = mdiag;
            
	   if (j != 1){ // Lower main diagonal.
		A[k][(j-2)*(Ny-2)+i-1] = -rx;
		M[k][(j-2)*(Ny-2)+i-1] = rx;
           }

	   if (j != Ny-2){ // Upper main diagonal.
		A[k][j*(Ny-2)+i-1] = -rx;
		M[k][j*(Ny-2)+i-1] = rx;
           }
           //if i=1 doesn't set the i-1 terms (first row of spacial lattice)
	   //in the first row of matrix A (k=0,nx-1,...) doesn't set the k-1 column of the k diagonal term
	   if (i != 1){ // Lower lone diagonal.
	        A[k][k-1] = -ry;
	        M[k][k-1] = ry;
           }
	   // in the last row doesn't set the k+1 column	
	   if (i != Nx-2){ // Upper lone diagonal.
		A[k][k+1] = -ry;
		M[k][k+1] = ry;
           }
        }

        //meshgrid
        vector < vector <double > > meshx;
        vector < vector <double > > meshy;
        vector <double > xx;
        double step=(L-0)/(Ny-2-1);
        for (int ix=0; ix<Nx; ix++){ xx.push_back(ix*step); vector <double > yy; for(int iy=0; iy<Nx; iy++){  yy.push_back(ix*step);} meshy.push_back(yy);}
        for (int ix=0; ix<Nx; ix++){ meshx.push_back(xx);}
        //for (int ik=0; ik<=Nx-1; ik++){ //N values each row
        //  for (int jk=0; jk<=Nx-1; jk++){cout << meshy[ik][jk] << " " ;} cout << endl;} //set matrix size
        //vector< vector<vector<complex <double>>> > psit;

        vector < vector <complex<double> > > psi; //spatial matrix

        psi = psi0(meshx,meshy,x0,y0,0.5,15*3.1415,L,Dy); //initial wavefunction
        cout << "psi0 created" << endl;
        //boundary conditions, 0 at the edges of the box
        for (int iy=0; iy<Nx; iy++){ psi[0][iy]=0;}
        for (int iy=0; iy<Nx; iy++){ psi[Nx-1][iy]=0;}
        for (int iy=0; iy<Nx; iy++){ psi[iy][0]=0;}
        for (int iy=0; iy<Nx; iy++){ psi[iy][Nx-1]=0;}
  
        psi = doubleSlit_interaction(psi, j0, j1, i0, i1, i2, i3,L,Dy); //eliminate the save function inside the slit

        //crea un archivo donde guardar los datos
 	ofstream Solution( "Solution.dat", ios::out );
        Print(psi,Nx);

        //We solve the matrix system at each time step in order to obtain the wave function.
        for(int t=1; t<=Nt-1; t++){
         cout << "t= " << t << endl;
         //reshape psi matrix to a vector
         vector < complex<double> > psi_vect;
         for (int ix=0; ix<Nx; ix++){ for (int jx=0; jx<Nx; jx++){ psi_vect.push_back(psi[jx][ix]);}}

         //Matrix multiplication My=b, b=mul
         vector < complex<double> > mul;
         for(int p=0;p<=N-1;p++){mul.push_back(0);} //set size
         for(int p=0;p<=N-1;p++){
	   mul[p]=0;
	     for(int k=0;k<=N-1;k++){mul[p]+=M[p][k]*psi_vect[k];}
         }

         //solve matrix equation with (A,mul)

         //C is real 2Nx2N matrix equivalent to complex A
         vector < vector < double> > C; //2N values each row
         for (int ik=0; ik<=N-1; ik++){ 
          vector < double> Cr;
          for (int jk=0; jk<=N-1; jk++){ Cr.push_back( real(A[ik][jk]) ); }  
          for (int jk=0; jk<=N-1; jk++){ Cr.push_back( -(imag(A[ik][jk])) ); }
          C.push_back(Cr);
         }

         for (int ik=0; ik<=N-1; ik++){ 
          vector < double> Cr2n;
          for (int jk=0; jk<=N-1; jk++){ Cr2n.push_back( imag(A[ik][jk]) ); }  
          for (int jk=0; jk<=N-1; jk++){ Cr2n.push_back( real(A[ik][jk]) ); }
          C.push_back(Cr2n);
         }
 
         //2N real vector equivalent to b 
         vector < double> bR;
         for (int ik=0; ik<=N-1; ik++){ bR.push_back( real(mul[ik]) ); }
         for (int ik=0; ik<=N-1; ik++){ bR.push_back( imag(mul[ik]) ); }
         
         vector <double> psi_2Nvect;
         //for (int ik=0; ik<=2*N-1; ik++){ //N values each row
         //  for (int jk=0; jk<=2*N-1; jk++){cout << C[ik][jk] << " " ;} cout << endl;} //set matrix size
         //for (int ik=0; ik<=2*N-1; ik++){ //N values each row
         //  cout << bR[ik] << " " ; } cout << endl;//set matrix size

         {
         EqSystemSolver system1(C,bR);
         cout << "\nSuccessive over-relaxation Method"  << endl;
         psi_2Nvect=system1.Relaxation();
         }

         //get real and imaginary parts 
         for (int ix=0; ix<=N-1; ix++){ 
          complex <double> psisubk(psi_2Nvect[ix],psi_2Nvect[ix+N]);
          psi_vect[ix]=psisubk;}
         
         //reshape psi_vector as a spatial matrix
         for (int iy=0; iy<Nx; iy++){ 
           vector <complex<double>> psir; //row of the psi matrix
           for (int ik=0; ik<Nx; ik++){ 
            psir.push_back(psi_vect[(ik+iy*L)]);
           }
          psi[iy]=psir;
         }

         //resulting matrix is [[psivect_0=psi_11,psivect_1=psi_21,...],[]] but it has to be [[psivect_0=psi_11,psivect_1=psi_12,...],[]] so we transpose the resulting matrix

         // Computing transpose of the matrix
         vector < vector <complex<double> > > psitrans;
         psitrans=psi0(meshx,meshy,x0,y0,0.5,15*3.1415,L,Dy);
         for (int i = 0; i < Nx; i++){
           for (int j = 0; j < Nx; j++){
             psitrans[j][i] = psi[i][j];
           }
         }
         cout << "mm" << endl;
         psi=psitrans;

         psi = doubleSlit_interaction(psi, j0, j1, i0, i1, i2, i3,L,Dy);
         Print(psi,Nx);
         //psit.push_back(psi); //psit is a vector of matrices


        } //end of time loop

}
