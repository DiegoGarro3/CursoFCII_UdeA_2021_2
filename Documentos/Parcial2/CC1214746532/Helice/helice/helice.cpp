#include "helice.h"
#include "../circulo/circulo.cpp"//para poder ejecutar el codigo sin multiple definicion

Espiral::Espiral() //constructor
: Circular()
{

    Z0(1);
    Vz(-1);
}

Espiral::~Espiral(){//de igual forma el destructor de Espiral no hace nada diferente a lo que hace el destructor}

void Espiral::Z0(float Z){//se da z0

	z0 = Z;
}


float Espiral::Obtener_Z0(){//se retorna z0
	
    return z0;
}


void Espiral::Vz(float VZ){//se da vz

	vz = VZ;
}
float Espiral::Obtener_Vz(){//se retorna vz
	
    return vz;
}

vector<float> Espiral::zpos(){//se calcula z en los n intervalos dados por la clase circular

	vector<float> z;
	vector<float> tiempo = Circular::t();
	
	for(int i=0; i<=Circular::Obtener_Intervalos(); i++){
		z.push_back(z0 + vz * tiempo[i]);
	}
	
	return z;
}