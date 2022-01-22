#include <string>

using namespace std;

class Factura {
    public:
        Factura(string, string, int, int);

        void setPieceNumber(string);
        void setPieceDescription(string);
        void setArticlesQuantity(int);
        void setArticlePrice(int);

        string getPieceNumber();
        string getPieceDescription();
        int getArticlesQuantity();
        int getArticlePrice();

        int obtenerMontoFactura();
    
    private:
        string pieceNumber;
        string pieceDescription;
        int articlesQuantity;
        int articlePrice;
};