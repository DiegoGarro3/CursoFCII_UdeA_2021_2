#ifndef INCREMENTO_H
#define INCREMENTO_H

class Incremento
{
public:
Incremento( int c = 0, int i = 1 ); // constructor predeterminado
 
// definición de la función agregarIncremento
void agregarIncremento()
{
cuenta += incremento;
}
 
void imprimir() const; // imprime cuenta e incremento
 
private:
int cuenta;
const int incremento; // miembro de datos const
};
#endif
