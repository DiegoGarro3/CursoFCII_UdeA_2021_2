#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const string HEX_VALS_UPPER = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
const string HEX_VALS_LOWER = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};


string convertValueFromInputSysToOutSys(string, char, char);
string binaryToDecimal(string);
string decimalToBinary(string);
string hexadecimalToDecimal(string);
string decimalToHexadecimal(string);

int main() {
    string fileName;
    cout << "Introduzca el nombre del archivo (incluyendo terminacion) con los datos en tabla," << endl;
    cout << "con cada fila teniendo este formato:" << endl;
    cout << "<Numero a convertir> <Sistema de entrada> <Sistema de salida>" << endl;
    cout << "Los sistemas solo pueden ser B (binario), D (decimal) o H (hexadecimal). Un ejemplo seria:" << endl;
    cout << "24 D B" << endl;
    cout << "Nombre del archivo: " << endl;
    cin >> fileName;

    ifstream fileNumbersToCovert(fileName);

    if (fileNumbersToCovert.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    cout << "A continuacion se muestra la tabla leida con los valores convertidos:" << endl;

    cout << setw(20) << "Valor" << setw(10) << "Sistema1" << setw(10) << "Sistema2" << setw(25) << "ValorSalida" << endl;

    string inputValue;
    char inputSystem;
    char outputSystem;

    while (fileNumbersToCovert >> inputValue >> inputSystem >> outputSystem) {
        cout << setw(20) << inputValue << setw(10) << inputSystem << setw(10) << outputSystem 
            << setw(25) << convertValueFromInputSysToOutSys(inputValue, inputSystem, outputSystem) << endl;
    }
    
    return 0;
}

string convertValueFromInputSysToOutSys(string inputVal, char inputSystem, char outputSystem) {
    bool correctInput = (inputSystem == 'B' || inputSystem == 'D' || inputSystem == 'H') && 
                        (outputSystem == 'B' || outputSystem == 'D' || outputSystem == 'H');
    string outputVal;
    if (correctInput) {
        if (inputSystem == 'B') {
            if (outputSystem == 'B') {
                outputVal = inputVal;
            } else if (outputSystem == 'D') {
                outputVal = binaryToDecimal(inputVal);
            } else if (outputSystem == 'H') {
                outputVal = binaryToDecimal(inputVal);
                outputVal = decimalToHexadecimal(outputVal);
            }
        } else if (inputSystem == 'D') {
            if (outputSystem == 'B') {
                outputVal = decimalToBinary(inputVal);
            } else if (outputSystem == 'D') {
                outputVal = inputVal;
            } else if (outputSystem == 'H') {
                outputVal = decimalToHexadecimal(inputVal);
            }
        } else if (inputSystem == 'H') {
            if (outputSystem == 'B') {
                outputVal = hexadecimalToDecimal(inputVal);
                outputVal = decimalToBinary(outputVal);
            } else if (outputSystem == 'D') {
                outputVal = hexadecimalToDecimal(inputVal);
            } else if (outputSystem == 'H') {
                outputVal = inputVal;
            }    
        }
    } else {
        outputVal = string("invalid");
    }

    return outputVal;
}

string binaryToDecimal(string binVal) {
    int decVal = 0;
    int base = 1;
    for (int i = binVal.length() - 1; i >= 0; i--) {
        if (binVal[i] == '1') {
            decVal += base;
        }
        base = base * 2;
    }

    return to_string(decVal);
}


string decimalToBinary(string strDecVal) {
    int decVal = stoi(strDecVal);
    int quotient = 1;
    int remainder;
    string reverseBinVal;
    string binVal;
    quotient = decVal;
    while (quotient != 0) {
        remainder = quotient % 2;
        reverseBinVal.append(to_string(remainder));
        quotient = quotient/2;
    }
    for (int i = reverseBinVal.length() - 1; i >= 0; i--) {
        binVal.push_back(reverseBinVal[i]);
    }
    
    return binVal;
};

string hexadecimalToDecimal(string hexVal) {
    int decVal = 0;
    int base = 1;
    int hexDigitVal;
    for (int i = hexVal.length() - 1; i >= 0; i--) {
        hexDigitVal = HEX_VALS_LOWER.find_first_of(hexVal[i]);
        if (hexDigitVal == string::npos) {
            hexDigitVal = HEX_VALS_UPPER.find_first_of(hexVal[i]);
        }
        decVal += base * hexDigitVal;
        base = base * 16;
    }

    return to_string(decVal);
};

string decimalToHexadecimal(string strDecVal) {
    int decVal = stoi(strDecVal);
    int quotient = 1;
    int remainder;
    string reverseBinVal;
    string binVal;
    quotient = decVal;
    while (quotient != 0) {
        remainder = quotient % 16;
        reverseBinVal.push_back(HEX_VALS_LOWER[remainder]);
        quotient = quotient/16;
    }
    for (int i = reverseBinVal.length() - 1; i >= 0; i--) {
        binVal.push_back(reverseBinVal[i]);
    }
    
    return binVal;
};