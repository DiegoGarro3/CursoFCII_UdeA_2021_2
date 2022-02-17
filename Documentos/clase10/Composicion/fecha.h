#ifndef FECHA_H
#define FECHA_H

class Fecha
{
public:
Fecha( int = 1, int = 1, int = 1900 ); // constructor predeterminado
 
void imprimir() const; // imprime la fecha en formato mes/día/año
~Fecha(); // se proporciona para confirmar el orden de destrucción
 
private:
int mes; // 1-12 (Enero-Diciembre)
int dia; // 1-31 con base en el mes
int anio; // cualquier año
 
// función utilitaria para comprobar si el dia es apropiado para mes y anio
int comprobarDia( int ) const;
};

#endif
