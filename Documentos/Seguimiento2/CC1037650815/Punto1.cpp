#include<iostream>
#include<math.h>

using namespace std;

float calc_prom(int arreglo[]){
float suma =0;
float promedio;

for (int i=0; i<14; i++){
suma=suma+arreglo[i];
}
promedio=suma/14;

return promedio;


};
float varianza(int arreglo[]){

float suma=0;
float varianza;

for (int i=0; i<14; i++){
suma=suma+pow(arreglo[i]-calc_prom(arreglo),2);

}
varianza=suma/14;

return varianza;




};

int main(){

int valores_prueba[14]={89, 95, 72, 83, 99, 54, 86, 75, 92, 73, 79, 75, 82, 73};

cout<<"El promedio es:"<<calc_prom(valores_prueba)<<endl;
cout<<"La varianza es:"<<varianza(valores_prueba)<<endl;



return 0;
}

