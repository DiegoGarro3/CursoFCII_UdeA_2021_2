#include "ahorcado.h"

Juego::Juego(){

    /*
    
    El constructor se encarga de iniciar la palabra a adivinar, empezar el jueg
    y repetirlo las veces que el usuario quiera hacerlo
    */

    Juego::eleccion();
    Juego::Jugar();
    Juego::repetir();

}

void Juego::eleccion(){

    int elec{0};//variable que sera empleada para tomar una palabra del arreglo palabras

    if (cod.length()!=0){//en caso que se vuelva a jugar la varibale cod se volvera una string vacio

        cod.clear();
    }
    

    srand(time(NULL)); //semilla para el numero aleatorio
    elec = rand()%(palabras.size()-2); //numero aleatorio entre 0 y el tamaño del arreglo palabras menos u


    palabra = palabras[elec];//se elige una palabra al azar

    for (int i = 0; i < palabra.length(); i++){
        
        cod.append("X");//se llena cod como una string de la longitud de la palabra a adivinar con X
    }
}

void Juego::Jugar(){

    int intentos = 0;//contador de fallos
    string entro = "no";
    string adivinar="no";

    Juego::figura(intentos);

    while (jugar=="si"){//mientras se quiera jugar

        cout<<"Adivina la palabra "<<cod<<endl;
        cout<<"Que letra crees pertenece a la palabra?"<<endl;
        cin >> adi;//se añade a una letra para adivinar

        while (adi.length()!=1){//se verifica que se ingrese una letra

            cout<<"usted ingreso mas de una letra, intente de nuevo"<<endl;
            cin >> adi;
        }
        

        for (int i = 0; i < palabra.length(); i++){//se compara la letra ingresada con la palabra
            
            while (adi[0] == cod[i]){//se verifica que no se repitan letras correctas
                
                cout<<"Esa letra ya se encuentra entre las halladas,vuelve a intentar"<<endl;
                cin>>adi;

                while (adi.length()!=1){//se verifica que se ingrese una letra

                    cout<<"usted ingreso mas de una letra, intente de nuevo"<<endl;
                    cin >> adi;
                }
                

            }
            
            if (adi[0] == palabra[i]){//se adivina
                
                cod[i] = adi[0];
                entro = "si";//condicion de que hay minimo una letra tecleada en la palabra
            }

        }

        if(entro == "si" && cod != palabra){//se da la opcion de adivinar la palabra

            cout<<"La letra "<< adi <<" pertenece"<<endl;
            cout<<cod<<endl;
            cout<<"\nQuiere adivinar la palabra?(escriba si para adivinar,"<< 
            "de lo contrario ingrese cualquier otra letra)"<<endl;
            cin>>adivinar;

            if (adivinar=="si"){
                
                cout<<"Cual es la palabra?"<<endl;
                cin>>adi;

                if (adi==palabra){
                    
                    cout<<"Felicidades, ganaste, la palabra es " << palabra<<endl;
                    jugar="no";
                }

                else{

                    cout<<"Esa no es la palabra"<<endl;
                    intentos++;

                    if (intentos==7){

                        cout<<"Perdiste,la palabra es: "<< palabra <<endl;
                        jugar="no";
                    }
                    
                }
            }

            entro="no";
        }

        else if (entro == "si" && cod == palabra){//se gana si ya se adivino letra a letra

        cout<<"Felicidades, ganaste, la palabra es " << palabra<<endl;
        jugar="no";

        }
        

        else{//la letra ingresada no pertenece

            cout<<"Esa letra no pertenece a la palabra"<<endl;
            intentos++;

            if (intentos==7){
                
                cout<<"Perdiste,la palabra es: "<< palabra <<endl;
                jugar="no";
            }        
        }

        cout<<"\n";
        Juego::figura(intentos);//se muestra el progreso de los errores
    }
}

void Juego::repetir(){//funcion que hara que el codigo se repita tantas veces el usuario lo desee

    cout<<"Quiere volver a jugar?"<<endl;
    cin>>jugar;

    while(jugar=="si"){

        Juego::eleccion();
        Juego::Jugar();

        cout<<"\nQuiere volver a jugar?"<<endl;
        cin>>jugar;


    }
}

void Juego::figura(int fallo){

    /*
    Funcion que dibujara al ahorcado dependiendo de que tantos fallos tenga
    
    Como \ no se interpreta como un carecter a mostrar se ponen dos para que en el dibujo aparezca
    */

    if(fallo==0){
        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;        
    }

    else if (fallo==1){

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
        

    }

    else if (fallo==2){

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
        

    }

    else if (fallo==3){

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
        

    }

        else if (fallo==4){

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |       /|      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
        

    }
    
        else if (fallo==5){

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |       /|\\      " << endl;
		cout << " |        |      " << endl;
		cout << " |               " << endl;
		cout << " |               " << endl;
        

    }

        else if (fallo==6){

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |       /|\\      " << endl;
		cout << " |        |      " << endl;
		cout << " |       /       " << endl;
		cout << " |               " << endl;
        

    }

        else{

        cout << "___________" << endl;
		cout << " |        |      " << endl;
		cout << " |        |      " << endl;
		cout << " |        O      " << endl;
		cout << " |       /|\\      " << endl;
		cout << " |        |      " << endl;
		cout << " |       / \\      " << endl;
		cout << " |               " << endl;
        

    }
}