#include<iostream>
#include<math.h>

using namespace std;

// funcion que calcula el promedio de un arreglo.
double calc_prom( int b[], int tamanioDeArreglo ){
	double sum=0; //variable donde almaceno la suma de las entradas
	for ( int k = 0; k < tamanioDeArreglo; k++ ){
		sum += b[ k ]; //sumo cada entrada del arreglo
	}
	double promedio = sum/tamanioDeArreglo; //calculo el promedio
	return promedio; //retorno el promedio del arreglo
}

//funcion que calcula la varianza de un arreglo.
double varianza( int b[], int tamanioDeArreglo){
	double sum=0; //variable donde almaceno la suma 
	for( int i = 0; i < tamanioDeArreglo; i++){
		sum += pow( b[i] - calc_prom(b, tamanioDeArreglo) , 2); //calculo el cada termino de la suma varianza: sum( (b_i - b_prom)² )
	}
	double varianza = sum/tamanioDeArreglo; //calcula la varianza
	return varianza; //retorno la varianza del arreglo
}

int main(){
	const int tamanio_valores_prueba = 14; //declaro el tamao del arreglo constante
	int valores_prueba[tamanio_valores_prueba] = {89,95,72,83,99,54,86,75,92,73,79,75,82,73}; //defino e inicializo el arreglo
	double var,prom;
	
	prom = calc_prom( valores_prueba, tamanio_valores_prueba);//calculo el promedio
	var = varianza( valores_prueba, tamanio_valores_prueba);//calculo la varianza
	
	//imprimo en pantalla el promedio y la varianza
	cout<<"Promedio: "<<prom<<endl;
	cout<<"Varianza: "<<var<<endl;
	return 0;
}






