#include <iostream>
#include <cmath>
#include <time.h>

int Craps(){

  int dado1; //Inicailizacion variables lanzamiento de dados
  int dado2;
  int suma;
  int tirar;
  int Resultado=0;
  
  srand(time(NULL)); //Semilla para los numeros aleatorios
 
  std::cout << "Vamos a tirar los dados. Ingrese 1 para tirar: " ;
  std::cin >> tirar;
  std::cout << "\n";
  std::cout << "\n";
      
  //Lanzamineto de los dados 
  dado1=1+rand()%6;
  dado2=1+rand()%6;
  suma=dado1+dado2;
      
  std::cout << "El valor del dado1 es de : " << dado1 << std::endl;
  std::cout << "\n";
  std::cout << "El valor del dado2 es de : " << dado2 << std::endl;
  std::cout << "\n";
  std::cout <<  "La suma de los dos dados es :" << suma << std::endl;
  std::cout << "\n";
  std::cout << "\n";

  //Condicional para victoria inmediata

  if(suma==7 || suma==11){

    std::cout <<"Has Ganado!\n";
    std::cout << "\n";
    Resultado += 1;
    
  }
  //Condicional para perdida inmediata
  if(suma==2 || suma ==3 || suma==12){
	
    std::cout <<" ¡CRAPS!. Has perdido\n";
    std::cout << "\n";
    
  }

  //Condicional para continuar el juego
  
  if(suma==4 || suma==5 ||suma==6 || suma==8 || suma==9 || suma==10){
    
    int Punto;
    bool Condition;
    std::cout <<"Ahora " << suma << " Es tu punto, debes sacarlo para ganar, si sacas 7 pierdes." << std::endl;
    std::cout << "\n";
    std::cout << "\n";
	
    Punto=suma;
    Condition = false;

    // CONDICIONAL PARA QUE SE SIGA TIRANDO LOS DADOS HASTA QUE EL JUGADOR GANE O SAQUE 7 Y PIERDA.
    while(Condition == false){
      int dado1p;
      int dado2p;
      int sumap;

      //Interaccion con el usuario para que tire
      std::cout << "Ingresa 1 para tirar los dados: ";
      std::cin >> tirar;

      //Nuevo lanzamiento de dados
      dado1p=1+rand()%6;
      dado2p=1+rand()%6;
      sumap=dado1p+dado2p;
      
      std::cout << "El valor del dado1 es de : " << dado1p << std::endl;
      std::cout << "\n";
      std::cout << "El valor del dado2 es de : " << dado2p << std::endl;
      std::cout << "\n";
      std::cout <<  "La suma de los dos dados es :" << sumap << std::endl;
      std::cout << "\n";
      std::cout << "\n";

      //Condicional para la victoria le suma uno a la variable resultado para luego identificar esto como una victoria y  actualizar saldo en banco
      if (sumap == Punto){
	
	Condition=true;
	std::cout << "Has Ganado!\n";
	std::cout << "\n";
        Resultado +=1; //
      }
      //Condicional para la derrota 
      if(sumap==7){
	
	Condition=true;
	std::cout <<"Has perdido\n";
	std::cout << "\n";

     
      }
      //COndicional para decir que aun no ha ganado el suusario y debe volver a tirar
      if (sumap != Punto && sumap !=7){
	std::cout<< "Aun no has ganado tienes que sacar "<< Punto << std::endl;
      }
      
    }
  }
  return Resultado;
}
