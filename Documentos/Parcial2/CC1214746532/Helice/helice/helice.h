//en caso que se quiera heredar Espirals
#ifndef HELICE_H
#define HELICE_H

//importacion de la clase
#include "../circulo/circulo.h"
#include <fstream>

class Espiral: public Circular{//Creacion de una clase llamada Espiral
		
	public://Declaracion de las funciones publicas

		Espiral();//Consstructor de la clase
		~Espiral();//Destructor de la clase 
		
        //En helice.cpp se halla una breve descripcion de lo que hace cada funcion

		vector<float> zpos();

		void Z0(float);
		float Obtener_Z0();
		
		void Vz(float);
		float Obtener_Vz();
        
    private://Declaracion de las variables privadas

		float z0;
		float vz;
};

#endif