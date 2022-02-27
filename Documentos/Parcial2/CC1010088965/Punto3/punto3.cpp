#include "Jacobi.h"
#include "SOR.h"
#include <array>
#include <iostream>

using namespace std;

int main() {
    vector<vector<float>> coeffs = {
        {10, -1, 2, 0, 6},
        {-1, -11, -1, 3, 25},
        {2, -1, 10, -1, -11},
        {0, 3, -1, 8, 6}
    };

    float jacobiError = 0.0000001;
    float sorError = 0.0001;
    float relax = 1.25;

    cout << "==============================================" << endl;
    Jacobi jacobi = Jacobi(coeffs, jacobiError);
    jacobi.solve();
    cout << "==============================================" << endl;
    SOR sor = SOR(coeffs, sorError, relax);
    sor.solve();
    cout << "==============================================" << endl;
}