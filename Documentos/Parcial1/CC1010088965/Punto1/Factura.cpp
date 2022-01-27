#include <iostream>
#include <cmath>
#include <string>

#include "Factura.h"

using namespace std;

Factura::Factura(string inPieceNumber, string inPieceDescription, int inArticlesQuantity, int inArticlePrice) {
    pieceNumber = inPieceNumber;
    pieceDescription = inPieceDescription;
    articlesQuantity = inArticlesQuantity;
    setArticlePrice(inArticlePrice);
}

void Factura::setPieceNumber(string inPieceNumber) {
    pieceNumber = inPieceNumber;
}

void Factura::setPieceDescription(string inPieceDescription) {
    pieceDescription = inPieceDescription;
}

void Factura::setArticlesQuantity(int inArticlesQuantity) {
    articlesQuantity = inArticlesQuantity;
}

void Factura::setArticlePrice(int inArticlePrice) {
    if (inArticlePrice < 0) {
        articlePrice = 0;
    } else {
        articlePrice = inArticlePrice;
    }
}

string Factura::getPieceNumber() {
    return pieceNumber;
}

string Factura::getPieceDescription() {
    return pieceDescription;
}

int Factura::getArticlesQuantity() {
    return articlesQuantity;
}

int Factura::getArticlePrice() {
    return articlePrice;
}

int Factura::obtenerMontoFactura() {
    float amount = articlesQuantity*articlePrice;
    if (amount < 0) {
        amount = 0;
    }
    return amount;
}

