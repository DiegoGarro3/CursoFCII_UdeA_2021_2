#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include <fstream>

using namespace std;


//defining conversion functions
int dec_2_bin(int);
string dec_2_hex(int);
int  bin_2_dec(int);
int  hex_2_dec(string);
string bin_2_hex(int);
int hex_2_bin(string);


int main(){

    //initial message
    cout << "Recuerde ingresar sus datos en el archivo dataIn.out (solo convierte enteros positivos)" << endl;
    cout << "Presione Enter para continuar"<< endl;
    cin.ignore();

    
    //reading input data file

    ifstream dataIn( "dataIn.dat" ); 

    
    if ( dataIn.fail() )   
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    //creating ouput data file

    ofstream dataOut( "dataOut.dat" );

    if ( dataOut.fail() )      
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    string number;
    string sys1;
    string sys2;

    string decimal("decimal");
    string binario("binario");
    string hexadeci("Hex");

    //writing ouput file header
    dataOut << setw(10) << setiosflags(ios::left) << "Numero" << setw(13) << "Sistema_1" << setw(13) << "Sistema_2" << setw(13) << "# Convertido" << endl;
    
    //dataIn >> trash >> trash >> trash >> trash;
     while ( dataIn >> number >> sys1 >> sys2 ){
        
        //convert decimal to binary
        if(sys1 == decimal && sys2 == binario  ){
            
            int num = stoi(number); //convert string number to int
            int conv_num = dec_2_bin(num);

            //add data to ouput file 
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << conv_num << endl;
            
        }

        //convert decimal to hexadecimal
        else if (sys1 == decimal && sys2 == hexadeci)
        {
            int num = stoi(number); //convert string number to int
            string conv_num = dec_2_hex(num);

            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << conv_num << endl;
        }

        //decimal to decimal
        else if (sys1 == decimal && sys2 == decimal)
        {
            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << number << endl;
        }


        //convert binary to decimal
        else if(sys1 == binario && sys2 == decimal  ){
            
            int num = stoi(number); //convert string number to int
            int conv_num = bin_2_dec(num);

            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << conv_num << endl;

        }

        //convert binary to hexadecimal
        else if (sys1 == binario && sys2 == hexadeci)
        {
            int num = stoi(number); //convert string number to int
            string conv_num = bin_2_hex(num);

            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << conv_num << endl;
        }

        //binary to binary
        else if (sys1 == binario && sys2 == binario)
        {
            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << number << endl;
        }
        
        //convert hexadecimal to decimal
        else if (sys1 == hexadeci && sys2 == decimal)
        {
            
            int conv_num = hex_2_dec(number);

            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << conv_num << endl;
        }

        //convert hexadecimal to binary
        else if (sys1 == hexadeci && sys2 == binario)
        {
            
            int conv_num = hex_2_bin(number);

            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << conv_num << endl;
        }

        //hexadecimal to hexadecimal
        else if (sys1 == hexadeci && sys2 == hexadeci)
        {
            //add data to ouput file
            dataOut << setw(10) << setiosflags(ios::left) << number << setw(13) << sys1 << setw(13) << sys2 << setw(13) << number << endl;
        }

        }
        //close ouput file 
        dataOut.close();
        
        //end messeage
        cout << "Se terminó la conversión, revise el archivo dataOut.dat "<< endl;
        
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

