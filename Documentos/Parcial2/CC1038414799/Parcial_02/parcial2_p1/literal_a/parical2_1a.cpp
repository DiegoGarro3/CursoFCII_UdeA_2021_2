#include<cmath>
#include"circular.h"

using namespace std;


int main()
{   
    //Define Circular object
    Circular circMotion(1.5,2.0,M_PI/4.0,0.1,3.2); 
    circMotion.motion2D(); //Run the circular movement simulation

    return 0;
}

