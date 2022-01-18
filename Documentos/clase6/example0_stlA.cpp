// Initializing an array's elements to zeros and printing the array.
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main() {
  array<int, 10> n; //n es un arreglo de 10 enteros
  
  // initialize elements of array n to 0        
  for (size_t i{0}; i < n.size(); ++i) {
    n[i] = 0; //establece el elemento en la ubicación i a 0
  }
  
  cout << "Elemento" << setw(10) << "Valor" << endl;
  // imprime el valor de cada elemento del arreglo
  for (size_t j{0}; j < n.size(); ++j) {
    cout << setw(7) << j << setw(10) << n[j] << endl;
  }
  
  return 0; 
}
