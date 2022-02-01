#include "factura.h"

int main() 
{   
    /* initialization of item reference, item description,
    number of items and price of the item */  

    Factura factura("04", "Tornillos", 5, 500.0);

    //set the description of the item
    factura.setDescri("Destornillador estrella");

    //set the price of the item
    factura.setPrice(10000);

    //set the numbers of items
    factura.setArticles(10);


    //print the bill on the screen
    factura.printBill(); 

    return 0;
}