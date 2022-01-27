#include<iostream>
#include<iomanip>
#include<cmath>
#include "esquema.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Guessngame::Guessngame()
{ 
  num=generatenum();
}

// genera el numero aleatorio
int Guessngame::generatenum()
{
  int rnum{0};
  srand(time(NULL));// Necesario inicializa los numeros aleatorios. De lo contrario siempre dan lo mismo
  rnum = 1 + rand() % (1000+1 - 1);
  //cout << rnum << endl;
  return rnum;
}

// aqui se desarrolla el juego y la interaccion con el usuario
void Guessngame::game()
{ 
  unsigned int guess{0};
  int guessed{0};
  cout << "El juego ha generado un numero aleatorio entre 1 y 1000 " << endl;
  while (guessed!=1)
      {
	  cout << "Introdusca el numero que usted cree que fue generado " << endl;
	  cin >> guess;

	  if (guess==num)
	  { cout << " Es correcto, el numero generado fue " << num << endl; 
            guessed=1;
	  }
	  if (guess<num)
	  { cout << " su numero es menor que el numero aleatorio generado " << endl;
	  }
	  if (guess>num)
	  { cout << " su numero es mayor que el numero aleatorio generado " << endl;
	  }
	  
      } 
}

