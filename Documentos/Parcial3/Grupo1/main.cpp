#include <iostream>
#include <iomanip>
#include "ForwardDiff.h"
#include "BackwardDiff.h"
#include "CrankNicolson.h"
#include <cmath>
using namespace std;

float func(float x){
    return sin(M_PI*x);
}

int main() {
    ForwardDiff forwardDiff(1., 1., 10, 0.01, 0.5);
    forwardDiff.setf(&func);
    forwardDiff.getSolution();

    BackwardDiff backwardDiff(1., 1., 10, 0.01, 0.5);
    backwardDiff.setf(&func);
    backwardDiff.getSolution();

    CrankNicolson crankNicolson(1., 1., 10, 0.01, 0.5);
    crankNicolson.setf(&func);
    crankNicolson.getSolution();
} 