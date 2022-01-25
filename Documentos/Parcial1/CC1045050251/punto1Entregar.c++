#include <iostream>
using namespace std;


 // declaracion de la clase Factura
class Factura{

    private:
        string numerodepieza;
        string descripcion;
        int cantidad; //cantidad a comprar
        float precio; //precio por articulo
        float pagar;

    public:
        Factura(string,string,int,float);
        void obtenerMontoFactura();
};

Factura::Factura(string _numerodepieza,string _descripcion,int _cantidad,float _precio){
    numerodepieza = _numerodepieza;
    descripcion = _descripcion;
    cantidad = _cantidad;
    precio = _precio;
}

void Factura::obtenerMontoFactura(){

    //float cantidad,precio,pagar;

    if (cantidad < 0){
        cout<<"\n**La cantidad es 0 porque no es positiva por tanto el monto es 0** \n";
        cantidad = 0;
      }

    if (precio < 0){
        cout<<"\n**El precio es 0 porque no es positivo por tanto el monto es 0** \n";
        precio = 0;
        }
    pagar = cantidad * precio;

    cout<<"Numero de pieza \t"<<numerodepieza<<endl;
    cout<<"Descripcion del producto \t"<<descripcion<<endl;
    cout<<"Cantidad comprada \t"<<cantidad<<endl;
    cout<<"precio por unidad \t"<<precio<<endl;

    if (cantidad>0 and precio>0) {cout<<"\n**El monto total es ="<<pagar<<endl;}
    cout<<"\n------------------------ \n";
}

int main(){
    string numerodepieza_;
    string descripcion_;
    int cantidad_;
    //cantidad a comprar
    float precio_; //precio por articulo
    float pagar_;

    cout<<"Ingrese el numero de pieza = \n"; cin>>numerodepieza_;
    cout<<"Ingrese descripcion del producto = \n"; cin>>descripcion_;
    cout<<"Ingrese la cantidad = \n"; cin>>cantidad_;
    cout<<"Ingrese el precio por unidad =\n"; cin>>precio_;

    cout<<"\n-------FACTURA CLIENTE---------- \n";
    Factura venta1(numerodepieza_,descripcion_,cantidad_,precio_);
    venta1.obtenerMontoFactura();

    cout<<"\n-------Ejemplos de la capacidad de la clase---------- \n";

    Factura venta2("dell234","Amarilla con puntos rojos",-10,2700);
    venta2.obtenerMontoFactura();

    Factura venta3("CO3467","Grande con bordes",15,-7300);
    venta3.obtenerMontoFactura();

    Factura venta4("4UdeA546576","metalico con ruedas azules",-7,-1700);
    venta4.obtenerMontoFactura();


    system("pause");
    return 0;

}
