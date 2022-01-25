#include <iostream>
#include <iomanip>

using namespace std;

float f(float x, float y) {
    return y - x*x + 1;
}

float modifiedEulerCycle(float x, float h) {
    static float y = 0.5;

    y = y + h*f(x + 0.5 * h, y + 0.5 * h * f(x, y));
    return y;
}

float rungeKutta4Cycle(float x, float h) {
    static float y = 0.5;
    float K1, K2, K3, K4;

    K1 = h * f(x, y);
    K2 = h * f(x, y + 0.5 * K1);
    K3 = h * f(x, y + 0.5 * K2);
    K4 = h * f(x, y + K3);
    y = y + (1. / 6.) * (K1 + 2 * K2 + 2 * K3 + K4);

    return y;
}


int main() {
    float x0 = 0, xf = 2, h = 0.01, y0 = 0.5;
    float x;

    cout << "Posicion inicial: " << x0 << endl;
    cout << "Posicion final: " << xf << endl;
    int n = static_cast<int>((xf - x0) / h);
    cout << "Numero de pasos de tiempo: " << n << endl;

    cout << "======================================" << endl;
    cout << "           X|  ModEuler-Y|       RK4-Y" << endl;
    cout << "--------------------------------------" << endl;

    x = x0;
    for (int i = 0; i < n; i++)
    {
        cout << setw(12) << x << "|" << setw(12) << modifiedEulerCycle(x, h) << "|" << setw(12) << rungeKutta4Cycle(x, h) << endl;
        x = x + h;
    }

    cout << "======================================" << endl;
}
