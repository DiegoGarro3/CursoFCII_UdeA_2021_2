#include <iostream>

using namespace std;


class estadistica {

    public:
        estadistica(double [], int); 
        double calcavg();
        double variance();        
    
    private:        
        int n;        
        double avg;
        double var;
        //At end because it's a flexible array (why??)
        double x[];
        
};