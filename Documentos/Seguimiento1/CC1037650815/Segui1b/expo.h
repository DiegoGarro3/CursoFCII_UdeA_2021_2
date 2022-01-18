#include <iostream> 

class ExponSeries
{
 public:
  ExponSeries(double ); 
  long double fact(unsigned int); //long double es para gran cantidad de terminos en la serie, para factoriales grandes
  long double Series();
  void mostrarvalorexp(); 

 private:
  double x;
  int N;

}; 
