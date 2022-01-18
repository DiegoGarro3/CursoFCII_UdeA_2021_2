#include<iostream>
using namespace std;

#include "exponential.h"

int main() 
{   // create an object Exponential
    Exponential exponencial(4);
    // Calculate exponential(x,N), where x is de argument and N the accuracy 
    exponencial.getExp(-7,10);
    //print the result of the exponential
    exponencial.displayMessage(); 

    return 0;
}