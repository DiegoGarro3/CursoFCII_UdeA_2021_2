#include "Jacobi.h"
#include "SOR.h"

using namespace std;

int main() {
    vector<vector<float>> coeffs_test = {
        {10, -1, 2, 0, 6},
        {-1, 11, -1, 3, 25},
        {2, -1, 10, -1, -11},
        {0, 3, -1, 8, 6}
    };

    float Tol = 1e-4;
    float relax = 8e-1;

    cout << "-------------------------------------------------------------------------" << endl;
    Jacobi jacobi(coeffs_test, Tol);
    jacobi.solution();
    cout << "-------------------------------------------------------------------------"<< endl;
    SOR sor(coeffs_test, Tol, relax);
    sor.solution();
    cout << "-------------------------------------------------------------------------" << endl;
    
    return 0;
}
