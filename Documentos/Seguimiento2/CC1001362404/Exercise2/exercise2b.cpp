// Preprocessors
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "sysconvert.h"

int main(){
    
    string fname_input, fname_output;
    
    const string str1 = "Introduzca nombre de archivo <Entrada> <Salida> \nPor ejemplo: data.txt new_data.txt  \nNota: Formato de archivo <number> <Init_system> <End_system>;
    
        
    cout << str1 << endl;
    cin >> fname_input >> fname_output;
    
    
    sysconvert output_number(input_number, sys_1, sys_2);
    
    cout << "\nValor " << input_number << " en "
        <<  sys_1 << " para " << sys_2 << " es "
        <<  output_number.convert() << endl;
    
    
    return 0;
    
}

