#include "ecuaciones.h"

Ecuacion::Ecuacion(){

    /*
    El constructor de la clase crea la matriz expandida asociada al sistema
    de ecuaciones una vez se ha introducido el # de variables del sistema y
    luego se le ingresa la primera aproximacion para la solucion del sistema
    */

    cout<<"De cuantas variables es su sistema de ecuaciones?"<<endl;
    cin>>tam;

    Ecuacion::ecu();
    Ecuacion::ini();
    cout<<"\n"<<endl;

}

void Ecuacion::ecu(){
    
    vector<float> ecuacion; 
    float coeficiente;
    float suma{0};

    for (int i = 0; i < tam; i++){

        for (int j = 0; j <= tam; j++){
            /*
            Se crea una matriz nx(n+1) la cual representa la matriz expandida asociada 
            al sistema de ecuaciones 
            */

            if(j<tam){

                cout<<"Ingrese el coeficiente " <<j+1<<" de la ecuacion "<<i+1<<endl;
                cin>>coeficiente;
            }

            else{

                cout<<"Ingrese a que se iguala la ecuacion "<<i+1<<endl;
                cin>>coeficiente;
            }  
        
            ecuacion.push_back(coeficiente);
        }
        
        Ecu.push_back(ecuacion);//A ecu se le añade una ecuacion hasta formal la matriz
        ecuacion.erase (ecuacion.begin(),ecuacion.begin()+(tam+1));
    }

/*
si la matriz es diagonal dominante converge, de lo contrario no sabemos.
Empleando ese argumento se iterara el sistema hasta converger o de no ser
diagonal dominante se pondra un cota de iteraciones
*/

    for (int i = 0; i < tam; i++){

        suma=0;
        for (int j = 0; j < tam; j++){

            suma+=abs(Ecu[i][j]);
        }

        suma-=Ecu[i][i];

        if(abs(Ecu[i][i]) <= suma){
        
            converge = "no";
        }
    }
}

void Ecuacion::ini(){//Inicializacion de la solucion aproximada

    float CI{0};
    for(int i=0; i<tam; i++){ 
        
        cout<<"Ingrese la aproximacion incial para la variable #"<<i+1<<endl;
        cin>>CI;
        X_0.push_back(CI);
        X.push_back(CI);

    }
}

void Ecuacion::Jacobi(){

    vector<float> X0 = X_0;
    float tol=pow(10,-6);
    string correr="si";
    float suma{0};
    unsigned int contador=0;
    unsigned int con_int=0;
    int algo=0;

    X=X_0;
   while (correr =="si"){//iteracion del metodo de jacobi
        
        contador=0;
        
        for (int i = 0; i < tam; i++){
            
            suma=0;
            
            for (int j = 0; j < tam; j++){

                if (i!=j){

                    suma-=Ecu[i][j]*X0[j];  
                }
            }
  
            suma+=Ecu[i][tam];
            X[i]=suma/Ecu[i][i];

            if(abs((X[i]-X0[i]))<tol){

                contador++;
                if(contador==tam){

                    cout<<"Para el metodo de Jacobi la solucion es"<<endl;
                    for (int p = 0; p < tam; p++){
        
                        cout<<"X"<<p<<"= "<<X[p]<<endl;
                    }

                    correr="no";
                }
            }
 
        }

        X0=X;
        con_int ++;
        if (converge == "no" && con_int==20){

            cout<<"El metodo no converge para el sistema"<<endl;
            correr="no";
        }

    }
    
}

void Ecuacion::SOR(){//iteracion del metodo SOR

    vector<float> X0=X_0;
    float tol=pow(10,-6);//tolerancia
    string correr="si";
    float suma{0};
    unsigned int contador=0;
    unsigned int con_int=0;
    int algo=0;
    float w=1.5;//contante del metodo, si 0<w<1 aseguramos convergencia pero no que 
    //el metodo sea sobrerelajado(SOR), 1<w<2 sirve pero dependiendo del sistema puede que no
    //sea optimo

    X=X_0;
    while (correr =="si"){
        
        contador=0;
        
        for (int i = 0; i < tam; i++){
            
            suma=0;
            
            for (int j = 0; j < tam; j++){

                if (i!=j){

                    suma-=Ecu[i][j]*X[j];  
                }
            }
  
            suma+=Ecu[i][tam];
            suma*=w/Ecu[i][i];
            X[i]=suma +(1-w)*X[i];

            if(abs((X[i]-X0[i]))<tol){

                contador++;
                if(contador==tam){
                    
                    cout<<"Para el metodo SOR la solucion es"<<endl;
                    for (int p = 0; p < tam; p++){
        
                        cout<<"X"<<p<<"= "<<X[p]<<endl;
                    }
                    correr="no";
                }
            }
 
        }

        X0=X;
        con_int ++;
        if (converge == "no" && con_int==20){

            cout<<"El metodo no converge para el sistema"<<endl;
            correr="no";
        }

    }
}