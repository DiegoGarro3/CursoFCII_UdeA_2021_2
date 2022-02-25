/*#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
*/
//#include "Expiral.h"

#include "Circular.h"

using namespace std;



int main()
{
    float radio=3, frequency=0.3, phase=M_PI*0.5, time=60*3;
    unsigned int steps=20;
    
    Circular particle(radio, frequency, phase, time, steps);
    particle.get_File();
    
    
    return 0;
    
}

