// Preprocessors
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "sysconvert.h"

int main(){
    
    string input_number;
    char sys_1, sys_2;
    
    const string str1 = "Introduzca <number> <Init_system> <End_system> \nPor ejemplo: 1000101 B H";
    
        
    cout << str1 << endl;
    cin >> input_number >> sys_1 >> sys_2;
    
    
    sysconvert output_number(input_number, sys_1, sys_2);
    
    cout << "\nValor " << input_number << " en "
        <<  sys_1 << " para " << sys_2 << " es "
        <<  output_number.convert() << endl;
    
    /* JUST A TESTING
    sysconvert new_number("1000101",'B','H');
    sysconvert new1_number(new_number.convert(),'H','B');
    sysconvert new2_number(new_number.convert(),'H','D');

    
    cout << new_number.convert() << endl;
    cout << new1_number.convert() << endl;
    cout << new2_number.convert() << endl;
    */
    
    return 0;
    
}

