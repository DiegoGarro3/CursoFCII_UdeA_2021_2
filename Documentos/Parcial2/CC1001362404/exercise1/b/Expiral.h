#ifndef EXPIRAL_H
#define EXPIRAL_H

//Preprocessors 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include "../a/Circular.h"

using namespace std;


//Description of the class Circular
class Expiral : public  Circular
{    
    public:    
    
    Expiral(float, float, float, float, unsigned int, float = 0.0, float = 0.0); //constructor
    ~Expiral(); //destructor
    
    void set_z0(float);
    void set_vz0(float);
    
    float get_z0();
    float get_vz0();
    
    //metodos
    float zpos(float);
    
    void get_File();
    
    
        
    private:
    //protected:
    
    //miembros de la clase 
    float z0;
    float vz0;    
        
};
#endif