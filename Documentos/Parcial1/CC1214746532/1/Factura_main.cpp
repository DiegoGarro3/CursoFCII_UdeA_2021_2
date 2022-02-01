/*
Codigo main que probara el alcance de la clase Factura
*/

#include "Factura.h"

int main(){

    Factura a;

    cout<<"Factura por defecto"<<endl;
    cout<<"\n";

    cout<<"articulo comprado: "<<setw(10)<<a.Obtener_descripcion()<<endl;
    cout<<"# de elementos comprados " <<setw(10)<<a.Obtener_pieza()<<endl;
    cout<<"Cantidad de elementos comprados"<<setw(10)<<a.Obtener_cantidad()<<endl;
    cout<<"Valor del elemento comprado:"<<setw(10)<<"$"<<a.Obtener_valor()<<endl;
    cout<<"Mooonto total a pagar:"<<setw(10)<<"$"<<a.obtenerMontoFactura()<<endl;
    cout<<"\n";

    a.Establecer_cantidad(4);
    a.Establecer_descripcion("tornillo 3/8");
    a.Establecer_pieza("cuatro");
    a.Establecer_valor(4900);

    cout<<"Factura generada una vez se han ingresado los valores del articulo"<<endl;
    cout<<"\n";

    cout<<"articulo comprado: "<<setw(10)<<a.Obtener_descripcion()<<endl;
    cout<<"# de elementos comprados " <<setw(10)<<a.Obtener_pieza()<<endl;
    cout<<"Cantidad de elementos comprados"<<setw(10)<<a.Obtener_cantidad()<<endl;
    cout<<"Valor del elemento comprado:"<<setw(10)<<"$"<<a.Obtener_valor()<<endl;
    cout<<"Mooonto total a pagar:"<<setw(10)<<"$"<<a.obtenerMontoFactura()<<endl;
    cout<<"\n";

}