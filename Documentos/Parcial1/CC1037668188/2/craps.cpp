#include"crp.h"

Craps::Craps(void)
{

};

int Craps::PlayCraps(void)
{
    srand(time(NULL));
    int dado1, dado2, suma;
    int ganar=2;
    int i=1;
    int punto;
    cout<< "TIRO   DADO 1   DADO 2    SUMA "<<endl;
    cout<< "----   ------   ------    -------"<<endl;  
    do
    {
        dado1=1+rand()%(6);
        dado2=1+rand()%(6);
        suma=dado1+dado2;
        if(i==1)
        {
            punto=suma;
            if(suma==7 || suma==11)
            {
                ganar=1;
            };
            if(suma==2 || suma==3 || suma==12)
            {
                ganar=-1;
            };
        }
        else
        {
            if(suma==7)
            ganar=-1;
            if(suma==punto)
            ganar=1;
        }
        if(i==1 && ganar==2)
        {cout << setw(3) << i << "   "
        << setw(5) << dado1 << "   "
        << setw(5) << dado2  << "   "
        << setw(6)<< suma <<" :punto"<< endl;}
        else
        {
        cout << setw(3) << i << "   "
        << setw(5) << dado1 << "   "
        << setw(5) << dado2  << "   "
        << setw(6) << suma << endl;
        }
        i++;
    }
    while(ganar==2);
    cout<<endl;
    
    if (ganar==1)
    cout<<"¡GANASTE!"<<endl;
    else
    {
        if(i==2)
        cout<<"CRAPS: PERDISTE"<<endl;
        else
        cout<<"PERDISTE"<<endl;
    }
    cout<<endl;
    return ganar;
};

void Craps::message1()
{
    cout<< "Suerte de principiante, ¡Adelante vamos a apostar más!"<< endl;
};

void Craps::message2()
{
    cout<<"Lo siento, te quedaste sin fondos. "<<endl;
};
void Craps::message3()
{
    cout<<"Te estas quedando sin dinero, piensalo."<< endl;
};
void Craps::message4()
{
    cout<< "Vas ganando, sigue jugando."<<endl;
};
void Craps::message5()
{
    cout<<"Fabuloso: has ganado mas del doble del saldo inicial, ya es tiempo de cambiar las fichas por dinero, piensalo."<<endl;
};
void Craps::message6()
{
    cout<<"Animo es la primer apuesta, vas a romperla"<<endl;
};






