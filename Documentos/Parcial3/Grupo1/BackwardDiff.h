#include <vector>

using namespace std;

class BackwardDiff{
    public:
        BackwardDiff(float, float, int, float, float);

        void setf(float (*)(float));

        vector<vector<float>> getSolution();

        void saveFile(vector<vector<float>>);

    private:
        float alpha;
        float l;
        int m;
        float k;
        float tf;

        float (*f) (float); 
};