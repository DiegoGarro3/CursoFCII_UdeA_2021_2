
//Una institución ofrece un curso que prepara a los estudiantes para el examen de admisión a la UdeA. El año pasado, diez de los estudiantes que completaron este curso tomaron el examen. La institución quiere saber qué tan bien les fue a sus estudiantes en el examen. Se le pide que escriba un programa para resumir los resultados. "Imagine":  Se le ha dado una lista de estos 10 estudiantes. Junto a cada nombre se escribe un 1 si el estudiante aprobó el examen o un 2 si el estudiante fallo. Si mas de 8 estudiantes aprobaron el examen escriba un mensaje que diga <excelente instructor>.

#include<iostream> //libreria para entrada y salida de datos en pantalla. 

using namespace std; //para usar la forma corta de cin>> y cout<<.

int main(){ //funcion principal del programa.

	int i,resultado, aprobados, reprobados; //declaracion de variables.
	
	i=1; 
	aprobados=0;   //inicializacion de variables
	reprobados=0;
	
	while (i<=10){ //ciclo while para pedir al usuario repetitivvamente los resultados del examen de cada estudiante.
		cout<<"Entre el resultado de la lista. (1 = aprobado, 2 = reprobado): "; //se imprime en pantalla.
		cin>>resultado; //se pide ingresar la variable en pantalla.
		
		if (resultado==1){ //sentencia if para contar los estudiantes aprobados.
			aprobados++;	//contador de aprobados.		
		}
		else{ //si no se cumple if entra en else.
			reprobados++; //contador de reprobados.
		}
		i++; //contador que indica al while cuando salir del bucle.
	}
	
	cout<<"Aprobados: "<<aprobados<<endl; //se imprime en pantalla el numero de aprobados.
	cout<<"Reprobados: "<<reprobados<<endl; //se imprime en pantalla el numero de reprobados.
	
	if (aprobados>=8){ //sentencia if para revisar si aprobaron 8 o mas estudiantes.
		cout<<"Excelente Profesor!!"<<endl;//se imprime en pantalla.
	}
	
	return 0; //se retorna un entero por la funcion principal.
}
