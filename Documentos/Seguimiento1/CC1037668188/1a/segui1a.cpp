#include<iostream>
using namespace std;

int main(){
int count=0,i(0);   // contador de estudiantes: count, contador del ciclo: i
int result;
cout<< "INGRESE UN 1 SI EL ESTUDIANTE APROBÓ, Y UN 0 SI FALLÓ."<< endl;

while (i < 10)
{
cout << "Estudiante # "<<i+1<<endl;
cin >> result;       // Ingresar el determinador valor asignado al estudiante i-esimo.
if(result !=  0 && result !=1){
cout<< "Error: ingrese 1 o 0"<< endl;
continue;
}

if(result==1)
count++;

i++;
}
if(count>8)
cout << "Excelente instructor"<< endl;
else
cout<< "DEBE MEJORAR EL instructor" <<endl;
return 0;
}