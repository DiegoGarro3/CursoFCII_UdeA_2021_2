/*
Codigo seguimiento 1c
Santiago Quintero Cordoba 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int numero = 0; //numero que se debe adivinar
int adivinar =0; //numero que se adivina y se espera que sea igual a la variable anterior
string jugar = "s"; //condicion de juego

int main(){

    srand(time(NULL)); //semilla para el numero a adivinar
    numero = 1+rand()%(1001-1); //numero aleatorio entre 1 y 1000

    while (jugar=="s"){ //mientras se cumpla la condicion se jugara

        cout <<"Adivine el numero en el que estoy pensando, es uno entre 1 y 1000"<<endl;
        cin >> adivinar; //entrada por teclado del numero adivinado
            
            if(adivinar == numero){//se adivino el numero
                cout<<"Felicidades, has ganado"<<endl;
                cout<<"¿Quieres volver a jugar?"<<endl;
                cout<<"s para jugar, cualquier otra tecla para salir"<<endl;
                cin >> jugar;//se ingresa si se quiere volver a jugar
                if (jugar=="s"){
                        numero = 1+rand()%(1001-1); //numero aleatorio entre 1 y 1000 
                }
            }

            else if (adivinar > numero){//el numero es mayor al que se debe adivinar
                
                cout<<"Su numero es mayor al que estoy pensando"<<endl;
            }
            
            else{//el numero es menor al numero a adivinar


                cout<<"Su numero es menor al que estoy pensando"<<endl;
            }

    }
}