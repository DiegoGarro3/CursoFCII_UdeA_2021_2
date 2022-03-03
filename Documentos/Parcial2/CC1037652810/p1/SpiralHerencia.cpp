#include <iostream>
#include <vector>
#include <fstream> // flujo de archivo
#include <sstream> 
#include <iomanip>

using namespace std;


#include "Spiralcprotot.h"

// constructor
Spiral::Spiral(double z0, double vz, double rad, double delt, double Tt, double angfre, double f)
  // llama al constructor de la clase base setteando las variables privadas de la instancia como constantes, estas se pueden obtener por medio de funciones publicas
  : Circular( rad,delt,Tt,angfre,f)
{
  setZpos( z0, vz ); // adds movement in z
  imprimir();
  cout << "\n\n";
}

Spiral::~Spiral()
{
cout << "Spiral class Destructed " << endl;
//imprimir();
cout << "\n\n";
}

void Spiral::setZpos( double z0, double vz )
{
 int tsize = Circular::getTtotal()/Circular::getDeltat();
 vector<double> timevect = Circular::Time();
 for(int i=0; i<tsize; i++){
         zpos.push_back( z0 + vz*timevect[i] );
 }
}

vector <double> Spiral::getZpos() const
{
 return zpos;
}

void Spiral::imprimir()
{
 cout << fixed << setw(5) << "Time" << setw(18) << "Xpos" << setw(18) << "Ypos" << setw(18) <<  "Zpos" << endl;
 int tsize = Circular::getTtotal()/Circular::getDeltat(); 
 //crea un archivo donde guardar los datos
 ofstream spiralmov( "spiral.dat", ios::out );
 spiralmov << fixed << setw(5) << "Time" << setw(18) << "Xpos" << setw(18) << "Ypos" << setw(18) <<  "Zpos" << endl;
 for (int j=0;j<tsize;j++)
      { 

          cout << fixed << setw(5) << Circular::Time()[j] << setw(18) << Circular::Xpos()[j] << setw(18) << Circular::Ypos()[j] << setw(18) <<  getZpos()[j] << endl;
          spiralmov<< fixed << setw(5) << Circular::Time()[j] << setw(18) << Circular::Xpos()[j] << setw(18) << Circular::Ypos()[j] << setw(18) <<  getZpos()[j] << endl;

      }
}
