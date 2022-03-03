#include<cmath>
#include<iomanip>
#include<iostream>
#include <vector>

using namespace std;

double Matriz(int i, int j,int size){
    
     vector<vector<double>> m={ {10,-1,2, 0},
                                {-1,11,-1,3},
                                {2,-1,10,-1},
                                {0,3, -1, 8} };
    //Devuelve un elemento de la matriz o el tamaño de la matriz segun se necesite en el codigo.
    if(size==0){
       

        return m[i][j];

    }

    if (size==1){

        return m.size();
    }

    return 0;


}


double Jacobi(int k,int ite){

    double x0[]={0.0,0.0,0.0,0.0}; //Semilla
    double xo[]={0.0,0.0,0.0,0.0}; //Solucion de la ecuacion
    double B[4]={6.0, 25.0, -11.0, 15.0}; //Terminos independientes en la ecuacion

    //Division de los terminos independientes por los terminos digaonales de la matriz
    for(int h=0 ; h < Matriz(0,0,1); h++){

        for(int v=0 ; v < Matriz(0,0,1); v++ ){

            if (h==v)
            {
                B[h]=B[h]/Matriz(h,v,0);
            }
            
        }

    }
    
    for( int m=0; m <= ite ; m++){

        for (int i = 0; i < Matriz(0,0,1); i++){   
            xo[i] = 0;
            for (int j = 0; j < Matriz(0,0,1); j++)
            { 
                
                if(j != i){

                    xo[i] += (-Matriz(i,j,0)*x0[j])/Matriz(i,i,0);
                    
                    
                }
            }
             
            xo[i]+=B[i];
        }
        
        for (int l = 0; l < Matriz(0,0,1) ; l++){
            x0[l]=xo[l];   
        }

     
            
    }    
    return xo[k];
}


double SOR(int k, float w,int ite){

    double x0[]={0.0,0.0,0.0,0.0}; //Semilla
    double xo[]={0.0,0.0,0.0,0.0}; //Solucion de la ecuacion
    double B[4]={6.0, 25.0, -11.0, 15.0}; //Terminos independientes en la ecuacion

    //Division de los terminos independientes por los terminos digaonales de la matriz
    for(int h=0 ; h < Matriz(0,0,1); h++){

        for(int v=0 ; v < Matriz(0,0,1); v++ ){

            if (h==v)
            {
                B[h]=B[h]/Matriz(h,v,0);
            }
            
        }

    }
    
    //Formula de recurrencia para el vector xo
    for( int m=0;  m <= ite ; m++){

        for (int i = 0; i < Matriz(0,0,1); i++){   
            //Se reinicializa el valor siempre para no sumas el termino que se calculo en el paso anterior
            xo[i]=0.0;
            for (int j = 0; j < i; j++)
            { 
                xo[i] += w*(-Matriz(i,j,0)*xo[j])/Matriz(i,i,0);
            
            }

            
            for (int n = i+1; n < Matriz(0,0,1) ; n++)
            {
                xo[i] += w*(-Matriz(i,n,0)*x0[n])/Matriz(i,i,0);
            }

            xo[i]+= w*B[i]+(1-w)*x0[i];
        
        }
        //Reasignacion de el vector semilla con la solucion.
        for (int l = 0; l < Matriz(0,0,1) ; l++){
            x0[l]=xo[l];   
        }

    }    

    return xo[k];
}






int main(){

    float w{0};
    int Precision{0};
    cout << "Ingrese el valor de w para calcular la ecuacion por el metodo SOR : ";
    cin >> w;
    cout << "Ingrese el numero de iteraciones que desaa realizar: ";
    cin >> Precision;
    cout << "\n";
    

    cout << fixed << setw(3)<< "Solution" << "    " << fixed <<  setw(3)<< "Jacobi" << "       " << fixed <<setw(3) << "SOR" << endl;
    cout << "\n";
    for (int i = 0; i <=3; i++)
    {
         cout << fixed << setw(3) << "x["<< i <<"] " <<  "    " << fixed << setw(3) <<Jacobi(i,Precision) <<  "    "  <<fixed<< setw(3) << SOR(i,w,Precision) <<endl;
    }
    cout << "\n";
    cout << "El numero de iteraciones para ambos casos fue de " << Precision << " para SOR el parametro w es " << w << endl;
    return 0;
    
    


}