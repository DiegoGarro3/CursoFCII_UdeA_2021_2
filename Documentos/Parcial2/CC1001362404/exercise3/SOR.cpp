#include "SOR.h"

using namespace std;


SOR::SOR(vector<vector<float>> coeffs_input, float error_input, float relax_input) {

	set_Coefficients(coeffs_input);
	set_Degree(coeffs_input.size());
	set_Error(error_input);
	set_Relax(relax_input);
	set_FileName();
}

SOR::~SOR() {
}


void SOR::set_Coefficients(vector<vector<float>> coeffs_input) {
	coeffs = coeffs_input; 
}
void SOR::set_Degree(float degreeIn) { 
	degree = degreeIn;
}
void SOR::set_Error(float error_input) { 
	error = error_input; 
}
void SOR::set_Relax(float relax_input) { 
	relax = relax_input; 
}


vector<vector<float>> SOR::get_Coefficients() const { 
	return coeffs; 
}
float SOR::get_Degree() const { 
	return degree;
}
float SOR::get_Error() const { 
	return error; 
}
float SOR::get_Relax() const { 
	return relax; 
}

///////////////////////////////////////////////////////////////
//Create and return an Output Document with < x0, x1, x2, x3 >

bool SOR::check_FileExistence(const string& filename)
{
    ifstream f(filename.c_str());
    return f.is_open();
}

void SOR::set_FileName()
{
    
    cout << "Please enter in the name of the file you'd like to create for SOR solver: ";
    cin >> filename;
}

string SOR::get_FileName()
{
    return filename;
}

void SOR::openFile( fstream& file )
{
    const bool file_exists = check_FileExistence(filename);
    if (!file_exists)
    {
        cout << "File " << filename << " not found." << endl;
        filename = get_FileName();
        ofstream dummy(filename.c_str());
        if (!dummy.is_open()) {
            cerr << "Could not create file." << endl;
            exit(1);
        }
        cout << "File created.\n" << endl;
    }
                       
    file.open(filename.c_str(), ios::out | ios::trunc);
}

////////////////////////////////////////////////////////////

void SOR::solution() {
    cout << "\nSTARTING SOR ... \n" << endl;
    vector<float> errors(degree);
    vector<float> pseudo_results(degree, 0);
    vector<float> results(degree, 0);
        
    fstream file_output;
    openFile(file_output); 
    
    bool non_precise = true;

    while (non_precise){
        for (size_t i = 0; i < degree; i++) {
            results[i] = coeffs[i][degree];
            for (size_t j = 0; j < degree; j++) {
                if (i != j) {
                    results[i] -= coeffs[i][j]*pseudo_results[j];
                }
            }
            results[i] *= (relax / coeffs[i][i]);
            results[i] += (1 - relax) * pseudo_results[i];
            cout << "x" << i << " = " << left << setw(10) << fixed << setprecision(6) << results[i] << "| ";
            
            ///
            file_output << left 
                        << setw(10) << fixed << setprecision(6) << results[i];            
        }
        non_precise = false;
        for (size_t i = 0; i < degree; i++) {
            errors[i] = fabs(results[i] - pseudo_results[i]);
            if (errors[i] > error) {
                non_precise = true;
            };
            pseudo_results[i] = results[i];
        }
        cout << endl;
        ///
        file_output << endl;
    }
     
    file_output.close();
    cout << "\nSOR has already finished ..." << endl;    
    cout << "Solution \n[";
	
    for (std::vector<float>::iterator it = results.begin(); it != results.end(); ++it){
		cout << setw(10) << fixed << setprecision(6) << *it;
    }
    cout << "]\n";
}



