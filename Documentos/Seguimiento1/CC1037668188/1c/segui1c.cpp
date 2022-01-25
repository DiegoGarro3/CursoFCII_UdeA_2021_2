#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(){
    int numero; //numero que se debe adivinar
    int minumero =0; //numero que escojo
    int si = 1; //condicion para volver a jugar, 0 sino
    srand(time(NULL)); //semilla para el numero
    while(si==1){
        cout << "ADIVINA EL NUMERO: DEL 1 AL 1000, Empecemos."<< endl;
        numero=1+rand()%(1000);  // numero aleatorio entre 1 y 1000, incluyendo 1 y 1000
        do
        {
            cout<< "Ingresa un numero entre 1 y 1000: ";
            cin >> minumero;
            if(minumero==numero){
                cout<<"Adivinaste el numero!"<<endl;
                break;
            }
            if(minumero<1 || minumero>1000){
                cout<< "ERROR: el numero debe estar entre 1 y 1000"<< endl;
                continue;
            }
            if(minumero<numero){
                cout<<"Tu numero es menor que el numero que tienes que adivinar, escoge otro."<<endl;
            }
            else if(minumero>numero)
            {
                cout<< "Tu numero es mayor que el numero que tienes que adivinar, escoge otro."<<endl;
            }
        }   
        while(minumero != numero);
    cout<<"Si quieres volver a jugar ingrasa 1, sino ingresa 0: ";
    cin >> si;
    if(si==0)
    cout<< "Gracias por jugar."<< endl;
    else
    cout<< "Listo, volvamos a jugar."<< endl;

        
    }
}    
    
        




