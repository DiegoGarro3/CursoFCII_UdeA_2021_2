#include<cmath>
#include<iomanip>
#include "Ising .h"
using namespace std;


int main(){

    Ising Paramagnetico(40000,100,1.0,0.0,0,25.0,1.0);
    //Ising Ferromagnetico(40000,100,2.0,1,1);
    //Ising FerromagneticoB(40000,100,2.0,1,0);

    //Ising SnapShots1(80000,100,5,1,1,0.0,0.0);


    //SnapShots1.GetSpin();

    Paramagnetico.GetSolution();
    //Ferromagnetico.GetSolution();
    //FerromagneticoB.GetSolution();

    return 0;


}