#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

#include "Circular.h"

Circular::Circular(
    float radiusIn, float angFreqIn, float dtIn,
    float durationIn, float phaseIn
) {
    radius = radiusIn;
    angFreq = angFreqIn;
    dt = dtIn;
    duration = durationIn; 
    phase = phaseIn;

    intervalsNumber = static_cast<int>(duration/dt);
};
Circular::~Circular() {
    vector<float>().swap(xPositions);
    vector<float>().swap(yPositions);
};

void Circular::setRadius(float radiusIn) { radius = radiusIn; }; 
float Circular::getRadius() const { return radius; };

void Circular::setAngFreq(float angFreqIn) { angFreq = angFreqIn; };
float Circular::getAngFreq() const { return angFreq; };

void Circular::setDt(float dtIn) { dt = dtIn; }; 
float Circular::getDt() const { return dt; };

void Circular::setDuration(float durationIn) { duration = durationIn; }; 
float Circular::getDuration() const { return duration; };

void Circular::setIntervalsNumber(int intervalsNumberIn) { intervalsNumber = intervalsNumberIn; }; 
int Circular::getIntervalsNumber() const { return intervalsNumber;};

void Circular::setPhase(float phaseIn) { phase = phaseIn; }; 
float Circular::getPhase() const { return phase; };

float Circular::getXPosIdx(int idx) { return xPositions[idx]; };
float Circular::getYPosIdx(int idx) { return yPositions[idx]; };

void Circular::xpos(float t) {
    xPositions.push_back(radius*cos(angFreq*t + phase));
}
void Circular::ypos(float t) {
    yPositions.push_back(radius*sin(angFreq*t + phase));
}

void Circular::calculateMovement() {
    float t = 0.;
    for (size_t i = 0; i < intervalsNumber; i++) {
        xpos(t);
        ypos(t);
        cout << "t: " << t << ", x: " << xPositions[i] << ", y: " << yPositions[i] << endl;
        t += dt;
    }
};
