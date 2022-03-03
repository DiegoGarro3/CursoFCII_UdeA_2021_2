#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

std::string decimal_hexa(int num){
  
  std::string cadena[]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
  int coc{10};
  int res{10};
  std::string hexa;
  
  while(res != 0){
    
    coc=num/16;
    res=num%16;
    if (res ==0 ){
      break;
    }
    
    //std::cout << coc << "   " << res << "   " << cadena[res] << std::endl;
    hexa = cadena[res]+ hexa;
    num=coc;
  }

  return hexa;

}

std::string decimal_binario(int num){
  std::string binario[2]={"0","1"};
  std::string bin;
  int cociente{50};
  int residuo {50};
  while (cociente !=0){
    
    cociente=num/2;
    residuo=num%2;
    bin=binario[residuo]+bin;
    num=cociente;
  }
  
  return bin ;
  


}

int hexagesimal_decimal(std::string num){

  int  decimal{0};
  char hexa[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 

  for (int i=0; i <= num.length()-1 ; i++ ){
   
    
    for (int j=0; j <= 15 ; j++){

      if(num[i]==hexa[j]){
	
	decimal+=j*pow(16,num.length()-1-i);
      }
      
    }
    
  }
  return decimal;
    


}

int bina_decimal(std::string num){
  
  int decimal{0};
  char bina[]={'0','1'};
  
  for (int i=0; i <= num.length()-1 ; i++ ){
   
    
    for (int j=0; j <= 1 ; j++){

      if(num[i]==bina[j]){
	
	decimal+=j*pow(2,num.length()-1-i);
      }
      
    }
    
   }
   
  return decimal;
    

}

    

int main(){


  std::string Opciones[]={"hexadesimal","decimal","binario"};
  std::cout << "Vamos a convertir un numero, escriba el sistema inicial: " << std::endl;
  
  for(int i=0 ; i<=2;i++){
    
    std::cout << Opciones[i] << "  ";
   }
  
  std::string inicio;
  std::cin >> inicio;
  
  //Hexadecimal 
  if (inicio==Opciones[0]){
    
    std::cout << "Ingrese el numero en el sistema " << Opciones[0] << std::endl;
    std::string hexa;
    std::cin >> hexa;
    std::string b;
    std::cout << "A que sistema desea converterir el numero : "<< std::endl;
    std::cin >> b;
    
    //Hexadecimal a Decimal
    if (b == Opciones[1]){
      std::cout << "El numero " << hexa << "  en el sistema decimal es igual a :  " << hexagesimal_decimal(hexa) << std::endl;

    }
    
    //Hexadecimal a binario
    if (b==Opciones[2]){
      std::cout << "El numero " << hexa << "  en el sistema binario es igual a :  " << decimal_binario(hexagesimal_decimal(hexa))  << std::endl;

    }
    
    
  }
  
  //Decimal
  if(inicio==Opciones[1]){
    
    std::cout << "Ingrese el numero en el sistema " << Opciones[1] << std::endl;
    int decimal;
    std::cin >> decimal;
    std::string c;
    std::cout << "A que sistema desea converterir el numero : "<< std::endl;
    std::cin >> c;
    
    // Decimal a hexadecimal
    if (c == Opciones[0]){
      std::cout << "El numero " << decimal << "  en el sistema hexadecimal es igual a :  " << decimal_hexa(decimal) << std::endl;

    }
    
    //Decimal a binario
    if (c ==Opciones[2]){
      std::cout << "El numero " << decimal << "  en el sistema binario es igual a :  " << decimal_binario(decimal)  << std::endl;

    }
    
  }


  //Binario
  if(inicio==Opciones[2]){
    
    std::cout << "Ingrese el numero en el sistema " << Opciones[2] << std::endl;
    std::string binario;
    std::cin >> binario;
    std::string d;
    std::cout << "A que sistema desea converterir el numero : "<< std::endl;
    std::cin >> d;
      
    // Binario a decimal
    if (d == Opciones[1]){
      std::cout << "El numero " << binario << "  en el sistema decimal es igual a :  " << bina_decimal(binario) << std::endl;
	
    }
    
    // binario a hexadecimal
    if (d ==Opciones[0]){
      std::cout << "El numero " << binario << "  en el sistema hexadesimal es igual a :  " << decimal_hexa(bina_decimal(binario))  << std::endl;
	
    }
    


  }

  return 0;

}


 



