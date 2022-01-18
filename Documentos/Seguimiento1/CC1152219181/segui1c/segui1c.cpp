#include <iostream>
#include <time.h>
#include <stdlib.h>

int main()
{
  int num;
  bool E;
  int n;
  bool F;
  int a;

  F=false;

  while(F==false){
    
      E=false;
      
      srand(time(NULL));

     std::cout << "Generamos un numero del 1 al 1000. ¿Puedes adivinarlo?" << std::endl;
     num=1+rand()%(1000);
    
    while(E==false){
      
    std::cout <<"Ingresa un numero del 1 al 1000" << std::endl;
    std::cin>> n;
    std::cout << "\n" << std::endl;
    
    if (n < num){
      std::cout  << n << " " <<  "Es menor que el numero que debes adivinar" <<  std::endl;
 
    }

    else if(n >num){
      
      std::cout  << n << " " << "Es mayor que el numero que debes adivinar" <<  std::endl;
      
      
    }

    else if(n==num){

      std::cout << "Has ganado el numero es" << " " << n << std::endl;
      std::cout << "\n" << std::endl;
      E=true;
      }
    
    }

    
    std::cout << "¿Quieres volver a jugar?" << std::endl;
    std::cout << "Ingresa 1 si deseas volver a jugar y 0 si deseas dejar de jugar." << std::endl;
    std::cin >> a;
    std::cout << "\n" << std::endl;
    if ( a == 0){

      break;

    }
      
    
    

  }

  return 0;
  
}
