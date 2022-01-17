#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;

int main() {
   // use the default random-number generation engine to
   // produce uniformly distributed pseudorandom int values from 1 to 6
   default_random_engine engine(static_cast<unsigned int>(time(0)));
   uniform_int_distribution<unsigned int> randomInt(1, 6);

   const size_t arraySize{7}; //// ignora el elemento cero
   array<unsigned int, arraySize> frequency{}; // inicializa a 0s

   for (unsigned int roll{1}; roll <= 6'000'000; ++roll) {
      ++frequency[randomInt(engine)];
   }

   cout << "Cara" << setw(13) << "Frecuencia" << endl;

   for (size_t face{1}; face < frequency.size(); ++face) {
      cout << setw(4) << face << setw(13) << frequency[face] << endl;
   }
   
}

