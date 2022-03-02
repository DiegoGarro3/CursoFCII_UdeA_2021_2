#include<iostream>
using namespace std; //si uso esta linea ya no tengo que escribir std::cout o 
                        //o std::cin ...se ahorra esa parte y solo se pone cout o cin

int main(){
    float capracticas,caparticipa,caexamen,notafinal;
    cout<<"Ingrese la calificacion de las practicas(40%) \n\n"; cin>>capracticas;
    cout<<"Ingrese la calificacion de participacion(20%) \n\n";cin>>caparticipa;
    cout<<"Ingrese la calificacion de examen(40%) \n\n";cin>>caexamen;

    capracticas*=0.4;
    caparticipa*=0.2;
    caexamen*=0.4;
    notafinal = capracticas+caparticipa+caexamen;

    cout<<"su nota final es= "<<notafinal<<"\n\n\n\n\n";

    system("pause");
    return 0;

}