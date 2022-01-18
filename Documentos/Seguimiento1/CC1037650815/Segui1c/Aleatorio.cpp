#include<iostream>
#include<iomanip>
#include<cmath>
#include "Aleatorio.h"
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
  cout << "¡Bienvenido al juego!. Adivina un número entre 1 y 1000 " << endl;
  while (guessed!=1)
      {
	  cout << "Piensa en un número y escríbelo" << endl;
	  cin >> guess;

	  if (guess==num)
	  { cout << " ¡Adivinaste!" << endl; 
            guessed=1;
	  }
	  if (guess<num)
	  { cout << " Escribe un número mayor " << endl;
	  }
	  if (guess>num)
	  { cout << " Escribe un número menor " << endl;
	  }
	  
      } 
}

