//Constructor de la clase Euler, y creacion de los metodos:
// Factorial:
//El factorial de un entero "n" no negativo se escribe como n! (n factorial) y se define de la siguiente manera:
//n! = n · (n – 1) · (n – 2) · . . . · 1 ( para valores de n mayores o iguales a 1)
//y
//n! = 1 ( para n = 0 o n = 1). 

// Exponencial:
//e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  .......


#include<math.h> //libreria para herramientas matematicas.
#include "segui1b_clase.h" //se llama la clase creada.

//Constructor, sirve para inicializar los atributos o variables de la clase.
Euler::Euler(double _x, int _N){ 
	x = _x; //inicializacion de variables que se pasaran desde la funcion principal cuando se cree un objeto.
	N = _N; //las variables sin _ se inicializan aqui y seran a las cuales les pasaremos los datos.
}

long double Euler::Factorial(int i){ //creacion del metodo Factorial.
	long double fact; //declaracion de variables que se usaran en este metodo.
	int j;
	
	if(i==0 || i==1){ //sentencia if para especificar el factorial de 1 y 0.
		return 1; //la funcion retorna como resultado del factorial: 1.
	}
	else{ //else para calcular el factorial para numeros diferentes de 0 y 1.
		fact=1;//inicializacion de la variable donde se almacena el factorial.
		for(j=2;j<=i;j++){ //ciclo for para multiplicar un numero por sus suscesivos antecesores, se detiene cuando llega al numero 
								// al cual estamos calculando el factorial.
			fact*=j; //se multiplica la variable de iteracion j con el acumulado del factorial.
		
		}
		return fact; //se retorna el resultado del factorial del numero.
	}
}

double Euler::Exponencial(double x, int N){ //creacion del metodo Exponencial.
	double sum; //declaracion de las variables que se usaran en este metodo.
	int i;
	sum=0; //inicializacion de la variable que almacena e^x.
	for (i=0;i<=N;i++){ //ciclo for para sumar iterativamente x^i/i! desde i=0 hasta i=N.
		sum += pow(x,i)/Euler::Factorial(i); //se almacena el resultado en sum, se usa el metodo pow(a,b)=a^b para la potenciacion y se 															//llama la funcion Factorial de la misma clase.
	}
	return sum; //se retorna el valor de sum que almacena el resultado de e^x.
}
