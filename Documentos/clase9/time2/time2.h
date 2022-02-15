#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
Tiempo( int = 0, int = 0, int = 0 ); // constructor predeterminado
 
// funciones "establecer"
void establecerTiempo( int, int, int ); // establece hora, minuto, segundo
void establecerHora( int ); // establece la hora (después de la validación)
void establecerMinuto( int ); 
void establecerSegundo( int );
 
// funciones "obtener"
int obtenerHora(); // devuelve la hora
int obtenerMinuto(); // devuelve el minuto
int obtenerSegundo(); // devuelve el segundo
 
void imprimirUniversal(); 
void imprimirEstandar();
 
private:
int hora; 
int minuto; 
int segundo; 
};

#endif
