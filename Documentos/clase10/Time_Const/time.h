#ifndef TIEMPO_H
#define TIEMPO_H
class Tiempo
{
public:
Tiempo( int = 0, int = 0, int = 0 );

void setTiempo( int, int, int );
void setHora( int ); 
void setMinuto( int ); 
void setSegundo( int );
 
// funciones "get" (por lo general se declaran const)
int getHora() const; 
 int getMinuto() const; // note el const
int getSegundo() const;
 
// funciones para imprimir (por lo general se declaran const)
void imprimirUniversal() const; // imprime el tiempo universal
void imprimirEstandar(); // imprime el tiempo estándar(debe ser const)
 
private:
int hora; // 0 - 23 (formato de reloj de 24 horas)
int minuto; // 0 - 59
int segundo; // 0 - 59
 
};

#endif
