//A usar///////////////////
//Santiago Quintero Corodoba seguimiento 2 

#include <iostream>
#include <string>
#include <fstream> 
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

const char hexa[] = "0123456789ABCDEF";
const char bina[] = "01";
const string binario = "01";
const string hexa_string = "0123456789ABCDEF";
const int hexa_0_a_15[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
const string bina2[16] = {"0000","0001","0010","0011","0100","0101","0110",
"0111","1000", "1001","1010","1011","1100","1101","1110","1111"};
const int binario2[] = {0,1};
const string binario_2 = "0000000100100011010001010110011110001001101010111100110111101111";

string entrada{0};
string salida{0};
string numero{0};
int numero2{0};
int num{0};
char conver[50];
int cociente{0};
int resi{0};
int i=0;
int suma=0;

int main(){

    ifstream archivo( "Convertir.dat"); //archivo de lectura

   
        if ( archivo.fail() )    {
        cout << "No se pudo abrir el archivo" << endl;
        exit( 1 );
        }

  	    ofstream archivo2;
  
      	archivo2.open("Convertir2.dat"); //se abre o crea el archivo a editar
  
  	    if(archivo2.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	    }

          cout<<"En el archivo dependieno de donde se abra pueden aparecer caracteres no deseados"<<endl;
    
        while (archivo.good()){
//se crea la parte superior de la tabla
            if(entrada =="sistema1"){
            
                archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
                <<"numero convertido" << endl;
            }
////////

////se implementan el el codigo las funciones de la parte A
            if (entrada=="decimal" && salida == "hexadecimal"){

                 num=stoi(numero);
                 i=0;

                 cociente = num/16;
                 resi=num%16;

                 num=cociente;

                 conver[0]=hexa[resi];

                 while (cociente!=0){
                    i++;
                    cociente=num/16;
                    resi=num%16;
                    num=cociente;
                    conver[i]=hexa[resi];
                }

                 char conver2[i];
    
                 for (int j = i; j>=0; j--){

                    conver2[i-j]=conver[j];
                    }
                	archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
                    << conver2 << endl;
                }   
   

     
            else if (entrada=="decimal" && salida == "binario") {
            
                num=stoi(numero);
                i=0;

                cociente = num/2;
                resi=num%2;

                num=cociente;

                conver[0]=hexa[resi];
    
                while (cociente!=0){

                    i++;
                    cociente=num/2;
                    resi=num%2;
                    num=cociente;
                 conver[i]=bina[resi];
                }

                char conver2[i];
    
                for (int j = i; j>=0; j--){

                    conver2[i-j]=conver[j];
                }
                
                archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
                << conver2 << endl;
            }

        else if (entrada=="hexadecimal" && salida == "decimal"){

             suma=0;
             for (int j = 0; j < numero.length(); j++){
                 for (int k = 0; k <= 16 ; k++){
                    if (numero[j] == hexa_string[k]){

                    suma+=hexa_0_a_15[k] * pow(16,numero.length()-j-1);
                }   
            }   
        
            archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
            << suma << endl;
        }
        
        }

        else if (entrada=="hexadecimal" && salida == "binario") {

            string con[numero.length()];

                for (int j = 0; j < numero.length(); j++){
                    for (int k = 0; k <= 16 ; k++){
                        if (numero[j] == hexa_string[k]){

                            con[j]=bina2[k];    
                        }   
                    }
                }
            archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
            << *con << endl;
        }

        else if (entrada=="binario" && salida == "decimal"){
                
                suma=0;
                for (int j = 0; j < numero.length(); j++){
                  for (int k = 0; k <= 16 ; k++){
                    if (numero[j] == binario[k]){

                    suma+=binario2[k] * pow(2,numero.length()-j-1);

                    }   
                }
            }
            archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
            << suma << endl;
        }
   
        else{
            
            string con[numero.length()];
        
            for (int j = 0; j < numero.length(); j+=4){
                for (int k = 0; k <= 4*16 ; k+=4){
                    if ((numero[j] == binario_2[k]) && (numero[j+1] == binario_2[k+1]) && (numero[j+2] == binario_2[k+2]) && (numero[j+3] == binario_2[k+3])){

                        con[j/4]=hexa_string[k/4];
                        
                }   
            }
        }
            archivo2 << left << setw(15) << numero << setw(15) << entrada << setw(15) << salida << setw(15) 
            << *con << endl;

        }
    
        archivo >> numero >> entrada >> salida;
    }

    
    
    //se hace cierre del archivo
    archivo.close();
    archivo2.close();
}