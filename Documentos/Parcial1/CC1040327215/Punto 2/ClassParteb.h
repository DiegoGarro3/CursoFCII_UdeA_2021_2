#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <unistd.h>


using namespace std;


class Craps
{

	 private:
  		int SaldoenBanco = 1000000; //saldo inicial
  		int ValorApuesta = 0;

 	public:
 		 Craps(); //constructor de la clase 
 		 void Apuesta(); //avisa el saldo que se apuesta
 		 int TirarDados(); //tira dados, retorna suma de dados
 		 void Resultado( bool ); //suma o resta (depende el caso) a la variable SaldoenBanco
 		 void Juego(); //es donde juega y envia booleano a Resultado
 		 void Menu(); //da las opciones al usuario

};
