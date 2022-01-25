#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;


class Craps
{

 public:
  Craps(); //constructor de la clase 
  void Apuesta(); //Saldo de la apuesta
  int LanzarDados(); //Lanza dados, retorna suma de dados
  void Resultado( bool ); //suma o resta los valores de las apuestas a la variable SaldoenBanco
  void Juego(); //Función de juego


 private:
  int SaldoenBanco = 1000000; //saldo inicial 
  int ValorApuesta = 0; 
};
Craps::Craps() //inicializa el constructor
{
  srand(time(0)); //controla el flujo
}
void Craps::Apuesta()
{
  bool condicion = false; 

  while (condicion == false){

   cout << "El saldo en banco es:: " << SaldoenBanco << endl;
    cout << " " << endl;
    
    cout << "Introduzca el valor de la apuesta: " << endl;
    cin >> ValorApuesta; //Guarda el valor de la apuesta
    cin.clear(); 

    if (ValorApuesta > SaldoenBanco) 
      {
      cout << "Saldo insuficiente. Introduza un valor menor." << endl;
    }
    
    else if (ValorApuesta <= 0) 
      cout << "No tiene dinero para realizar apuestas." << endl;

    else if (ValorApuesta == SaldoenBanco) 
      {
      cout << "¡Aviso!: Estás apostando todo el dinero disponible" << endl;
      condicion = true;
    }
  }
  cin.clear(); 
}
int Craps::LanzarDados()
{                                                               
                                                                                
  int dado1 = 0;                                                               
  int dado2 = 0; 
  int Lanzar = 0; //guarda el valor de la suma de los dados 
  char texto[12]; //guarda letra ingresada por el usuario para tirar los dados 
  
  cout << " " <<endl;
  cout << "Escribe LANZAR para tirar los dados" << endl;
  cin >> texto; //recibe el texto para empezar el juego
  cin.ignore();

  dado1 = 1 + rand()%6; //generar aleatorio (dado)                                 
  dado2 = 1 + rand()%6; //generar aleatorio (dado)
                                                                                
  Lanzar = dado1 + dado2; //suma dados mientras condicion sea falsa se repite el ciclo 
  
  cout<<"El resultado de tu lanzamiento fue:" << dado1 << " + " << dado2 << " = " << Lanzar << endl;
                                                                                
  return Lanzar;                                                         
}
void Craps::Resultado(bool apuesta) //recibe booleano desde Jugar() 
{

  if (apuesta==true) 
    {
      SaldoenBanco = SaldoenBanco + ValorApuesta; //Suma el Valor de la apuesta en SaldoenBanco
  }
  else{
    SaldoenBanco = SaldoenBanco - ValorApuesta; //Resta el valor de la apuesta en  SaldoenBanco
  }

}
void Craps::Juego() 
{

  Apuesta(); //llama la funcion Apuesta()

  bool con = true; //condicon
  int punto= 0; //punto para el jugador
  
while(con==true)
  {   
      int tirardados = 0; // inicializa variable tirada
      tirardados = LanzarDados(); //llama a la funcion Lanzar Dados, aqui empieza el juego en la primera tirada
      
      cout << "El resultado fue: " << tirardados  << endl;

      
      if (punto == 0)
	{

	  if (tirardados == 7 or tirardados == 11) // El jugador gana 
	  {
	  cout << "¡GANASTE LA APUESTA!" << endl;
	  Resultado(true); //envia booleano 
	  con = false; 
	}
	
	  else if (tirardados == 2 or tirardados == 3 or tirardados == 12) // El jugador pierde
	  {
	  cout << "CRAPS. La casa gana la apuesta :" << endl;
	  Resultado(false);
	  con = false;
	}
	  else // si no gana ni pierde en la primera
	  {
	  punto = tirardados; // Punto para el jugador
	  cout << tirardados << "Tiene un punto, si sacas este valor nuevamente ganas, si sacas 7 pierdes" << endl;
	  cout << " " << endl;
      }
    }
      else
	{
	  if (tirardados == punto) // El jugador gana
	  {
	  cout << "Tienes otro punto, ¡GANASTE!" << endl;
	  cout << " " << endl;
	  Resultado(true); 
	  con = false;
	}
	  else if (tirardados== 7) //El jugador pierde
	  {
	  cout << "El resultado fue 7. ¡PERDISTE!. :" << endl;
	  Resultado(false);
	  con = false;
	}
      }
  }
}

int main() //funcion principal
{
  int opcion=1;
  Craps JuegoCraps; //crea objeto de la clase Craps
  
  while(opcion==1){

    JuegoCraps.Juego(); Llama la función Juego 
    cout << "desea seguir jugando?: ";
    cin >> opcion;

  }
  return 0;
}
