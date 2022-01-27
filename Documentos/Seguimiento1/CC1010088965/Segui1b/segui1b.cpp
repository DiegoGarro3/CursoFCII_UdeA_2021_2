#include "Exponential.h"

int main() {
    // A continuación tres ejemplos de la exponencial funcionando
    
    // e^(4.5) con 9 términos calculados
    Exponential exponential_4_5__9(4.5, 9);
    exponential_4_5__9.calculateExponential();
    exponential_4_5__9.showResult();

    // e^(7) con 10 términos calculados
    Exponential exponential_7__10(7, 10);
    exponential_7__10.calculateExponential();
    exponential_7__10.showResult();

    // e^(2.3) con 5 términos calculados
    Exponential exponential_2_3__5(2.3, 5);
    exponential_2_3__5.calculateExponential();
    exponential_2_3__5.showResult();

    // e^(-3.2) con 12 términos calculados
    Exponential exponential_n3_2__12(-3.2, 12);
    exponential_n3_2__12.calculateExponential();
    exponential_n3_2__12.showResult();

    return 0;
}