#include <iostream>

using namespace std;


int factorial(int);

int main(){   
    
    int num;
    
    cout<< "Input a number" << endl;
    cin>>num;
        
    cout<< "The factorial of " << num << "! = " << factorial(num);
    
    return 0;
        
};

int factorial(int number){
    
    int product = 1;
    
    if(number==0 or number==1){
        product=1;
    }
    else{
        for(int i=1; i <= number; ++i){
           product*=i;
        }
        
    }
    return product;
        
}



