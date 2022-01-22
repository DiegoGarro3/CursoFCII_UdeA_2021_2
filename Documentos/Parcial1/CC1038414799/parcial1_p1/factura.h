#include <string> 
using std::string;

class Factura
{
public:
Factura( string, string, unsigned int, float ); 

void setPiece(string); 
string getPiece();

void setDescri(string); 
string getDescri();

void setArticles( int ); 
int getArticles();


void setPrice(float); 
float getPrice();

float ObtenerMontoFactura();
void printBill();


private:
string pieceRef; //item number
string pieceName; //item description 
int cant; //number of items 
float price; //price of the item  

}; 