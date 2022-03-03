#ifndef JACOBI_H
#define JACOBI_H

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


class Jacobi {

    public:
    
        Jacobi(vector<vector<float>>, float);
        ~Jacobi();

        void set_Coefficients(vector<vector<float>>);
        void set_Degree(float);
        void set_Error(float);
        
        
        vector<vector<float>> get_Coefficients() const;        
        float get_Degree() const;        
        float get_Error() const;
        
	bool check_FileExistence(const string& filename);
	void openFile( fstream& file );      
	void set_FileName();
	string get_FileName(); 

        void solution();

    private:
    
        vector<vector<float>> coeffs;
        float degree;
        float error;
        string filename;
};

#endif
