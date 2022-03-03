#include "ahorcado.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<cstdlib>
using namespace std;

Ahorcado::Ahorcado(void)
{
    srand(time(NULL));
    palabra=getpalabra();
};
Ahorcado::~Ahorcado(void)
{
};
string Ahorcado::getpalabra(void)
{
    int pal_n = rand()%51;
    int k=0;
    string palabra;
    string pal;
    ifstream archivo("Bank_word.dat"); 
    if ( archivo.fail() )    
    {
        cout <<"No se pudo abrir el archivo" << endl;
        exit( 1 );
    };
    while(archivo>> pal)
    {
        if(k==pal_n)
        {
            palabra=pal;
            break;
        }
        else
        k++;
    };
    archivo.close();
    return palabra;
};
void Ahorcado::playAhorcado(void)
{
    int k=0;
    string str =palabra;
    str.replace(str.begin(),str.end(),str.length(),'X');
    while(k<7)
    {   
        string str2=str;
        cout<<"Intentos = "<<7-k<<endl;
        cout<<"Palabra: "<< str<<endl;

        string letra;
        cout<<"Ingrese una letra: ";
        cin>>letra;
        for(int j=0;j<str.length();j++)
        {
            if(letra[0]==palabra[j])
            str[j]=letra[0];
        };
        if(str2!=str && str!=palabra)
        {
            cout<<"La letra: "<<letra<<" si se encuentra en la palabra"<<endl;
            cout<<endl;
            cout<<"Palabra: "<< str<< endl;
            char ele;
            cout<<endl;
            cout<<"¿Desea adivinar la palabra(arriesga un intento)?(s/n): ";
            cin>>ele;
            if(ele=='s')
            {
                string word;
                cout<<"Ingrese la palabra: ";
                cin>>word;
                if(word==palabra)
                str=word;
                else
                {
                    cout<<"Palabra incorrecta"<<endl;
                    k++;
                }
            };
        }
        else
        {
            k++;
            cout<<"La letra: "<<letra<< " no pertenece a la palabra."<< endl;
        }

        if(palabra==str)
        {
            cout<<endl;
            cout<<"GANASTE, la palabra correcta es: "<< str<<endl;
            break;
        };

        if(k==7)
        {
            cout<<endl;
            cout<<"AHORCADO: La palabra correcta era: "<< palabra<<endl;
            break;
        };
    cout<<endl;
    };
};