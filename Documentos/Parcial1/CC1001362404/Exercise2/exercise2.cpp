#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include <string>

using namespace std;

///////////////////////////

int tirarDados();
int jugarcraps(float &, float);

///////////////////////////

int main(){

  float SaldoenBanco = 1'000'000;
  float apuesta;
  bool decision = true;
  string continuar;
  int partidas = 0, ganadas = 0, perdidas = 0;
  
  
  cout << "\nBienvenido a Craps. \nSu saldo en el Banco inicializa en $1'000'0000."<<endl;
  
  while (decision && SaldoenBanco > 0){
  
  cout << "\nIngrese la cantidad de dinero que desea apostar en esta ronda: "<<endl; 
   
  cin >> apuesta;
  
  while (apuesta > SaldoenBanco || apuesta <= 0){
  
	  while(apuesta > SaldoenBanco){
	    cout << "La cantidad apostada excede su saldo, no tienes tanto dinero como quisieras. Ingresa de nuevo la cantidad a apostar: "<<endl;
	    cin >> apuesta;    
	  }
	    
	  while(apuesta <= 0){
	    cout << "No válido. Debe ingresar una cantidad mayor"<<endl; 
	    cin >> apuesta;
	  }
  }   

  cout << "\nApostó: $" << fixed << setprecision(2) << apuesta << endl; 
  cout << endl;
  
  int estadoJuego =  jugarcraps(SaldoenBanco, apuesta);
  
  //Historial de la partida
  partidas++;
  switch (estadoJuego){
    case 1:
      ganadas++;
      if( apuesta>=200'000 && apuesta<500'000 ){
        cout << "Bien jugado."<<endl;
      }
      else if( apuesta>=500'000 && apuesta<1'000'000 ){
        cout << "Asombrosa y arriegada jugada."<<endl;
      }
      else if( apuesta >= 1'000'000 ){
        cout << "Magnífica jugada. Eso es vivir al límite."<<endl;
      }
        
      break;
    default:
      perdidas++;
      if( apuesta>=200'000 && apuesta<500'000 ){
        cout << "Mal jugado."<<endl;
      }
      else if( apuesta>=500'000 && apuesta<1'000'000 ){
        cout << "Fue una jugada arriegada."<<endl;
      }
      else if( apuesta >= 1'000'000 ){
        cout << "Esta despilfarrando el dinero."<<endl;
      }
      break;
  }  
  
  cout<<"\nLuego de la ronda " << partidas;
  //cout<<"Su estado de juego "<< estadoJuego <<endl;
  //cout<<"Su nuevo saldo de juego es: $"<< to_string(SaldoenBanco) <<endl;
  cout<<" su nuevo saldo de juego es: $"<< fixed << setprecision(2) << (SaldoenBanco) <<endl;
  cout<<"Partidas ganadas: "<<ganadas<<"\nPartidads perdidas: "<<perdidas<<endl;
  
  int diff = (ganadas-perdidas);
  
  if( diff>0 && estadoJuego == 1){
    if (diff == 2){
    cout << "\nHoy es su día de suerte" << endl;
    }
    else if(diff == 3){
    cout << "\nDefinitivamente tiene la suerte de su lado." << endl;
    }
    else if(diff == 5){
    cout << "\n¿Acaso está usted bendecido? Lleva un buen número de partidas a favor. " << endl;
    }
  }
  else{
    if (diff == -2){
    cout << "\nHoy no  parece ser su día de suerte." << endl;
    }
    else if(diff == -3){
    cout << "\nHa dejado su amuleto de la suerte en casa." << endl;
    }
    else if(diff == -4){
    cout << "\nParece que Craps y su suerte no son los mejores amigos. Lleva unas cuantas partidas en contra." << endl;
    } 
  }
  
  if(SaldoenBanco <= 100'000)
    cout << "\nTienes pocos fondos ";
  
  cout << "¿Desea seguir apostando? [s/n] ";
  cin >> continuar;
  if(continuar.compare("n")==0){
    decision=false;
    cout << "Gracias por jugar Craps."<<endl;
    }
  else if(SaldoenBanco<=0){
    cout << "Lo sentimos, se ha quedado sin fondos para más apuestas.\nGracias por jugar Craps"<<endl;
  }
  
  }  
  return 0; // indica que terminó correctamente
}



/////////////////////////////////////////////////////////////////////////////////

int jugarcraps(float &saldo, float apostado)
{
  
  enum Estado { CONTINUAR, GANO, PERDIO };
  
  unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
  Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO
  
  // randomiza el generador de números aleatorios, usando la hora actual
  srand( time( NULL ) );

  int sumaDeDados = tirarDados(); // primer tiro del dado
  // determina el estado del juego y el punto (si es necesario), con base en el primer tiro
  switch ( sumaDeDados )
    {
    case 7: 
    case 11: 
      estadoJuego = GANO;
      break;
    case 2: 
    case 3: 
    case 12: 
      estadoJuego = PERDIO;
      break;
    default: 
      estadoJuego = CONTINUAR; 
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
      else if( sumaDeDados == 7 ) // pierde al tirar 7 antes del punto
	  estadoJuego = PERDIO;
    } // fin de while
  
  // muestra mensaje de que ganó o perdió
  if ( estadoJuego == GANO ){
    cout << "--------------------- \nEl jugador gana.\n" << endl;
    saldo+= apostado;
    }
  else{
    cout << "--------------------- \nNo tuvo suerte. El jugador pierde.\n" << endl;
    saldo-= apostado;     
    }
  return estadoJuego;
    
} 

int tirarDados()
{
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % (6+1-1); // tiro del primer dado
  int dado2 = 1 + rand() % (6+1-1); // tiro del segundo dado
  
  int suma = dado1 + dado2; // calcula la suma de valores de los dados
  
  // muestra los resultados de este tiro
  cout << "El jugador tiro " << dado1 << " + " << dado2
       << " = " << suma << endl;
  return suma; // devuelve la suma de los dados
} // fin de la función tirarDados


