#include <iostream>
#include <cmath>
#include <time.h>



int main(){
  int dado1;
  int dado2;
  int inicio;
  bool Condicion;
  srand(time(NULL));
  Condicion= false;
 
  while(Condicion == false){

    int tirar;
    int conf;

    std::cout << "Bienvenido al casino de Born. Vamos a jugar Craps.¿Estas listo?.Ingresa 1 si quieres jugar y 0 si deseas salir." << std::endl;
    std::cin >> inicio;
    std::cout << "\n";
    std::cout << "\n";
    
    if(inicio==1){
      int suma;
      std::cout << "Vamos a tirar los dados ingrese uno para tirar" << std::endl;
      std::cin >> tirar;
      std::cout << "\n";
      std::cout << "\n";
      
    
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

      if(suma==7 || suma==11){
	
	
	std::cout <<"Has Ganado\n";
	std::cout << "\n";
	std::cout <<"¿Quieres volver a jugar? Ingresa 1 si deseas volver a jugar y 0 si quieres salir";
	std::cin >> conf;
	
	if (conf==0){
	  
	  Condicion= true;
	}

	if(conf==1){
	  std::cout << "Muy bien volvamos a jugar\n";
	  std::cout << "\n";
	  std::cout << "\n";
	}

      }

      if(suma==2 || suma ==3 || suma==12){
	
	std::cout <<" ¡CRAPS!. Has perdido\n";
	std::cout << "\n";
	std::cout <<"¿Quieres volver a jugar? Ingresa 1 si deseas volver a jugar y 0 si quieres salir";
	std::cin >> conf;
	    
	if (conf==0){
	      
	  Condicion= true;
	}

	if(conf==1){
	  std::cout << "Muy bien volvamos a jugar\n"; 
	}
	
      }

      if(suma==4 || suma==5 ||suma==6 || suma==8 || suma==9 || suma==10){
	
	int Punto;
	bool Condition;
	std::cout <<"Ahora " << suma << " Es tu punto, debes sacarlo para ganar, si sacas 7 pierdes." <<std::endl;
	std::cout << "\n";
	std::cout << "\n";
	
	Punto=suma;
	Condition = false;
	
	while(Condition == false){
	  int dado1p;
	  int dado2p;
	  int sumap;

	  std::cout << "Ingresa 1 para tirar los dados\n";
	  std::cin >> tirar;

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

	  
	  if (sumap == Punto){
	    
	    Condition=true;
	    
	    std::cout << "Has Ganado\n";
	    std::cout << "\n";
	   
	    std::cout <<"¿Quieres volver a jugar? Ingresa 1 si deseas volver a jugar y 0 si quieres salir";
	    std::cin >> conf;
	    std::cout << "\n";
	    if (conf==0){
	      
	      Condicion= true;
	    }

	    if(conf==1){
	      std::cout << "Muy bien volvamos a jugar\n";
	    }
	  }
	  
	  if(sumap==7){
	    Condition=true;
	    
	    std::cout <<"Has perdido\n";
	    std::cout << "\n";
	    std::cout <<"¿Quieres volver a jugar? Ingresa 1 si deseas volver a jugar y 0 si quieres salir";
	    std::cin >> conf;
	    
	    if (conf==0){
	      
	      Condicion= true;
	    }

	    if(conf==1){
	      std::cout << "Muy bien volvamos a jugar\n"; 
	    }

	  }
	  
	  else{
	      std::cout<< "Aun no has ganado tienes que sacar "<< Punto << std::endl;
	  }
	}
      }
    }

    if(inicio==0){
      Condicion= true;
    }
  
  
  
  }

}
