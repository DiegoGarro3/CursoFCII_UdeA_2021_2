#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;



void DectoBin(){
cout<<"Ingrese un número decimal"<<endl;
int deci;
int coc=1;
int res;
cin>>deci;
cout<<"El número que ingresó en el sistema binario es:"<<endl;

int i=0;
vector<int> n;

while(coc>=0){
	coc= deci/2;
	res=deci%2;
	deci=coc;
	n.push_back(res);
	i++;
	if (coc==0){
		break;}
	}
	


for (int j=0;j<i;j++)
{cout<<n[i-(j+1)];

}

cout << endl;
};


void DectoHex(){

cout<<"Ingrese un número decimal"<<endl;
int deci;
int coc=1;
int res;
cin>>deci;
cout<<"El número que ingresó en el sistema hexadecimal es:"<<endl;

int i=0;
int n[i];

while(coc!=0){
	coc= deci/16;
	res=deci%16;
	deci=coc;
	n[i]=res;
	i++;
	}
	
string hexa[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

for (int j=0;j<i;j++)
{cout<<hexa[n[i-(j+1)]];

}
cout<<endl;
};

void Bintodeci(){

cout<<"Ingrese un número binario"<<endl;
int bin;
cin>>bin;
cout<<"El número que ingresó en el sistema decimal es:"<<endl;

int i=0;
int deci=0;

while (bin> 0)
{
    int numero= bin%10;
    bin /= 10;
    deci += numero*pow(2,i);
    i++;
    
   
}
cout<<deci<<endl;
};

void Hexatodeci(){
char hexa[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int potencia=0; 
int deci=0;
string numero;

cout<<"Ingrese un número Hexadecimal"<<endl;
cin>>numero;
cout<<"El número que ingresó en el sistema decimal es:"<<endl;
  
  for (int i = numero.length() - 1 ; i >= 0 ; i--)
  {
    
    for(int j=0;j<=15;j++)
    {     
      if (numero[i] == hexa[j]) 
        {
	deci += j * pow(16, potencia);
	potencia += 1;
        }
    }
    
  }
cout<<deci<<endl;
};

void Binatohexa(){

  int deci=0;
  int potencia=1;
  string numero;
  
cout<<"Ingrese un número Binario"<<endl;
cin>>numero;
cout<<"El número que ingresó en el sistema hexadecimal es:"<<endl;

  for (int i = numero.length() - 1 ; i >= 0 ; i--)
  {
    if(numero[i]=='1')
    {
      deci += 1 * potencia;
    }
    potencia *= 2;
  }
  char hexa[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; 
    string res; 
    while(deci % 16 !=0 )
    {
      int n = deci % 16;
      res = hexa [n] + res;
      deci /= 16;      
    }
    
   cout<<res<<endl;
   };
   
   void Hexatobin(){

  char hexa[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  int potencia=0;
  int res;
  string bin;
  int deci=0;
  string numero;
  int coc=1;
  int i=0;
  


  
 cout<<"Ingrese un número Hexadecimal"<<endl;
 cin>>numero;
 cout<<"El número que ingresó en el sistema binario es:"<<endl;
  
  for (int i = numero.length() - 1 ; i >= 0 ; i--)
  {  
    for(int j=0;j<=15;j++)
    {      
      if (numero[i] == hexa[j])
      {
	deci += j * pow(16, potencia);
	potencia += 1;
      }
    }
  }
  vector<int> n;
  
  while(coc>=0)
  {
	coc= deci/2;
	res=deci%2;
	deci=coc;
	n.push_back(res);
	i++;
	
	if (coc==0)
	{
		break;
	}
	
  }
	for (int j=0;j<i;j++)
	{
	cout<<n[i-(j+1)];

	}
}








int main()
{

  cout<<"Escoja una opcción\n"<<endl;
  cout<<"*****************************************"<<endl;
  cout<<"Ingrese 1 si desea pasar de sistema decimal a hexadecimal"<<endl;
  cout<<"Ingrese 2 si desea pasar de sistema decimal a binario"<<endl;
  cout<<"Ingrese 3 si desea pasar de sistema binario a decimal"<<endl;
  cout<<"Ingrese 4 si desea pasar de sistema hexadecimal a decimal"<<endl;
  cout<<"Ingrese 5 si desea pasar de sistema binario a hexadecimal"<<endl;
  cout<<"Ingrese 6 si desea pasar de sistema hexadecimal a binario"<<endl;
  
  int opcion;
  cin>>opcion;
  
  if (opcion == 1)
   {
    DectoHex();
   }
   if (opcion == 2)
   {
    DectoBin();
   }
   if (opcion == 3)
   {
    Bintodeci();
   }
    if (opcion == 4)
   {
    Hexatodeci();
   }
    if (opcion == 5)
   {
    Binatohexa();
   }
     if (opcion == 6)
   {
    Hexatobin();
   }
   
   
return 0;
}




