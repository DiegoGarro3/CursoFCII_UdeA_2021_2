#include<vector>
#include<iostream>
#include<iomanip>


using namespace std;

//template function for Jacobi method 
vector<double>  Jacobi(vector<vector<double>>,vector<double>); 

//template function for SOR method 
vector<double>  SOR(vector<vector<double>>,vector<double>,double);



int main()
{
    
    /* 
    Enter the coefficient Matriz for the equation system
    e.g: for a system a11*x1+a12*x2+...a1n*xn=b1
                      a21*x1+a22*x2+...a2n*xn=b2
                        .      .        .     .
                        .      .        .     .
                        .      .        .     .                                        
                      an1*x1+an2*x2+...ann*xn=bn

    the coeficient matrix is:
    {  {a11,a12,...,a1n},
       {a21,a22,...,a2n},
          .   .   .
          .   .   .
          .   .   .
       {an1,an2,...,ann}  }


    */

    vector<vector<double>> coef ={  {10,-1,2,0},
                                    {-1,11,-1,3},
                                    {2,-1,10,-1},
                                    {0,3,-1,8}  };


    /* Enter the  constant coeficients as a vector
    {b1,b2,...bn}
    */
    vector<double> cons = {6.0, 25.0, -11.0, 15.0};

    //Jacobi solution
    vector<double> sol_jacobi;
    sol_jacobi = Jacobi(coef,cons);

    //SOR solution
    vector<double> sol_SOR;
    sol_SOR = SOR(coef,cons,1.25);


    cout << "|" << setw(6) << fixed << "Raices" << "|" 
    << setw(13) << fixed << "Jacobi " << "|"
    << setw(13) << fixed << "SOR" << "|"
    << endl;

    cout << "------------------------------------" 
    << endl;

    unsigned int dim = sol_jacobi.size(); //number of equations

    //print and compare solutions of both methods
    for(unsigned int i=0; i<dim;i++) 
    {
        cout << "|" << setw(5) << fixed << "x_" << i+1 << "|" 
        << setw(13) << fixed << setprecision(4) << sol_jacobi[i] << "|"
        << setw(13) << fixed << setprecision(4) << sol_SOR[i] << "|"
        << endl;
        
    }

}


vector<double> Jacobi(vector<vector<double>> coeficientes,vector<double> constantes)
    /*
    Define function of Jacobi method that recives:
        Coefficient matrix
        Constant coeficients vector

    and returns solution vector
    */
{
    unsigned int dimension = constantes.size(); //number of equations
    vector<double> x0(dimension,0); //initial solution approximation  
    vector<double> xk(dimension,0); //vector to store solutions

    unsigned int m = 0;
    while(m < 1000) //Number of iterations
    {
        for(unsigned int i=0;i<dimension;i++)
        {   
            xk[i] = 0;
            
            for(unsigned int j=0;j<dimension;j++)
            {
                if(i!=j)
                {
                    xk[i] += (-coeficientes[i][j]*x0[j])/coeficientes[i][i]; //recurence equation
                }
                
            }  

            xk[i] += constantes[i]/coeficientes[i][i]; //adding coefficients
        }

        x0 = xk; //actualize solution approximation   

        m++;
    }


    return xk; //return solution vector 

}

//Definne function of SOR method
vector<double> SOR(vector<vector<double>> coeficientes,vector<double> constantes, double omega)
{   
    /*
    Define function of SOR method that recives:
        Coefficient matrix
        Constant coeficients vector
        Relaxation parameter- omega

    and returns solution vector
    */

    unsigned int dimension = constantes.size(); //number of equations
    vector<double> x0(dimension,0); //initial solution approximation
    vector<double> xk(dimension,0); //vector to store solutions

    unsigned int m = 0;
    while(m < 1000) //Number of iterations
    {
        for(unsigned int i=0;i<dimension;i++)
        {   
            xk[i] = 0;
            
            for(unsigned int j=0;j<i;j++)
            {
                //recurence equation part 1
                xk[i] += omega*(-coeficientes[i][j]*xk[j])/coeficientes[i][i]; 
                
                
            }  

            for(unsigned int k=i+1;k<dimension;k++)
            {
                //recurence equation part 2
                xk[i] += omega*(-coeficientes[i][k]*x0[k])/coeficientes[i][i]; 
                
                
            }
            //putting together part 1 and part 2 of recurence equation
            //and adding constant coeficients
            xk[i] += (1-omega)*x0[i]+omega*(constantes[i]/coeficientes[i][i]);
        }

        x0 = xk; //actualize solution approximation

        m++;
    }


    return xk; //return solution vector 

}




