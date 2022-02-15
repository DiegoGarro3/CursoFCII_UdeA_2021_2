/*El programa muestra un menú y permite introducir una de tres opciones para obtener 
la información de crédito. La opción 1 produce una lista de cuentas con saldos en cero.
La opción 2 produce una lista de cuentas con saldos de crédito. La opción 3 produce una lista de cuentas con saldos de
débito. La opción 4 termina la ejecución del programa. Si se introduce una opción inválida, se muestra el indicador para
que el usuario introduzca otra opción
*/

#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip>

using namespace std;

enum TipoSolicitud { SALDO_CERO = 1, SALDO_CREDITO, SALDO_DEBITO, TERMINAR }; //note esta definicion
int obtenerSolicitud();
bool debeMostrar( int, double );
void imprimirLinea( int, const string, double ); 

int main()
{
  ifstream archivoClientesSalida( "clientes.dat", ios::in );
  
  if ( !archivoClientesSalida )
    {
      cerr << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
  
  int solicitud;
  int cuenta;
  char nombre[ 30 ];
  double saldo;
  
  // obtiene la solicitud del usuario (por ejemplo, saldo en cero, de crédito o débito)
  solicitud = obtenerSolicitud();

  // procesa la solcitud del usuario
  while ( solicitud != TERMINAR )
    {
      switch ( solicitud )
	{
	case SALDO_CERO:
	  cout << "\nCuentas con saldos en cero:\n";
	  break;
	case SALDO_CREDITO:
	  cout << "\nCuentas con saldos de credito:\n";
	  break;
	case SALDO_DEBITO:
	  cout << "\nCuentas con saldos de debito:\n";
	  break;
	}

      // lee la cuenta, el nombre y el saldo del archivo
      archivoClientesSalida >> cuenta >> nombre >> saldo;

      // muestra el contenido del archivo (hasta eof)
      while ( !archivoClientesSalida.eof() )
	{
	  // muestra el registro
	  if ( debeMostrar( solicitud, saldo ) ){
	    imprimirLinea( cuenta, nombre, saldo );
	  }
	  
	  archivoClientesSalida >> cuenta >> nombre >> saldo;
	}

      archivoClientesSalida.clear(); // restablece eof para la siguiente entrada
      archivoClientesSalida.seekg( 0 ); // se reposiciona al inicio del archivo
      solicitud = obtenerSolicitud(); // obtiene una solicitud adicional del usuario
    }
  
  return 0; 
}

// obtiene la solicitud del usuario
int obtenerSolicitud()
{
  int solicitud; // solicitud del usuario
  // muestra las opciones de solicitud
  cout << "\nEscriba la opcion" << endl
       << " 1 - Listar cuentas con saldos en cero" << endl
       << " 2 - Listar cuentas con saldos de credito" << endl
       << " 3 - Listar cuentas con saldos de debito" << endl
       << " 4 - Finalizar ejecucion" << fixed << showpoint;
  do // introduce la solicitud del usuario
    {
      cout << "\n? ";
      cin >> solicitud;
    } while ( solicitud < SALDO_CERO && solicitud > TERMINAR );
  return solicitud;
}

// determina si se va a mostrar el registro dado
bool debeMostrar( int tipo, double saldo )
{
  // determina si se van a mostrar los saldos en cero
  if ( tipo == SALDO_CERO && saldo == 0 )
    return true;
  // determina si se van a mostrar los saldos de crédito
  if ( tipo == SALDO_CREDITO && saldo < 0 )
    return true;
  // determina si se van a mostrar los saldos de débito
  if ( tipo == SALDO_DEBITO && saldo > 0 )
    return true;
  
  return false;
}

void imprimirLinea( int cuenta, const string nombre, double saldo )
{
  cout << left << setw( 10 ) << cuenta << setw( 13 ) << nombre
       << setw( 7 ) << setprecision( 2 ) << right << saldo << endl;
}
