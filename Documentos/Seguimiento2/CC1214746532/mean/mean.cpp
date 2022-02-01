/*
Santiago Quintero Cordoba

Escriba un programa que incluya dos funciones llamadas calc_prom() y va-
rianza(). La función calc_prom() deberá calcular y devolver el promedio de
los valores almacenados en el arreglo llamado valores_prueba
*/

#include <iostream>
#include <array>
#include <cmath>

using namespace std;

//declaracion de variables
const int valores_a_tomar=3;//numero de elementos del arreglo
array<int, valores_a_tomar> valores_prueba={0,2,3};//arreglo

int suma{0};//suma para calcular los promedios
int suma2{0};//suma para calcular la suma de los cuadrados(significado del 2)

//declaracion de arreglos
double calc_prom(array<int, valores_a_tomar>);//funcion que devolvera el promedio de un arreglo
double varianza(array<int, valores_a_tomar>);//funcion que devolvera la varianza de un arreglo

int main(){

    cout<<"El valor medio del arreglo dado es: "<<calc_prom(valores_prueba)<<endl;//se muestra por pantalla el promedio del arreglo
//    cout<<"La varianza del arreglo dado es: "<<varianza(valores_prueba)<<endl;////se muestra por pantalla la varianza del arreglo
}

//IMPLEMENTACION DE LAS FUNCIONES

double calc_prom(array<int, valores_a_tomar> a){//Promedio

    suma=0;//para cuando se llame por segunda vez a la funcion se vuelva a inicializar la variable
    for (int i=0;i<a.size();i++){

        suma+=a.at(i);//se suma el elemento i-esimo
    }

    return static_cast<double>(suma)/a.size();//la suma_de_todos_los_elementos_del_arreglo/tamaño_del_arreglo=promedio
}

double varianza(array<int, valores_a_tomar> a){//Varianza
    
    suma=0;//para cuando se llame por segunda vez a la funcion se vuelva a inicializar la variable
    suma2=0;//para cuando se llame por segunda vez a la funcion se vuelva a inicializar la variable
    for (int i=0;i<a.size();i++){

        suma2+=pow(a.at(i),2);//se suma el cuadrado del elemento i-esimo

    }

    return static_cast<double>(suma2)/a.size() - pow(calc_prom(a),2);//Var[X] = E[X^2] - (E[X])^2

}