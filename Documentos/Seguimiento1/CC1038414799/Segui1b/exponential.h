class Exponential
{
public:
    Exponential(unsigned int); //Initialize N
    unsigned long factorial( unsigned int ); //Calculate the factorial of an integer
    double getExp( double , unsigned int  ); //Calculate the exponential of a double with a int of precision
    void displayMessage();

private:
    double x;       //Double to calculate exponetial e^x
    unsigned int N; //Precision-order of Tylor series
    double expx;    //Result of exponential
};
