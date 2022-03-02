#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Juego{//Creacion de una clase llamada Juego

    public://Declaracion de las funciones publicas
        
        Juego();//Constructor de la clase

        //En ahorcado.cpp se halla una breve descripcion de lo que hace cada funcion

        void eleccion();

        void Jugar();

        void repetir();


    private://Declaracion de las variables privadas

        vector<string> palabras = {"algo","nada","parcial","materia","dificil","ganable","repetir","hasta","cinco",
        "veces","mi","titulo","se","ve","lejos","marzo","ocho","millonarios","cero","empezo","a","acabarse","la","imaginacion"};

        string palabra;
        string cod;
        string adi;

        string jugar = "si";
};