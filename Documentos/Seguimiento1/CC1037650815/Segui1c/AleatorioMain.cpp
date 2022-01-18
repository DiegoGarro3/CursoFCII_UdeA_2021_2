#include <iostream>
#include "Aleatorio.h" 

using namespace std;

int main()
{ 
  int repgame{0};
  repgame=1;

  while (repgame==1)
    {
      Guessngame mygame; // llama el constructor de la clase que llama una funcion que genera un numero aleatorio

      mygame.game(); // te pide adivinar y te indica si tu numero es mayor o menor (interaccion con usuario)

      cout << "¿Quieres jugar nuevamente? (si=1, no=0)" << endl;
      cin >> repgame;
  }
  
  return 0; 
} 
