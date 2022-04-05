#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

#include "Clase.h"

using namespace std;

Poisson::Poisson(float A,float B,float C,float D,float nn,float mm,int NN)
{
    setLeft(A);
    setRight(B);
    setDown(C);
    setUp(D);
    setn(nn);
    setm(mm);
    setN(NN);
  




};

void Poisson::SaveFile(vector<vector<float>> matrix, vector<float> x, vector<float> y){
    ofstream Datos("datos.txt" ); //Escribe un archivo



	if ( Datos.fail() ){   // misma cosa    
            
            cout << "No se pudo abrir el archivo" << endl;
            exit( 1 );
    }

        Datos << left << setw(5) << "i" << setw(5) << "j" << setw(13) <<  "Xi" <<  setw(13) << "Yj" << setw(13)  << "Wij"  << endl;
        for (size_t i = 1; i <=n-1; i++)
        {
            for (size_t j = 1; j <= m-1; j++)
            {
                Datos << left << setw(5) << i << setw(5) << j << setw(13) <<  x[i] <<  setw(13) << y[j] << setw(13)  << matrix[i][j]  << endl;
            }
            
        }

        Datos.close();
        
        
        
            
};


void Poisson::setLeft(float A){
    a=A;

};
void Poisson::setRight(float B){
    b=B;
};
void Poisson::setDown(float C){
    c=C;
};
void Poisson::setUp(float D){
    d=D;
};
void Poisson::setn(float nn){
    n=nn;
};
void Poisson::setm(float mm){
    m=mm;
};
void Poisson::setN(float NN){
    N=NN;
};


void Poisson::setBRight(float (*f)(float , float )){
    BoundaryRight=f;

};
void Poisson::setBLeft(float (*f)(float , float)){
    BoundaryLeft=f;
};
void Poisson::setBDown(float (*f)(float , float)){
    BoundaryDown=f;
};
void Poisson::setBUp(float (*f)(float , float)){
    BoundaryUp=f;
};
void Poisson::setF(float (*f)(float , float)){
    Source=f;
};

float Poisson::G(float x, float y)
{
    if (x==a){ //Pared Izquierda
        
        
        return BoundaryLeft(x,y);

    }

    if (x==b){ //Pared derecha
        

        return BoundaryRight(x,y);
    }

    if (y==d){ //Pared superior

        
        return BoundaryUp(x,y);
    }

    if (y==c){//Pared inferior

        
        return BoundaryDown(x,y);
    }

    return 0;

};





float Poisson::F(float x,float y){
    return Source(x,y);
};


vector<vector<float>> Poisson::GetSolution(){


    float h=(b-a)/n;
    float k=(d-c)/m;

    float lambda=pow((h/k),2);
    float mu=2.0*(1.0+lambda);

    vector<float> Xi(n);
    vector<float> Yj(m);
    
    vector<vector<float>> w(n,vector<float>(m));
    
    Xi[0]=a;
    for (size_t i = 1; i <= n-1 ; i++)
    {   
        
        Xi[i]=a + i*h;
        
        
        
    }
    

    Yj[0]=c;


    for (size_t j = 1; j <= m-1 ; j++)
    {   
        Yj[j]= c + j*k;
        
    }

    w[0][0]=0.0;

    //Semilla de la solucion
    for (size_t i = 1; i <= n-1 ; i++)
    {   
        for (size_t j = 1; j <=m-1; j++)
        {
            w[i][j]=0.0;
            
            
        }

        
    }

    int l{0};

   
    while (l <= N)
    {   
        float z{0};
        float Norm;
        //Primer mesh point
        z= ((-pow(h,2)*F(Xi[1],Yj[m-1])+ G(a,Yj[m-1]) + 
        (lambda*G(Xi[1],d))+ (lambda*w[1][m-2]) + w[2][m-1] ))/mu;

        Norm=abs(z-w[1][m-1]);
        w[1][m-1]=z;

        //Step 8
        for (size_t i = 2; i <= n-2; i++)
        {
        
            z= (-pow(h,2)*F(Xi[i],Yj[m-1]) + 
            (lambda*G(Xi[i],d))+ (w[i-1][m-1]) + (w[i+1][m-1]) + (lambda*w[i][m-2]))/mu;

            if(abs(w[i][m-1]-z) > Norm ){

                Norm=abs(w[i][m-1]-z);

            }

            //Mesh points m-1 en y hasta la penultima en x. 
            w[i][m-1]=z;

        }
        
        //Step 9

        //Mesh point  (n-1)(m-1)
        z= (-pow(h,2)*F(Xi[n-1],Yj[m-1]) + 
        (lambda*G(Xi[n-1],d))+  G(b,Yj[m-1]) + (w[n-2][m-1]) + (lambda*w[n-1][m-2]))/mu;
        
        if(abs(w[n-1][m-1]-z) > Norm ){
            Norm=abs(w[n-1][m-1]-z);

        }
        
        

        w[n-1][m-1]=z;

        //step 10
        for (size_t j = m-2; j >= 2; j--)
        {   //Step 11
            z= (-pow(h,2)*F(Xi[1],Yj[j]) + 
            (G(a,Yj[j]))+ lambda*(w[1][j+1]) + lambda*(w[1][j-1]) + w[2][j])/mu;
                     
            if(abs(w[1][j]-z) > Norm ){
                Norm=abs(w[1][j]-z);


            }
            //Recorre todo y
            w[1][j]=z;
            
            //step 12
            for (size_t i = 2; i <= n-2; i++)
            {
                z= (-pow(h,2)*F(Xi[i],Yj[j]) + 
                lambda*(w[i][j+1]) + w[i-1][j]+ w[i+1][j] + lambda*(w[i][j-1]))/mu;

                if(abs(w[i][j]-z) > Norm ){
                    Norm=abs(w[i][j]-z);


                }

                w[i][j]=z;

            }
            
            

            //Step 13
                
            z= (-pow(h,2)*F(Xi[n-1],Yj[j]) + 
            (G(b,Yj[j])) + lambda*(w[n-1][j+1])+lambda*(w[n-1][j-1]) + w[n-2][j])/mu;

            if(abs(w[n-1][j]-z) > Norm ){
                Norm=abs(w[n-1][j]-z);


            }

            w[n-1][j]=z;
            
        }
        

        //Step 14
        z= (-pow(h,2)*F(Xi[1],Yj[1]) + 
        (G(a,Yj[1]))+ lambda*G(Xi[1],c) + lambda*(w[1][2]) + w[2][1])/mu;

        if(abs(w[1][1]-z) > Norm ){
            Norm=abs(w[1][1]-z);


        }

        w[1][1]=z;

        //step 15
        for (size_t i = 2; i <= n-2; i++)
        {   
            z= (-pow(h,2)*F(Xi[i],Yj[1]) + 
            (lambda*G(Xi[i],c)) + lambda*(w[i][2])+ w[i+1][1] + w[i-1][1])/mu;

            if(abs(w[i][1]-z) > Norm ){
                Norm=abs(w[i][1]-z);
            }
            
            w[i][1]=z;

        }
            
        z= (-pow(h,2)*F(Xi[n-1],Yj[1]) + 
        (G(b,Yj[1])) + lambda*(G(Xi[n-1],c))+ w[n-2][1] + lambda*w[n-1][2])/mu;
            
        if(abs(w[n-1][1]-z) > Norm ){
            Norm=abs(w[n-1][1]-z);
        }
        

                
        w[n-1][1]=z;

        if(Norm <= 1e-10){

            break;

        }

        l+=1;

        
    /*
        for (size_t i = 1; i <= n-1 ; i++)
        {   
            for (size_t j = 1; j <=m-1; j++)
            {
                
                cout << i << "  " << j << "  " << w[i][j] << "  La solucion exacta es: " << F(Xi[i],Yj[j]) << endl;
            
            }

        
        }
        cout << "\n";
        cout << "\n";

    */
    cout << l << endl;

    }
    

    SaveFile(w,Xi,Yj);



    

    return w;

};

    