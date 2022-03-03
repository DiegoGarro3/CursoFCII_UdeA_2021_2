#include <iostream>
#include <stdlib.h> //salir del programa
#include <fstream>  //manejo de archivos
#include <string> //manejo de strings
#include <iomanip> //manejo de salidas en pantalla
#include <cstdlib>

using namespace std;

//uso la funcion creada en Tarea2b_conversor.cpp que me convierte el numero de un sistema a otro
string Conversor_Unidades( string, string, string );

int main()
{
	ifstream archivo( "Archivo.txt", ios::in); //leemos archivo
  
  	if ( archivo.fail() ){
   	cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
   }
	
  	ofstream new_archivo;
  
  	new_archivo.open("New_Archivo.txt",ios::out); //abrimos archivo
  
  	if(new_archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}
	
	//declaracion de variables  
  	string sistema1;
  	string numero;
  	string sistema2;
  	string num_convertido;
  
  	int i=1;
  	
  	//leo el numero y los sistemas de la primera linea
  	archivo >> numero >> sistema1 >> sistema2;
	
	while(archivo.good()) // comprueba el siguiente carácter
   {
		if(i==1){
			//escribo encabezados en el nuevo archivo
    		new_archivo << left << setw( 12 ) << numero << setw( 12 ) << sistema1
			<< setw( 12 ) << right << sistema2 << setw(16) << "num convertido" << endl;
    			
    		archivo >> numero >> sistema1 >> sistema2;
    		i++;
    	}
    	else{
    		
    		//almaceno en num_convertido la conversion del numero al sistema2			
    		num_convertido = Conversor_Unidades(numero,sistema1,sistema2);
    		
    		//escribo en el nuevo archivo el numero, los sistemas y el numero convertido
    		new_archivo << left << setw( 12 ) << numero << setw( 12 ) << sistema1
			<< setw( 12 ) << right << sistema2 << setw(16) << num_convertido << endl;
    		
    		//leo el numero y los sistemas de la siguiente linea
    		archivo >> numero >> sistema1 >> sistema2;
    		
    		i++;
    		}
	}	
	return 0; 
}







