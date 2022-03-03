#include "circulo.h"

Circular::Circular(){

    //se inicializan las variables
    Circular::Radio(1);
    Circular::Frecuencia(2);
    Circular::Intervalos(100);
    Circular::Tiempo_final(6.28);
    Circular::Fase(2);
    
    dt = t_final/n;//se calcula el tamaño de separacion entre dato y dato
}

Circular::~Circular(){//el destructor esta vacio}

/*a diferencia de los otros puntos se quiere heredar los elementos de l
clase circulo y por ende es bueno crear funciones que inicialicen y
devuelvan las variables porque la clase que hereda no puede acceder
a las variables privadas de forma directa*/
void Circular::Radio(float radio){//se da el radio
	
    r = radio;
}

float Circular::Obtener_Radio(){//se obtiene el valor del radio
	
    return r;
}

void Circular::Frecuencia(float W){//se da la frecuencia
	
    w = W;
}

float Circular::Obtener_Frecuencia(){//se obtiene la frecuencia
	
    return w;
}

void Circular::Tiempo_final(float t_f){//se da el tiempo final
	
    t_final = t_f;
}

float Circular::Obtener_Tiempo_final(){//se obtiene el tiempo final
	
    return t_final;
}

void Circular::Intervalos(float N){//se da el numero de intervalos
	
    n = N;
}

float Circular::Obtener_Intervalos(){//se obtienen los intervalos

    return n;
}

void Circular::Fase(float a){ //se da la fase

	alfa = a;
}

float Circular::Obtener_Fase(){//se obtiene la fase
	
    return alfa;
}

vector<float> Circular::t(){//se calculan los n+1 tiempos ya que al tener n intervalos se dividen en n+1 elementos
    
    vector<float> tiempo{0};
	
	for(int i=1; i<=n; i++){

	   tiempo.push_back(i*dt);
	}

	return tiempo;
}

vector<float> Circular::xpos(){//se calcula la posicion en x
	
    vector<float> x;
	
	const vector<float> tie = t();
	
	for(int i=0; i<n+1; i++){
		x.push_back(r*cos(w*tie[i] + alfa) );
	}
	
	return x;
}

vector<float> Circular::ypos(){//se calcula la posicion en y
	
    vector<float> y;
	
	const vector<float> tie = t();
	
	for(int i=0; i<n+1; i++){
		y.push_back(r*sin(w*tie[i] + alfa) );
	}
	
	return y;
}