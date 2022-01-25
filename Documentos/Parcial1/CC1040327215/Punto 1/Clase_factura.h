#include<iostream>
#include<math.h>

using namespace std;

class Factura{ //Creamos nuestra clase
	private:
		string ref_pieza; //referencia de la pieza
		string descrip_pieza; // descripción
		int can_pieza;  // cantidad
		float prec_pieza; // precio
	public:
		Factura(string, string, int, float); //iniciamos con el constructor
		//Iniciamos nuestras funciones obtener y establecer para cada dato del private
		void establecerref_pieza(string);
		string obtenerref_pieza();
		
		void establecerdescrip_pieza(string);
		string obtenerdescrip_pieza();

		void establecercan_pieza(int);
		int obtenercan_pieza();
		
		void establecerprec_pieza(float);
		float obtenerprec_pieza();
		
		
		double obtenerMontoFactura(int,float);



};
