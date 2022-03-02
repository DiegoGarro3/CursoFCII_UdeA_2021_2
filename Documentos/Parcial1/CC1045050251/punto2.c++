
#include <iostream>
#include <ctime>
using namespace std;

/* funcion para encontrar dos numeros aleatorios
y me devuelve la suma*/

int alea(int u){
  srand(u);
  int i, n, aleatorio1,aleatorio2,suma_, DESDE=1, HASTA=6;
  cout << "Numeros aleatorios entre " << DESDE << " y " << HASTA << endl;
  for (i = 1; i <= 2; i ++){
    if (i=1){
      aleatorio1 = rand()%(HASTA-DESDE+1)+DESDE;
      cout << aleatorio1 << " ";
         }
   if (i=2){
     aleatorio2 = rand()%(HASTA-DESDE+1)+DESDE;
     cout << aleatorio2 << "\n ";
         }
  }
  suma_ = aleatorio1+aleatorio2;
  cout <<"la suma de las caras superiores es = \t"<< suma_ << " \n";
  return suma_;
}

float saldo;
float queda;
float SaldoenBanco( saldo=10000, queda){

  while (apuesta <= saldo) {
    saldo = saldo - apuesta;

  }

}

int main()
{
  //int u+=1; //le sumo uno a la semilla que obtendra la siguiente pareja aleatoria
  int u = time(NULL);
  cout<<"tomando como semilla" << u << '\n';
  int suma = alea(u); //primer lanzamiento
  if(suma==7 or suma==11){
    cout <<"--------Felicitaciones sacaste \t"<<suma<<"\t en el primer tiro \t"<< "\n por tanto ganaste----\n";
  }

  if(suma==2 or suma==3 or suma ==12){
    cout <<"--------perdiste \t"<<"\n por tanto gana la casa----\n";
  }

  if(suma==4 or suma==5 or suma ==6 or suma ==8 or suma ==9 or suma ==10){
    cout <<"-------acabas de sacar TU punto \t""\n";
    cout << "\n por tanto puedes tirar de nuevo hasta\n";
    cout << "\n que saques de nuevo TU punto o hasta \n";
    cout << "\n que obtengas un numero 7 en los dados----\n";

    int tupunto = suma; //capturo el valor sacado que es TU punto
    cout<<"\n------NUEVO LANZAMIENTO------\n";

    /*aqui necesito poner un tunel para que el algoritmo regrese aqui
    y verifique si en su tercera tirada saco 7 o su punto o continua tirando*/


    int suma2=alea(rand()); //lanzo de nuevo los dados
    cout<<"tu nuevo lanzamiento da como suma = "<<suma2<<"por tanto: \n"<<endl;
      //verifico cuanto saco en esta segunda vez

    tunelderegreso:

    if (tupunto==suma2){
      cout<<"Felicitaciones acabas de lanzar el mismo valor que TU punto por tanto GANAS";
      return 0;
     }
    if (suma2==7){
      cout<<"Acabas de sacar un 7 por tanto PERDISTE y gana la casa";
      return 0;
     }

    if(suma2!=tupunto && suma2!=7){
      cout <<" \n puedes lanzar de nuevo \n";
      cout << "-----OTRO LANZAMIENTO--------";
      system ("pause"); //espera que el usuario vuelva a lanzar los dados
      int suma2=alea(rand()+time(NULL)+1); //reasigno un valor a suma2 que es el lanzamiento n-esimo
                                //lanzo de nuevo los dados porque no saco ni 7 ni su punto
      cout<<"tu nuevo lanzamiento da como suma = "<<suma2<<"por tanto: \n"<<endl;
      //verifico de nuevo las condiciones
      //haciendo que se devuelva con goto hasta donde escribi tunelderegreso
      goto tunelderegreso;
      return 0;
    }

  }

   system("pause");
}
