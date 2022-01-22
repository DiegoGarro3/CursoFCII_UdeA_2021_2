#include <iostream>
#include <cstdlib> 
#include <ctime> 


using namespace std;
int SaldoenBanco = 1000000; //inicializar saldo en banco
int apuesta=1000; //inicializar apuesta
int cdt=1; //inicializar contador


int tirarDados(); // tira los dados, calcula la suma
void craps(int &, int); //prototipo función de craps
void mensaje(); //prototipo función con mesajes

int main()
{


  while (apuesta != 0)
  {
    //Ingresa la apuesta 
    cout << "Ingrese un monto para apostar (si desea retirarse del juego apueste 0): ";
    cin >> apuesta;
    cout << '\n';

    //si el usuatrio no quiere seguir apostando pone 0 y se termina el juego
    if(apuesta == 0)
      break;

    //verifica que la apuesta no exceda el saldo en el banco
    while (apuesta > SaldoenBanco)
    {
      cout << "¡La cantidad a apostar excede el saldo en el banco!, ingrese nueva apuesta: ";
      cin >> apuesta;
      cout << '\n';

    }
   
    craps(SaldoenBanco, apuesta); //juega craps con lo apostado
    
    //Elige aleatoriamente si mostrar o no un mensaje después de cada juego
    srand(time(0));
    int num_ale = 1 + rand() % 2;
    if (num_ale == 1)
    {
      mensaje();
    }
  
    //para si se queda sin fondos en el banco
    if (SaldoenBanco == 0)
    {
      apuesta=0;
      cout << "Lo siento. Se quedó sin fondos."<<endl;
      
    }

  }
  
  cout << "El juego se ha terminado y su saldo en Banco quedó en : "<< SaldoenBanco << endl;
  return 0;

}


//imprime mensajes según el saldo en el banco
void mensaje()
{
  if(SaldoenBanco >= 2000000)
    cout << "<<La sacaste del estadio. Sería buen tiempo de cambiar tus fichas plata>>" << endl;

  else if (SaldoenBanco >= 100000 & SaldoenBanco < 2000000 )
  {
     cout << "<<Hágale, no pasa nada, arriesguese>>" << endl;
  }

  else if (SaldoenBanco < 100000 )
  {
     cout << "<<Usted se esta quebrando, ¿no le parece?>>" << endl;
  }

}
