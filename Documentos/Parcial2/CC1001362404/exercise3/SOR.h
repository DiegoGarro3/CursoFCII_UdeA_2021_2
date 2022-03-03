#ifndef SOR_H
#define SOR_H


#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>


using namespace std;

#include "SOR.h"

class SOR {

    public:
    
        SOR(vector<vector<float>>, float, float);
        ~SOR();

        void set_Coefficients(vector<vector<float>>);
        void set_Degree(float);
        void set_Error(float);
        void set_Relax(float);
        
        vector<vector<float>> get_Coefficients() const;        
        float get_Degree() const;        
        float get_Error() const;        
        float get_Relax() const;
        
	bool check_FileExistence(const string& filename);
	void openFile( fstream& file );      
	void set_FileName();
	string get_FileName();         

        void solution();

    private:
    
        vector<vector<float>> coeffs;
        float degree;
        float error;
        float relax;
        string filename;
};

#endif
