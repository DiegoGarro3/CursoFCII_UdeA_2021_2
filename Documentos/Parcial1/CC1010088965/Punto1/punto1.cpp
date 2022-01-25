#include <iostream>
#include "Factura.h"

int main() {
    cout << "A continuacion se genera una factura de un articulo de computacion, pero el asistente incorrectamente ingresa como -3000000 el precio por articulo:" << endl;
    Factura facturaComputador("60317", "Computador de 600GB de SSD y 4GB de RAM.", 1, -300000);
    cout << "Se ha generado una factura con estas caracteristicas: " << endl;
    cout << "   Numero de pieza: " << facturaComputador.getPieceNumber() << endl;
    cout << "   Descripcion de pieza: " << facturaComputador.getPieceDescription() << endl;
    cout << "   Cantidad de articulos comprados: " << facturaComputador.getArticlesQuantity() << endl;
    cout << "   Precio por articulo: " << facturaComputador.getArticlePrice() << endl;
    cout << "Como se puede ver, el sistema hizo la correccion a 0 en el precio por articulo." << endl;
    cout << "Ahora se modifica la descripcion de la pieza para que tenga 6GB de RAM, y se le corrige el precio:" << endl;
    facturaComputador.setPieceDescription("Computador de 600GB de SSD y 6GB de RAM.");
    facturaComputador.setArticlePrice(1600000);
    cout << "   Descripcion de pieza: " << facturaComputador.getPieceDescription() << endl;
    cout << "   Precio por articulo: " << facturaComputador.getArticlePrice() << endl;
    cout << "Ahora sucede que el cliente que hizo la compra quiso comprar 2 computadores mas, para un total de 3" << endl;
    facturaComputador.setArticlesQuantity(3);
    cout << "   Cantidad de articulos comprados: " << facturaComputador.getArticlesQuantity() << endl;
    cout << "Ahora se desea saber el precio total de la factura:" << endl;
    cout << "   Precio total de factura: " << facturaComputador.obtenerMontoFactura() << endl;
}