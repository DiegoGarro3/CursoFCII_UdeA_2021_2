#include <iostream>
#include <cmath>
#include <time.h>

int Craps();



int main(){

  double apuesta{0};
  int SaldoenBanco=1000000; //Inicializacion Saldo en Banco
  int CRAPS{0};
  
  while(SaldoenBanco != 0){

    std::cout << "Tu saldo es: " << SaldoenBanco << std::endl; 
    std::cout << "Bienvenido al casino de Born. Vamos a jugar Craps.¿Quiere hacer una apuesta?. Ingresa el valor de la apuesta: ";
    std::cin >> apuesta; //ngresa la apuesta del ususario
    
    //COndicion para que la apuesta siempre sea menor que el saldo en banco
    while (apuesta > SaldoenBanco){
      std::cout << "Saldo Insuficiente. " << "Tu saldo es: " << SaldoenBanco << " Por favor ingrese otro valor para apostar:";
      std::cin >> apuesta;
    }
    
    std::cout << "Apuesta aceptada.Iniciando Juego.\n";
    
    //Ejecucion del juego
    CRAPS=Craps();
    CRAPS;
    
    //El juego devuelve un 1 si el jugador gana y asi podremos actualizar el saldo en banco
    if(CRAPS==1){
      
      int exit{0};
      
      SaldoenBanco += apuesta;
      std::cout << "Tu nuevo sueldo es :"<< SaldoenBanco << std::endl;
      std::cout << "\n";
      std::cout << "¿Desea volvera apostar?.Ingrese uno si lo desea o cero si desea salir:";
      std::cin >> exit;
      std::cout << "\n";
      
      if (exit==0){

	if(SaldoenBanco<=100000){
	  break;

	}

	//Interaccion con el usuario para que siga jugando
	int exitt{0};
	std::cout << "¿Esta seguro que desea salir?. Acabas de ganar estas en buena racha, ¡VAMOS POR MAS!" << std::endl;
	std::cout << "\n";
	std::cout << "Si quieres volver a apostar ingresa 1, si deseas salir ingresa 0:";
	std::cin >> exitt;
	std::cout << "\n";
	
	if(exitt==0){
	  break;
	}
	
      }
      


    }
    //Condicional en caso de que el usuario pierda para reducir el saldo en banco
    if(CRAPS==0){
      

      SaldoenBanco -= apuesta;
      int exit{0};
      std::cout << "Tu nuevo saldo es : " << SaldoenBanco << std::endl;
      std::cout << "\n";

      //Condicional para salir del juego ya que el usuario no puede apostar mas
      if (SaldoenBanco == 0){
      
	std::cout << "Lo siento. Se quedo sin fondos!" << std::endl;
	break;
      
      }
      
      std::cout << "¿Desea volvera apostar?.Ingrese uno si lo desea o cero si desea salir:";
      std::cin >> exit;
      std::cout << "\n";
      
      if (exit==0){

	if(SaldoenBanco<=100000){
	  break;

	}
	//Interaccion con el usuario
	int exitt{0};
	std::cout << "¿Esta seguro que desea salir?. Puedes recuperar lo que perdiste.¿Porque no lo intentas?" << std::endl;
	std::cout << "\n";
	std::cout << "Si quieres volver a apostar ingresa 1, si deseas salir ingresa 0:";
	std::cin >> exitt;
	std::cout << "\n";
	
	if(exitt==0){
	  break;
	}
	
      }
    }

   
    
    //Interacciones con el usuario para que se retire

    if(SaldoenBanco <= 100000){
      int exit{0};
      std::cout << "Deberia parar, se esta arruinando, piense en su familia" << std::endl;
      std::cout << "\n";
      std::cout << "Si desea salir ingrese 0 o 1 si quiere seguir jugando. " << std::endl;
      std::cin >> exit;
      std::cout << "\n";
      
      if(exit == 0){
	
	break;

      }
      

    }

    if (SaldoenBanco >= 5000000){

      int exit{0};
      std::cout << "Es hora de retirar el dinero. Recuerde que la ludopatia es mala! " << std::endl;
      std::cout << "\n";
      std::cout << "Si desea salir ingrese 0 o 1 si quiere seguir jugando. " << std::endl;
      std::cin >> exit;
      std::cout << "\n";
      
      if(exit == 0){
	
	break;

      }
      

    }

   
  }
  return 0;
}


