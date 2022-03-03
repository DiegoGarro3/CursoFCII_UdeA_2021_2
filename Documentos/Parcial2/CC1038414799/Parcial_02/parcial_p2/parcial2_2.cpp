#include<iostream>
#include<string>
#include <unistd.h>
#include <ctime>

using namespace std;

string word;
unsigned int rdm;

int main()
{   
    
    //a list of words to guess
    string words[]= {"hola","perro","proton","estudiante","gato",
    "nuclear","carro"};
    
    //sentinel while loop to continue playing until the user decide not to
    char usr = '1';
    while(usr=='1')
    {

        //selects a random word of the list to be guessed
        srand(time(0));
        rdm= rand()%7;
        word=words[rdm];
        
        
        unsigned int length= word.length();

        string codex (length, '-'); //creatas de codificated word
        
        cout << "\n";
        cout << "Vamos a jugar ahorcado, adivine la palabra (tiene " << length <<" letras): " << codex << endl;
        string letr;
        
        //while loop to count the seven attemps the player has
        int i=0;
        while (i<7)
        {
            
            //player enters a letter
            cout << "Ingrese una letra (minúscula): ";
            cin >> letr; 
            
            cout << endl;
            int idx=0;

            //search if the word to be guessed has the letter
            idx =word.find(letr);

            
            //enters if the word has the letter
            if( idx != string::npos){

                cout << "La palabra si tiene esa letra: ";

                //replace the letter in the codificated word
                while( idx != string::npos ){
                    codex.replace( idx , 1 , letr );
                    idx = word.find( letr , idx+1 );
                }

            cout << codex << "\n"; //shows the codificated word

            
            //End game if the player completed the word guessing letter by letter
            if(codex==word)
            {
                cout << "\n";
                cout << "¡Has adivindado! La palabra es " << codex <<endl;
                i=10;
                break;
            }

            char opt = '2';

            //if player guess one letter can choose to guess the entire word
            cout <<"Si desea adivinar la palabra pulse 1, sino pulse culaquier tecla: ";
            cin >> opt;

            if (opt=='1')
            {   
                string guess;
                cout << "Ingrese la palabra (en minúsculas): ";
                cin >> guess;

                //End game if the player guess the word
                if(guess == word)
                {
                    cout << "\n";
                    cout << "¡Has adivindado! La palabra es " << guess <<endl;
                    i=10;
                }

                //if player doesn't guess the word he lose one attemp 
                else
                {   cout << "\n";
                    cout << guess << " no es la palabra, le restan "<< 6-i <<" intentos"  <<endl;
                    cout << "palabra: "<< codex << endl;
                    i++;
                }
            }


                
            }

            //if player doesn't guess a letter he lose one attemp 
            else{
                cout << "\n";
                cout << "La palabra no tiene esa letra, le restan "<< 6-i << " intentos" << endl;
                cout << "palabra: "<< codex << endl;
                i++;

            }

        }
            //Loser message 
            if(i!=10)
            {   cout << "\n";
                cout << "!Has sido colgado! x x" << endl;
                cout << "                    ~ " << endl;
            }

        //Option to play again
        cout << "\n";
        cout << "Pulse 1 si desea jugar de nuevo, sino pulse cualquier otra tecla: ";
        cin >> usr;
    
    }

    return 0;
}