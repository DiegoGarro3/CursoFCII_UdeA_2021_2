#include <array>
#include <iostream>

using namespace std;

float calc_prom( const int [] );
float varianza( const int [] );

int main()

{   int size_a = 14; //list size 
    
    //the list 
    int valores_prueba[size_a]={89, 95, 72, 83, 99, 54, 86, 75,92, 73, 79, 75, 82,73};
    
    //print mean
    cout << "El promedio del arreglo es: " << calc_prom(valores_prueba) << endl;
    
    //print variance
    cout << "La varianza del arreglo es: " << varianza(valores_prueba) << endl;
    

}

//function to calculate the mean of the list
float calc_prom( const int arr[] )
{
    float sum = 0;
    for(int i = 0; i < 14;++i){
        sum += arr[i];
    
    }

    float prom = sum/14;

    return prom; //returns the mean

}


//function to calculate the variance of the list
float varianza( const int arr[] )
{
    float sum = 0;
    float xvar = calc_prom(arr); 
    for(int i = 0; i < 14;++i){
        sum += (arr[i]-xvar)*(arr[i]-xvar);
    
    }

    float var = sum/14;

    return var; //returns the variance

}