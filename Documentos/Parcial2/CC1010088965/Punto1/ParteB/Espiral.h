#ifndef ESPIRAL_H
#define ESPIRAL_H
#include <vector>

#include "../ParteA/Circular.h"

class Espiral : public Circular {
    public:
        Espiral(
            float, float, float, float, float, float, float
        );
        ~Espiral();

        void setZo(float);
        float getZo() const;

        void setVelocity(float);
        float getVelocity() const;

        void zpos(float);

        void calculateMovement();
        void writeToFile();

    private:
        float zo;
        float velocity;
        std::vector<float> zPositions;
};

#endif