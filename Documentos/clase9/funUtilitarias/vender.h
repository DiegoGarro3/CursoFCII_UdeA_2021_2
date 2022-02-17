#ifndef VENDEDOR_H
#define VENDEDOR_H

class Vendedor
{
 public:
  Vendedor(); 
  void obtenerVentasDelUsuario(); // recibe las ventas del teclado
  void establecerVentas( int, double ); // establece las ventas para un mes específico
  void imprimirVentasAnuales(); // resume e imprime las ventas
 private:
  double totalVentasAnuales(); // prototipo para la función utilitaria
  double ventas[ 12 ]; 
}; 

#endif
