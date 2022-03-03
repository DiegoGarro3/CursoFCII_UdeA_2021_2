#include "convertir.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <stdlib.h>



using namespace std;

//Definiendo los "dígitos" del sistema hexadecimal.
const string hexBase[16]={"0","1","2","3","4","5","6","7","8","9",
                          "A","B","C","D","E","F"};

//Definiendo la equivalencia a los "dígitos" del sistema hex en el sistema binario.
const string binBase[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000",
                          "1001","1010","1011","1100","1101","1110","1111"};


string dec2bin(string inNum){
    //Convertir string de entrada a un número.
    //int num = stoi(inNum);
    //Contenedor del resultado final.
    string outNum="";
    int cocient=std::stoi(inNum);
    //Si el string de entrada fue 0. 
    if(cocient==0){
        return "0";
    }
    //Realizar el proceso iterativo de hallar residuos al dividir.
    while(cocient!=0){
        //Cada residuo es almacenado como una cadena en el contenedor del resultado final y en orden inverso.
        outNum.insert(0,to_string(cocient%2));
        //Cambiar para la siguiente iteración.
        cocient=cocient/2;
    }
    return outNum;
}

string bin2dec(string inNum){
    //Contenedor del resultado final.
    int outNum=0;
    //Contador para los exponentes.
    int expn=0;
    //Iteración sobre cada caracter del string de entrada.
    for(char c : inNum){
        //Si c es un caracter de un dígito, entonces la operación c-'0' es el valor numérico de ese dígito.
        //El valor numérico de c se multiplica por potencias de 2 de acuerdo a su posición.
        outNum+=(c-'0')*pow(2,inNum.size()-1-expn);
        //Incrementar el exponente en 1.
        expn+=1;
    }
    return to_string(outNum);
}

string bin2hex(string inNum){
    //Completar con ceros el número hasta que len(num)%4=0.
    while(inNum.size()%4!=0){
        inNum.insert(0,"0");
    }
    //Contenedor del resultado final.
    string outNum="";
    //Número de grupos de 4 en que se puede descomponer el string de entrada.
    int l=inNum.size()/4;
    //Para cada grupo en el que se descompone el string de entrada.
    for(int i=1;i<l+1;i++){
        //Extraer cada subcadena de a 4 caracteres del string de entrada. 
        string hexDig=inNum.substr(inNum.size()-4*i,4);
        for(int j=0;j<16;j++){
            //Convertir cada subcadena en su equivalente en la base hex.
            if(hexDig==binBase[j]){
                //Guardando la conversión en el contenedor.
                outNum.insert(0,hexBase[j]);
            }
        }
    }
    return outNum;
}

string hex2bin(string inNum){
    //Contenedor del resultado final.
    string outNum="";
    for(int i=0;i<inNum.size();i++){
        for(int j=0;j<16;j++){
            //Encontrar el equivalente j en la base binaria del dígito i en el string de entrada.
            if(inNum.substr(i,1).compare(hexBase[j])==0){
                //Cuando ocurra la coincidencia, guardar en el contenedor.
                outNum+=binBase[j];
            }
        }
    }
    //Eliminar posibles ceros iniciales.
    while(string{outNum[0]}==string{"0"}){
        outNum.erase(0,1);
    }
    return outNum;
}

string Conversor(){
    
    string Systems[3]={"binario","decimal","hexadecimal"};
    
    int Xsys=0;
    int Ysys=0;
    string number{""};
    string outNum{""};
    cout<<"Esta aplicación es un conversor de números entre los sitemas binario, decimal y hexadecimal"<<endl;
    cout<<"Ingrese el sistema inicial: \n[0] Binario \n[1] Decimal \n[2] Hexadecimal \n... ";
    cin>>Xsys;
    cout<<"Ingrese el número en el sistema que indicó... ";
    cin>>number;
    cout<<"Ingrese el sistema final: \n[0] Binario \n[1] Decimal \n[2] Hexadecimal \n... ";
    cin>>Ysys;
    
    cout<<"Está convirtiendo el número "<<number<<" en "<<Systems[Xsys]<<" al sistema "<<Systems[Ysys]<<endl;
    
    if(Xsys!=Ysys){
        if (Xsys==0 && Ysys==1){
                outNum = bin2dec(number);
                //cout<<number<<" en "<<Systems[Xsys]<<" es igual a "<<outNum<<" en "<<Systems[Ysys];
        }
        else if (Xsys==0 && Ysys==2){
            outNum = bin2hex(number);
        }
        else if (Xsys==1 && Ysys==0){
            outNum = dec2bin(number);
        }
        else if (Xsys==1 && Ysys==2){
            outNum = bin2hex(dec2bin(number));
        }
        else if (Xsys==2 && Ysys==0){
            outNum = hex2bin(number);
        }
        else if (Xsys==2 && Ysys==1){
            outNum = bin2dec(hex2bin(number));
        }
    }
    else {
        outNum = number;
    }
    return outNum;
}