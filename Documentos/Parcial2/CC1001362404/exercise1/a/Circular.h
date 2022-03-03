#ifndef CIRCULAR_H
#define CIRCULAR_H

//Preprocessors 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;


//Description of the class Circular
class Circular{
    
    public:    
    
    Circular(float, float, float, float, unsigned int); //constructor
    
    void set_r(float);
    void set_w(float);
    void set_phase(float);
    void set_time(float);
    void set_steps(unsigned int);
    void set_FileName();
    
    float get_r();
    float get_w();
    float get_phase();
    float get_time();
    unsigned int get_steps();
    string get_FileName();
    
    bool check_FileExistence(const string& filename);
    void openFile( fstream& file );
        
    void get_File();
    
    
    //Position functions
    float xpos(float);
    float ypos(float); 
    
    ~Circular(); //destructor
    
        
    private:
    //protected:
    
    //miembros de la clase 
    float r;
    float w;
    float a;
    float time;
    unsigned int n;
    string filename;
    
        
};
#endif
