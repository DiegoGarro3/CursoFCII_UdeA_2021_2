#include "ecuaciones.h"

Ecuacion::Ecuacion(){

    cout<<"De cuantas variables es su sistema de ecuaciones?"<<endl;
    cin>>tam;

    Ecuacion::ecu();
    Ecuacion::ini();

}

void Ecuacion::ecu(){
    
    vector<float> ecuacion; 
    float coeficiente;

    for (int i = 0; i < tam; i++){

        for (int j = 0; j <= tam; j++){

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
        
        Ecu.push_back(ecuacion);
        ecuacion.erase (ecuacion.begin(),ecuacion.begin()+(tam+1));

    }

/////////////////////////////////////////////

    float suma{0};

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

void Ecuacion::ini(){

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
   while (correr =="si"){
        
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

    for (int p = 0; p < tam; p++){
        
        cout<<X[p]<<endl;
    }
    
}

void Ecuacion::SOR(){

    vector<float> X0=X_0;
    float tol=pow(10,-6);
    string correr="si";
    float suma{0};
    unsigned int contador=0;
    unsigned int con_int=0;
    int algo=0;
    float w=1.5;

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

    for (int p = 0; p < tam; p++){
        
        cout<<X[p]<<endl;
    }
    
}