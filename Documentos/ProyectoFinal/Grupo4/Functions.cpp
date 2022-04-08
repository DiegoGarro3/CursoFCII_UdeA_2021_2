#include<cmath>
#include<iomanip>
#include "Ising .h"

using namespace std;




Ising::Ising(int steps,int size, float t,float j, int reverse,float h, float delta_h)
{   
    Setsteps(steps);
    Setsize(size);
    SetTemperature(t);
    SetJ(j);
    Reverse=reverse;

    H=h;
    delta_H=delta_h;



}


Ising::~Ising()
{
    cout<< "Los datos han sido almacenados exitosamente!" << endl;
}

void Ising::Setsize(int size){
    SIZE=size;
}

void Ising::SetJ(int j){
    J=j;
}
void Ising::Setsteps(int steps){
    STEPS=steps;
}

void Ising::SetTemperature(int t){

    T=t;
}

float Ising::randomUniform(){

    // construct a trivial random generator engine from a time-based seed:
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);

  uniform_real_distribution<double> distribution (0.0,1.0);


  return distribution(generator);

}

int Ising::pbc(int i){

    if (i+1 > SIZE){

    return 0;

    };

    if (i-1 < 0)
    {
        return SIZE-1;
    };


    return i;

}

vector<vector<float>> Ising::Spin(){

    vector<vector<float>> spin(SIZE,vector<float> (SIZE));

    if (J==0)
    {
    
    srand(time(NULL));
    

    for (size_t i = 0; i < SIZE; i++)
    {   
        for (size_t k = 0; k < SIZE; k++)
        {   
            
            int random=rand()%2;
            

            if (random==0){

                spin[i][k]=-1;
                

            }

            if(random==1){
                
                spin[i][k]=1;
            }

        }
        
    }

    }
        if (J==1){

        if (Reverse==1){

            for (size_t i = 0; i < SIZE; i++)
            {   
                for (size_t k = 0; k < SIZE; k++)
                {   
                    spin[i][k]=1;
                }
        
            }
        }

        if (Reverse==0){

            for (size_t i = 0; i < SIZE; i++)
            {   
                for (size_t k = 0; k < SIZE; k++)
                {   
                    spin[i][k]=-1;
                }
        
            }  

        }  
    }
    return spin;
};



float Ising::Hamiltonian(vector<vector<float>> spin, float H, int i,int j){

    float E=-J*spin[i][j]*(spin[pbc(i-1)][j] + spin[pbc(i+1)][j] + spin[i][pbc(j-1)] + spin[i][pbc(j+1)]) - spin[i][j]*H;
    return E;
  
}

vector<vector<float>> Ising::Metropolis(float H){
    
    vector<vector<float>> spin = Spin();


    srand(time(NULL));
    int tmc{0};
    while (tmc < STEPS)
    {
        int i=rand()%(SIZE);
        int j=rand()%(SIZE);

        float Ea=Hamiltonian(spin,H,i,j);
        spin[i][j]*=-1.0;
        float Delta_E=Hamiltonian(spin,H,i,j)-Ea;

        if ((1.0-exp(-Delta_E/T)) >= randomUniform())
        {
            spin[i][j]*=-1.0;

        }

        tmc+=1;

    }

    return spin;
    
};




float Ising::Magnetizacion(vector<vector<float>> state){


    float M=0.0;

    for (size_t i = 0; i < SIZE; i++)
    {   
        for (size_t k = 0; k < SIZE; k++)
        {
            M += state[i][k];
        }
    }


    
    return M;




};


void Ising::GetSolution(){

    string name;

    if (J==1)
    {
         name="Ferromagnetismo"+ to_string(Reverse)+ ".dat";
    }

    if (J==0){
        name="Paramagnetismo" + to_string(T)+".dat";
    }
    
    ofstream Datos(name); //Escribe un archivo

	if ( Datos.fail() ){   // misma cosa    
            
            cout << "No se pudo abrir el archivo" << endl;
            exit( 1 );
    }


    for (float i = -H; i < H; i+=delta_H)
    {
        vector<vector<float>> spin=Metropolis(i);
        
        float Mag= Magnetizacion(spin);


        Datos << left << setw(15) << i << setw(15) << Mag/(SIZE*SIZE) << endl;
        
    }
    

};

void Ising::GetSpin(){

    string name="spin.dat";
    ofstream SPIN(name);
    if ( SPIN.fail() ){   // misma cosa    
            
        cout << "No se pudo abrir el archivo" << endl;
        exit( 1 );
    }

    vector<vector<float>> matrix=Metropolis(0.0);

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t k = 0; k < SIZE; k++)
        {   

            SPIN << left << setw(5) << matrix[i][k] << endl;
        }
        
    }



}

