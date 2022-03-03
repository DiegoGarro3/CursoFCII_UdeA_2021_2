#include <iostream>
#include "Circular.h"

int main() {
    Circular circularMov = Circular(
        1.5, 2.0, 0.1, 3.2, 3.1415926/4.
    );
    circularMov.calculateMovement();
}