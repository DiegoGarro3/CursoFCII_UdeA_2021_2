// Preprocessors
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;



//Description of the class
class sysconvert{
    
    public:    
    
    sysconvert(string, char, char);
    
    string convert();   

    
        
    private:
    
    string number;
    char sys_init;
    char sys_end;
    
    string DectoHex(string);
    string DectoBin(string);
    
    string HextoDec(string);
    string HextoBin(string);
    
    string BintoDec(string);
    string BintoHex(string);    

    
    string cnumber;
    
    
        
};


