#include <iostream>

int main(){
  int i; 
  int C{0}; // Valor 0 o 1
  int G; //Contador de los que pasaron
  int P; // Contador de los que no pasaron
  
  G=0;
  P=0;
  i=0;
  

  while (i<10){
    
      std::cout << "Ingrese el resultado de el estudiante. (1 = Gano , 0 = Perdio):";
      std::cin >> C ;
      if (C == 0 || C == 1){ //Si C=0 o C=1 
	
	if( C==0 ){
	P=P+1;
	}
      
	if( C==1){
	G=G+1;
	}

	i++;
      }
      else{
	std::cout<< "Error,se ingreso un numero diferente de 0 o 1\n";
	
      }
	
  }
  
  std::cout << "Aprobaron: " << G << std::endl;
  std::cout << "No Aprobaron: " << P << std::endl;
  
  if(G>=8){
    std::cout << "Excelente instructor!\n";
  }
    
  

  
}
