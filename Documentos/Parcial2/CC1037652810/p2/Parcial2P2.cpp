#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time
#include <iomanip>
#include <string>
#include <cstring> // this is to use strlen to know the length of the char array

using namespace std;

int busquedaLineal( string arreglo, string clave, int tamanioDelArreglo )
{ 
  for ( int j = 0; j < tamanioDelArreglo; j++ ){
    if ( arreglo.substr( j, 1 ) == clave ){ 
      return j;
    }
  }
  
  return -1; // no se encontró la clave
}

string dynamicString(int size){
  string dynamicstring;
  for (int i=0;i<size; i++){ dynamicstring= dynamicstring + 'x';}
  //cout << dynamicstring << endl; //shows adivine la palabra: xxxx
  return dynamicstring;
  
}

//choose the word to guess
string whichword()
{
  // elige valores aleatorios 
  string words[] = {"Fields","Metal","Waves","Worlds","Physics","Matter","Charge"};
  //randomiza el generador de números aleatorios, usando la hora actual
  srand( time( 0 ) );
  int size=sizeof(words)/sizeof(words[0]);
  cout << "size " << size << endl;
  int ran = 0 + rand() % (size-1)+1-0 ; // tiro del primer dado
  
  // muestra los resultados
  cout << "num aleatorio " << ran << endl;
  return words[ran];
} 


void game()
{ 

  unsigned int result{0};
  // enumeración con constantes que representa el estado del juego
  enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  //enum class Estado {CONTINUAR, GANO, PERDIO}; // note el "class"
  Estado estadoJuego=CONTINUAR; // puede contener CONTINUAR, GANO o PERDIO
  
  string word = whichword();
  int size = word.length();
  string dynamicstring=dynamicString(size);
  cout << "Palabra a adivinar: " << dynamicstring << endl; //shows adivine la palabra: xxxx
  int mistakes{0};
  // mientras el juego no esté completo
  while ( estadoJuego == CONTINUAR ) 
    {  
      
      string letter;
      cout << "Introdusca una letra (La palabra tiene mayuscula inicial)" << endl;
      cin >> letter;
      int posguess{0};
      string choice;
      string guessword;
      
      posguess=busquedaLineal(word,letter,word.length());
      
      if (posguess==-1){mistakes=mistakes+1; cout << "current mistakes: " << mistakes << endl;} //dynamicstring[j] = ( posguess == -1 ) ? "x" : letter;
      else {dynamicstring.replace( posguess, 1, letter );}
      cout << "Palabra a adivinar: " << dynamicstring << endl;
      if (dynamicstring==word){ estadoJuego=GANO; cout << "palabra adivinada, ganaste!" << endl; break;}
      if (mistakes==7){estadoJuego=PERDIO;; cout << "Cometiste 7 errores, Perdiste!" << endl; break;} 
      cout << "Quiere adivinar la palabra completa? (si, no)" << endl;
      cin >> choice;
      if (choice=="si"){cout << "Cual es la palabra? " << endl; cin >> guessword; 
          if (guessword==word){dynamicstring=guessword; estadoJuego = GANO; cout << "Correcto, Ganaste!" << endl;}
          else {estadoJuego=PERDIO; cout << "Incorrecto, Perdiste!" << endl;}
      } //choise to guess the whole world so the world introduced is compared with the answer
      //cout << dynamicstring << endl; 
            
 }//end of while
} 

int main()
{
  string wanaplay= "si";
  while(wanaplay=="si"){
    
    game();
    cout << "Quiere jugar de nuevo? (si, no)" << endl;
    cin >> wanaplay;
  }
}
