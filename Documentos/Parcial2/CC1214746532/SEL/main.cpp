#include "ecuaciones.h"

int main(){

    Ecuacion Sistema;
    Sistema.Jacobi();
    cout<<"\n";
    Sistema.SOR();
}

/*

Ambos metodos suelen llegar a soluciones que difieren
en un cifra decimal que no afecta el resultado

La confianza del metodo SOR depende del parametro w
el cual al jugar con el se obtienen resultados con mas
iteraciones que el jacobi o menos dependiendo de su escogencia 
lo cual muestra esa falencia al desconocer al principio el sistema
y no tener un w optimo dejando en principio el metodo de jacobi
como la eleccion y usando SOR en caso de saber el valor optimo de w

*/