#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>


using namespace std;


void Welcome_message();


int main(){

//Mensaje de Inicio del Juego
  Welcome_message();
  
//Listado de Palabras a seleccionar
  vector <string> word = {"palabra", "juega", "armamento","plato","computador","efimero", "mecanico", "tolerancia", "murcielago", "libro"};
  
  enum States {CONTINUAR, SALIR};
  States Estado_juego = CONTINUAR;
  
  while(Estado_juego == CONTINUAR ){  
  
 //Generamos un número aleatorio
  srand(time(NULL));
  size_t random_num;  
  random_num = rand() % word.size();


  
//Seleccionamos una palabra para adivinar 
  string word_random = word[random_num];
  
  
//Longitud de la palabra seleccionada
  size_t word_length = word_random.length();
  string word_hidden(word_length, 42);
  
    
  
  cout << endl;
//Mostrar numero de caracteres de la palbra oculta
  for(size_t i=0; i < word_length; i++){
    cout << word_hidden[i];
  }  
  
  string adivinanza;
  
//contador de intentos incorrectos
  unsigned int intentos_incorrectos = 0, max_oportunidades = 7;
  
  while (word_hidden.find(42) != std::string::npos && intentos_incorrectos < max_oportunidades){
  
//El usuario introduce aquello que desea adivinar  
	cout << "\nIntroduzca una letra, fragmento o palabra: " << endl;
	getline(cin, adivinanza);
		

//adivina la palabra completa y sale del ciclo while
	if (adivinanza.compare(word[random_num]) == 0){
	
	  word_hidden = adivinanza;	
	   	
	}
//Sino buscamos coincidencias		
	else{

		size_t pos_acierta = word_random.find(adivinanza);
						
		if (pos_acierta != std::string::npos){
		
			while (pos_acierta != std::string::npos){
			
				for (size_t j = pos_acierta; j < (pos_acierta + adivinanza.length()); j++)
				{
				word_hidden[j] = word_random[j];
				word_random[j] = '*';
				}
				//busca si existen otro caracter (fragmento) igual en la palabra oculta
				pos_acierta = word_random.find(adivinanza);			
			}
		}
		
		else{
			++intentos_incorrectos;
			cout << "\nNo hay coincidencias. Te quedan " << (max_oportunidades - intentos_incorrectos) << " intentos.\n";
		}	
	}
	
		
	cout << endl;
//Mostrando en pantalla el avance de la palabra oculta
	for(size_t i=0; i < word_length; i++){
	cout << word_hidden[i];
	}
	
	cout << endl;
	
	if (intentos_incorrectos == max_oportunidades){
		cout << "Te has quedado sin intentos. La palabra correcta es -> [" << word[random_num] << " ]" << endl;
	}
	
	if(word_hidden.find(42) == std::string::npos){
	  cout << "Felicidades. Has descubierto la palabra." << endl;
	}	
	
  }

//Pregunta si desea continuar el Juego
  cout << "¿Desea jugar de nuevo? Ingrese Sí [presione 's'] / No [cualquier tecla]\n";
  
  string decision;
  getline(cin, decision);  
  
  if (decision.compare("s")!=0){
    Estado_juego = SALIR;
  }
  
  }
  
  
  
  cout << "\n Gracias por jugar." << endl;  

  return 0;
}

void Welcome_message()
{
	string Inicio, Instrucciones;
	Inicio = "Bienvenido a AHORCADOs. \nEl juego de adivinar palabras.";
	Instrucciones = "\nIntrucciones: \n 1. El sistema selecciona una palabra de manera aleatoria. \n 2. Debe intentar adivinar la palabra (minúsculas). Puede ingresar letras, fragmentos de la palabra (ej. 'lor' de la palabra 'color') o la palabra completa. \n 3. Tiene 7 oportunidades para adivinar. \n\nDisfrute del juego.";

	cout << Inicio << Instrucciones << endl;
}
