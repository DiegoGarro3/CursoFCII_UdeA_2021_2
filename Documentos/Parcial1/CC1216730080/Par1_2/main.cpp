#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time
#include <string>
#include <iomanip>
#include <unistd.h> 

using namespace std;

int tirarDados(); // tira los dados, calcula y muestra la suma
int Craps(); 
int talk(int);

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

int Craps(){
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
  
  // muestra mensaje de que ganó o perdió
  if ( estadoJuego == GANO )
    cout << "El jugador gana" << endl;
  else
    cout << "El jugador pierde" << endl;
  return estadoJuego; // 1 si GANA, 2 si PIERDE.
}

int talk(int _saldo){
     if (_saldo>2000000){
      cout<<"Hasta las estrellas!"<<endl;
  }
  if (_saldo<2000000 && _saldo>1000000){
      cout<<"Su noche apenas empieza."<<endl;
  }
  if (_saldo==1000000){
      cout<<"Justo donde empezamos..."<<endl;
  }
  if (_saldo<1000000  && _saldo>=750000){
      cout<<"Una pérdida pequeña. Nada que temer."<<endl;
  }
  if (_saldo<750000  && _saldo>=500000){
      cout<<"No pasa nada por arriesgarse."<<endl;
  }
  if (_saldo<500000  && _saldo>=250000){
      cout<<"Se está quebrando, ¿no le parece?"<<endl;
  }
  if (_saldo<250000  && _saldo>=100000){
      cout<<"Un poco de confianza puede ser mejor que la suerte."<<endl;
  }
  if (_saldo<100000){
      cout<<"Todos tienen malas noches."<<endl;
  }
  return 0;
}

int main()
{
    int SaldoenBanco=1000000;
    bool withdraw=false;
    while(withdraw==false && SaldoenBanco>0){
    int bet=0;
    cout<<"Vamos por una nueva ronda!\nIntroduzca un valor de apuesta ";
    cin>>bet;
    while (bet>SaldoenBanco && bet>0){
        cout<<"Apuesta no válida, por favor ingrese otro valor ";
        cin>>bet;
    }
    cout<<"Apuesta de"<<setw(8)<<bet<<" aceptada."<<endl;
    for(int i=3;i>0;i--){
        cout<<"Los dados se lanzarán en "<<i<<"..."<<endl;
        sleep(1);
    }
        int b=Craps();
        if (b==1){
            SaldoenBanco+=bet;
            cout<<"Su saldo es "<<SaldoenBanco<<endl;
        }
        else{
            SaldoenBanco-=bet;
            cout<<"Su saldo es "<<SaldoenBanco<<endl;
        }
        talk(SaldoenBanco);
        char play=' ';
        cout<< "Desea retirarse [w] o continuar [c]? ";
        cin>>play;
        if (play=='c'){
            if(SaldoenBanco==0){
                cout<<"Lo siento, se quedó sin fondos!"<<endl;
            }
            else{
                withdraw=false;
            }
        }
        else{
            withdraw=true;
            cout<<"El jugador se retira con"<<setw(8)<<SaldoenBanco<<". Disfrute su dinero!"<<endl;
        }
    }
    //cout<<Craps();
} // fin de main


