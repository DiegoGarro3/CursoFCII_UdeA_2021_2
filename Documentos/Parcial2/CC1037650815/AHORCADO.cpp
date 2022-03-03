#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>

#define WORDS_PATH "palabras.txt" //Camino para cargar el archivo con las palabras 

using namespace std;


int juego(string, string); //Función para jugar 
void cargar_palabras();  //Función para cargar las palabras del archivo de texto
int fracasos = 0; //Contador de los fracasos dentro del juego
string ahorcado;  // guarda la palabra que el jugador debe adivinar

void cargar_palabras()
{

  vector <string> lista_palabras; //Vector para guardar las palabras 
  string palabra_aux;  //Lee las palabras del archivo txt
  ifstream archivo_palabras(WORDS_PATH); //Se carga el archivo
	
  if (archivo_palabras.fail())  //El archivo no se abrió con éxito
  { 
      cout << "El archivo no se abrió con éxito" << endl;
      exit( 1 );
  }
       
  while(!archivo_palabras.eof()) //Guardan las palabras del archivo en el vector
  { 
    archivo_palabras >> palabra_aux;
    lista_palabras.push_back(palabra_aux);
  }
  
  int i = rand() % lista_palabras.size(); //Se genera un número aleatorio
  ahorcado = lista_palabras.at(i); //Se guarda la palabra en la variable string
  
}


int juego(string palabra_ahorcado, string palabra_juego) //Función del juego

{ 

int size=palabra_ahorcado.length();
string palabra_secreta (size, '-');
cout<<palabra_secreta<<endl;

  while(fracasos < 7) //solo se puede equivocar un máximo de 7 veces
  
  { 
  
  cout << "Introduzca la letra (recuerde hacerlo en minúscula)" << endl;
  string letra; //Letra que el jugador introduce
  cin >> letra;
  int aciertos = 0; //Variable que determina si el jugador acierta
  int posicion = palabra_ahorcado.find( letra ); //Se usa la función find() para encontrar la letra que el jugador ha escrito en la palabra que está buscando adivinar
  
  if(posicion >= 0)
  
  {
    while ( posicion != string::npos ) //Función para buscar la letra en la palabra
    
      {
      
       palabra_secreta.replace( posicion, 1 , letra );
	posicion = palabra_ahorcado.find( letra, posicion + 1 );
	palabra_juego.append(letra) ; //Va agregando las letras que va acertando el jugador al string auxiliar
	
	aciertos = 1;
	
      }
      
    cout<<palabra_secreta<<endl;  
    
  }
  
  
  else{fracasos++;} //De lo contrario cuenta el fracaso
  
  if (aciertos == 1) //casos en que el jugador acierta
  
  { 
  
      cout << "¿Desea intentar escribir la palabra completa (si/no)?" << endl;
      string respuesta; //Se le permite ingresar la palabra completa
      cin >> respuesta;
      
       if(respuesta == "si")
       
       {
       
	cout << "Introduzca la palabra" << endl;
	string palabra; //Palabra que escribe el jugador
	cin >> palabra;
	
	if(palabra_ahorcado == palabra) //Adivina la palabra completa
	
	{ 
	
	  cout << "Felicitaciones, ¡Ganaste!" << endl;
	  break;
	  
	}
	
	else{ fracasos++;}
	
       }
       else{}
       
  }
  
  else{}

  if(palabra_juego.length() == palabra_ahorcado.length()) //Caso en el que la persona logra adivinar la palabra
  
  { 
  
    cout << "Felicitaciones, ¡Ganaste!" << endl;
    break;
    
  }
   else{}
  } 
  
  return 0;
}



int main()
{
 
  srand(time(NULL)); //Se inicializa la semilla para tomar al azar la palabra
  cargar_palabras(); //Se carga la palabra que debe adivinar
  string intento;  //guarda las letras que va adivinando
  
  cout << R"(
                 8888888888 888
                 888        888                     __________
                 888        888                    |         |
                 8888888    888                    |         0
                 888        888                    |        /|\
                 888        888                    |        / \
                 888        888                    |
                 8888888888 888                    |



                          888                                             888
                          888                                             888
                          888                                             888
                  8888b.  88888b.   .d88b.  888d888 .d8888b  8888b.   .d88888  .d88b.
                     "88b 888 "88b d88""88b 888P"  d88P"        "88b d88" 888 d88""88b
                 .d888888 888  888 888  888 888    888      .d888888 888  888 888  888
                 888  888 888  888 Y88..88P 888    Y88b.    888  888 Y88b 888 Y88..88P
                 "Y888888 888  888  "Y88P"  888     "Y8888P" Y888888  "Y88888  "Y88P"
    )" << '\n';
  cout << "BIENVENIDO AL JUEGO DEL AHORCADITO."<<endl;
  cout << "El número de palabras es de: " << ahorcado.length() << " letras." << endl;
  juego(ahorcado, intento);  //Inicio del juego
  string respuesta;  //Guarda respuesta
  cout << "¿Desea jugar de nuevo?" << endl;
  cin >> respuesta;
  
  if(respuesta == "si") //Jugar de nuevo
  { 
    cargar_palabras();
     cout << "El número de palabras es de: " << ahorcado.length() << " letras." << endl;
    juego(ahorcado, intento);
  }
  else //No desea jugar de nuevo
  {
    cout << "PERDISTE" << endl;
    cout << "Vuelve pronto a jugar de nuevo" << endl;
  }
  return 0;
}


