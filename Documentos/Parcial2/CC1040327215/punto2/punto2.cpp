#include<iostream>
#include<string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

void Muerte(){
	
	
  	srand( time(0) ); // numero aleatorio visto en clase con la hora local 
	string palabras[15]={"vida","fisica","carretera","celular","saturno","cosmologia","profesor","andromeda"
				"jupiter","relatividad","agujero","inflaton","latinoamerica","pandemia","oscura"}; // ponemos unas palabras algo tranqui ;)
	
	string jugar="si"; // condición de juego, en caso de que escriba algo diferente, no entrará al while
	
	while(jugar=="si"){
	
	cout<<"HOLA! Te damos la bienvenida al juego de ahorcado, realizado por un quasi físico "<<endl;
	cout<< "INTRUCCIONES DE USO"<<endl;
	cout<< "1. Ingrese solo letras y no números"<<endl;
	cout<< "2. Las letras a ingresar deben de estar en minúsculas"<<endl;
	cout<< "3. Disfrute y aprenda a perder. Como decía Maturana 'Perder es ganar un poco'"<<endl;
	cout<< "4. Ver ilustración, sí, exacto, así vas a terminar"<<endl;

			cout << " " << endl; 
   		cout <<"   +----+   " << endl; 
   		cout <<"   |    |   " << endl; 
   		cout <<"   |    O   " << endl; 
   		cout <<"   |   /|\\ " << endl; 
   		cout <<"   |   / \\ " << endl; 
   		cout <<"   |        " << endl; 
   		cout <<"  =============" << endl; 
		//generamos el aleatorio para coger una de las 15 palabras de strings 
		int n = rand()%15;
	
		string ocultas = ""; // generamos un string que llenaremos la palabra escogida con x, hora de adivinar 
		
		for(int i=0; i<palabras[n].size(); i++){ // llenamos ese string con x
			ocultas+="x";
		}
		cout<<endl<<ocultas<<endl;
		
		string letra,si_no,respuesta; // string que se iràn llenando en el camino
		
		int k=1; // con esto ya entra a su primer intento
		
		while(ocultas != palabras[n] && k<=7){
		
			cout<<endl<<"Ingrese una letra: ";cin>>letra;
			int conta=0,l=0;
			string palabra;
		
			 // usamos los mètodos vistos en clase para manipulación de string, .compare y el .replace
			for(int i=0; i<palabras[n].size(); i++){
			
				palabra = string(1, palabras[n][i]);
				
				if( palabra.compare(letra)==0 ){ 

					ocultas.replace(i,1,letra); // hacemos el reemplazo
					if(l==0){
						cout<<"¡Haz acertado con esa letra!"<<endl; // notificamos que acertò
						l+=1;
					}
				}
				else{
					conta+=1; 
				}
			}
			
			if(conta==palabras[n].size()){
				cout<<endl<<"La letra ingresada no es válida "<<endl;
				cout<<"Menos uno, campeón, vuelve a intentarlo "<<k<<endl;
				cout<<endl<<ocultas<<endl;
				k+=1;
			}
			else{
				
				cout<<endl<<ocultas<<endl; // reemplazamos en caso tal de que acierte
				
				if(ocultas==palabras[n]){
					continue;
				}
				else{
					//se pregunta si se quiere adivinar la palabra
					cout<<endl<<"Desea adivinar la palabra completa? (si/no) "<<endl;
					cin>>si_no;
					
					//se comprueba si la palabra ingresada coincide
					if(si_no=="si"){
						cout<<"Ingrese la palabra: ";
						cin>>respuesta;
					
						if(respuesta==palabras[n]){
							ocultas=palabras[n];
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
		// en caso de que gane, se lo hacemos saber
		if(ocultas==palabras[n]){
			cout<<"Enhorabuena, has adivinado la palabra: "<<ocultas<<endl;
		}
		//
		else{
			cout<<endl<<"EL juego ha terminado, la palabra que no pudiste adivinar es: "<<palabras[n]<<endl;
		}
		//va a seguir?
		cout<<endl<<"Quiere continuar jugando? (si/no) "<<endl;
		cin>>jugar;	
	}
}

int main(){
	
	Muerte(); // le damos candela al jueguito :D
	
	return 0;
}
