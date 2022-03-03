#include<iostream>
#include<string>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time

using namespace std;

void Ahorcado(){
	
	// randomiza el generador de números aleatorios, usando la hora actual
  	srand( time(0) );
  	int dim_pal = 10;
	string palabras[dim_pal]={"mundial","misil","bomba","rusia","guerra","tercera","atacar","seguridad","paz","ucrania"};
	
	string jugar="si";
	
	while(jugar=="si"){
	
		cout<<endl<<"=========================================================================="<<endl;
		cout<<"Bienvenidos al juego Ahorcado, tiene 7 intentos incorrectos para adivinar."<<endl;
		cout<<"=========================================================================="<<endl;
		
		//numero aleatorio para elegir una de las 10 palabras para adivinar
		int p = rand()%dim_pal;
	
		//se reemplazan las letras de la palabra a adivinar por x
		string ahorcado = "";
		
		for(int i=0; i<palabras[p].size(); i++){
			ahorcado+="x";
		}
		//imprimimos en pantalla la palabra con "x"s
		cout<<endl<<ahorcado<<endl;
		
		//se declaran strings a usar
		string letra,si_no,respuesta;
		
		int k=1;
		
		//ciclo while que se repite hasta que se adivine la palabra o cumpla 7 intentos incorrectos 
		while(ahorcado != palabras[p] && k<=7){
		
			cout<<endl<<"Ingrese una letra: ";
			cin>>letra;
		
			int cont=0,c=0;
			string pal;
		
			//ciclo for que compara la letra ingresada con las letras de la palabra
			for(int i=0; i<palabras[p].size(); i++){
			
				//se usa el contructor de la clase string para convertir las letras (char) del banco de palabras en letra string
				pal = string(1, palabras[p][i]);
				
				//se usa el metodo A.compare(B) que compara dos string, si son iguales retorna un 0, sino retorna 1 o -1 dependiedo
				//de quien sea mayor, A o B.
				if( pal.compare(letra)==0 ){
				
					//se usa el metodo A.replace(int a,int b,B) reemplaza en el string A en la posicion "a" con una cantidad de "b" espacios
					//el string B
					ahorcado.replace(i,1,letra);
					
					//imprimo si la letra pertenece solo una vez así la palabra tenga mas de 1 vez esa letra
					if(c==0){
						cout<<"La letra pertenece"<<endl;
						c+=1;
					}
				}
				else{
					cont+=1;
				}
			}
			//se cuenta las veces que la letra no coincidio y si luego de comparar la cuenta tiene el mismo valor que el numero 
			//de letras de la palabra, etonces la letra no coincidio
			if(cont==palabras[p].size()){
				cout<<endl<<"La letra no pertenece"<<endl;
				cout<<"Intento incorrecto "<<k<<endl;
				cout<<endl<<ahorcado<<endl;
				k+=1;
			}
			else{
				//se imprime la palabra reemplezando la letra que coincidio
				cout<<endl<<ahorcado<<endl;
				
				//si al ingresar letras se completa la palabra acaba el ciclo  
				if(ahorcado==palabras[p]){
					continue;
				}
				else{
					//se pregunta si se quiere adivinar la palabra
					cout<<endl<<"Desea adivinar la palabra? (si/no) "<<endl;
					cin>>si_no;
					
					//se comprueba si la palabra ingresada coincide
					if(si_no=="si"){
						cout<<"Ingrese la palabra: ";
						cin>>respuesta;
					
						if(respuesta==palabras[p]){
							ahorcado=palabras[p];
						}
						//si no coincide la palabra se cuenta como un intento incorrecto
						else{
							cout<<"Intento incorrecto "<<k<<" No es la palabra correcta"<<endl;
							k+=1;
						}	
					}
				}
			}
		}
		//si al completar el ciclo while la palabra es la indicada, se indica que gano
		if(ahorcado==palabras[p]){
			cout<<endl<<"*******************************************************"<<endl;
			cout<<"Felicidades ha adivinado la palabra!! "<<ahorcado<<endl;
			cout<<"*******************************************************"<<endl;
		}
		//si al completar el ciclo while la palabra no es la indicada, se indica que perdio
		else{
			cout<<endl<<"Usted ha sido ahorcado, la palabra era "<<palabras[p]<<" y usted obtuvo "<<ahorcado<<endl;
		}
		//finalmente se pregunta si desea volver a jugar
		cout<<endl<<"Desea volver a jugar? (si/no) "<<endl;
		cin>>jugar;	
	}
}

int main(){
	
	//se usa la funcion que reproduce el juego ahorcado
	Ahorcado();
	
	return 0;
}













