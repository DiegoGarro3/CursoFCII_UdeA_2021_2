#include "schrodinger.h"

schrodinger::schrodinger(double a,double b,int n,double (*pot)(double),double M){

    x_inf=a;
    x_sup=b;
    N=n;
    V=*pot;
    m=M;

    double h=(x_sup-x_inf)/N;

    set_x();
    set_T();
    set_vx();
 
    H = -0.5*pow((hbar*v_c)/h,2)* T/m  + V_x; 


}

schrodinger::~schrodinger(){};

void schrodinger::set_x(void)
{
    x.resize(N+1);
    double h=(x_sup-x_inf)/N;
    for(int i=0;i<=N;i++)
    {
        x[i]=h*i + x_inf;
    };

};


void schrodinger::set_T(void)
{
    T.resize(N-1,N-1);
    
    for(int i=0;i<(N-1);i++)
    {
        for(int j=0;j<(N-1);j++){
        
            if(i==j){
                T(i,j)=-2;
            }

            else if(abs(i-j)==1){

                T(i,j)=1;
            }

        }
    }

}

void schrodinger::set_vx(void){

    V_x.resize(N-1,N-1);

    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++){
            
            if(i==j){
                V_x(i,j)=V(x[i]);
            }

            else{
                V_x(i,j)=0;
            }
        }
    }
}

Eigen::MatrixXd schrodinger::get_H(void){

    return H;
}

int schrodinger::get_N(void){

    return N;
}

Eigen::VectorXd schrodinger::get_x(void){

    return x;
}