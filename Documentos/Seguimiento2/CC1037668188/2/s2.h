#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
class Conversion
{
    public:
    Conversion(void);
    // Prototipos de funciones conversion
    string DecimalToBinario(int);
    int BinarioToDecimal(string); 
    string DecimalToHexadecimal(int); 
    int HexadecimalToDecimal(string);
    string BinarioToHexadecimal(string);
    string HexadecimalToBinario(string);
};