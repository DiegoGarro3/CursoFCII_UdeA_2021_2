
#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

class Exponencial{
    private:
        // Variables privadas el valor de "x" y "n"la presicion.
        float x;
        int n;
        
        // Función que calcula el factorial.
        unsigned long int Factorial(int n){
            if (n<0){
                return 0;
            }
            if (n==0 || n==1){
                return 1;
            } else {
                return n*Factorial(n-1);
            }
        }
    public:
        // Definición del constructor de la clase.
        Exponencial(float,int);
        
        // Función que calcula el valor de la exponencial.
        float Exponential(float x, int n){
            float etox=0;
            for (int i=0; i<n+1; i++){
                etox+=pow(x,i)/Factorial(i);
            }
            return etox;
        }
        
        // Función que imprime el valor de exp(x) a orden n.
        void printExp(){
            cout << "El valor de exp(" << x << ") hasta orden " << n << " es " << Exponential(x,n);
        }
};

// Cuerpo del constructor de manera explícita.
Exponencial::Exponencial(float xx,int nn){
    x=xx;
    n=nn;
}

int main()
{
    Exponencial example1(1,8);
    example1.printExp();

    return 0;
}
