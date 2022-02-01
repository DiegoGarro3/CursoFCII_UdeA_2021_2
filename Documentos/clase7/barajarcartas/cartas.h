/*
Los arreglos pueden contener apuntadores. Un uso común de dicha estructura de datos es formar un arreglo de cadenas
basadas en apuntador, lo cual se conoce simplemente como un arreglo de cadenas. Cada entrada en el arreglo es una
cadena, pero en C++ una cadena es en esencia un apuntador a su primer carácter, por lo que cada entrada en un arreglo
de cadenas es simplemente un apuntador al primer carácter de una cadena.
*/

class MazoDeCartas
{
 public:
  MazoDeCartas(); // el constructor inicializa el mazo
  void barajar(); // baraja las cartas en el mazo
  void repartir(); // reparte las cartas en el mazo
 private:
  int mazo[ 4 ][ 13 ]; // representa el mazo de cartas
};


