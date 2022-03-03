#include<iostream>
#include<iomanip>
#include <cmath>
#define D 20 // tamaño máximo de las matrices

using namespace std;

int main(){
	int n,k,nmax,conta=0;	
	float A[D][D],b[D],x[D],c[D],suma,xsor[D],csor[D],w; // definimos los arreglos 
	
	cout<<"Ingrese el número de ecuaciones"<<endl;cin>>n;
	cout<< "Ingrese el número de iteraciones: "<<endl;cin>>nmax;
	cout<< "Ingrese el parámetro de relajación (w): "<<endl;cin>>w;
	//cout<<"Ahora ingrese el coeficiente de las variables por ecuación"<<endl;
	for(int i=0;i<n;i++){
		x[i]=0; // condición inicial JACOBI
		xsor[i]=0; // condición inicial SOR
		for(int j=0;j<n;j++){ // almacenamos los datos de los coeficientes
			cout<<"Ingrese el coeficiente "<<i+1<<" "<<j + 1<<" de la matriz: ";
			cin>>A[i][j];
		}
	}
	
	cout<<"Ingrese los términos independientes: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"\t"; 
		cin>>b[i]; // ALMACENAMOS LOS TERMINOS INDEPENDIENTES
	}
	
	//MIRAMOS LA CONIDICIÓN DE CONVERGENCIA PARA JACOBI
	for(int i=0; i<n;i++){ // condición de convergencia para el método
		suma = 0.0;
		for(int j=0;j<n;j++){
			if(i != j){
				suma += abs(A[i][j]); // sumamos la primera fila de la matriz A y luego la segunda y asì sucesivamente 
			}
		}
	
		if(abs(A[i][i])<suma){ // comparamos de la primera fila con el coeficiente ii de la matriz A
			conta++;
			break; // salimos del for
		}
	}
	
	if(conta == 1){
		cout<<"El método de JACOBI no converge dado que A[i][i]<Suma |A[i][j]|"<<endl; // anunciamos que el método no converge
		}
	else{ // HACEMOS EL MÈTODO DE JACOBI EN CASO DE CONVERGER
		for(int k=0;k<nmax;k++){
			for(int i=0;i<n;i++){
				c[i]=b[i];
				for(int j=0;j<n;j++){
					if(i!=j){ // hacemos la suma sobre los i diferentes de J
						c[i]=c[i]-A[i][j]*x[j];
					}
			
				}
			}
		
			for(int i=0;i<n;i++){ // traemos nuestro resultado de iteración
				x[i]=c[i]/A[i][i]; 
			}
		}
		
	// Fin método de JACOBI
	cout<<"La solución por el método de JACOBI es: "<<endl; // damos la soluciòn
	
	for(int i=0;i<n;i++){
		cout<<"x("<<i+1<<") = "<<x[i]<<endl; // imprimimos los resultados
	}
		
		}
		
		//METODO DE SOR
	for(int k=0;k<nmax;k++){
		for(int i=0;i<n;i++){
			csor[i]=b[i];
			for(int j=0;j<n;j++){
				if(i!=j){ // hacemos la suma sobre los i diferentes de J
					csor[i]=csor[i]-A[i][j]*xsor[j]; //sumamos para i distinto de J
				}
		
			}
		}
	
		for(int i=0;i<n;i++){ // traemos nuestro resultado de iteración
			xsor[i]=(1-w)*xsor[i] + w*csor[i]/A[i][i]; // relación de recurrencia
		}
	}
	
	//fin método de SOR

		
	cout<<"La solución por el método de SOR es: "<<endl; // damos la soluciòn
	
	for(int i=0;i<n;i++){
		cout<<"x("<<i+1<<") = "<<xsor[i]<<endl; // imprimimos los resultados
	}
	
return 0;
}
