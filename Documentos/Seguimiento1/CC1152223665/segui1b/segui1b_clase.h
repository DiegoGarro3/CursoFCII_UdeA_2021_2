//Creacion de la clase con las siguientes caracteristicas:
//dos variables privadas: el valor de "x" y "N"la presicion (el numero de terminos de la serie).
//dos metodos: Factorial: n! y Exponencial: e^x.

class Euler{ //clase que calcula el factorial de un numero y el valor de e^x.
	private: //variables privadas. 
		double x; //declaracion de la variable x como double.
		int N; //declaracion variable N como entero.
	public: //metodos o funciones de la clase
		Euler(double,int); //constructor.
		long double Factorial(int); //metodo que calcula el factorial. long double porque puede llegar a almacenar numeros muy muy grandes.
		double Exponencial(double,int); //metodo que calcula e^x.
};
