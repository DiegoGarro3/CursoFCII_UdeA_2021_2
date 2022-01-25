#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Factura{
    private:
      string numPieza;
      string descPieza;
      int cantPieza;
      float precioPieza;
      
    public:
    Factura(string,string,int,float);
    
    void set_numPieza(string);
    void set_descPieza(string);
    void set_cantPieza(int);
    void set_precioPieza(float);
    
    string get_numPieza();
    string get_descPieza();
    int get_cantPieza();
    float get_precioPieza();
    
    float obtenerMontoFactura();
};

Factura::Factura(string _num,string _desc,int _cant,float _precio){
    numPieza=_num;
    descPieza=_desc;
    cantPieza=_cant;
    precioPieza=_precio;
};
void Factura::set_numPieza(string _num){
    numPieza=_num;
};

void Factura::set_descPieza(string _desc){
    descPieza=_desc;
};

void Factura::set_cantPieza(int  _cant){
    if (_cant>=0){
    cantPieza=_cant;
    }
    else{
        cantPieza=0;
    }
};


void Factura::set_precioPieza(float _precio){
    if (_precio>=0){
    precioPieza=_precio;
    }
    else{
        precioPieza=0;
    }
};

string Factura::get_numPieza(){
    return numPieza;
}

string Factura::get_descPieza(){
    return descPieza;
}

int Factura::get_cantPieza(){
    return cantPieza;
}

float Factura::get_precioPieza(){
    return precioPieza;
}

float Factura::obtenerMontoFactura(){
    return cantPieza*precioPieza;
}


int main(){

    Factura factura1("0001","Martillo",2,4.0);
    cout << "El precio del " << factura1.get_descPieza()<<" es "<<factura1.get_precioPieza() <<endl;
    cout<<"Al comprar  "<<factura1.get_cantPieza()<<" debe pagar un total de "<<factura1.obtenerMontoFactura()<<endl;
    factura1.set_precioPieza(5.0);
    cout<< "El nuevo precio del martillo es "<<factura1.get_precioPieza()<<endl;
    cout<<"Debe pagar "<<factura1.obtenerMontoFactura();
    
    cout<<endl;
cout<<"Impresión en forma de columnas";
cout<<endl;
    
cout<<setw(30)<<"Factura Ferretería."<<endl;
cout<<setw(6)<<"Ref."<<setw(15)<<"Descripción"<<setw(8)<<"Precio"<<setw(7)<<"Cant."<<endl;
cout<<setw(factura1.get_numPieza().size()+2)<<factura1.get_numPieza()<<setw(factura1.get_descPieza().size()+4)<<factura1.get_descPieza()<<setw(8)<<factura1.get_precioPieza()<<setw(8)<<factura1.get_cantPieza()<<endl;
cout<<endl;
cout<<endl;
cout<<setw(factura1.get_numPieza().size()+factura1.get_descPieza().size()+15)<<"Total"<<setw(7)<<factura1.obtenerMontoFactura();
        
}
