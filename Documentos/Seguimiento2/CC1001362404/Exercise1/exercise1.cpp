#include <iostream>
#include "stad.h"

using namespace std;

    
int main(){
    
    const int size = 14;
    
    double t[size] = {89, 95, 72, 83, 99, 54, 86, 75, 92, 73, 79, 75, 82, 73};
    estadistica testvals(t, size);
    
    cout<<"The average of the data is "<<testvals.calcavg()<<endl;
    cout<<"And the variance is "<<testvals.variance()<<endl;
    
        
        
    return 0;
    
}
