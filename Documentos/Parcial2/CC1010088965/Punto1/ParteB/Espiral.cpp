#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#include "Espiral.h"

Espiral::Espiral(
    float radiusIn, float angFreqIn, float dtIn,
    float durationIn, float phaseIn, float zoIn, float velocityIn
) : Circular(radiusIn, angFreqIn, dtIn, durationIn, phaseIn) {
    zo = zoIn;
    velocity = velocityIn;
};
Espiral::~Espiral() {
    vector<float>().swap(zPositions);
}

void Espiral::setZo(float zoIn) { zo = zoIn; }; 
float Espiral::getZo() const { return zo; };

void Espiral::setVelocity(float velocityIn) { velocity = velocityIn; };
float Espiral::getVelocity() const { return velocity; };

void Espiral::zpos(float t) {
    zPositions.push_back(zo + velocity*t);
};

void Espiral::calculateMovement() {
    float t = 0.;
    for (size_t i = 0; i < getIntervalsNumber(); i++) {
        xpos(t);
        ypos(t);
        zpos(t);
        cout << "t: " << t << ", x: " << getXPosIdx(i) << ", y: " << getXPosIdx(i) << ", z: " << zPositions[i] << endl;
        t += getDt();
    }
};

void Espiral::writeToFile() {
    float t = 0.;
    ofstream fileOut("datos.txt");
    fileOut << "t x y z" << endl;
    for (size_t i = 0; i < getIntervalsNumber(); i++) {
        fileOut << t << " " << getXPosIdx(i) << " " << getYPosIdx(i) << " " << zPositions[i] << endl;
        t += getDt();
    }
}
