#include <iostream>
#include <iomanip>
#include <fstream> // flujo de archivo
#include <sstream> 
#include <iomanip>
#include <math.h>

using namespace std;


#include "Spiralcprotot.h"

int main()
{
	
  double r=1.5;
  double dt=0.1;
  double T=3.2;
  double w=2.0;
  double thet=M_PI/4;

  // establece el formato de salida de punto flotante
  cout << fixed << setprecision( 4 );
  cout << endl;
  Spiral spiral( 1,2,r,dt,T,w,thet);
 
 return 0;
}
