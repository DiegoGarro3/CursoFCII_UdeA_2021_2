// Aplicación que juegue a adivinar un número de la siguiente manera: la aplicación elije un número del 1 al 1000 y le pide que lo adivine. Si su elección es la correcta, el juego termina. Si no es correcta, la aplicación le indica si su elección es mayor o menor que el número correcto. No hay límite en cuanto al número de elecciones que puede realizar. Su programa deberá iterar hasta que el jugador adivine correctamente. Ademas, una vez el jugador adivine el numero, debera tener la opcion de jugar de nuevo si desea.

#include<iostream> //libreria entrada y salida de datos.
#include<stdlib.h> //libreria numeros pseudo-aleatorios.
#include<time.h> //libreria herramientas de tiempo. 
#include<string> // libreria para uso de strings.

using namespace std; 
 
int main(){ //funcion principal.

	int num_guess,num,i; //declaracion de vairiables a usar.
	string respuesta; //declaracion del string.
	
	//se imrpime en pantalla.
	cout<<"Adinive el numero de 1 a 1000 ingresando su eleccion hasta que acierte."<<endl;
	respuesta="si"; //se inicializa string.
	
	//ciclo while para repetir el juego.
	while(respuesta=="si"){ 
		srand(time(NULL)); //semilla para la generacion de numeros aleatorios diferentes en cada juego.
									//time(NULL) numero de segundos desde 0 horas de 1970 hasta el momento. 
		num_guess=1+rand()%(1001-1); //numero aleatorio entre  y 1000. se inicializa la variable num_guess.
		
		cout<<"ingrese un numero: "; //se imprime y se pide ingresar un numero en pantalla.
		cin>>num; //se inicializa la vairable num.
	
		//sentencias if (si), else if (sino si), else (sino); para determinar si el numero ingresado es mayor, menor o igual al numero a 		//adivinar. Ademas se imprime si el numero es mayor o menor. 
		if (num<num_guess){
			cout<<"el numero es menor que el correcto"<<endl;
		}
		else if (num>num_guess){
			cout<<"el numero es mayor que el correcto"<<endl;
		}
		else{
			num=num_guess;
		}
	
		//este ciclo while es para que el usuario entre un numero que se acerca cada vez mas al numero a adivinar gracias a la informacion 			//obtenida en cada itento. cuando num==num_guess, entonces se termina el ciclo.
		while(num!=num_guess){
						
			cout<<"ingrese un numero: ";
			cin>>num;
	
			if (num<num_guess){
				cout<<"el numero es menor que el correcto"<<endl;
			}
			else if (num>num_guess){
				cout<<"el numero es mayor que el correcto"<<endl;
			}
			else{
				num=num_guess;
			}
			
		}
		//se muestra en pantalla que acerto el numero y se imprime la pregunta si desea volver a jugar.
		cout<<"Adivino!! el numero correcto es "<<num<<endl<<endl;
		cout<<"Desea volver a jugar? (si/no): ";
		cin>>respuesta; //si el string ingresado es si entonces vuelve y entra en el primer ciclo while, sino acaba el programa.
	}
	
	return 0; //se retorna un numero entero para la funcion principal.
}
