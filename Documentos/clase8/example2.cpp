#include <iostream>

using namespace std;

class ExcepcionDivisionEntreCero
{
public:

  ExcepcionDivisionEntreCero(  )
   {
     displayMessage( ); //llamar a la función displayMessage
   }
  
  void displayMessage()
  {
      cout << "Bienvendo a las exceciones!" << endl;
   } 
  
};

double cociente( int numerador, int denominador )
{
  // lanza ExcepcionDivisionEntreCero si intenta dividir entre cero
  if ( denominador == 0 )
    throw ExcepcionDivisionEntreCero(); // termina la función
  // devuelve el resultado de la división
  return static_cast< double >( numerador ) / denominador;
}

int main()
{
  int numero1; // numerador especificado por el usuario
  int numero2; // denominador especificado por el usuario
  double resultado;
  
  cout << "Escriba dos enteros (fin de archivo para terminar): ";
  // permite al usuario introducir dos enteros para la división
  while ( cin >> numero1 >> numero2 )
    {
      // el bloque try contiene código que podría lanzar una excepción
      // y código que no se debe ejecutar si ocurre una excepción
      try
	{
	  resultado = cociente( numero1, numero2 );
	  cout << "El cociente es: " << resultado << endl;
	} // fin de try
      // el manejador de excepciones maneja una excepción que se divide por cero
      catch ( ExcepcionDivisionEntreCero divideByZeroException )
	{
	  cout << "Ocurrio una excepcion: "<< endl;
	} // fin de catch
      cout << "\nEscriba dos enteros (fin de archivo para terminar): ";
    }

  cout << endl;
return 0; 
}
