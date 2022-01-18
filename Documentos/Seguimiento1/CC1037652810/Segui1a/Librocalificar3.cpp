#include <iostream>
#include "cursename.h"

using namespace std;


LibroCalificar::LibroCalificar( string nombre )
{
  establecerNombreCurso( nombre ); 
} 

void LibroCalificar::establecerNombreCurso( string nombre )
{
  if ( nombre.length() <= 25 )
    nombreCurso = nombre; 
  else 
    { 
      nombreCurso = nombre.substr( 0, 25 ); 
      cout << "El nombre \"" << nombre << "\" excede la longitud maxima (25).\n"
	   << "Se limito nombreCurso a los primeros 25 caracteres.\n" << endl;
    }
} 

string LibroCalificar::obtenerNombreCurso()
{
  return nombreCurso;
} 

void LibroCalificar::mostrarMensaje()
{
  cout << "Bienvenido al libro de calificaciones para \n" << obtenerNombreCurso() << "!\n"
       << endl;
} 

// recibe las calificaciones y determina el numero de estudiantes que pasaron
void LibroCalificar::RecibirCalificaciones()
{

  int contadorCalif; // número de la calificación a introducir a continuación
  int calificacion; // el valor de la calificacion introducida por el usuario
  int frecuencia1s = 0; // cuenta de veces que se tiró 1
  int frecuencia2s{0}; // cuenta de veces que se tiró 2
  contadorCalif = 1;
  
  while ( contadorCalif <= 10 ) 
    {
      cout << "Escriba una calificacion: "; 
      cin >> calificacion;
      contadorCalif = contadorCalif + 1;
      switch ( calificacion )
        {
        case 1:
          ++frecuencia1s; // incrementa el contador de 1s
          break;
        case 2:
          ++frecuencia2s; // incrementa el contador de 2s
          break;
        default: // valor inválido
        cout << "El programa nunca debio llegar aqui!";
        }
    }

  cout << "Aprobaron " << frecuencia1s << endl;
  cout << "Reprobaron " << frecuencia2s << endl;

  if (frecuencia1s>=8)
     cout << "Excelente instructor" << endl;
  else
     cout << "le falta un poco al instructor" << endl;

} 
