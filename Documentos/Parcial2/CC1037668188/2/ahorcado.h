#ifndef AHORCADO_H
#define AHORCADO_H

#include<string>
using namespace std;

class Ahorcado
{
    public:
    Ahorcado(void);
    ~Ahorcado();
    string getpalabra(void);
    void playAhorcado(void);
    void messege1(void);
    void messege2(void);
    void messege3(void);
    void messege4(void);

    private:
    string palabra;
};
#endif