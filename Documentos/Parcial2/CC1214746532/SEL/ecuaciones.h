/*
Santiago Quintero Cordoba 

Parcial 2
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class Ecuacion{//Creacion de una clase llamada Ecuacion

    public://Declaracion de las funciones publicas
        
        Ecuacion();//Constructor de la clase

        //En ecuacion.cpp se halla una breve descripcion de lo que hace cada funcion

        void ini();
        void Jacobi();

        void SOR();

        void ecu();

    private://Declaracion de las variables privadas

        unsigned int tam;
        vector<float> X;
        vector<vector<float>> Ecu;
        string converge = "si";
        vector<float> X_0;
};