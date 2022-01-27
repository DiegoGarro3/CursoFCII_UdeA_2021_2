#include <string> 
    
using std::string;
    
class Factura
{
 public :
       
  Factura( string, string, int, int ); 
  void establecerNum( string );      
  string obtenerNum();   
  void establecerDesc( string );      
  string obtenerDesc();
  void setAmount( int );      
  int obtainAmount();
  void setPrice( int );      
  int obtainPrice();
  void mostrarMensaje();
  int ObtenerMontoFactura(); 
  void mostrartotal();
  
 private :     
  string pnum;
  string pdesc;
  int cantidad;
  int precio;
};
