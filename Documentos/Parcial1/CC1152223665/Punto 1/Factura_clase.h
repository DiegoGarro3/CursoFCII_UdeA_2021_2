//PUNTO 1. Clase FACTURA.

#include<string>

using namespace std;

class Factura { //clase que imprime la factura de un articulo de una fereteria.
	private: //variables privadas.
		string Ref_art; //referencia del articulo.
		string Nomb_art; //nombre del articulo.
		int Cant_art; //cantidad del articulo.
		float Prec_art; //precio del articulo.
	
	public: //metodos o funciones de la clase.
		Factura(string, string, int, float); //constructor.
		
		//funciones para ingresar o establecer y almacenar los datos del articulo. 
		void establecerRef_art(string);
		string obtenerRef_art();
		
		void establecerNomb_art(string);
		string obtenerNomb_art();
		
		void establecerCant_art(int);
		int obtenerCant_art();
		
		void establecerPrec_art(float);
		float obtenerPrec_art();
		
		//funcion para obtener el monto de la factura.
		
		double obtenerMontoFactura(int,float);
};

