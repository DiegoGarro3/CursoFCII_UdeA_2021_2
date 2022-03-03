#include <iostream>
#include "Espiral.h"

int main() {
    Espiral espiralMov = Espiral(
        1.5, 2.0, 0.1, 3.2, 3.1415926/4., 0.5, 2.1
    );
    espiralMov.calculateMovement();
    espiralMov.writeToFile();
}