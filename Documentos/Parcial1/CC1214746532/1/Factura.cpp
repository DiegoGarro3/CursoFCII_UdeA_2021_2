#include "Factura.h"

Factura::Factura(){//Constructor de la clase
    
    /*Si no se dan valores a la factura la clase iniciara
    con los siguientes valores por defecto*/
    pieza="Cero";
    descripcion="Inicio de turno, aun no hay facturas";
    cantidad = 0;
    valor=0;

}

void Factura::Establecer_pieza(string piezas){//Funcion que da un valor a pieza

    pieza=piezas;
}

void Factura::Establecer_descripcion(string des){//Funcion que da un valor a descripcion

    descripcion=des;
}

void Factura::Establecer_cantidad(unsigned  int cant){//Funcion que da un valor a cantidad

    cantidad = cant;
}

void Factura::Establecer_valor(long int val){//Funcion que da un valor a valor

    if(val>=0){

        valor = val;
    }
    else{//en el caso que valor sea negativo se toma igual a cero

        valor=0;
    }
}

long int Factura::Obtener_valor(){//Funcion que retorna valor
    return valor;
}

unsigned int Factura::Obtener_cantidad(){//Funcion que retorna cantidad
    return cantidad;
}

string Factura::Obtener_descripcion(){//Funcion que retorna descripcion

    return descripcion;
}

string Factura::Obtener_pieza(){//Funcion que retorna pieza

    return pieza;
}

unsigned long int Factura::obtenerMontoFactura(){//Funcion que retorna el monto a pagar

    return valor*cantidad;
}