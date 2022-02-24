#include <iostream>
#include <string> //manejo de strings
#include <vector> //manejo de vectores
#include <math.h> //uso de herramientas matematicas como potenciacion


using namespace std;

//DECIMAL a HEXADECIMAL
string Deci_to_Hexa(string numero){
	int n,base,cociente,tam,residuo;
	
	n = stoi(numero); //convierto el string en entero para trabajar con el
	base=16; //sistema de base 16
	cociente=1;
	tam=16;
	string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	int i=0;
	vector<int> residuos; //vector de enteros vacio
	
	while(cociente!=0){
   	cociente = n/base; // calculo la parte entera
      residuo = n%base; //calculo el residuo
      residuos.push_back( residuo ); // almaceno los residuos en un vector
      n = cociente;
      i++;
   }
   
   string num_convertido=""; //almaceno en un string los residuos del numero decimal en orden del ultimo hasta el primero
   
   for(int j=0;j<i;j++){
   	num_convertido += hex[residuos[i-(j+1)]];
   }
   return num_convertido; //retorno un string con el numero convertido a hexadecimal
}

//DECIMAL a BINARIO
string Deci_to_Bin(string numero){
	int n,base,cociente,tam,residuo;
	
	n = stoi(numero); //convierto el string en entero para trabajar con el
   base=2; //sistema de base 2
   cociente=1;
   int i=0;
   vector<int> residuos; //vector de enteros vacio
    
   while(cociente!=0){
   	cociente = n/base; // calculo la parte entera
      residuo = n%base; //calculo el residuo
      residuos.push_back( residuo ); // almaceno los residuos en un vector
      n = cociente;
      i++;
   }
   string num_convertido=""; //almaceno en un string los residuos del numero decimal en orden del ultimo hasta el primero
   for(int j=0;j<i;j++){
   	num_convertido += to_string(residuos[i-(j+1)]);
   }
   return num_convertido; //retorno un string con el numero convertido a binario
   }

//HEXADECIMAL a DECIMAL
string Hexa_to_Deci(string numero){
	int tam,k,base;
	
	tam = 16;
   string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
 		
   base = 16;
   k=numero.size(); //tamaño o longitud del hexadecimal
   
   int convertidos[k];
   string digitos[k];
    
   for(int i=0;i<k;i++){
   	digitos[i]=numero[i]; //almaceno cada digito del numero ingresado en un arreglo
   }
    
   for(int i=0;i<k;i++){           //comparo los digitos ingresado con los hexadecimales y averiguo que posicion les corresponde
   	for(int j=0;j<tam;j++){      //esta posicion coincide con su correspondiente numero entero ej. A=10
      	if(digitos[i] == hex[j] ){//guardo la posicion que le corresponde a cada digito ingresado en "convertidos"
         	convertidos[i] = j; 
        	}
    	}
   }
   int sum = 0; 
      
   for(int i=0;i<k;i++){
        sum += convertidos[i]*pow(base, k-(i+1)); //uso el entero correspondiente de cada digito hexadecimal y trabajo con el      
   }
   string num_convertido = to_string(sum); //convierto el total de la suma de enteros en un string 
   return num_convertido; //retorno un string con el numero convertido a decimal
}

//HEXADECIMAL a BINARIO
string Hexa_to_Bin(string numero){
   int tam,k;
   tam = 16;
   string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	string bin[tam]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001",
   "1010","1011","1100","1101","1110","1111"};
    
   k=numero.size(); //tamaño o longitud del hexadecimal
   string digitos[k];
   string convertidos[k];
   
   for(int i=0; i<k; i++){
   	digitos[i]=numero[i]; //almaceno cada digito del numero ingresado en un arreglo
   }
    		
   for(int i=0; i<k; i++){      
   	for(int j=0; j<tam; j++){    //comparo el arreglo con los digitos del numero ingresado con todos los posibles del sistema 
      	if(digitos[i] == hex[j] ){	//hexadecimal, luego dependiendo de la posicion que coincida almaceno el digito binario con esa
         	convertidos[i] = bin[j];  //posicion
      	}
      }
   }
   string num_convertido=""; //almaceno en un string los digitos hexadecimales a su correspondiente binario
   for(int i=0; i<k; i++){
   	num_convertido += convertidos[i];
   }
   return num_convertido; //retorno un string con el numero convertido a binario
}

//BINARIO a DECIMAL
string Bin_to_Deci(string numero){
	int k,base;
   
   k = numero.size(); //tamaño o longitud del binario
   string digitos[k]; //arreglo donde almaceno cada digito del binario
   base = 2;
    		
   for(int i=0; i<k; i++){
   	digitos[i]=numero[i];
   }
    
   int sum=0;
   for(int i=0; i<k; i++){
   	sum += stoi(digitos[i])*pow(base,k-(i+1)); //convierto cada digito del binario en entero y trabajo con el
   }
   		
  	string num_convertido = to_string(sum); //convierto el total de la suma de enteros en un string 
   return num_convertido; //retorno un string del numero convertido a decimal
}

//BINARIO a HEXADECIMAL
string Bin_to_Hexa(string numero){
	int tam,k;
   tam=16;
   string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
   string bin[tam]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001",
   "1010","1011","1100","1101","1110","1111"};
    
   k=numero.size(); //tamaño o longitud del binario
   string digitos[k/4]; //numero de digitos divididos en grupos de 4
    
   int l=0;
   for(int i=0; i<k/4; i++){
   	digitos[i] = numero.substr(l,4); //guardo en "digitos" el binario dividiendolo en grupos de 4 ceros y unos, siendo cada grupo una entrada.   
      l=l+4;
   }
    
   string convertidos[k/4]; //guardo los grupos de 4 convertidos a hexadecimal
    		
   for(int i=0; i<k/4; i++){
   	for(int j=0; j<tam; j++){
      	if(digitos[i]==bin[j]){ //comparo cada grupo de 4 ceros y unos ingresados con cada componente de "bin" 
         	convertidos[i]=hex[j]; //almaceno el correspondiente grupo pero en hexadecimal
         }
      }
   }
   string num_convertido = ""; //convierto el arreglo de strings en un solo string con el numero convertido
   for(int i=0;i<k/4;i++){
   	num_convertido+=convertidos[i];
   }
   return num_convertido; //retorno un string del numero convertido a hexadecimal
}

string Conversor_Unidades(string numero, string sistema1, string sistema2){
	
	//Conversores de DECIMAL a...
   if(sistema1=="Decimal"){
 	 	
 	 	//Hexadecimal
    	if(sistema2=="Hexadecimal"){
    		return Deci_to_Hexa(numero);
    	}

    	//Binario
    	else if(sistema2=="Binario"){
    		return Deci_to_Bin(numero);
    	}
    	//Se hacen estos return cuando el nombre del sistema2 no tiene la primera letra en mayuscula.
    	else{
    		return "  Ingreso un sistema mal digitado, este conversor exige que los nombres de los sistemas tengan primera letra en mayuscula. "; 
    	} 
	}
    
   //Conversores de HEXADECIMAL a...
   if(sistema1=="Hexadecimal"){
    
   	//Decimal
   	if(sistema2=="Decimal"){
   		return Hexa_to_Deci(numero); 
   	}
    
   	//Binario
   	else if(sistema2=="Binario"){
   		return Hexa_to_Bin(numero);       
    	}
    	else{
    		return "  Ingreso un sistema o numero mal digitado, este conversor exige que los nombres de los sistemas tengan primera letra en mayuscula. ";
    	}
	}
    
   //Conversores de  BINARIO a ... 
   if(sistema1=="Binario"){
   
   	//Decimal
    	if(sistema2=="Decimal"){
    		return Bin_to_Deci(numero);
    	}
    
    	//Hexadecimal
		else if(sistema2=="Hexadecimal"){
    		return Bin_to_Hexa(numero);
   	}
   	else{
   		return "  Ingreso un sistema o numero mal digitado, este conversor exige que los nombres de los sistemas tengan primera letra en mayuscula. ";
   	}    
   }
   //Se hacen estos return cuando el nombre del sistema1 no tiene la primera letra en mayuscula.
   return "  Ingreso un sistema o numero mal digitado, este conversor exige que los nombres de los sistemas tengan primera letra en mayuscula. ";
}

    
    
    
    
