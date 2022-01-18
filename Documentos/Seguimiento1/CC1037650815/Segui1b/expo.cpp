#include<iostream>
#include<iomanip>
#include<cmath>
#include "expo.h"

using namespace std;

//unsigned long factorial( unsigned long ); // prototipo de función

ExponSeries::ExponSeries( double Exponent)
{
   unsigned int Numberofterms;
   cout << "Escriba el número de términos para la serie " << endl;
   cin >> Numberofterms;
   x=Exponent;
   N=Numberofterms;
}

// Esta funcion calcula el factorial de un numero, alternativamente se podria usar una funcion construida con recursion para calcular el factorial, tal como se hizo con al serie de Fibonacci

//void ExponSeries::Numberofterms()
//{ unsigned int Nofterms
//  cin
//}
long double ExponSeries::fact (unsigned int num)
{
  long double mm = 1;
  long double factorial = 1;

  if (num == 0){ factorial=1; }
  else{
    
    while(mm<=num){
      factorial*=mm;
      mm++;
    }
  //cout << factorial << endl;
  }

  return factorial;

} // end fact function

long double ExponSeries::Series()
{ 
  int jj = 0;
  long double Ex=0;

  while (jj<N)
    {
    
      Ex = Ex + (pow(x,jj)/fact(jj));      

      //cout << fact(jj) << endl; 
      
      jj++;  
    }
  return Ex;
}
void ExponSeries::mostrarvalorexp()
{
  cout << "El valor de e^x, con " << N << " términos \n" << "y con x igual a " << x << " es " << Series() << endl;

} 

