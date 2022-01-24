#include <string> 
using std::string;
class Factura
{
    
    public:
    Factura(string,string,int, double);  // constructor
    //proptotipos de funciones establecer
    void setnumpieza(string);
    void setdescripcion(string);
    void setcantidad(int);
    void setvalor(double);

    //prototipos de funciones obtener
    string getnumpieza(void);
    string getdescripcion(void);
    int getcantidad(void);
    double getvalor(void);
    
    // prototipo funcion monto de factura
    double obtenerMontoFactura();
    // prototipo funcion displayFactura()
    void displayFactura();

    private:
    string numeroDePieza;
    string descripcion;
    int cantidad;
    int valor;

};