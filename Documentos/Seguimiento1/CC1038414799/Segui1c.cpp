#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
unsigned int replay = 0;
unsigned int num = 1;
unsigned int guess = 1;


int main()
{

    while (replay != 1)
    {
        cout << "La maquina elegirá un número entre 1 y 1000 que debe ser adivinado por usted"<< endl;
        srand(time(0));
        num = 1+rand()%(1000); //Random number between 1 and 1000

        cout << "Ingrese el número: ";
        cin >> guess; //Player select a number 
        cout << '\n';

        while (num != guess) //While loop if the player's number is not the random number
        {
            
            //Enter here if the player's number is smaller than random number
            if (num < guess) 
            {
                cout << "Su elección "<< guess <<" es mayor que el número a adivinar" << endl;
                cout << "Ingrese otro número: ";
                cin >> guess; //Select another number
                cout << '\n';
            }
            
            //Enter here if the player's number is bigger than random number
            else if (num > guess)
            {
                cout << "Su elección "<< guess <<" es menor que el número a adivinar" << endl;
                cout << "Ingrese otro número: ";
                cin >> guess; //Select another number
                cout << '\n';
            }

        }
        
        cout << "Adivinaste el número, si era: " << num << endl; //Print the random nuber if the player guess it
        cout << "¿Deseas jugar de nuevo? (Si = 0 , No=1 ): ";//Ask the player to play again
        cin >> replay;
        cout << '\n';      
    }
    
    cout << "Se finaliza el juego."<< endl;
    return 0;   
}