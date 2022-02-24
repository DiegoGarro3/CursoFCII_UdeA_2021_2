#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


string entrada{0};
string salida{0};
const string hexa[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
const int hexa2[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
const char hexa3[] = "0123456789ABCDEF";
const string bina[2] = {"0","1"};
const string bina2[16] = {"0000","0001","0010","0011","0100","0101","0110",
"0111","1000", "1001","1010","1011","1100","1101","1110","1111"};
const char bina3[] = "01";
const int bina4[2] = {0,1};
const char bina5[] = "0000000100100011010001010110011110001001101010111100110111101111";


int numero{0};
char numero2[50];
int i=0;
string conver[50];
int cociente{0};
int resi{0};
int tam = 0;
int suma=0;

void dec_a_hex(){

    cout<<"ingrese el numero que quiere convertir de decimal a hexaecimal"<<endl;

    cin >> numero;

    cociente = numero/16;
    resi=numero%16;

    numero=cociente;

    conver[0]=hexa[resi];

    while (cociente!=0){
        i++;
        cociente=numero/16;
        resi=numero%16;
        numero=cociente;
        conver[i]=hexa[resi];
    }

    cout<<"el numero ingresado en hexadecimal es: "<<endl;
    for (int j = i; j>=0; j--)
    {
        cout<<conver[j];
    }

    cout<<"\n";
    
}

void dec_a_bi(){

    cout<<"ingrese el numero que quiere convertir de decimal a binario"<<endl;

    cin >> numero;

    cociente = numero/2;
    resi=numero%2;

    numero=cociente;

    conver[0]=bina[resi];

    while (cociente!=0){
        i++;
        cociente=numero/2;
        resi=numero%2;
        numero=cociente;
        conver[i]=bina[resi];
    }

    cout<<"el numero ingresado en hexadecimal es: "<<endl;

    for (int j = i; j>=0; j--)
    {
        cout<<conver[j];
    }

    cout<<"\n";    
}

void hex_a_dec(){


    cout<<"ingrese el numero que quiere convertir de hexadecimal a decimal"<<endl;

    cin >> numero2;

    while (numero2[ i ] != '\0'){
        
        i++;
    }
    
    tam = i;

    for (int j = 0; j < i; j++){
        for (int k = 0; k <= 16 ; k++){
            if (numero2[j] == hexa3[k]){

                suma+=hexa2[k] * pow(16,i-j-1);
            }   
        }
    }
    
    cout<<"el numero ingresado en decimal es: "<<endl;
    cout<< suma <<endl;
}

void hex_a_bin(){


    cout<<"ingrese el numero que quiere convertir de hexadecimal a binario"<<endl;

    cin >> numero2;

    while (numero2[ i ] != '\0'){
        
        i++;
    }
    
    tam = i;
    string con[i];

    cout<<"el numero ingresado en decimal es: "<<endl;

    for (int j = 0; j < i; j++){
        for (int k = 0; k <= 16 ; k++){
            if (numero2[j] == hexa3[k]){

                con[j]=bina2[k];
                cout<<con[j];
            }   
        }
    }
    cout<<"\n";
}

void bin_a_dec(){


    cout<<"ingrese el numero que quiere convertir de binario a decimal"<<endl;

    cin >> numero2;

    while (numero2[ i ] != '\0'){
        
        i++;
    }
    
    tam = i;

    for (int j = 0; j < i; j++){
        for (int k = 0; k <= 16 ; k++){
            if (numero2[j] == bina3[k]){

                suma+=bina4[k] * pow(2,i-j-1);
            }   
        }
    }
    
    cout<<"el numero ingresado en decimal es: "<<endl;
    cout<< suma <<endl;
}

void bin_a_hex(){


    cout<<"ingrese el numero que quiere convertir de binario a hexadecimal, "<<
    "para esta conversion el numero debera ser multiplo de 4,"<<
    "el programa falla para otro caso, en caso de que su numero no sea"<<
    " multiplo de 4 añada al incio la cantidad de ceros faltantes"<<endl;

    cin >> numero2;

    while (numero2[ i ] != '\0'){
        
        i++;
    }
    
    tam = i;
    string con[i];


    if(tam%4==0){
        cout<<"el numero ingresado en hexdecimal es: "<<endl;

        for (int j = 0; j < i; j+=4){
            for (int k = 0; k <= 4*16 ; k+=4){
                if ((numero2[j] == bina5[k]) && (numero2[j+1] == bina5[k+1]) && (numero2[j+2] == bina5[k+2]) && (numero2[j+3] == bina5[k+3])){

                    con[j/4]=hexa[k/4];
                    cout<<con[j/4];
                }   
            }
        }
        cout<<"\n";
    }
}

int main(){


    cout<< "ingrese el sistema en el que va a iniciar "<<
    "recuerde que todo debe estar en minusculas"<<endl;

    cin >> entrada;

    while (entrada != "binario" && entrada != "hexadecimal" && entrada != "decimal"){
        
        cout<<"ingreso un sistema erroneo, intente de nuevo excribiendo todo en minuscula "<<
        "recuerde que las opciones son decimal, hexadecimal y binario"<<endl;
        cin >> entrada;
    }

    cout<< "ingrese el sistema en el que se va a convertir su numero de partida, "<<
    "recuerde que todo debe estar en minusculas y deben ser diferentes"<<endl;

    cin >> salida;

    while ((salida != "binario" && salida != "hexadecimal" && salida != "decimal") || salida==entrada){
        
        cout<<"ingreso erroneamente, intente de nuevo excribiendo todo en minuscula "<<
        "recuerde que las opciones son decimal, hexadecimal y binario y debe ser diferente a la entrada"<<endl;
        cin >> salida;
    }

    if (entrada=="decimal" && salida == "hexadecimal"){

        dec_a_hex();
    }
    
    else if (entrada=="decimal" && salida == "binario"){
        
        dec_a_bi();
    }
    
    else if (entrada=="hexadecimal" && salida == "decimal") {

        hex_a_dec();
    }

    else if (entrada=="hexadecimal" && salida == "binario")    {

        hex_a_bin();
        
    }
       
    else if (entrada=="binario" && salida == "decimal"){
        bin_a_dec();
    }
    
    else{
        bin_a_hex();

    }
}