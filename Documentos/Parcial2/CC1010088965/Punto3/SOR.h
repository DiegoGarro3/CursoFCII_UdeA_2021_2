#ifndef SOR_H
#define SOR_H
#include <vector>

using namespace std;

#include "SOR.h"

class SOR {
    public:
        SOR(vector<vector<float>>, float, float);
        ~SOR();

        void setCoeffs(vector<vector<float>>);
        vector<vector<float>> getCoeffs() const;

        void setDegree(float);
        float getDegree() const;

        void setError(float);
        float getError() const;

        void setRelax(float);
        float getRelax() const;

        void solve();

    private:
        vector<vector<float>> coeffs;
        float degree;
        float error;
        float relax;
};

#endif