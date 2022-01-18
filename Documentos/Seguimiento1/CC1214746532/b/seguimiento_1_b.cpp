/*
Codigo seguimiento 1b, implementacion de la clase creada en seguimiento_1_b.h
Santiago Quintero Cordoba 
*/

#include "seguimiento_1_b.h"//se importa la clase


exponencial::exponencial(){//Constructor de la clase
    cout<<"Ingrese la presicion con que desea calcular la exponencial de un numero dado"<<endl;
    cout<<"NOTA: Una presicion mayor a 12 puede generar errores de calculo"<<endl;    
    cin>>N;
    cout<<"Ingrese el numero real al cual le quiera aproximar la exponencial"<<endl;
    cin>>x;
/*Se ingresan por teclado los valores x y N que en la clase se definieron,
como se calculara e^x, x correponde al exponente de ee y N es la presicion
con la cual se calculara la exponencial*/
}

unsigned int exponencial::factorial(unsigned int n){ //creacion de la funcion factorial la cual va a devolver 
                                                     //el factorial de un numero entero positivo dado
int producto = 1;
    if(n == 0){
        return producto; //se entrega 0!=1
    }
    
    else{
        for(int i=1;i <= n;i++){//el ciclo hace n!=1*2*...*(n-1)*n de a un elemento a la vez
            producto*=i;
        }
        return producto;
    }
}
/*NOTA:por la forma en que se creo la funcion, a lo sumo se puede calcular el factorial de numeros menores o iguales a 12,
en terminos practicos para lo que se busca hacer es lo suficientemente bueno y por ende no se necesito poner una mayor presicion
*/

double exponencial::e(){//La funcion e de la clase exponencial se encarga de calcular por medio de
                        //una expansion polinomial de grado N  

    double total = 1;//cuando N=0 se aproxima e^x a 1

    //e^x = 1 + (x/1!) + (x^2/2!) + (x^3/3!) + ...

    for (int i=1;i<=N;i++){//Se usa el for para sumar los terminos de orden i a la suma

        total+= pow(x,i)/exponencial::factorial(i);
    }

    return total;//Se retorna el valor final de la suma(la proximacion de e^x)
}

void exponencial::mostrar(){//La funcion se encarga de mostrar en pantalla el valor de e^x

    cout << fixed << exponencial::e()<<endl;//El uso de fixed es para mostar 6 cifras decimales para así poder comparar 
    //entre diferentes presiciones
    
}