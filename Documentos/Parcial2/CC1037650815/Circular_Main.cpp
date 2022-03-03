#include "Circular_.h"
#include <math.h>
const float PI=3.1415;

int main()
{
  double r=1.0;
  double w=3.0;
  double t=5.0;
  double fase=PI/2;
  double  dt=0.1;
  double z0=1.0;
  double vz=1.0;
    

  Expiral E(r,w,t,fase,dt,z0,vz);

  E.zpos();
  E.ypos();
  E.xpos();
  
  return 0;
}
