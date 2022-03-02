#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

//Los comentarios de cada paso se hicieron solo en las funciones de Tarea2b_conversor.cpp
//como son casi los mismos codigos la idea es la misma, solo cambia en que este imprime los numeros y el otro los retorna  

//DECIMAL a HEXADECIMAL
void Deci_to_Hexa(string numero){
	int n,base,cociente,tam,residuo;
	
	n = stoi(numero);
	base=16;
	cociente=1;
	tam=16;
	string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	int i=0;
	vector<int> residuos;
	
	while(cociente!=0){
   	cociente = n/base; // parte entera
      residuo = n%base; // residuo
      residuos.push_back( residuo );
      n = cociente;
      i++;
   }
   
   cout<<"El número "<<numero<<", corresponde en Hexadecimal a: ";
   for(int j=0;j<i;j++){
   	cout<<hex[residuos[i-(j+1)]];
   }
   cout<<endl;
}

//DECIMAL a BINARIO
void Deci_to_Bin(string numero){
	int n,base,cociente,tam,residuo;
	
	n = stoi(numero);
   base=2;
   cociente=1;
   int i=0;
   vector<int> residuos;
    
   while(cociente!=0){
   	cociente = n/base; // parte entera
      residuo = n%base;
      residuos.push_back( residuo ); // residuo
      n = cociente;
      i++;
   }
   cout<<"El número "<<numero<<", corresponde en  Binario a: ";
   for(int j=0;j<i;j++){
   	cout<<residuos[i-(j+1)];
   }
   cout<<endl;
}

//HEXADECIMAL a DECIMAL
void Hexa_to_Deci(string numero){
	int tam,k,base;
	
	tam = 16;
   string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
 		
   base = 16;
   k=numero.size(); //tamaño del string numero
   
   int convertidos[k];
   string digitos[k];
    
   for(int i=0;i<k;i++){
   	digitos[i]=numero[i];
   }
    
   for(int i=0;i<k;i++){
   	for(int j=0;j<tam;j++){
      	if(digitos[i] == hex[j] ){
         	convertidos[i] = j; // guardamos los datos donde están 
        	}
    	}
   }
   int sum = 0; 
      
   for(int i=0;i<k;i++){
   	sum += convertidos[i]*pow(base, k-(i+1));      
   }
   cout<<"El número "<<numero<<", corresponde en Decimal a: "<<sum<<endl;
}

//HEXADECIMAL a BINARIO
void Hexa_to_Bin(string numero){
   int tam,k;
   tam = 16;
   string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	string bin[tam]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001",
   "1010","1011","1100","1101","1110","1111"};
    
   k=numero.size();
   string digitos[k];
   string convertidos[k];
   
   for(int i=0; i<k; i++){
   	digitos[i]=numero[i];
   }
    		
   for(int i=0; i<k; i++){
   	for(int j=0; j<tam; j++){
      	if(digitos[i] == hex[j] ){
         	convertidos[i] = bin[j]; // guardamos los datos donde están    
      	}
      }
   }
   cout<<"El número "<<numero<<", corresponde en Binario a: ";
   for(int i=0; i<k; i++){
   	cout<<convertidos[i];
   }
   cout<<endl;
}

//BINARIO a DECIMAL
void Bin_to_Deci(string numero){
	int k,base;
   
   k = numero.size();
   string digitos[k];
   base = 2;
    		
   for(int i=0; i<k; i++){
   	digitos[i]=numero[i];
   }
    
   int sum=0;
   for(int i=0; i<k; i++){
   	sum += stoi(digitos[i])*pow(base,k-(i+1));
   }
   		
  	cout<<"El número "<<numero<<", corresponde en Decimal a: "<<sum<<endl;
}

//BINARIO a HEXADECIMAL
void Bin_to_Hexa(string numero){
	int tam,k;
   tam=16;
   string hex[tam]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
   string bin[tam]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001",
   "1010","1011","1100","1101","1110","1111"};
    
   k=numero.size();
   string digitos[k/4];
    
   int l=0;
   for(int i=0; i<k/4; i++){
   	digitos[i] = numero.substr(l,4);
      l=l+4;
   }
    
   string convertidos[k/4];
    		
   for(int i=0; i<k/4; i++){
   	for(int j=0; j<tam; j++){
      	if(digitos[i]==bin[j]){
         	convertidos[i]=hex[j];
         }
      }
   }
   cout<<"El numero "<<numero<<", corresponde en Hexadecimal a: ";
   for(int i=0;i<k/4;i++){
   	cout<<convertidos[i];
   }
   cout<<endl;
}

void Conversor_Unidades(string sistema1, string numero, string sistema2){
	
	//Conversores de DECIMAL a...
   if(sistema1=="Decimal"){
 	 	
 	 	//Hexadecimal
    	if(sistema2=="Hexadecimal"){
    		Deci_to_Hexa(numero);
    	}

    	//Binario
    	else{
    		Deci_to_Bin(numero);
    	} 
	}
    
   //Conversores de HEXADECIMAL a...
   if(sistema1=="Hexadecimal"){
    
   	//Decimal
   	if(sistema2=="Decimal"){
   		Hexa_to_Deci(numero); 
   	}
    
   	//Binario
   	else{
   		Hexa_to_Bin(numero);       
    	}
	}
    
   //Conversores de  BINARIO a ... 
   if(sistema1=="Binario"){
   
   	//Decimal
    	if(sistema2=="Decimal"){
    		Bin_to_Deci(numero);
    	}
    
    	//Hexadecimal
		else{
    		Bin_to_Hexa(numero);
   	}    
   }
}

int main(){
	string sistema1, sistema2, numero;
	
	cout<<"Bienvenido al conversor de sistemas de unidades"<<endl;
	cout<<"==========================================================="<<endl;
	
   cout<<"Ingrese el sistema inicial: Decimal, Binario, Hexadecimal: "<<endl;
   cin>>sistema1;
   
   cout<<"Ingrese el número: "<<endl;
   cin>>numero;
   
   cout<<endl<< "Al elegir un sistema inicial el sistema final debe ser uno de los dos sistemas sobrantes." <<endl;
   
   cout<<endl<<"Ingrese el sistema final: Decimal, Binario, Hexadecimal: "<<endl;
   cin>>sistema2;
   
   Conversor_Unidades(sistema1, numero, sistema2);
   
	return 0;
}

    
    
    
    
