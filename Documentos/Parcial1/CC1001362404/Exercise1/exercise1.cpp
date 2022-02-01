#include "Factura.h"
#include <iostream>

using namespace std;

int main(){
	string codigo;
	string descripcion;
	int cantidad;
	float precio;
	cout << "Introduzca el codigo del articulo: "<<endl;
	getline(cin, codigo);	
	cout << "Introduzca la descripcion: "<<endl;
	getline(cin, descripcion);
	cout << "Introduzca la cantidad: "<<endl;
	cin >> cantidad;
	cout << "Introduzca el costo: "<<endl;
	cin >> precio;
	
	
	Factura articulo(codigo, descripcion, cantidad, precio);
	articulo.obtenerMontoFactura();
	
	return 0;
}
