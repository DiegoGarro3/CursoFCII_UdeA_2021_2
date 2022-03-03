#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;
int main(){

   
    string palabra[]={"lasagna","paleta","heroico","zeus","mabely","colombia"};  //Palabra que se debe adivinar.
    bool restart=true;
    



    
    while(restart==true){
        srand(time(NULL)); //Semilla para los numeros aleatorios
        int indice=0+rand()%5;
        string encriptada[]={"-------","------","-------","----","------","--------"};//Encriptacion de la palaba.
        char adivinar; //Letra que ingresa el usuario para advinar.
        int vidas{7}; //Numero de intentos que tiene para adivinar la palabra.
        int replay{2};
        int fail{0};

        cout << "Vamos a jugar ahorcado, adivine la siguiente palabra, tiene 7 intentos para lograrlo." << endl;
        cout << "La palabra tiene " << palabra[indice].size() << " letras" << endl;
        cout << encriptada[indice] << endl;
        cout << "\n";

        while(vidas > 0){

            int adivinarYa{5};
            cout << "Ingrese una letra: ";
            cin >> adivinar;
            cout << "\n";

        
            //Busca si la letra ingresada esta en la palabra que se debe adivinar
            if (palabra[indice].find(adivinar) == string::npos)
            {   
                cout << "La letra " << adivinar << " no esta en la palabra que se debe adivinar" << endl; 
                vidas-=1;
                cout << "Te quedan " << vidas << " intentos" << endl;
                cout << "\n";
                cout << "Asi va su progreso: ";
                cout << encriptada[indice] << endl;
                cout << "\n";
           
            }

            //El siguiente for halla la posicion de la letra ingresada en la palabra que hay que adivinar y luego la asigna a la variable encriptada en esa misma posicion
            else {
            
                for (int i = 0; i <= palabra[indice].size(); i++)
                {
                    if (adivinar == palabra[indice][i])
                    {
                        encriptada[indice][i]=adivinar;
                    }
                
                }

                cout << "Asi va su progreso: ";
                cout << encriptada[indice] << endl;
                cout << "\n";
                
                if(encriptada[indice].compare(palabra[indice]) != 0){
                    cout << "Si desea adivinar la palabra completa ingrese 1 y 0 si desea ingresar otra letra: ";
                    cin >> adivinarYa;
                }

            }

        
            //Opcion para ingresar la palabra completa
            if (adivinarYa == 1){
                string AdivinarCompleta;
                cout << "Ingrese la palabra completa: " << endl;
                cin >> AdivinarCompleta;
                cout << "\n";

                if(AdivinarCompleta.compare(palabra[indice])==0){
                    
                    cout << "Has ganado,felicitaciones!" << endl;
                    cout << "Si desea salir ingrese 0, ingrese cualquier otro numero para volver a jugar :";
                    cin >> replay;
                    cout << "\n";

                    if (replay==0)
                    {
                        restart=false;
                        vidas=0;
                        fail=1;
                    } 

                    if (replay !=0){

                        vidas=0;
                        fail=1;

                    }          

                }

                else{
                    vidas-=1;
                    cout << "Palabra incorrecta, te quedan " << vidas << " intentos" << endl;  
                    cout << "\n";
                }

               

            
            }

            else{

                if(encriptada[indice].compare(palabra[indice]) == 0){

                    cout << "Has adivinado la palabra, felicitaciones!" << endl;
                    cout << "\n";
                    cout << "Si desea salir ingrese 0, ingrese cualquier otro numero para volver a jugar :";
                    cin >> replay;
                    cout << "\n";

                    if (replay==0)
                    {
                        restart=false;
                        vidas=0;
                        fail=1;
                    }   

                    if (replay !=0){

                        vidas=0;
                        fail=1;

                    }   

                }   
            } 





    

        }

        
        
        if (vidas==0 && fail==0){
            cout << "Te has quedado sin vidas, la palabra era :" << palabra[indice] << endl;
            cout << "\n";
            cout << "Si desea salir ingrese 0, ingrese cualquier otro numero para volver a jugar :";
            cin >> replay;
            cout << "\n";

            if (replay==0 )
            {
                restart=false;
            }
        }

    }
    return 0;


    
    




}

