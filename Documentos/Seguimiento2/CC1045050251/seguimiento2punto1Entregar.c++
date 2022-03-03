#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const int num_ = 14;    //prototipo de la funcion
float calc_prom( int [num_]);
float varianza( int [num_]);

int main() {
  int valores_prueba[num_] = {89,95,72,83,99,54,86,75,92,73,79,75,82,73};
  cout << "el promedio es \t" <<calc_prom(valores_prueba)<< endl;
  cout << "la varianza es \t" <<varianza(valores_prueba)<< '\n';
  system ("pause");
  return 0;
}

float calc_prom(int arreglo_[num_]){
  float suma = 0.0;
  int i;
  float promedio_=0.0;

  for ( i = 0; i <num_; i++){
    //std::cout << "valor i =" << i << "\t es =" << arreglo_[i]<<"\n";
    suma = suma + arreglo_[i];
  }
  promedio_ = suma/num_ ;
  return promedio_;
}

float varianza(int arreglo2_[num_]){
  float numerador = 0.0;
  float suma = 0.0;
  int i;
  float varianza_ = 0.0;
  float prom = 80.5;

  for ( i = 0; i <num_; i++){
    numerador = (arreglo2_[i] - prom)*(arreglo2_[i] - prom);
    suma = suma + numerador;
  }
  varianza_ = suma/num_;
  return varianza_ ;
}
