#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

    bool game_state=true;
    int guessing;
    int random_number;
    string continue_option;
    
    while(game_state){
        
        
        srand(time(NULL));
        random_number = 1 + rand() % (1000 +1 - 1);
        
        cout << "Se generado un número aleatorio entre 1 y 1000;"<<endl;
        cout << "trata de adivinarlo ¿Podrás? "<<endl;
        
        
        
        do{
            cout << "Ingrese un número: ";
            cin >> guessing;
            if(guessing<random_number){
                cout << "El número que ingresó es MENOR que el escogido."<<endl;
            }
            else if(guessing>random_number){
                cout << "El número que ingresó es MAYOR que el escogido."<<endl;
            }
            else{
                cout << "Acertó el número!"<<endl;
            }
            
        }
        while (guessing!=random_number);
        
        
        
        cout << "¿Reintentar el juego? [s/n] ";
        cin >> continue_option;
        if(continue_option.compare("n")==0){
            game_state=false;
            cout << "Game Over. Gracias por jugar."<<endl;
        }
        
    }
    
}


