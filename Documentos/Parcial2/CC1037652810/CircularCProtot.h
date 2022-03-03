#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <vector>

using namespace std;

class Circular {	
  public:

	Circular(double, double, double, double, double); //constructor
	~Circular(); //destructor
		

	double getRadio() const;
	double getDeltat() const;
	double getTtotal() const;
	double getOmega() const;
	double getFase() const;

        vector<double> Time();//public functions
	vector<double> Xpos();
	vector<double> Ypos();

  private:	

	const double Radio;
	const double Deltat;
	const double Ttotal;
	const double W;
	const double Fase;
        
        vector<double> timevect; //vectors to fill
        vector<double> xpos;
        vector<double> ypos;      		

};
#endif
