
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int aprobado=0;
    int reprobado=0;
    int outcome;
    for (int i=0;i<10;i++){
        cout << "Ingrese el resultado del estudiante " << i+1 << ": ";
        cin >> outcome;
        if(outcome>2){
            cout << "El resultado ingresado no es válido." << endl;
            break;
        }
        else if(outcome==1){
            aprobado+=1;
        } else {
            reprobado+=1;
        }
    }
    cout << "Aprobados: " << aprobado << endl;
    cout << "Reprobados: " << reprobado << endl;
    if(aprobado>8){
        cout << "Excelente Profesor!";
    }
}

