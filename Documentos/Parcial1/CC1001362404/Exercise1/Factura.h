#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



class Factura{
	public:
	
		Factura(string, string,  int, float);
		
		void setnumber( string );
		string getnumber();
		void setdescription( string );
		string getdescription();
		void setquantity( int );
		int getquantity();
		void setcost( float );
		float getcost();
		
		void calcularFactura();
		void obtenerMontoFactura();
				
		
	private:
		
		string number;
		string description;
		int quantity;
		float cost;
		float total;
};

