#include <iostream>
#include "esquema.h" 

using namespace std;

int main()
{ 
  int wannaplay{0};
  wannaplay=1;

  while (wannaplay==1)
    {
      Guessngame letsplay; // llama el constructor de la clase que llama una funcion que genera un numero aleatorio

      letsplay.game(); // te pide adivinar y te indica si tu numero es mayor o menor (interaccion con usuario)

      cout << "¿Quiere jugar nuevamente? (si=1, no=0)" << endl;
      cin >> wannaplay;
  }
  
  return 0; 
} 
