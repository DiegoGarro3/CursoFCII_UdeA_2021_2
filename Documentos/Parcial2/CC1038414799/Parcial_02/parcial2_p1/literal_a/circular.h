#ifndef CIRCULAR_H
#define CIRCULAR_H

class Circular
{

public:    

    Circular(double = 0.0, double = 0.0, double = 0.0, double =0.0, double =0.0);
    ~Circular();


    //Set functions
    void setRadius(double);
    void setFrecuency(double);
    void setPhase(double);
    void setDt(double);
    void setTime(double);
    


    //get functions
    double getRadius() const;
    double getFrecuency() const;
    double getDt() const;
    double getTime() const;
    double getPhase() const;

    //equations of motions
    double xpos(double) const;
    double ypos(double) const;
    void motion2D() const;

private:

    double radius;
    double frecuency;
    double dt; //delta of time
    double time;
    double phase; 
};

#endif