#include <iostream>
#include <string>

using namespace std;

const string HEX_VALS_UPPER = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
const string HEX_VALS_LOWER = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};


string convertValueFromInputSysToOutSys(string, char, char);
string binaryToDecimal(string);
string decimalToBinary(string);
string hexadecimalToDecimal(string);
string decimalToHexadecimal(string);

int main() {
    char inputSystem;
    char outputSystem;
    string inputVal;
    string outputVal;
    bool correctInput = false;
    cout << "Introduzca con el siguiente formato el numero que desea convertir (sin los corchetes):" << endl;
    cout << "<Sistema de entrada> <Numero a convertir> <Sistema de salida>" << endl;
    cout << "Los sistemas solo pueden ser B (binario), D (decimal) o H (hexadecimal). Un ejemplo seria:" << endl;
    cout << "D 24 B" << endl;
    cout << "Ahora usted: " << endl;
    while (!correctInput) {
        cin >> inputSystem;
        cin >> inputVal;
        cin >> outputSystem;
        correctInput = (inputSystem == 'B' || inputSystem == 'D' || inputSystem == 'H') && 
                        (outputSystem == 'B' || outputSystem == 'D' || outputSystem == 'H');
        if (!correctInput) {
            cout << "Introdujo sistemas no validos. Por favor introduzca nuevamente: " << endl;
        }
    }
    outputVal = convertValueFromInputSysToOutSys(inputVal, inputSystem, outputSystem);
    cout << "El valor convertido es " << outputVal << endl;
}

string convertValueFromInputSysToOutSys(string inputVal, char inputSystem, char outputSystem) {
    string outputVal;
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