//JUEGO CRAPS CON APUESTAS.

#include<iostream>
#include<string>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time

using namespace std;

// tira los dados, calcula la suma y muestra los resultados
int tirarDados()
{
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % 6; // tiro del primer dado
  int dado2 = 1 + rand() % 6; // tiro del segundo dado
  
  int suma = dado1 + dado2; // calcula la suma de valores de los dados
  
  // muestra los resultados de este tiro
  cout << "El jugador tiro " << dado1 << " + " << dado2
       << " = " << suma << endl;
  return suma; // devuelve la suma de los dados
} // fin de la función tirarDados

string Craps()
{
  // enumeración con constantes que representa el estado del juego
  enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  //enum class Estado {CONTINUAR, GANO, PERDIO}; // note el "class"
  
  unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
  Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO
  
  // randomiza el generador de números aleatorios, usando la hora actual
  srand( time( 0 ) );

  int sumaDeDados = tirarDados(); // primer tiro del dado
  // determina el estado del juego y el punto (si es necesario), con base en el primer tiro
  switch ( sumaDeDados )
    {
    case 7: // gana con 7 en el primer tiro
    case 11: // gana con 11 en el primer tiro
      estadoJuego = GANO;
      break;
    case 2: // pierde con 2 en el primer tiro
    case 3: // pierde con 3 en el primer tiro
    case 12: // pierde con 12 en el primer tiro
      estadoJuego = PERDIO;
      break;
    default: // no ganó ni perdió, por lo que recuerda el punto
      estadoJuego = CONTINUAR; // el juego no ha terminado
      miPunto = sumaDeDados; // recuerda el punto
      cout << "El punto es " << miPunto << endl;
      break; // opcional al final del switch
    } // fin de switch

  // mientras el juego no esté completo
  while ( estadoJuego == CONTINUAR ) // no ganó ni perdió
    {
      sumaDeDados = tirarDados(); // tira los dados de nuevo
      
      // determina el estado del juego
      if ( sumaDeDados == miPunto ) // gana al hacer un punto
			estadoJuego = GANO;
      else if ( sumaDeDados == 7 ) // pierde al tirar 7 antes del punto
	  		estadoJuego = PERDIO;
    } // fin de while
  string resultado;
  // muestra mensaje de que ganó o perdió
  if ( estadoJuego == GANO ){
    cout << "El jugador gana" << endl;
    resultado="gana";
    return resultado; 
  }
  else{
    cout << "El jugador pierde" << endl;
    resultado="pierde";
    return resultado;
  }
}

//Funcion principal.
int main(){ 
	
	//se declaran las variables a usar.
	string resultado, jugar; //variables tipo strings que devuelve funcion Craps  para ver si se vuelve a jugar. 
	int SaldoenBanco=1000000,SaldBank=1000000; //se inicializan variables de saldo en banco.
	int apuesta;
	
	//se imprime un mensaje al inicio del juego y su saldo en banco.
	cout<<"Bienvenido al juego de apuestas Craps"<<endl;
	cout<<"\n";
	cout<<"Su Saldo en Banco es: "<<SaldoenBanco<<endl;
	
	//se inicializa jugar en si para jugar almenos la primera vez.
	jugar="si";
	
	while(jugar=="si"){ //ciclo while para que el usuario decida si vuelve a jugar o no.
		
		cout<<"Ingrese una apuesta: ";
		cin>> apuesta; //se pide un ingresar una apuesta
		
		while(apuesta>SaldoenBanco){ //se comprueba que la apuesta no sea mayor al saldo en banco  se pide ingresarla hasta que sea valida.
			cout<<"Ingrese una apuesta menor o igual al SaldoenBanco: ";
			cin>>apuesta;
		}
		
		resultado=Craps(); //se juega una ronda de craps  se establece si pierde o gana.
		
		//si gana se le suma su apuesta a su saldo en banco.
		if (resultado=="gana"){
			SaldoenBanco += apuesta;
		}
		
		//si pierde se le resta su apuesta a su saldo en banco.
		else{
			SaldoenBanco -= apuesta;
		}
		
		//se comprueba si luego de la apuesta el saldo en banco quedo nulo, y si es asi se muestra un mensaje.
		if (SaldoenBanco==0){
			cout<<"Lo siento. ¡Se quedó sin fondos!"<<endl;
			break; //al no haber fondos se sale del juego. break se sale del ciclo y acaba el programa.
		}
		
		//si no se muestra en cuanto esta su saldo en banco.
		else{
		cout<<"Su nuevo Saldo en Banco es: "<<SaldoenBanco<<endl;
		}
		
		//cuando su saldo en banco es la tercera parte o menos de su saldo inicial, el juego le muestra un mensaje de advertencia.
		if (SaldoenBanco<=SaldBank/3){
			cout<<"Usted se está quebrando, no le parece?"<<endl;
		}
		
		//cuando su saldo en banco esta entre el saldo inicial mas o menos la quinta parte del saldo inicial, muestra un mensaje de aliento.
		if (SaldBank-SaldBank/5<=SaldoenBanco && SaldoenBanco<=SaldBank+SaldBank/5){
			cout<<"Hágale, no pasa nada, ¡Arriésguese!"<<endl;
		}
		
		//cuando su saldo es mayr o igual al doble de su saldo inicial, el juego muestra un mensaje de felicitaciones y recomienda no 	apostar mas. 
		if (SaldoenBanco>=SaldBank*2){
			cout<<"La sacaste del estadio. Tienes el doble o más dinero que con lo que empezaste. Es tiempo de cambiar sus fichas por plata."<<endl;
		}
		
		//finalmente se pregunta si desea volver a apostar o no.
		cout<<"Desea volver a apostar? (si/no) ";
		cin>>jugar;
	}	
	return 0;
}
















