
#include <iostream>

#include <math.h>

using namespace std;

float calc_prom(int a[]) // definimos la función para calcular el promedio
{
    float sum = 0; // definimos la suma y el promedio
    float prom;
    for(int i=0;i<14; i++){
        
        sum += a[i]; // sumamos los elementos del arreglo
    }
    
     prom = sum*1/14; // calculamos el promedio

    return prom; // retornamos el promedio
}

float varianza(int a[]){ // definimos la función varianza
    
    float prom,varianza; // necesitamos del promedio y definir la varianza
    prom = calc_prom(a); // calculamos de nuevo el promedio con la función
    float var = 0; // inicializamos la suma
    for(int i=0;i<14;i++){ // hacemos el cálculo de la varianza
        
       var += pow(a[i]-prom, 2);
    }
    
    varianza = var*1/14;// valor de la varianza
    
    return  varianza; // retornamos la varianza

}

int main()
{
    int valores_prueba[14]={89,95,72,83,99,54,86,75,92,73,79,75,82,73}; // escribimos el arreglo
    float promedio, varia;
    
    promedio = calc_prom(valores_prueba); //llamamos la función promedio
    varia = varianza(valores_prueba); // llamamos la función varianza
    
    
    cout<<"El promedio de los datos es: "<<promedio<<endl; //devolvemos los valores pedidos
    cout<<"La varianza de los datos es: "<<varia<<endl;
    
    return 0;
}
