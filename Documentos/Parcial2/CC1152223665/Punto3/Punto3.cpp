/*
METODO DE JACOBI

Sea x un vector de incognitas, A una matriz de coeficientes y b un vector de terminos independientes
	Ax=b
Podemos reescribir con una matriz D diagonal y una matriz R con ceros en la diagonal
	A=D+R
	(D+R)x=b
	Dx+Rx=b
	Dx = b-Rx
multiplicando por D⁻¹ ambos lados
	D⁻¹Dx = D⁻¹(b-Rx)
así
	x = D⁻¹(b-Rx)

la ecuación de recurrencia es 

	x^(k+1) = D⁻¹(b - Rx^k) 

para k=1,...,max_iter; x⁰ es un vector solucion inicial y x^(k+1) es una aproxcimacion posterior a x^k
Dij⁻¹ = 1/Aij
*/

#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

//n es el numero de ecuaciones lineales, A es la matriz de coeficientes, b es el vector de terminos independientes
//x0 es el vector de soluciones iniciales y max_iter es el numero maximo de iteraciones que hará el metodo de Jacobi.
vector<float> Jacobi(int n, vector< vector<float> > A, vector<float> b, vector<float> x0, int max_iter){
	
	//comprobamos que el metodo sea convergente a partir de la matriz A de coeficientes, si no lo es se muestra mensaje
	// Condicionde convergencia: |Aii|>SUMA |Aij| para i fijo y suma sobre j desde 1 hasta n
	int conv=0;
	float suma;
	for(int i=0; i<n; i++){
		suma=0.0;
		for(int j=0; j<n; j++){	
			if(i != j){
				suma += abs(A[i][j]);
			}
		}
		if(abs(A[i][i]) < suma){
			conv++;
		}
	}
	
	if(conv!=0){
		cout<<"****El metodo de Jacobi no converge****, la matriz de coeficientes no cumple la condicion |Aii|>SUMA |Aij| para i fijo y suma sobre j desde 1 hasta n."<<endl;
		cout<<"Se recomienda usar parametro de relajacion w(0,1) en el metodo de SOR para que converja."
		return x0;
	}
	else{
		//creo un vector
		vector<float> X;
		//lleno el vector de n ceros
		for(int i=0; i<n; i++){
			X.push_back(0);
		}	
	
		//creo una matriz nxn, usando el contructor de la clase vector
		vector< vector<float> > R(n, vector<float>(n) );
		//se llena la matriz colocando ceros en la diagonal y el resto con los valores de la matriz de coeficientes
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j){
					R[i][j]=0;
				}
				else{
					R[i][j]=A[i][j];
				}
			}	
		}
	
		float sum;
	
		//se calcula a partir de la solucion inicial una solucion posterior, mediante la ecuacion de recurrencia.
		for(int k=0; k<max_iter; k++){
			for(int i=0; i<n; i++){
				sum=0.0;
				for(int j=0; j<n; j++){
					sum += R[i][j]*x0[j];
				}
				X[i] = ( b[i] - sum )/A[i][i];						
			}
			x0=X;
		}
	
		//se retorna un vector con las soluciones a las incognitas
		return X;
	}
}

/*
METODO DE SOR (Sobrerrelajacion sucesiva)

Sea x un vector de incognitas, A una matriz de coeficientes y b un vector de terminos independientes
	Ax=b
Podemos reescribir con una matriz D diagonal, una matriz U triangular superior y una matriz L triangular inferior
	A = D+U+L
	w(D+U+L)x = wb
	wDx+wUx+wLx = wb
	wLx = wb-wUx-wDx
	Dx+wLx = wb-wUx-wDx+Dx
	Dx = wb-wUx-wLx+(1-w)Dx
	D⁻¹Dx = wD⁻¹b-wD⁻¹(U+L)x+(1-w)D⁻¹Dx
	x = wD⁻¹[b-(U+L)x]+(1-w)x
	
Luego U+L=R, donde R=A-D		
así
	x = (1-w)x + wD⁻¹(b-Rx)

la ecuación de recurrencia es 

	x^(k+1) = ( 1-w )x^k + wD⁻¹( b - Rx^k )

para k=1,...,max_iter; x⁰ es un vector solucion inicial y x^(k+1) es una aproxcimacion posterior a x^k
Dij⁻¹ = 1/Aij
*/

//n es el numero de ecuaciones lineales, A es la matriz de coeficientes, b es el vector de terminos independientes
//x0 es el vector de soluciones iniciales, w es el parametro de relajacion y max_iter es el numero maximo de iteraciones que hará el metodo de Jacobi.
vector<float> SOR(int n, vector< vector<float> > A, vector<float> b, vector<float> x0, float w, int max_iter){
	
    //creo un vector
	vector<float> X;
	//lleno el vector de n ceros
	for(int i=0; i<n; i++){
		X.push_back(0);
	}	
	
	//creo una matriz nxn, usando el contructor de la clase vector
	vector< vector<float> > R(n, vector<float>(n) );
	//se llena la matriz colocando ceros en la diagonal y el resto con los valores de la matriz de coeficientes
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				R[i][j]=0;
			}
			else{
				R[i][j]=A[i][j];
			}
		}	
	}
	
	float sum;
	
	//se calcula a partir de la solucion inicial una solucion posterior, mediante la ecuacion de recurrencia.
	for(int k=0; k<max_iter; k++){
		for(int i=0; i<n; i++){
			sum=0.0;
			for(int j=0; j<n; j++){
				sum += R[i][j]*x0[j];
			}
			X[i] = (1-w)*x0[i] + w*( b[i] - sum )/A[i][i];						
		}
		x0=X;
	}
	
	//se retorna un vector con las soluciones a las incognitas
	return X;
	
}

int main(){
	
	//sistema de ecuaciones de orden n
	int n;
	cout<<"Ingrese el orden del sistema de ecuaciones: ";
	cin>>n;
	cout<<endl;
	
	//creo una matriz nxn
	vector< vector<float> > A(n, vector<float>(n) );
	
	float entrada;
	
	//el usuario llena la matriz de coeficientes 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"Ingrese la posicion "<<i+1<<","<<j+1<<" de la matriz de coeficientes: ";
			cin>>entrada;
			A[i][j]=entrada;
		}
	}
	cout<<endl;
	
	//se crea y el usuario llena el vector de terminos independientes
	vector<float> b;
	float ind;
	for(int i=0; i<n; i++){
		cout<<"Ingrese el termino independiente de la ecuacion "<<i+1<<": ";
		cin>>ind;
		b.push_back(ind);
	}
	cout<<endl;
	
	//se crea y el usuario llena el vector de soluciones iniciales
	vector<float> x0;
	float ini;
	for(int i=0; i<n; i++){
		cout<<"Ingrese la solucion inicial "<<i+1<<": ";
		cin>>ini;
		x0.push_back(ini);
	}
	cout<<endl;
	
	//el usuario ingresa el parametro de relajacion
	float w;
	cout<<"Ingrese el parametro de relajacion: ";
	cin>>w;
	cout<<endl;
	
	//el usuario ingresa el numero de iteraciones maxima
	int max_iter;
	cout<<"Ingrese el numero de iteraciones maxima: ";
	cin>>max_iter;
	cout<<endl;
	
	//se crea el vector solucion al sistema de ecuaciones lineales por metodo Jacobi
	vector<float> X_solucion1;
	X_solucion1 = Jacobi(n,A,b,x0,max_iter);
	
	//se crea el vector solucion al sistema de ecuaciones lineales por metodo SOR
	vector<float> X_solucion2;
	X_solucion2 = SOR(n,A,b,x0,w,max_iter);
	
	cout<<setw(16)<<left<<"JACOBI"<<setw(15)<<"SOR"<<endl;
	//imprimimos la solucion de las X o incognitas
	for(int i=0; i<n; i++){
		cout<<"x"<<i+1<<" = "<<setw(10)<<left<<X_solucion1[i]<<"x"<<i+1<<" = "<<setw(7)<<X_solucion2[i]<<endl;
	} 
	
	return 0;
}












