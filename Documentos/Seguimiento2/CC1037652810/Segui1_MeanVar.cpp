#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double mean (int Array[], size_t size ) 
{ 
  double sum{0};
  for (size_t i=0; i<size ;i++){
    sum=sum+Array[i];
    //cout << sum << Array[i] << endl;
  }
  sum=sum/size;
  return sum;
}

double Variance (int Array[], size_t size, double mean ) 
{ 
  double sum{0};
  double var{0};
  for (size_t i=0; i<size; i++){
    var=pow((Array[i]-mean),2);
    sum=sum+var;
    //cout << sum << Array[i] << endl;
  }
  sum=sum/size;
  return sum;
}

int main()
{ 
 int Array[]={89,95,72,83,99,54,86,75,92,73,79,75,82,73}; 
 double meanv{0};
 double var{0};
 size_t size= (sizeof(Array)/sizeof(Array[0])); //divide el tamaño de todo el arreglo entre el tamaño por entrada, para obtener la cantidad de entradas
 cout << fixed << setw(20) << left << "Size of the Array: " << setw(20) << right << setprecision(5) << size << endl;
 meanv=mean(Array,size);
 var=Variance(Array,size,meanv);
 cout << fixed << setw(20) << left << "The Mean is: " << setw(20) << right << setprecision(5) << meanv << endl;
 cout << fixed << setw(20) << left << "The Variance is: " << setw(20) << right << setprecision(5) << var << endl;
 return 0;
}
