/*
Codigo seguimiento 1a
Santiago Quintero Cordoba 
*/

#include <iostream>
using namespace std;
//Declaracion e inicializacion de variables
int contador = 0;//contador que tomara en cuenta cuantos estudiantes pasaron el examen
int aprobacion = 0;//si tuacion del estudiante, 1 si aprobo y 2 si reprobo
///////////////////

int main(){

    cout <<"Ingrese 1 si el estudiante aprobo, de lo contrario ingrese 2"<<endl;
    cout <<"NO INGRESE UNA LETRA BAJO NINGUN CASO"<<endl;

    for(int i=1;i<=10;i++) {//inicia un ciclo for donde se ingresa la situacion de cada estudiante

        cout <<"Ingrese la situacion del estudiante # "<< i<<endl;
        cin >> aprobacion;//se ingresa por teclado la situacion del estudiante
        switch (aprobacion)//se toman los casos (se entra 1 2 o un valor invalido)
        {
        case 1:
            contador++;//si el estudiante i-esimo aprobo el examen entonces se le añade al contador un uno
            break;
        case 2:
            break;
        default://en caso que se ingrese un valor diferente de 1 o 2 se inicia un ciclo hasta que se ingrese un valor valido
            cout <<"Valor no valido, intente de nuevo"<<endl;
            while (aprobacion != 1 && aprobacion != 2){
                cout <<"Ingrese la situacion del estudiante # "<< i<<endl;
                cin >> aprobacion;
            }
            break;
        }//final del switch
    }//final del for
    
    //se imprimen mensajes dependiendo del valor final de contador
    if(contador >= 8){
        cout << "Excelente instructor"<<endl; 
    }
    else{
        cout << "Como instuctor debe mejorar"<<endl;
    }

}