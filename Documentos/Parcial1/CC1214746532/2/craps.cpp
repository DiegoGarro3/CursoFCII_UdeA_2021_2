/*
Santigo quintero codoba

Parcial 1, punto 2.a

Codigo de craps, observar que solo se juega una vez(ganar o perder)
ya que a diferencia de clases(tareas) pasadas no se especifica que se
deba volver a jugar
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

unsigned int dado1 = 0; //valor del primer dado
unsigned int dado2 =0; //valor del segundo dado
unsigned int punto =0; //valor usado para la suma de los dos dados
unsigned int juego = 0; //condicion de juego cuando en el primer turno no se gana ni se pierde

int main(){

    srand(time(NULL)); //semilla para el numero aleatorio
    dado1 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6
    dado2 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6

    punto = dado1 +  dado2;

    cout<<"Sacaste: "<<punto<<endl;

    if(punto == 7 || punto == 11){//Mensaje de victoria
        cout<<"Ganaste"<<endl;
    }

    else if (punto == 2 || punto == 3 || punto ==12){//Mensaje de derrota
        cout<<"Craps, perdiste"<<endl;
    }
    
    else{//El juego debe seguir
        while(juego != punto && juego != 7){//Mientras se tenga un valor diferente al punto o 7 se debe repetir 
            cout<<"tire de nuevo los dados"<<endl;

            dado1 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6
            dado2 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6

            juego = dado1 + dado2;

            cout<<"Sacaste: "<<juego<<endl;

            if(juego==7){//Se saca 7  y se piurde
                cout<<"Craps, perdiste"<<endl;
            }

            else if(juego==punto){//Se obtiene el punto y se gana
                cout<<"Ganaste"<<endl;
            }


        }
    }
}