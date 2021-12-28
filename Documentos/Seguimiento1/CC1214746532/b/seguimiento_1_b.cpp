/*
Codigo seguimiento 1b, implementacion de la clase creada en seguimiento_1_b.h
Santiago Quintero Cordoba 
*/

#include "seguimiento_1_b.h"


exponencial::exponencial(){
    cout<<"Ingrese la presicion con que desea calcular la exponencial de un numero dado"<<endl;
    cout<<"NOTA: Una presicion mayor a 12 puede generar errores de calculo"<<endl;    
    cin>>N;
    cout<<"Ingrese el numero real al cual le quiera aproximar la exponencial"<<endl;
    cin>>x;

}

unsigned int exponencial::factorial(unsigned int n){ //creacion de la funcion factorial la cual va a devolver 
                                                     //el factorial de un numero entero dado
int producto = 1;
    if(n == 0){
        return producto;
    }
    
    else{
        for(int i=1;i <= n;i++){
            producto*=i;
        }
        return producto;
    }
}
/*NOTA:por la forma en que se creo la funcion, a lo sumo se puede calcular el factorial de numeros menores o iguales a 12,
en terminos practicos para lo que se busca hacer es lo suficientemente bueno y por ende no se necesito poner una mayor presicion
*/

double exponencial::e(){

    double total = 1;

    for (int i=1;i<=N;i++){

        total+= pow(x,i)/exponencial::factorial(i);
    }

    return total;
}

void exponencial::mostrar(){

    cout << fixed << exponencial::e()<<endl;
    
}