#include<string>
#include "Factura_clase.h"

using namespace std;

//constructor, sirve para incializar los atributos o variables de la clase.
Factura::Factura(string _Ref_art, string _Nomb_art, int _Cant_art, float _Prec_art){
	
	//inicializacion de variables que se pasaran desde la funcion principal cuando se cree un objeto.
	//las variables sin _ se inicializan aqui y seran a las cuales les pasaremos los datos.
	Ref_art = _Ref_art;
	Nomb_art = _Nomb_art;
	Cant_art = _Cant_art;
	Prec_art = _Prec_art;
}

//Funcion establecer para cada dato lo que hace es almacenar el argumento en una variable de la clase.
void Factura::establecerRef_art(string ref){ 
	Ref_art = ref;
}
//Funcion obtener para cada dato lo que hace es retornar el valor de la variable, ya sea string, int o float. 
string Factura::obtenerRef_art(){
	return Ref_art;
}

void Factura::establecerNomb_art(string nomb){
	Nomb_art = nomb;
}
string Factura::obtenerNomb_art(){
	return Nomb_art;
}

void Factura::establecerCant_art(int cant){
	Cant_art = cant;
	if (Cant_art<0){
		Cant_art=0;
	}
}
int Factura::obtenerCant_art(){
	return Cant_art;
}

void Factura::establecerPrec_art(float prec){
	Prec_art = prec;
	if (Prec_art<0){
		Prec_art=0;
	}
}
float Factura::obtenerPrec_art(){
	return Prec_art;
}

//Funcion que retorna el precio final de comprar "x" cantidad de articulos que tienen un precio de "y". 
double Factura::obtenerMontoFactura(int Cant_art, float Prec_art){
	
	double MontoFactura;
	MontoFactura=Cant_art*Prec_art;

	return MontoFactura;
}

















