//Preprocessors 
#include "Circular.h"
using namespace std;


//Implementations of the class Circular:

Circular::Circular(float rr, float ww, float aa, float tt, unsigned int nn){
    
    set_r(rr);
    set_w(ww);
    set_phase(aa);
    set_time(tt);
    set_steps(nn);
    set_FileName();
}

Circular::~Circular(){}

// Setting functions
void Circular::set_r(float rr)
{
    r = rr;
}
void Circular::set_w(float ww)
{
    w = ww;
}
void Circular::set_phase(float aa)
{
    a = aa;
}
void Circular::set_time(float tt)
{
    time = tt;
}
void Circular::set_steps(unsigned int nn)
{
    n = nn;
}

//Getting functions
float Circular::get_r()
{
    return r;
}
float Circular::get_w()
{
    return w;
}
float Circular::get_phase()
{
    return a;
}
float Circular::get_time()
{
    return time;
}
unsigned int Circular::get_steps()
{
    return n;
}

//Computing functions. Yield the x, y positions in a given time t
float Circular::xpos(float t)
{
    float x_position;
    x_position = r * cos( w*t + a);
    
    return x_position;
}
float Circular::ypos(float t)
{
    float y_position;
    y_position = r * sin( w*t + a);
    
    return y_position;
}


//Create and return an Output Document with < x, y > (OR < t, x, y >)

bool Circular::check_FileExistence(const string& filename)
{
    ifstream f(filename.c_str());
    return f.is_open();
}

void Circular::set_FileName()
{
    
    cout << "Please enter in the name of the file you'd like to create: ";
    cin >> filename;
}

string Circular::get_FileName()
{
    return filename;
}

void Circular::openFile( fstream& file )
{
    const bool file_exists = check_FileExistence(filename);
    if (!file_exists)
    {
        cout << "File " << filename << " not found." << endl;
        filename = get_FileName();
        ofstream dummy(filename.c_str());
        if (!dummy.is_open()) {
            cerr << "Could not create file." << endl;
            exit(1);
        }
        cout << "File created." << endl;
    }
                       
    file.open(filename.c_str(), ios::out | ios::trunc);
}

void Circular::get_File()
{   
    fstream file_output;
    openFile(file_output);
    
    float t = 0;
    float dt = time/n;
        
    while(t < time && file_output.is_open())
    {
       
        file_output << left
            //<< setw(8) << fixed << setprecision(2)<< t  //uncomment to print a file including time steps
            << setw(8) << fixed << setprecision(2) << xpos(t)
            << setw(8) << fixed << setprecision(2) << ypos(t)
            << endl;
        
        t += dt;
    }
    
    file_output.close();
}

