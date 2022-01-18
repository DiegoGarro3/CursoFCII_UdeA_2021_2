
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm> // contiebe sort y binary_search
using namespace std;

int main() {
   const size_t arraySize{7}; 
   array<string, arraySize> colors{"red", "orange", "yellow",
      "green", "blue", "indigo", "violet"};

   // salid array original
   cout << "Unsorted array:\n";
   for (string color : colors) {
      cout << color << " ";
   }

   sort(colors.begin(), colors.end()); // sort al contenido de colores

   // salida del arreglo ordenado
   cout << "\nSorted array:\n";
   for (string item : colors) {
      cout << item << " ";
   }

   // buscar "indigo" en el arreglo colors
   bool found{binary_search(colors.begin(), colors.end(), "indigo")};
   cout << "\n\n\"indigo\" " << (found ? "was" : "was not")
      << " found in colors" << endl;

   // buscar "cyan" en el arreglo colors
   found = binary_search(colors.begin(), colors.end(), "cyan");
   cout << "\"cyan\" " << (found ? "was" : "was not")
      << " found in colors" << endl;
}

