//leer datos de un archivo
#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;


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

int main(){
    
    ifstream archivoClientesEntrada( "conversion.txt" );
    ofstream archivosalida("conversionout.txt" );

    if ( archivoClientesEntrada.fail() )   
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    	if ( archivosalida.fail() )   // misma cosa    
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    string numero;
    string sistema1;
    string sistema2;
    

    while ( archivoClientesEntrada >> numero >> sistema1 >> sistema2 ){
        
        if (sistema1 == "decimal"){
            if(sistema2== "hexadecimal"){
                string conversion=decimal_hexa(stoi(numero));
                archivosalida << left << setw(12) << numero << setw(12) << sistema1 << setw(12) << sistema2 <<setw(12) << conversion << endl;


            }
            
            if(sistema2 == "binario"){
                string conversion=decimal_binario(stoi(numero));
                archivosalida << left << setw(12) << numero << setw(12) << sistema1 << setw(12) << sistema2 <<setw(12) << conversion << endl;
                

            }
            
           


        }
         

        if (sistema1 =="binario"){

            if(sistema2 == "hexadecimal"){
                string conversion=decimal_hexa(bina_decimal(numero));
                archivosalida << left << setw(12) << numero << setw(12) << sistema1 << setw(12) << sistema2 <<setw(12) << conversion << endl;


            }
            
            if(sistema2== "decimal"){
                string conversion=to_string(bina_decimal(numero));
                archivosalida << left << setw(12) << numero << setw(12) << sistema1 << setw(12) << sistema2 <<setw(12) << conversion << endl;
                

            }
            


        }

        if (sistema1 =="hexadecimal"){

            if(sistema2== "decimal"){
                string conversion=to_string(hexagesimal_decimal(numero));
                archivosalida << left << setw(12) << numero << setw(12) << sistema1 << setw(12) << sistema2 <<setw(12) << conversion << endl;


            }
            
            if(sistema2 == "binario"){
                string conversion=to_string(bina_decimal(to_string(hexagesimal_decimal(numero))));
                archivosalida << left << setw(12) << numero << setw(12) << sistema1 << setw(12) << sistema2 << right << setw(12) << conversion << endl;
                

            }
            


        }
    

    }

    return 0;

}   



