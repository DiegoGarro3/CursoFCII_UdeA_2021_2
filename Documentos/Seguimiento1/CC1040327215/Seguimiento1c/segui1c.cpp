#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){

  int numero,n, adivinar=0, volver; //declaramos nuestras variables

  srand(time(NULL)); // creamos nuestro numero aleatorio
  numero =1+ rand()%1000; // sabemos que dicho numero aleatorio debe de estar entre 1 y 1000
  cout << "Bienvenidos a ADIVINALANDIA, por favor ingrese un numero: \n";// derechos de autor :D

  while(adivinar==0){ // Inicializamos el ciclo, este empezará si adivinar==0, y ya nosotros lo establecimos así al inicio del programa
      cin >> n; //le decimos al usuario que ingrese el numero 

      if(n>numero){ // Empezamos con las pistas de si es mayor o menor el número que ingreso con respecto al que debe adivinar
	cout<< "El numero que ingresaste es MAYOR al numero que debes adivinar, sigue intentando";
	cout<<endl<<endl;

      }
      else if(n<numero){
	cout << "El numero que ingresaste es MENOR al numero que debes adivinar, sigue intentando";
	cout<<endl<<endl;

      }
      else{
	cout << "Enhorabuena, haz adivinado el número "<<n;// si adivina el nùmero le felicitamos
	cout << endl;
	cout << "SI quieres volver a jugar marca 0, de lo contrario marca 1: \n"; // le preguntamos si desea volver a jugar 
	cin >> volver;

       	//En caso tal de que quiera volver a jugar, el programa entrará al else y tomará a adivinar como igual a cero, dicha condición
	// hace que el programa entre de nuevo al while y comencemos de nuevo el juego

	if(volver==0){
	  numero =1+ rand()%1000; // creamos un nùmero aleatorio diferente para que el usuario vuelva a jugar
	  adivinar = 0;

	}
	else{
	  adivinar = 1;

	}

      }


    }



  return 0;

}
