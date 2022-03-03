#include <string> 
#include "ClassCircular.h"
using namespace std;

class Espiral : public Circular // hacemos la herencia con ":"
{
 private:
        float z0;
        float vz;
 public:

        Espiral( float, float, float, float, float, float, float);//constructor
        ~Espiral();// destructor
        
        void establecerz0(float); // establecemos la posición inicial en z
        float obtenerz0();
        
        void establecervz(float); // establecemos la velocidad en Z
        float obtenervz();
        
        vector<float>  zpos(float,float); // nuestro vector de la posiciòn en Z de la partícula
};
