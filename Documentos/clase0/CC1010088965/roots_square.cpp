#include <iostream>
#include <cmath>

using namespace std;

float * calculate_roots(float a, float b, float c) {
    static float roots[4];

    // Cuatro elementos correspondientes a las partes reales e imaginarias

    if (b*b >= 4*a*c) {
        roots[0] = (-b + sqrt(b*b - 4*a*c))/(2*a);
        roots[1] = 0;
        roots[2] = (-b - sqrt(b*b - 4*a*c))/(2*a);
        roots[3] = 0;
    } else {
        roots[0] = -b/(2*a);
        roots[1] = sqrt(4*a*c - b*b)/(2*a);
        roots[2] = -b/(2*a);
        roots[3] = -sqrt(4*a*c - b*b)/(2*a);
    }
    return roots;
}

int main(void) 
{
    float a, b, c;
    float *roots_dir;

    cout << "Fórmula cuadrática es ax²+bx+c." << endl;
    cout << "Escriba a: ";
    cin >> a;
    cout << "Escriba b: ";
    cin >> b;
    cout << "Escriba c: ";
    cin >> c;
    
    roots_dir = calculate_roots(a, b, c);
    cout << "La primera raíz es : " << *(roots_dir) << " + " << *(roots_dir+1) << "i" << endl;
    cout << "La segunda raíz es : " << *(roots_dir+2) << " + " << *(roots_dir+3) << "i" << endl;
    return 0;
}