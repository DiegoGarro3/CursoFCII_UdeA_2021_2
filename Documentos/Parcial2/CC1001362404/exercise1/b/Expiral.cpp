#include "Expiral.h"
using namespace std;




Expiral::Expiral(float rr, float ww, float aa, float tt, unsigned int nn, float zz_0, float vv_z)
: Circular(rr, ww, aa, tt, nn)
{
    set_z0(zz_0);
    set_vz0(vv_z);
}

Expiral::~Expiral(){
}

void Expiral::set_z0(float zz_0)
{
    z0 = zz_0; 
}
void Expiral::set_vz0(float vv_z)
{
    vz0 = vv_z;
}
float Expiral::get_z0()
{
    return z0;
}
float Expiral::get_vz0()
{
    return vz0;
}

float Expiral::zpos(float t)
{
    float z_position;
    z_position = z0 + vz0*t;
    
    return z_position;
}

void Expiral::get_File()
{
    Circular::get_File();
    
    ifstream input(Circular::get_FileName());
    string line;
    vector<string> oldlines;
    
    while(getline(input,line))
    {
        oldlines.push_back(line);
    }
    input.close();
    
    
    ofstream output(Circular::get_FileName());
    
    /*
    float t = 0;
    float dt = Circular::get_time() / Circular::get_steps();
    
    for(size_t i=0; i<oldlines.size(); i++)
    {
        output << oldlines[i]
            << setw(8) << fixed << setprecision(2) << zpos(t)
            << endl;
        t += dt;
    }*/
    
    for(size_t i=0; i<oldlines.size(); i++)
    {
        float t = stof( oldlines[i].substr(0, oldlines[i].find_first_of(" ")) );
        output << left << oldlines[i]
            << setw(8) << fixed << setprecision(2) << zpos(t)
            << endl;
    }        
        
    output.close();
}

