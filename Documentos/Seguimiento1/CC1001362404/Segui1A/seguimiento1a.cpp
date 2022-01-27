#include <iostream>

using namespace std;

int main(){
	cout << "Evalue el profesor de acuerdo al número de alumnos aprobados de diez que presentaron el exámen de admisión"<<endl;
	cout<<"Ingrese el dígito (1) para aprobado y (2) para no aprobados:" << endl;
	
	int est_aprobados=0;
	int est_reprobados=0;
	int var;
	string decision;
	
	for (int i=1; i<=10; i++){
	cout << "Alumno " << i << "= ";
	cin >> var;
	
	if(var != 1 && var !=2){
		cout << "Paramétro no válido" <<endl;
		break;
	}
	else if(var==1){
		++est_aprobados;
	}
	else {
		++est_reprobados;
	}	
	}
	if (est_aprobados + est_reprobados == 10){
	cout << "Total de alumnos"<< "\n";
	cout << "Aprobados = " << est_aprobados <<"\n";
	cout << "Reprobados = " << est_reprobados <<"\n";
	
	decision = (est_aprobados < 8) ? "Cambie de profesor" : "Excelente profesor, se merece un aumento";
	cout << decision<<endl;
	}
	return 0;
}
