/*
Santiago Quintero Cordoba 

Parcial 2
*/

//para no tener poblemas en la herencia con redefiniciones
#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class Circular{//Creacion de una clase llamada Circular

    public://Declaracion de las funciones publicas
        
        Circular();//Constructor de la clase
        ~Circular();//Destructor de la clase

        //En circulo.cpp se halla una breve descripcion de lo que hace cada funcion

        vector<float> xpos();
		vector<float> ypos();
        vector<float> t();

        void Radio(float);
        float Obtener_Radio();

        void Frecuencia(float);
        float Obtener_Frecuencia();

        void Tiempo_final(float);
        float Obtener_Tiempo_final();

        void Intervalos(float);
        float Obtener_Intervalos();

        void Fase(float);
        float Obtener_Fase();        

    private://Declaracion de las variables privadas

        float r;
        float w;
        float t_final;
        unsigned int n;
        float alfa;
        float dt;
};

#endif