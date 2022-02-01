#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "ClassParteb.h"

//Creamos nuestro constructor

using namespace std;

Craps::Craps() //inicializa el constructor
{
  srand(time(0)); //controla el flujo
}


void Craps::Apuesta()
{
  bool condicion = false; //mientras condicion sea falsa se repite el ciclo para controlar los valores a apostar

  while (condicion == false){

    cout << "Su saldo es: " << SaldoenBanco << endl; //avisa saldo
    cout << " " << endl;
    

    
    cout << "Ingrese el dinero que desea apostar: " << endl;
    cin >> ValorApuesta; //guarda valor a apostar en variable ValorApuesta
    cin.clear(); //borra indicador para nuevas operaciones

    if (ValorApuesta > SaldoenBanco) //Le informamos que va a apostar el dinero que NO tiene
      {
      cout << "Su saldo es insuficiente, ingrese otro valor" << endl;
    }
    
    else if (ValorApuesta < 0) //Le decimos que no ingrese un valor negativo (de forma educada)
      cout << "NO recibimos dinero negativo" << endl;

    else if (ValorApuesta == SaldoenBanco) //Puede darse el caso en que apueste todo de un tiron (sin miedo al éxito)
      {
      cout << "Estás apostando la cantidad total de tu saldo" << endl;
      condicion = true;
    }
    else if (ValorApuesta > 0.5*SaldoenBanco) //Le informamos que está apostando más de la mitad de su dinero
      { 
      cout << "Estás apostando más de la mitad de tu dinero... Sin miedo al éxito?" << endl;
      condicion = true;
    }    
    else if (ValorApuesta < 0.5*SaldoenBanco) //avisa que apuesta menos de la mitad, cambia condicion para salir del ciclo
      {
      cout << "Estás apostando menos de la mitad de su dinero, hombre cobarde no goza mujer buena!" << endl;
      condicion = true;
    }
     else if (ValorApuesta == 0.5*SaldoenBanco) //avisa que apuesta la mitad, cambia condicion para salir del ciclo
       {
       cout << "Va a apostar el 50% de su saldo disponible" << endl;
       condicion = true;
     }
  }
  cin.clear(); //borra indicador para nuevas operaciones
}
int Craps::TirarDados() //inicializamos tirar dados
{                                                               
                                                                                
  int dado1 = 0; //dado 1                                                               
  int dado2 = 0; //dado 1                                                           
  int tiro = 0; //guarda suma
  char ingreso; //guarda letra ingresada por el usuario para poder tirar dados
  
  cout << " " <<endl;
  cout<<"Por favor, para jugar, ingrese cualquier letra seguido de la tecla Enter."<<endl;
  cin>>ingreso; //recibe ingreso
  cin.ignore(); //limppia el bufer de entrada

  dado1 = 1 + rand()%6; //generar aleatorio (dado)                                 
  dado2 = 1 + rand()%6; //generar aleatorio (dado)
                                                                                
  tiro = dado1 + dado2; //suma dados 
  
  cout << "En la tirada, el jugador a sacado " << dado1 << "+" << dado2  << "=" << tiro << endl; //mostramos la suma de los dos dados
                                                                                
  return tiro;                                                         
}
void Craps::Resultado(bool apuesta) //recibe booleano desde Jugar() 
{

  if (apuesta==true) 
    {
      SaldoenBanco = SaldoenBanco + ValorApuesta; //aumenta SaldoenBanco
  }
  else{
    SaldoenBanco = SaldoenBanco - ValorApuesta; //disminuye SaldoenBanco
  }

}
void Craps::Juego() //donde juega
{

  Apuesta(); //llama la funcion Apuesta()

  bool condicion = true; //condicon
  int punto = 0; //punto para el jugador
  
while(condicion==true)
  {   
      int tirada = 0; //inicializa variable tirada
      tirada = TirarDados(); //llama a la funcion tirar los dados, aqui empieza el juego en la primera tirada
      
      cout << "Obtuviste: " << tirada  << endl;

      
      if (punto == 0)
	{

	  if (tirada == 7 or tirada == 11) //condicion para ganar 
	  {
	  cout<<"Gano en la primera tirada, excelente!"<<endl;
	  Resultado(true); //envia booleano a Resultado
	  condicion = false; 
	}
	
	  else if (tirada == 2 or tirada == 3 or tirada == 12) //condicion de perder 
	  {
	  cout<<"Perdio, perder es ganar un poco decia Maturana. :("<<endl;
	  Resultado(false);
	  condicion = false;
	}
	  else //si no gana ni pierde en la primera, entra aqui en esta ruta
	  {
	  punto = tirada; //se pone el punto que si se repite gana
	  cout << "Saco el punto  " << tirada << " Si saca ese mismo numero gana, empiece a tirar" << endl;
	  cout << " " <<endl;
      }
    }
      else
	{
	  if (tirada == punto) //gana
	  {
	  cout<< "Saco el punto, Gano!"<<endl;
	  cout << " " <<endl;
	  Resultado(true);
	  condicion = false;
	}
	  else if (tirada == 7) //pierde
	  {
	  cout<<"Sacaste un 7 y por lo tanto has perdido, lo sentimos, suerte la próxima "<<endl;
	  cout << " " <<endl;
	  Resultado(false);
	  condicion = false;
	}
      }
  }
 Menu();
}
void Craps::Menu()//inicializamos menú
{

  int opcion;

    cout<<"BIENVENIDO A LA PERDICIÓN"<<endl; // no sabe pa dónde va
  cout << " " << endl;
  cout << "Menu:"<<endl;
  cout << " " << endl;
  cout << "Usted tiene esta plata: " << SaldoenBanco << endl;
  cout << "Seleciona una opcion: "<< endl;
  cout << "Presione 1 para jugar ahora." <<  endl;
  cout << "Presione 2 para salir del juego." << endl;
  cout << " " << endl;
  cin>>opcion; //guarda opcion de usuario
  
  if (opcion==1) //juega
    {
      if (SaldoenBanco>0) //revisa que tenga plata
      {
	Juego(); //llama la funcion juego
    }
      else //sale del juego
      {
      string volver;
      cout << "Gracias por dejar parte de ti en este lugar, vuelva pronto" << endl;
      }
  }
  else if (opcion==2) //se despide del usuario
    {
    cout << "Saliendo del juego, su ganacia fue de: " << SaldoenBanco << endl;
  }
  else //se asegura que lo que puso este en el menu
    {
    cout << "Opción no válida" << endl;
    Menu();
  }
 
}
