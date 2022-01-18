#include <iostream>
#include "cursename.h"

using namespace std; 
LibroCalificar::LibroCalificar( string nombre )
{
    nombreCurso=nombre; 
} 
void LibroCalificar::mostrarMensaje()
{
  cout << "Bienvenido al libro de calificaciones para \n" << endl;
} 

// determina el promedio de la clase, con base en las 10 calificaciones escritas por el usuario
void LibroCalificar::RecibirNota()
{
  int contadorCalif; // número de la calificación a introducir a continuación
  int calificacion; // el valor de la calificacion introducida por el usuario
  int contador1=0;
  int contador2=0;
  
  contadorCalif = 1;
  
  // fase de procesamiento
  while ( contadorCalif <= 10 ) 
    {
      cout << "Escriba una calificacion: "; 
      cin >> calificacion;
      contadorCalif = contadorCalif + 1;
      if (calificacion==1)
        contador1=contador1+1;
      else 
        contador2=contador2+1;
    }
 if (contador1>=8)
    cout << "Eres un buen instructor";
 else
    cout << "Le falta mejorar al instructor" << endl;
  
}
  
