#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <vector>

class Circular {
    public:
        Circular(
            float, float, float, float, float
        );
        ~Circular();
    
        void setRadius(float); 
        float getRadius() const;

        void setAngFreq(float); 
        float getAngFreq() const;

        void setDt(float); 
        float getDt() const;

        void setDuration(float); 
        float getDuration() const;

        void setPhase(float); 
        float getPhase() const;

        void setIntervalsNumber(int); 
        int getIntervalsNumber() const;

        float getXPosIdx(int);
        float getYPosIdx(int);

        void xpos(float);
        void ypos(float);
        void calculateMovement();

        void writeToFile();

    private:
        float radius;
        float angFreq;
        float dt;
        float duration;
        float phase;
        int intervalsNumber;
        std::vector<float> xPositions;
        std::vector<float> yPositions;
};

#endif