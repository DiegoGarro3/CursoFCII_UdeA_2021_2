//Ecuaciones Diferenciales Ordinarias.

//programa en c++ para resolver ecuaciones diferenciales ordinarias usando
//los metodos “Modified Euler" y “Runge-Kutta Order Four".

//dy/dx = y − x^2 + 1, 0 ≤ x ≤ 2, y(0) = 0.5.

#include<iostream> //importacion de librerias necesarias.
#include<iomanip>
#include<math.h>

using namespace std;

//funcion correspondiente a la ecuacion diferencial f(x,y)=dy/dx.
//los argumentos de la funcion son x e y.
double f(float x, float y){
	return y-pow(x,2)+1; 
}

//funcion que implementa el metodo de Euler modificado.
//los argumentos de la funcion son el valor de x, y los iniciales x0 e y0.
double Euler_Method(float x,float x0,float y0){
	//se establecen las variables a usar dentro de la funcion.
	float h=0.01; //paso sobre el cual se evoluciona hasta llegar a x.
	float xn,_yn,prom;
	int i=0;
	
	//sentencia if para que el metodo sea capaz de que al ingresar x0 retorne y0.
	if(x==x0){
		return y0;
	}
	
	
	else {
	//ciclo while para iterar hasta llegar al valor de la funcion solucion evaluada en x deseado.
	//x/h es el numero de iteraciones necesarias para ir de x0 a x con paso de h.
		while(i<x/h){
			//se varia x con el paso h.
			xn = x0 + h;
			//se encuentra una y posterior al paso actual.
			_yn = y0 + h*f(x0,y0);
			//se calcula el promedio entre la y posterior e la y actual. 
			prom = (f(x0,y0)+f(xn,_yn))/2;
			//luego se calcula la real y posterior pero usando un promedio. 
			y0 = y0 + h*prom;
			//se reestablece x0 como la x posterior.
			x0=xn;
			//se itera i hasta que sea menor a x/h.
			i++;
		}
	//al final se retorna el valor de yo que contiene la funcion solucion a la ecuacion diferencial evaluada en x.
	return y0;
	}
}

//funcion que implementa al metodo Runge Kutta orden 4.
double RK4(float x,float x0,float y0){
	
	//se establecen las variables a usar dentro de la funcion.
	float k1,k2,k3,k4,h;
	int i=0;
	h=0.01; //paso sobre el cual se evoluciona hasta llegar a x.
	
	//sentencia if para que el metodo sea capaz de que al ingresar x0 retorne y0.
	if(x==x0){
		return y0;
	}
	
	else{ 
	//ciclo while para iterar hasta llegar al valor de la funcion solucion evaluada en x deseado.
	//x/h es el numero de iteraciones necesarias para ir de x0 a x con paso de h.
		while(i<x/h){
		//terminos que usan x0 y y0 para calcular la y posterior. 
			k1 = f(x0,y0);
			k2 = f(x0+0.5*h,y0+0.5*k1*h);
			k3 = f(x0+0.5*h,y0+0.5*k2*h);
			k4 = f(x0+h,y0+k3*h);
		//se calcula la y posterior. 
			y0 = y0 + h*(k1+2*k2+2*k3+k4)/6;
		//se calcula la x posterior.
			x0=x0+h;	
		//se itera i hasta que sea menor a x/h.
			i++;
		}
	//al final se retorna el valor de yo que contiene la funcion solucion a la ecuacion diferencial evaluada en x.
	return y0;
	}
}

//funcion principal.
int main(){
	//se declaran las variables correspondientes a los valores iniciales de la ecuacion diferencial.
	float x=2, x0=0, y0=0.5, paso=0.1;
	//se declara e incializa la variable de iteracion.
	int i=0;
	
	//imprimimos la ecuacion diferencial a resolver.
	cout<<"dy/dx = y − x^2 + 1, 0 ≤ x ≤ 2, y(0) = 0.5"<<endl;
	cout<<"y(x) es la soluciion de la ecuacion diferencial."<<endl;
	cout<<"\n";
	//se imprime el nombre o encabezado de la tabla que contendra los valores de x y su correspondiente y(x) calculado
	//con ambos metodos.
	cout<<setw(7)<<left<<"x"<<setw(22)<<"Euler Mejorado y(x)"<<setw(18)<<"Runge Kutta 4 y(x)"<<endl;
	
	//ciclo while para calcular y(x) aumentando x de x0 a x con paso=0.1.
	//x/paso es el numero de iteraciones necesarias para ir de x0 a x con paso=0.1. 
	while(i<=x/paso){
	//se imprime en forma de tabla los valores de x, e y(x) con ambos metodos. y(x) es la solucion de la ec diferencial.
		cout<<setw(7)<<left<<i*paso<<setw(22)<<Euler_Method(i*paso,x0,y0)<<setw(18)<<RK4(i*paso,x0,y0)<<endl;
	//se itera i hasta que sea menor o igual a x/h.
		i++;
	}
	//se retorna un entero debido a la funcion principal.
	return 0;
}





