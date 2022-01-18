#include <string> 
    
using std::string;
    
class LibroCalificar
{
 public :
       
  LibroCalificar( string ); 
  void establecerNombreCurso( string );      
  string obtenerNombreCurso();   
  void mostrarMensaje(); 
  void RecibirCalificaciones();
  
 private :     
  string nombreCurso;
};
