#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int tirarDados() //tira dados
{
  int dado1, dado2, suma;
  dado1 = 1 + rand()%6; //número aleatorio entre 1 y 6 (cara de los dados)
  dado2 = 1 + rand()%6;

  suma = dado1 + dado2; // sumamos lo que haya sacado

  cout << "En la tirada, el jugador a sacado " << dado1 << "+" << dado2  << "=" << suma << endl; //mostramos la suma de los dos dados

  return suma;
}

//creamos la función principal

int main(){

  enum Estado {CONTINUAR, GANO, PERDIO};
  int miPunto; //punto si no gana o pierde en el primer tiro
  Estado estadoJuego; //Puede contener CONTINUAR, GANO O PERDIO

  srand(time(0)); //controla tiempo de ejecucion

  int sumaDados = tirarDados(); //llama tira dados y almacena suma

  switch(sumaDados) //bloque de condiciones para el juego
        {
    //gana en el primer tiro
    case 7: 
    case 11:
      estadoJuego = GANO;
      break; //sale del switch
    //perdio en el primer tiro
    case 2:
    case 3:
    case 12:
      estadoJuego = PERDIO;
      break; //sale del switch
   
    //el juego continua
    default:
      estadoJuego = CONTINUAR; //el juego contiua!
     
      miPunto = sumaDados; // recordamos el punto
      cout << "Esta en el punto " << miPunto << endl;
      break;
     
	}

  while(estadoJuego == CONTINUAR) //bucle que se repite hastq que cambie la variariable estado del juego
    {
      sumaDados = tirarDados(); //tiramos los dados nuevamente

      if(sumaDados == miPunto)
	  estadoJuego = GANO;
      else if(sumaDados == 7)
          estadoJuego = PERDIO; 
    }
    	if ( estadoJuego==GANO) //Mostramos un mensaje de si perdió o ganó
		cout<<"El jugador gana"<<endl;
	else
	cout<<"EL jugador pierde"<<endl;
	
	return 0;
}

