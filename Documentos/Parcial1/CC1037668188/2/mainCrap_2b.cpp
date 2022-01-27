#include"crp.h"

int main()
{
    const int saldo_ini=1000000;
    int Saldo;
    int apuesta;
    int k=1;
    cout<<endl;
    cout<< "jUEGO: CRAPS."<<endl;
    cout<< "Bienvenido."<< endl;
    Craps Game;
    Saldo=saldo_ini;
    cout<< "Saldo en Banco: "<< Saldo<<endl;
    cout<<endl;
    while(Saldo>0)
    {
        int play;
        do{
        cout<<"Ingrese una apuesta: ";
        cin>> apuesta;}
        while(Saldo<apuesta || apuesta<0);
        cout<<endl;
        
        play=Game.PlayCraps();
        Saldo=Saldo+play*apuesta;
        cout<< "Saldo en banco: "<< Saldo<< endl;
        cout<<endl;
        if(k==1)
        {
            if(Saldo>(saldo_ini))
            {
                Game.message1();
                cout<<endl;
            }
            else{
            Game.message6();
            cout<<endl;
            };

        };
        if(Saldo<2*saldo_ini/10)
        {Game.message3();
        cout<<endl;};
        if(Saldo>=(2*saldo_ini))
        {
        Game.message5();
        cout<<endl;
        };
        if (Saldo>saldo_ini && Saldo<(2*saldo_ini) && k!=1)
        {Game.message4();
        cout<<endl;
        };
        k++;

    };
    Game.message2();


    return 0;
}