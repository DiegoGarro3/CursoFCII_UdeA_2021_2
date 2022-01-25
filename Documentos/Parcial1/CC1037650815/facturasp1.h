#include <string> 

using std::string;
using namespace std;


class Factura
{

    private:
        string numerodepieza;
        string descripcion;
        int cantidadarticulos; 
        int precio; 
        float total;

    public:
        Factura(string,string,int,float);
        void MontodeFactura();
        void mostrartotal();
};

    
