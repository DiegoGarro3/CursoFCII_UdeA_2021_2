
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    bool play=true;
    while(play){
        
        //Seleccionando el número.
        srand(time(NULL));
        int number=1 + rand() % (1000 +1 - 1);
        
        cout << "Este juego se trata de adivinar un número del 1 al 1000 elegido aleatoriamente;"<<endl;
        cout << "para ello debe ingresar un número y se le dirá si es mayor o menor al número elegido."<<endl;
        
        //Comprobando la victoria.
        int guess;
        do{
            cout << "Ingrese el número que cree que fue elegido... ";
            cin >> guess;
            if(guess<number){
                cout << "El número que ingresó es MENOR que el escogido."<<endl;
            }
            else if(guess>number){
                cout << "El número que ingresó es MAYOR que el escogido."<<endl;
            }
            else{
                cout << "Acertó el número!"<<endl;
            }
            
        }
        while (guess!=number);
        
        //Volver a jugar.
        string again;
        cout << "Volver a jugar? [y/n] ";
        cin >> again;
        if(again.compare("n")==0){
            play=false;
            cout << "Fin del juego!";
        }
        
    }
    
}



