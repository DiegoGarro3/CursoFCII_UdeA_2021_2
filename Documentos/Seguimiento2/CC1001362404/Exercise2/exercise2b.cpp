// Preprocessors
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "sysconvert.h"

int main(){
    
    string input_number;
    char sys_1, sys_2;
    string fname_input, fname_output;
    
    const string str1 = "Introduzca nombre de archivo <Entrada> <Salida> \nPor ejemplo: data.txt data_new.txt  \nNota: Formato de archivo <number> <Init_system> <End_system>";
    
        
    cout << str1 << endl;
    /* For quick testing to uncomment:
    fname_input = ("data.txt");
    fname_output = ("data_new.txt");*/
    cin >> fname_input >> fname_output;
    cout << endl;
    
    ifstream file_input(fname_input);    
    if(file_input.fail()){
        string error_message = ("Error en la lectura del archivo");
        cout << error_message << endl;
        exit(1);
    }    
    ofstream file_output(fname_output, ios::out | ios::trunc);
    
    //Headers for output display and file
    
    
    /*NOTE: If it's required to reprocess the data, not convenient put a header.
            Just stetic issue.
    file_output << left << setfill(' ') << setw(16) << "Input_number"
        << setw(8) << "sys_1" << setw(8) << "sys_2"
        << setfill(' ') << setw(16) << "Output_number"
        << endl;*/
    
    cout<< right << setfill(' ') << setw(16) << "Input_number"
        << setw(8) << "sys_1" << setw(8) << "sys_2"
        << setfill(' ') << setw(16) << "Output_number"
        << endl;
    
    
    while(file_input >> input_number >> sys_1 >> sys_2){
        
        sysconvert output_number(input_number, sys_1, sys_2);
        
        file_output << left << setfill(' ') << setw(16) << input_number 
            << setw(8) << sys_1 << setw(8) << sys_2
            << setfill(' ') << setw(16) << output_number.convert()
            << endl;

        
        cout<< right << setfill(' ') << setw(16) << input_number
            << setw(8) << sys_1 << setw(8) << sys_2
            << setfill(' ') << setw(16) << output_number.convert()
            << endl;
    }
                
    file_output.close();
    return 0;
    
}

