#include <vector>

using namespace std;

class Poisson{

public:

    Poisson(float,float,float,float,float,float,int);

    //Set Functions
    void setLeft(float);
    void setRight(float);
    void setDown(float);
    void setUp(float);
    void setn(float);
    void setm(float);
    void setN(float);
    
    void setBRight(float (*)(float , float));
    void setBLeft(float (*)(float , float));
    void setBDown(float (*)(float , float));
    void setBUp(float (*)(float , float));
    void setF(float (*)(float , float));
    

/*

    //Get functions
    float GetLeft(float) const;
    float GetRight(float) const;
    float GetDown(float) const;
    float GetUp(float) const;
    float Getn(float) const;
    float Getm(float) const;
    float GetN(float) const;
    */


    //FUNCTIONS

    

    float G(float, float);

    float F(float,float);

    vector<vector<float>> GetSolution();

    void SaveFile(vector<vector<float>>,vector<float>,vector<float>);





private:
    float n;
    float m;
    float a;
    float b;
    float c;
    float d;
    float N;
    float (*BoundaryUp)(float,float );
    float (*BoundaryDown)(float,float);
    float (*BoundaryRight)( float,float);
    float (*BoundaryLeft)(float,float);  
    float (*Source)(float,float); 

};