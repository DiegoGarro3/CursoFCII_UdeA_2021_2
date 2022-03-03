#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

#include "SOR.h"

using namespace std;

vector<double> SOR(vector<vector<double> > A, vector<double> b, vector<double> guess, double TOL, double w, int N){

    //STEP 1.
    int k = 1;
    
    vector<double> x0 = guess;
    vector<double> xk(guess.size(),0);
    
    //STEP 2.
    while (k < N){
    
        //STEP 3.
        for (int i=0; i<A.size(); i++){
            
            //***
            double comSum = 0.0;
            double sumUp = 0.0;
            
            for (int j=1-1; j<i; j++){
        
                comSum += A[i][j] * xk[j];
            
            }
            
            for (int j=i+1; j<A.size(); j++){
            
                sumUp += A[i][j] * x0[j];
            
            }
        
            double xi = w / A[i][i] * (-comSum - sumUp + b[i]) + (1 - w) * x0[i];
            xk[i]=xi;
            
        }
        
        //STEP 4.
        if (absDiff1(x0, xk)<TOL){
            cout<<"Iteraciones de SOR: "<<k-1<<endl;
            return x0;
        
        }
        else{
            //STEP 5.
            k++;
        
            //STEP 6.
            x0 = xk;
            xk = *new vector<double>(guess.size(),0.0);;
        }
        
    }
    cout<<"Iteraciones de SOR: "<<k-1<<endl;
    //STEP 7
    return xk;
}

double absDiff1(vector<double> _u, vector<double> _v){
    
    double value = 0;
    
    for (int i=0; i<_u.size(); i++){
    
        value += pow(_u[i] - _v[i], 2);
        
    }
    
    return sqrt(value);
    
}