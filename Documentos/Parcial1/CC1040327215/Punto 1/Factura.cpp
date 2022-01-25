#include<iostream>
#include"Clase_factura.h"

using namespace std;

int main(){ //Realizamos el main para ver verificar el funcionamiento del código

//establecemos nuestras variables
	string ref_pieza,refe;
	string descrip_pieza,descripcion;
	int can_pieza,cantidad;
	float prec_pieza, monto;

	double montofactura;

//Le pedimos al usuario que ingrese los detalles de la compra
	
	cout<< "Bienvenidos a la ferreteria Don Comedias"<<endl;
	cout<<"Por favor ingrese la referencia del producto: ";
	cin>> ref_pieza;
	
	cout<<"Ingrese el nombre del producto con referencia "<<ref_pieza<<": ";
	cin>> descrip_pieza;
	
	cout<<"Cuantos "<<descrip_pieza<<" desea comprar?: ";
	cin>> can_pieza;
	
	cout<<"Ingrese el precio por unidad de dicho artículo: ";
	cin>>prec_pieza;

//Retornamos los valores pedidos
	
	Factura fact = Factura(ref_pieza, descrip_pieza, can_pieza, prec_pieza);
	
	fact.establecerref_pieza(ref_pieza);
	refe = fact.obtenerref_pieza();
	
	fact.establecerdescrip_pieza(descrip_pieza);
	descripcion = fact.obtenerdescrip_pieza();
	
	fact.establecercan_pieza(can_pieza);
	cantidad = fact.obtenercan_pieza();
	
	fact.establecerprec_pieza(prec_pieza);
	monto = fact.obtenerprec_pieza();
	
	montofactura = fact.obtenerMontoFactura(cantidad,monto);

//Por último le entregamos su factura y le agradecemos por su compra!
	
	cout<<"DETALLES DE SU COMPRA"<<endl;
	
	cout<<"Referencia: "<<refe<<endl;
	cout<<"Descripción: "<<descripcion<<endl;
	cout<<"Cantidad: "<<cantidad<<endl;
	cout<<"Precio por unidad: "<<monto<<endl;
	cout<<"Precio TOTAL: "<<montofactura<<endl;
	
	cout<<"!Gracias por realizar la compra, vuelva pronto!"<<endl;
	
	
	
	
	return 0;
	
	
	
	
	








}
