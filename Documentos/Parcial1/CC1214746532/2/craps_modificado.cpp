/*
Santigo quintero codoba

Parcial 1, punto 2.b
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

unsigned long int SaldoenBanco = 1000000;
unsigned long int apuesta = 0;

unsigned int dado1 = 0; //valor del primer dado
unsigned int dado2 =0; //valor del segundo dado
unsigned int punto =0; //valor usado para la suma de los dos dados
unsigned int juego = 0; //condicion de juego cuando en el primer turno no se gana ni se pierde
string jugar = "s";//condicion de seguir jugando

int main(){
    
    cout<<"Su Saldo es de: "<<SaldoenBanco<<" pesos"<<endl;//mensaje que muestra el sado del jugador
    while (jugar =="s" || jugar =="S")//se juega, se verifica la condicion
    {

        if(SaldoenBanco>=5000000){//en el caso que el jugador tenga 5000000 o mas se toma la siguietne "conversacion"
            cout<<"hagale, no pasa nada, arriesguese!"<<endl;
        }

        cout<<"Ingrese su apuesta"<<endl;
        cin >> apuesta;//se ingresa el valor de la apuesta

        while (apuesta>SaldoenBanco){//ciclo que verifica que no se apueste mas de lo que se tiene
            cout<<"Su apuesta es mayor a lo que puede apostar"<<endl;
            cout<<"Ingrese su apuesta"<<endl;
            cin >> apuesta;

        }
        
        if(apuesta == SaldoenBanco){//interaccion con usuario
            cout<<"Parace que tenemos un jugar valiente en la mesa"<<endl;
        }
        
        cout<<"Tire los dados"<<endl;
        srand(time(NULL)); //semilla para el numero aleatorio
        dado1 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6
        dado2 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6


        punto = dado1 +  dado2;

        cout<<"Sacaste: "<<punto<<endl;
        cout<<"\n";

        if(punto == 7 || punto == 11){//Mensaje de victoria
            cout<<"Ganaste"<<endl;
            
            if(apuesta>=2000000){//interaccion con usuario
                cout<<"La sacaste del estadio. Ahora es tiempo de cambiar sus fichas por la plata!"<<endl;
            }

            SaldoenBanco+=apuesta;//se añade la cantidad ganada al saldo
            cout<<"Su Saldo es de: "<<SaldoenBanco<<" pesos"<<endl;
            cout<<"¿Quiere volver a jugar?, presione s para confirmar"<<endl;
            cin>> jugar;
            cout<<"------"<<endl;
        }

        else if (punto == 2 || punto == 3 || punto ==12){//Mensaje de derrota
            cout<<"Craps, perdiste"<<endl;
            SaldoenBanco-=apuesta;//se resta la cantidad perdida al saldo
            cout<<"Su Saldo es de: "<<SaldoenBanco<<" pesos"<<endl;
                    
            if(SaldoenBanco<=10000){//interaccion con usuario
                cout<<"Usted se esta quebrando, no le parece?"<<endl;
            }

            if (SaldoenBanco == 0){//interaccion con usuario
                cout<<"Lo siento. Se quedo sin fondos!"<<endl;
                jugar="salir";
            }
            else{
                cout<<"¿Quiere volver a jugar?, presione s para confirmar"<<endl;
                cin>> jugar;
                cout<<"------"<<endl;
            }
        }
    
        else{//El juego debe seguir
            while(juego != punto && juego != 7){//Mientras se tenga un valor diferente al punto o 7 se debe repetir 
                cout<<"tire de nuevo los dados"<<endl;

                dado1 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6
                dado2 = 1+rand()%(7-1); //numero aleatorio entre 1 y 6

                juego = dado1 + dado2;

                cout<<"Sacaste: "<<juego<<endl;

                if(juego==7){//Se saca 7  y se piurde
                    cout<<"Craps, perdiste"<<endl;
                    SaldoenBanco-=apuesta;//se resta la cantidad perdida al saldo
                    cout<<"Su Saldo es de: "<<SaldoenBanco<<" pesos"<<endl;

                    if(SaldoenBanco<=10000){//interaccion con usuario
                        cout<<"Usted se esta quebrando, no le parece?"<<endl;
                    }
                    
                    if (SaldoenBanco == 0){//interaccion con usuario
                        
                        cout<<"Lo siento. Se quedo sin fondos!"<<endl;
                        jugar="salir";
                    }
                    
                    else{
                        cout<<"¿Quiere volver a jugar?, presione s para confirmar"<<endl;
                        cin>> jugar;
                        cout<<"------"<<endl;
                    }
                }  

                else if(juego==punto){//Se obtiene el punto y se gana
                    cout<<"Ganaste"<<endl;

                    if(apuesta>=2000000){//interaccion con usuario
                        cout<<"La sacaste del estadio. Ahora es tiempo de cambiar sus fichas por la plata!"<<endl;
                    }

                    SaldoenBanco+=apuesta;//se añade la cantidad ganada al saldo
                    cout<<"Su Saldo es de: "<<SaldoenBanco<<" pesos"<<endl;
                    cout<<"¿Quiere volver a jugar?, presione s para confirmar"<<endl;
                    cin>> jugar;
                    cout<<"------"<<endl;
                }
            }
            juego=0;
        }
                
    }
}