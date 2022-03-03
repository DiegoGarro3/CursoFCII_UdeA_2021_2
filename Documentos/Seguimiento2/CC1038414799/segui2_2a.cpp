#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;

//defining conversion functions
int dec_2_bin(int);
string dec_2_hex(int);
int  bin_2_dec(int);
int  hex_2_dec(string);
string bin_2_hex(int);
int hex_2_bin(string);


int main(){
    
    int op1; //Initial system option
    int op2; //Final system option

    //Interface

    cout << "Este programa permite convertir enteros positivos entre diferentes sistemas"<< endl;
    cout << "Ingrese el sistema inicial (1: Decimal, 2: Hexadecimal, 3: Binario): ";
    cin >> op1;

    cout << "Ingrese el sistema final (1: Decimal, 2: Hexadecimal, 3: Binario): ";
    cin >> op2;

    if(op1==2){
        
        //if initial system is hexadecimal recives a string

        string n_in;
        cout << "Ingrese el número a convertir (si es hexadecimal use todo mayusculas): ";
        cin >> n_in;
        cout << endl;

        //select hexa to deci
        if (op2==1)
        {
            cout << "El valor en el nuevo sistema númerico: " << hex_2_dec(n_in) << endl;
        }


        //select hexa to hexa
        else if (op2==2)
        {
            cout << "El valor en el nuevo sistema númerico: " << n_in << endl;
        }

        //select hexa to binary
        else if (op2==3)
        {
            cout << "El valor en el nuevo sistema númerico: " << hex_2_bin(n_in) << endl;
        }

        else{

            //final number system error
            cout << "Revise la selección del sistema final, fue incorrecta ";
        }
        


    }
    
    else if (op1==1 || op1==3  ){

        //if initial system is binary or decimal recives an integer
        
        int n_in;
        cout << "Ingrese el número a convertir: ";
        cin >> n_in;
        cout << endl;

        //bin to bin
        if (op1==1 && op2==1 )
        {
           cout << "El valor en el nuevo sistema númerico: " << n_in << endl;
        }

        //bin to hex
        else if (op1==1 && op2==2 )
        {
           cout << "El valor en el nuevo sistema númerico: " << dec_2_hex(n_in) << endl;
        }

        //dec to bin
        else if (op1==1 && op2==3 )
        {
           cout << "El valor en el nuevo sistema númerico: " << dec_2_bin(n_in) << endl;
        }


        //bin to dec
        else if (op1==3 && op2==1 )
        {
           cout << "El valor en el nuevo sistema númerico: " << bin_2_dec(n_in) << endl;
        }

        
        //bin to hex
        else if (op1==3 && op2==2 )
        {
           cout << "El valor en el nuevo sistema númerico: " << bin_2_hex(n_in) << endl;
        }

        
        //bin to bin
        else if (op1==3 && op2==3 )
        {
           cout << "El valor en el nuevo sistema númerico: " << n_in << endl;
        }

        else{
            
            //final number system error
            cout << "Revise la selección del sistema final, fue incorrecta ";
        }
    
    }

    else{
        //final number system error
        cout << "Revise la selección del sistema inicial, fue incorrecta";
    }

}

//convertion function from decimal to binary
int  dec_2_bin(int outient){

    int div;
    vector<int> remainders; //vector to save division remainders

    while(outient>=0){
        
        div = outient/2;
        remainders.push_back(outient%2);
        outient = div;
        

        if(outient == 0){
            break;
        }

    }
    int sum=0;

    for(int i = remainders.size();i>0;i--)
    {
        
        sum += remainders[i-1] * pow(10,i-1);

    }

    return sum; //binary number
}


//convertion function from decimal to hexadecimal


string  dec_2_hex(int outient){

    int div;
    vector<int> remainders; //vector to save division remainders

    while(outient!=0){
        div = outient/16;
        remainders.push_back(outient%16);
        outient = div;

    }
    
    //hexadecimal digits
    string hexa[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    
    string result; 
    
    for(int i = remainders.size();i>0;i--)
    {
        
       result += hexa[remainders[i-1]];
    
    }

    return result; //hexadecimal number
}


//convertion function from binary to decimal
int bin_2_dec(int number){


    int i=0;
    int sum=0;

    while (number > 0)
    {
        
        int digit = number%10;
        number /= 10;
        sum += digit*pow(2,i);
        i++;
        
        
    }

    return sum; //decimal number

}


//convertion function from hexadecimal to decimal
int hex_2_dec(string number){

    //hexadecimal digits
    char hexa[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


    int sum = 0;
    int x= 0;
    

    for(int i=number.length()-1;i>=0;i--){

        for(int j = 0; j<16; j++){
            
            if (number[i]==hexa[j]){
                sum += j*pow(16,x);
                x+=1;
            }
        }
    }
    
    return sum; //decimal number
}


//convertion function from binary to hexadecimal
string bin_2_hex(int binary){
    
    //convert the binary to decimal
    int deci=bin_2_dec(binary);
    //convert the decimal to hexadecimal
    string hexa = dec_2_hex(deci);
    return hexa; //hexadecimal number
}


//convertion function from hexadecimal to binary
int hex_2_bin(string hexa){

    //convert the hexadecimal to decimal
    int deci=hex_2_dec(hexa);

    //convert the decimal to binary
    int bin=dec_2_bin(deci);

    return bin; //binary number
}

