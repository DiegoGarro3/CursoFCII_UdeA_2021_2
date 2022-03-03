#include"ahorcado.cpp"

int main()
{
    int i=1;
    while(i==1)
    {
        Ahorcado game;
        game.playAhorcado();
        cout<<endl;
        cout<<"Quiere volver a jugar? (s/n):"<< endl;
        char k;
        cin>>k;
        if(k=='n')
        {
            i=0;
        };
        if(k=='s')
        {
            game.~Ahorcado();
            i==1;
        };
        if(k!='s' && k!='n')
        {
            game.~Ahorcado();
            break;
        };
    };
    return 0;
};