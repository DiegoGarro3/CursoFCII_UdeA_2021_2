// Preprocessors
#include "sysconvert.h" //Calling the initialized class
using namespace std;

//constructor
sysconvert::sysconvert(string n, char sys1, char sys2){
    
    number = n;
    sys_init = sys1;
    sys_end = sys2;        
}

//method to get the value (string) in the new system (sys_end)
string sysconvert::convert(){
    
    if (sys_init == 'D'){
        
        if (sys_end == 'D'){
            cnumber = number;
        }
        
        else if(sys_end == 'B'){
            cnumber = DectoBin(number);
        }
        else if(sys_end == 'H'){
            cnumber = DectoHex(number);
        }
        else {
            cnumber = "Invalid";
        }
    }
    
    else if(sys_init == 'B'){
        
        if (sys_end == 'B'){
            cnumber = number;
        }
        
        if (sys_end == 'D'){
            cnumber = BintoDec(number);
        }
        else if(sys_end == 'H'){
            cnumber = BintoHex(number);
        }
        else {
            cnumber = "Invalid";
        }
    }

    else if(sys_init == 'H'){
        
        if (sys_end == 'H'){
            cnumber = number;
        }
        
        if (sys_end == 'D'){
            cnumber = HextoDec(number);
        }
        else if(sys_end == 'B'){
            cnumber = HextoBin(number);
        }
        else {
            cnumber = "Invalid";
        }
    }
    
    else{
        cnumber = "Invalid";
    }
    
    return (cnumber);
}

////////////////////////////////////////////////////////////////7

//Converting function

string sysconvert::DectoHex(string n){
    
    int n_dec = stoi(n);
    
    string n_hex;
    int q;
    
    const char Hex_values[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    while( n_dec != 0 ){
      q = n_dec % 16; 
      n_hex = Hex_values[q] + n_hex;
      n_dec/=16;  
    }
  
    return (n_hex);
}


string sysconvert::DectoBin(string n){
    
    string n_bin;
    int n_dec = stoi(n);
    int q;
    
    while(n_dec != 0){
        q = n_dec%2;       
        n_bin = to_string(q) + n_bin;
        n_dec /= 2;
    }
        
    return (n_bin);
}


string sysconvert::HextoDec(string n){

    int n_dec = 0;
    int i, j, position;
    
    const string Hex_values = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    for(i = (n.length() - 1); i >= 0; i--){
        j = (n.length() - 1) - i;
        
        position = Hex_values.find_first_of(n[i]);
        
        n_dec += pow(16,j)*position;
            
    }
    
    
    return (to_string(n_dec));
}

string sysconvert::HextoBin(string n){
    
    string n_hex;
    string n_bin = HextoDec(n);
    n_bin = DectoBin(n_bin);
    
    return (n_bin);
}


string sysconvert::BintoDec(string n){
    
    int n_dec = 0;
    int i, j, p;
    
    for(i = (n.length() - 1); i >= 0; i--){
        j = (n.length() - 1) - i;
        p = (int)(n[i] - '0');
        
        n_dec += pow(2,j)*p;
    }
    
    
    return (to_string(n_dec));
}
string sysconvert::BintoHex(string n){
    
    string n_hex;
    n_hex = BintoDec(n);
    n_hex = DectoHex(n_hex);
    
    return (n_hex);
}





