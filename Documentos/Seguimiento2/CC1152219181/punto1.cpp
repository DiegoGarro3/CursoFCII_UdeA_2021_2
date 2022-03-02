#include <iostream>
#include <iomanip>
#include <cmath>

float calc_prom(float valores_prueba[]){
  
  float sum=0;
  int i=0;
  float prom{0};
  
  while(i<14){
    
    sum += valores_prueba[i];
    i+=1;
  }
  
  prom= sum/14;
  return prom;
  
};

float varianza(float valores_prueba[],float calc_prom){

  float sum=0;
  int i=0;
  while(i<14){
    sum+=pow((valores_prueba[i]-calc_prom),2)/14;
    i+=1;

    

  }
  return sum;


}




int main(){
  
  float valores_prueba[14]={89, 95, 72, 83, 99, 54, 86, 75,
			92, 73, 79, 75, 82, 73};
  std::cout << "\n";
  std::cout << "El promedio de la lista es: " << calc_prom(valores_prueba) <<std::endl;
  std::cout << "\n";
  std::cout <<  "La varianza de la lista es: " << varianza(valores_prueba,calc_prom(valores_prueba)) << std::endl;
  std::cout << "\n";
  

  
  return 0;



}


