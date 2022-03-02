#include "ahorcado.h"

Juego::Juego(){

    Juego::eleccion();
    Juego::Jugar();
    Juego::repetir();

}

void Juego::eleccion(){

    int elec{0};

    if (cod.length()!=0){

        cod.clear();
    }
    

    srand(time(NULL)); //semilla para el numero aleatorio
    elec = rand()%(palabras.size()-1); //numero aleatorio entre 0 y el tamaño del arreglo palabras


    palabra = palabras[elec];

    for (int i = 0; i < palabra.length(); i++){
        
        cod.append("X");
    }
}

void Juego::Jugar(){

    int intentos = 0;
    string entro = "no";
    string adivinar="no";

    while (jugar=="si"){

        cout<<"Adivina la palabra "<<cod<<endl;
        cout<<"Que letra crees pertenece a la palabra?"<<endl;
        cin >> adi;

        for (int i = 0; i < palabra.length(); i++){
            
            while (adi[0] == cod[i]){
                
                cout<<"Esa letra ya se encuentra entre las halladas,vuelve a adivinar"<<endl;
                cin>>adi;

            }
            
            if (adi[0] == palabra.at(i)){
                
                cod[i] = adi[0];
                entro = "si";
            }

        }

        if(entro == "si" && cod != palabra){

            cout<<"La letra "<< adi<<" pertenece"<<endl;
            cout<<cod<<endl;
            cout<<"quiere adivinar la palabra?(escriba si para adivinar,"<< 
            "de lo contrario ingrese cualquier otra letra)"<<endl;
            cin>>adivinar;

            if (adivinar=="si"){
                
                cout<<"Cual es la palabra?"<<endl;
                cin>>adi;

                if (adi==palabra){
                    
                    cout<<"Felicidades, ganaste"<<endl;
                    jugar="no";
                }

                else{

                    cout<<"Esa no es la palabra"<<endl;
                    intentos++;

                    if (intentos==7){

                        cout<<"Perdiste"<<endl;
                        jugar="no";
                    }
                    
                }
            }

            entro="no";
        }

        else if (entro == "si" && cod != palabra){

        cout<<"Felicidades, ganaste"<<endl;
        jugar="no";

        }
        

        else{

            cout<<"Esa letra no pertenece a la palabra"<<endl;
            intentos++;

            if (intentos==7){
                
                cout<<"Perdiste"<<endl;
                jugar="no";
            }        
        }
    }
}

void Juego::repetir(){

    cout<<"Quiere volver a jugar?"<<endl;
    cin>>jugar;

    while(jugar=="si"){

        Juego::eleccion();
        Juego::Jugar();

        cout<<"Quiere volver a jugar?"<<endl;
        cin>>jugar;


    }
}