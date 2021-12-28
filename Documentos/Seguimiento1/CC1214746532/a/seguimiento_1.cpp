/*
Codigo seguimiento 1a
Santiago Quintero Cordoba 
*/

#include <iostream>
using namespace std;

int contador = 0;
int aprobacion = 0;
int i = 0;

int main(){

    cout <<"Ingrese 1 si el estudiante aprobo, de lo contrario ingrese 2"<<endl;
    for(i=1;i<=10;i++) {
        cout <<"Ingrese la situacion del estudiante # "<< i<<endl;
        cin >> aprobacion;
        switch (aprobacion)
        {
        case 1:
            contador++;
            break;
        case 2:
            break;
        default:
            cout <<"Valor no valido, intente de nuevo"<<endl;
            while (aprobacion != 1 && aprobacion != 2){
                cout <<"Ingrese la situacion del estudiante # "<< i<<endl;
                cin >> aprobacion;
            }
            break;
        }
    }
    
    if(contador >= 8){
        cout << "Excelente instructor"<<endl; 
    }
    else{
        cout << "Como instuctor debe mejorar"<<endl;
    }

}