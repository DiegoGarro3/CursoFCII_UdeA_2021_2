#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <fstream>
#include <iomanip>


using namespace std;

//empezamos con la parte A del segundo punto



string Conversor(string num, string sistema1, string sistema2){
	
	if(sistema1 == "decimal"){
	
		if (sistema2 == "Hex"){
		string resul;
		    //Hexagecimal
		    int n=stoi(num);
		    int m = 16;
		    int p=1;
		    // convertir de decimal a hex
		    
		    string hex[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
		    string dec[16]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};
		    int i=0;
		    int r[i];
		    while(p!=0){
			p = n/m; // parte entera
			r[i] = n%m; // residuo
			n = p;
			i++;
		    }
		    for(int j=0;j<i;j++){
			 resul += hex[r[i-(j+1)]];
		    }
		    
		    return resul;

		}
		
		if(sistema2 == "binario"){
			string rel="";
			int n=stoi(num); // pasamos de string a entero
			    int m=2;
			    int p=1;
			    int i=0;
			    int k[i]; // donde iremos guardando los string
			    
			    while(p!=0){ 
				p = n/m; // parte entera
				k[i] = n%m; // residuo
				n = p; //renombramos y sumamos 1 al contador
				i++;
			    }
			    for(int j=0;j<i;j++){
				rel += to_string(k[i-(j+1)]); // invertimos los residuos y los guardamos 
			    }
		    return rel;
		}

	}// if 
	
	
	//HEXADECIMAL  A DECIMAL O BINARIO

	if(sistema1 == "Hex"){
		if(sistema2 == "decimal"){
			string resul;
			string hex="0123456789ABCDEF";
		    int p,m,l,n;
		    n = 0;
		    p = hex.length();
		    l = num.length();	
		    int iguales[l]={};
		    m = 16;
		    for(int i=0;i<p;i++){
			for(int j=0;j<l;j++){
			    if(hex[i] == num[j] ){
				iguales[j] = i; // guardamos los datos donde están, posiciones
			     
			}
		    }
		    }		      
			for(int r=l-1;r>-1;r--){
			    n += iguales[l-(r+1)]*pow(m, r);//ecuación que nos da el número en deci  
		    }
		    resul = to_string(n); //convertimos de entero a string
		    return resul;
		}
		
		if(sistema2 == "binario"){
		    string hex="0123456789ABCDEF";
		    string bin="0000000100100011010001010110011110001001101010111100110111101111";
		    
		    int tamhex = hex.length(); // tamaño del string
		    int k = num.length(); // tamaño del string ingresado por el usuario
		    string iguales; // string que iremos llenando
		    
			for(int j=0;j<k;j++){ //for anidado para ir comparando los distintos string
			    for(int i=0;i<tamhex;i++){
				if(hex[i] == num[j] ){
					for(int l=4*i; l<4*(i+1);l++){
				    		iguales += bin[l]; // guardamos los datos donde esàn, las posiciones
				    		}
			     
							}
						    }
							}
							return iguales;
						}

} // FIN HEXADECIMAL


	//BINARIO A DECIMAL O HEXADECIMAL
	
	if(sistema1 == "binario"){
	
		if(sistema2 == "Hex"){ // para este se hizo de binario a deci y de deci a hexa, una especie de puente y algo pobre tambièn
					// pero funciona a las mil maravillas
		
			int m;
			    int k = num.length();		 			    
			    int resul;
			    m = 2;
			    string numeross[k];
			    for(int i=0;i<k;i++){
			    	numeross[i]=num[i];
			    }
			    
			    int numero = 0;
			    
			    for(int r=k-1;r>-1;r--){
				numero += stoi(numeross[r])*pow(m,k-(r+1));// aplicamos la ecuaciòn para traer a decimal
			    }
			    
			    resul = numero; //decimal, ahora lo llevamos a hexa
			    
		string resultado;
		int resultdeci = resul;
		    //Hexagecimal
		    int mh = 16;
		    int p=1;
		    // convertir de decimal a hex
		    
		    string hex[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
		    string dec[16]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};
		    int d=0;
		    int resto[d];
		    while(p!=0){
			p = resultdeci/mh; // parte entera
			resto[d] = resultdeci%mh; // residuo
			resultdeci = p;
			d++;
		    }
		    for(int j=0;j<d;j++){
			 resultado += hex[resto[d-(j+1)]];// invertimos el string (dado que el binario es el inverso del residuo)
		    }
		    
		    return resultado;
			    
			    
		
		
		
		}
		
	

		if(sistema2 == "decimal"){
			    int m;
			    int k = num.length();		 			    
			    string resul;
			    m = 2;
			    string numeross[k];
			    for(int i=0;i<k;i++){
			    	numeross[i]=num[i];
			    }
			    
			    int numero = 0;
			    
			    for(int r=k-1;r>-1;r--){
				numero += stoi(numeross[r])*pow(m,k-(r+1)); //aplicamos el algoritmo de la pàgina
			    }
			    
			    resul = to_string(numero);// convertimos a string
			    return resul;
		
		}

	}//FIN BINARIO


	
} 

//pasamos ahora al MAIN

int main(){	
	//creamos string donde guardaremos los datos respectivos
  string num;  // numero de entrada
  string sistema1; // sistema inicial
  string sistema2; //sistema al que queremos convertir
  string sistema3; //sistema convertido
	ifstream archivoEntrada( "archivo.dat" ); // cargamos el archivo
	ofstream archivoSalida( "arhchivoConvertido.dat", ios::out ); // creamos el archivo de salida

	if ( archivoEntrada.fail() )   //si no carga bien el archivo, imprimimos que hay un error al cargarlo
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

	if ( archivoSalida.fail() )   // misma cosa    
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

	/*

        archivoEntrada>>num>>sistema1>>sistema2;

	archivoSalida<<left <<setw(12)<< "Numero" <<setw(12)<<"Sistema1" << setw(12) << "Sistema2"<< setw(12)<<"Numero_convertido"<< endl;
	
	*/

    while(archivoEntrada>>num>>sistema1>>sistema2){ // traemos lo datos del archivo de entrada

	  sistema3 = Conversor(num,sistema1,sistema2);// guardamos los datos que devuelve la función

	  archivoSalida<<left <<setw(12)<< num <<setw(12)<<sistema1 << setw(12) << sistema2<< setw(12)<<sistema3<< endl; //en el archivo nuevo guardamos
	  // los datos que ya se tienen más la columna nueva que es la conversión
	    
	    }

// cout<<Conversor("25","decimal","Hex")<<endl; // con esta linea podemos pasar a cualquier sistema con introducir el numero, sistema inicial 
// y el sistema al que queremos llevar el número

      
	return 0;
}



























