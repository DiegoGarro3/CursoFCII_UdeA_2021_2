#include "Expiral.h"

using namespace std;



int main()
{
    float radio=3, frequency=0.3, phase=M_PI*0.5, time=60*3;
    unsigned int steps=3000;
    float z = 1.5, vz = 5;
    
    Expiral particle(radio, frequency, phase, time, steps, z, vz);
    particle.get_File();
    
    
    return 0;
    
}
