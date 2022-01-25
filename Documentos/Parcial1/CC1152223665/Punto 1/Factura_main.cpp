//librerias necesarias para ingresar e imprimir en pantalla, uso de strings, 
//manipulacion de input  output y clae creada.
#include<iostream> 
#include<string>
#include<iomanip>
#include "Factura_clase.h"

using namespace std;

int main(){
	
	string Ref_art, Nomb_art, ref, nomb; //declaracion de variables a usar.
	int Cant_art, cant;
	float Prec_art, prec;
	double monto;
	
	//ingreso por pantalla de las variables.
	cout<<"Ingrese la referencia del artículo: ";
	cin>>Ref_art;
	cout<<"Ingrese el nombre del artículo: ";
	cin>>Nomb_art;
	cout<<"Ingrese la cantidad de articulos: ";
	cin>>Cant_art;
	cout<<"Ingrese el precio del artículo: ";
	cin>>Prec_art;
	
	//se declara factura como un elemento de la clase Factura con sus respectivos atributos o variables que la clase 						
	//usa internamente para entregar los resultados
	Factura factura = Factura(Ref_art, Nomb_art, Cant_art, Prec_art);
	
	//se establecen las variables correspondientes dentro de la clase.
	factura.establecerRef_art(Ref_art);
	factura.establecerNomb_art(Nomb_art);
	factura.establecerCant_art(Cant_art);
	factura.establecerPrec_art(Prec_art);
	
	//se inicializan las variables del main con su funcion que retorna el valor correspondiente. 
	//se llaman los metodos establecer de la clase y se almacenan en variables.
	ref = factura.obtenerRef_art();
	nomb = factura.obtenerNomb_art();
	cant = factura.obtenerCant_art();
	prec = factura.obtenerPrec_art();
	
	//se llama el metodo obtenerMontoFactura de la clase y el valor retornado por la funcion se almacena en la variable.
	monto = factura.obtenerMontoFactura(cant, prec);
	
	//se imprime la factura al usuario con la informacion corrrespondiente en forma de "tabla".
	cout<<"FERRETERIA EL SUSTO"<<endl;
	cout << setw(10) <<"REFERENCIA"<<setw(10)<<"NOMBRE"<<setw(12)<<"CANTIDAD"<<setw(10)<<"PRECIO"<<setw(17)<<"MONTO FACTURA"<<endl;
	cout << setw(10) <<ref<<setw(10)<<nomb<<setw(12)<<cant<<setw(10)<<prec<<setw(17)<<monto<<endl;
	
	return 0;
}









