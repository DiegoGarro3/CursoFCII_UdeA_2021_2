#include<iostream>
#include"Clase_factura.h"

using namespace std;

Factura::Factura(string _ref_pieza, string _descrip_pieza, int _can_pieza, float _prec_pieza){ //creamos nuestro constructor
	ref_pieza = _ref_pieza; // datos que van a ingresar al constructor
	descrip_pieza = _descrip_pieza;
	can_pieza = _can_pieza;
	prec_pieza = _prec_pieza;
} // Apartir de acà, creamos nuestras funciones establecer (recibimos el dato y lo guardamos) y obtener (retornamos dicho dato que hemos establecido)
//Esto lo hacemos para cada dato que ingresa al constructor

void Factura::establecerref_pieza(string r){
	ref_pieza = r;

}

string Factura::obtenerref_pieza(){
	return ref_pieza;

}

void Factura::establecerdescrip_pieza(string d){
	descrip_pieza = d;

}

string Factura::obtenerdescrip_pieza(){
	return descrip_pieza;

}

void Factura::establecercan_pieza(int c){
	can_pieza = c;
	if(can_pieza<0){
	
	can_pieza = 0;
	}
	

}

int Factura::obtenercan_pieza(){
	return can_pieza;

}

void Factura::establecerprec_pieza(float p){
	prec_pieza = p;
	
	if(prec_pieza<0){
	prec_pieza = 0;
	}

}

float Factura::obtenerprec_pieza(){
	return prec_pieza;

}

//POr ùltimo, creamos la función MontoFactura

double Factura::obtenerMontoFactura(int can_pieza,float prec_pieza){
	double monto;
	monto = can_pieza*prec_pieza;
	return monto;
}









