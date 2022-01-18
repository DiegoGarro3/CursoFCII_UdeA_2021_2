#include <iostream>
#include <cmath>

class Exponential
{
  
public:
  
  Exponential(float x , int n){ //Constructor

    ValueX(x);
    ValueN(n);
    
    
  }

  void ValueX(float x){
    
    X=x;
  }
  
  void ValueN(int n){

    N=n;

  }

  void Display(){ //Funcion encargada de imprimir el resultado.
    std::cout<< "El resultado de e^" << X << " " << " con N = " << N << " " <<  "terminos es:" << std::endl;
    std::cout<< "e^" << X << " = " << ValueExp(X,N) << std::endl;
    
  }

  double Factorial(int n){ //Funcion que calcula el factorial.

  int m=1;
  double factorial=1;
  
  if (n==0){
    factorial=1;
  }

  else{
       
    while(m<=n){
      factorial*=m;
      m++;
    }
   
  }
  return factorial;
  }

  float ValueExp(float X,int N){//Funcion que calcula la exponencial
    float e{0};
    for (int m=0; m <= N; m+=1){
      
      e+=pow(X,m)/Factorial(m);
    }
    
    return e;
  }

  
  
 private:
  
  float X;
  int N;
  
};

int main(){
  
  int NN{0};
  float y{0};
  
  std::cout << "Ingrese el valor de x para calcular e^x:" << std::endl;
  std::cin >> y;
  std::cout << "Ingrese el numero de terminos N que desea de la serie:" << std::endl;
  std::cin >> NN;

  //Creacion de Objetos
  Exponential ex(y,NN);
  ex.Display();
  
  return 0;
  
  
  
}
