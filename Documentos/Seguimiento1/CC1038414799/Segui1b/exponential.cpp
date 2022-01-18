#include <iostream>
#include <cmath>

using namespace std;

#include "exponential.h"

Exponential::Exponential(unsigned int orderIni) //Exponential object
{
  N=orderIni; //Constructor to initializate N
}

unsigned long Exponential::factorial( unsigned int num )
{
  int mm = 1;
  double fact = 1;

  if (num == 0){ fact=1; }
  else{
    
    while(mm<=num){
      fact*=mm;
      mm++;
    }
    
  }

  return fact;

}


double Exponential::getExp( double arg, unsigned int order )
{
    x=arg;
    N=order;
    expx = 0;
    int jj  = 0;

    while (jj<=N)
    {
      
      expx = expx + (pow(x,jj)/factorial(jj)); //Exponential Tylor's series      
      
      jj++;
      
    }

    return expx;

}

void Exponential::displayMessage() //print the value of e^x
{
    cout << "El valor de e^"<< x <<" para "<< N << " terminos de la expansión de Tylor es: "<< expx << endl; 
 
}