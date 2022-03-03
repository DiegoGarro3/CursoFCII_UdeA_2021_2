#include"Ecuaciones.cpp"

int main()
{
  //Si la matriz A satisface que |A_ii| >=sum_j|A_ij| para todo i, es condicion suficiente para  converger.
  //Si la Matriz A satisface P(D^-1*R)<1 es condicion necesaria y  suficiente para la convergencia, donde D es la diagonal de A, R=A-D, y P es la funcion radio espectral.
    cout<<endl;
    vector<vector<double>>A={{10,-1,2,0},{-1,11,-1,3},{2,-1,10,-1},{0,3,-1,8}}; //Matriz asociada al sistema de ecuaciones
    vector<double>b={6,25,-11,15}; //Ax=b
    vector<double>x_0={0,0,0,0}; // condicion inicial
    //vector<vector<double>>A={{4,3,0},{3,4,-1},{0,-1,4}};
    //vector<double>b={24,30,-24};
    //vector<double>x_0={1,1,1};
    int iter=11; //iteraciones
    double w=1.25; //parametro de relajación
    Equa sist1(A,b); // Crea un objeto llamado sist1
    vector<double>sol1=sist1.jacobi(x_0,iter); //soluciones como metodos del objeto sist1
    vector<double>sol2=sist1.SOR(x_0,w,iter);
    cout<<"SOLUCIONES AL SISTEMA DE ECUACIONES Ax=b."<<endl;
    cout<<endl;
    cout<<"Solucion via metodo de Jacobi, usando "<<iter<< " iteraciones"<<endl;
    cout<<endl;
    for(size_t i=0;i<sol1.size();i++)
    cout<<"x"<<i<<" = "<< sol1[i]<<endl;
    cout<<endl;
    cout<<"Solucion via metodo SOR, con w= "<<w<<", usando "<<iter<<" iteraciones"<<endl;
    cout<<endl;
    for(size_t i=0;i<sol2.size();i++)
    cout<<"x"<<i<<" = "<< sol2[i]<<endl;
    cout<<endl;
    cout<<"Converge más rapido el metodo SOR"<<endl;

    return 0;
}

