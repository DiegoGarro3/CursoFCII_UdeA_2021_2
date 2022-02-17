#include <iostream>

using namespace std;

class Cuenta
{
  friend void setX( Cuenta &, int ); // declaración friend
public:
  // constructor
  Cuenta()
    : x( 0 ) // inicializa x en 0
  {
    // cuerpo vacío
  }
  
  // imprime x
  void imprimir() const
  {
    cout << x << endl;
  }
  
private:
  int x; 
};

// la función setX puede modificar los datos privados de Cuenta
// debido a que setX se declara como amiga de Cuenta (línea 11)
void setX( Cuenta &c, int val )
{
  c.x = val; // se permite debido a que setX es amiga de Cuenta
}

/*
// la función noPuedeSetX trata de modificar los datos private de Cuenta,
// pero no puede debido a que la función no es amiga de Cuenta
void noPuedeSetX( Cuenta &c, int val )
 {
   c.x = val; // ERROR: no puede acceder al miembro de datos private en Cuenta
 }
*/

int main()
{
  Cuenta contador; // crea objeto Cuenta
  cout << "contador.x despues de crear la instancia: ";
  contador.imprimir();
  
  setX( contador, 8 ); // establece x usando una función friend
  cout << "contador.x despues de la llamada a la funcion friend setX: ";
  contador.imprimir();
  
  //noPuedeSetX( contador, 3 ); // noPuedeSetX no es amiga
  
  return 0;
}
