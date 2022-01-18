#include"segui1b.h"  //include definicion de la clase
#include<iostream>   
using namespace std;
int main()
{   // variables declaracion
    int p=4, q(15);      
    double w=3,s(1);
    int n=7;


    Exponencial Expo1; // Objeto Expo1
    cout<<setiosflags(ios::showpoint)<<setprecision(6);
    cout<< "El factorial de "<< p<< " es: "<<Expo1.factorial(p)<<endl; // funcion factorial
    // ahora veamos la funcion exponencial de un numero x, con una precision N(# de terminos en la serie de taylor)
    cout<< "la exponencial de  "<< s<< " para "<<q <<" terminos es: "<<Expo1.Fun_Exp(s,q)<<endl;
    //ahora la funcion que muestra en pantalla el valor de e^w con una cierta precision N=n. 
    Expo1.display_exp(w,n);
    cout<<endl;

}

