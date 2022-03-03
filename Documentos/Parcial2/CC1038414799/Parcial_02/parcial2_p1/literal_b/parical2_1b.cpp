#include<cmath>
using namespace std;

#include "expiral.h"


int main()
{   
    //Expiral object
    Expiral expMotion(1.5,2.0,M_PI/4.0,0.1,3.2,0.5,2.1);
    expMotion.motion3D();//Runing the movement simulation

    return 0;
}