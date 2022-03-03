
#include<iostream>
#include<iomanip>
#include<math.h>


// Definiendo funciones
#define f1(x1,x2,x3,x4)  (6+x2-2*x3)/10
#define f2(x1,x2,x3,x4)  (-25-x1-x3+3*x4)/11
#define f3(x1,x2,x3,x4)  (-11-2*x1+2*x2+x4)/2
#define f4(x1,x2,x3,x4)  (6-3*x2+x3)/8
using namespace std;


int main()
{
 float x1_0=0, x2_0=0, x3_0=0, x4_0=0, x1_1, x2_1, x3_1, x4_1;
 int step=1;

 cout<< setprecision(6)<< fixed;
 cout<< endl<<"Count\tx1\t\tx2\t\tx3\t\tx4"<< endl;
 
 do
 {
  x1_1 = f1(x1_0,x2_0,x3_0,x4_0);
  x2_1 = f2(x1_0,x2_0,x3_0,x4_0);
  x3_1 = f3(x1_0,x2_0,x3_0,x4_0);
  x4_1 = f4(x1_0,x2_0,x3_0,x4_0);
  cout<< step<<"\t"<< x1_1<<"\t"<< x2_1<<"\t"<< x3_1<<"\t"<< x4_1<<  endl;

  step++;

  /* Iteraciones*/
  x1_0 = x1_1;
  x2_0 = x2_1;
  x3_0 = x3_1;
  x4_0 = x4_1;
 }

 while (step<10);

 cout<< endl<<"Solution: x1 = "<< x1_1<<", x2 = "<< x2_1<<" and x3 = "<< x3_1<<", x4= "<< x4_1;
 

 return 0;
}


