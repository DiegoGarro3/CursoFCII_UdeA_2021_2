#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;



string DectoBin(string deci_str){
int coc=1;
int res,deci;
int i=0;
vector<int> n;
string numero="";
deci=stoi(deci_str);


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
{numero+=to_string(n[i-(j+1)]);

}

return numero;
};



string DectoHex(string deci_str){


int coc=1;
int res,deci;
int i=0;
int n[i];
string numero="";
deci=stoi(deci_str);

while(coc!=0){
	coc= deci/16;
	res=deci%16;
	deci=coc;
	n[i]=res;
	i++;
	}
	
string hexa[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

for (int j=0;j<i;j++)
{numero+=hexa[n[i-(j+1)]];

}
return numero;
};

string Bintodeci(string bin_str){


int bin;
int i=0;
int deci=0;
string num="";
bin=stoi(bin_str);

while (bin> 0)
{
    int numero= bin%10;
    bin /= 10;
    deci += numero*pow(2,i);
    i++;
    
   
}
num=to_string(deci);
return num;
};

string Hexatodeci(string numero){
char hexa[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int potencia=0; 
int deci=0;

  
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
return to_string(deci);
};

string Binatohexa(string numero){

  int deci=0;
  int potencia=1;

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
    
   return res;
   };
   
 string Hexatobin(string numero){

  char hexa[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  int potencia=0;
  int res;
  string bin;
  int deci=0;
  int coc=1;
  int i=0;
  string num="";
   
  
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
	num+=to_string(n[i-(j+1)]);

	}
	return num;
}








int main()
{

ifstream archivoUsuarios( "Punto2b.dat" );

  //if ( !archivoUsuarios)
  if ( archivoUsuarios.fail() )   
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

 string valor, sistema1, sistema2;
 
 ofstream ArchivoUsuarioSalida;
 
 ArchivoUsuarioSalida.open("Punto2bSalida.dat");
 
 while ( archivoUsuarios >> valor >> sistema1 >> sistema2 )
 {
  
  if (sistema1 == "decimal" && sistema2 == "hexadecimal")
   {
    ArchivoUsuarioSalida<<setw(10)<<valor<<setw(15)<<sistema1<<setw(15)<<sistema2<<setw(15)<<DectoHex(valor)<<endl;
   }
   if (sistema1 == "decimal" && sistema2 == "binario")
   {
    ArchivoUsuarioSalida<<setw(10)<<valor<<setw(15)<<sistema1<<setw(15)<<sistema2<<setw(15)<<DectoBin(valor)<<endl;
   }
   if (sistema1 == "binario" && sistema2 == "decimal")
   {
   ArchivoUsuarioSalida<<setw(10)<<valor<<setw(15)<<sistema1<<setw(15)<<sistema2<<setw(15)<<Bintodeci(valor)<<endl;
   }
    if (sistema1 == "hexadecimal" && sistema2 == "decimal")
   {
   ArchivoUsuarioSalida<<setw(10)<<valor<<setw(15)<<sistema1<<setw(15)<<sistema2<<setw(15)<<Hexatodeci(valor)<<endl;
   }
    if (sistema1 == "binario" && sistema2 == "hexadecimal")
   {
   ArchivoUsuarioSalida<<setw(10)<<valor<<setw(15)<<sistema1<<setw(15)<<sistema2<<setw(15)<<Binatohexa(valor)<<endl;
   }
    if (sistema1 == "hexadecimal" && sistema2 == "binario")
   {
   ArchivoUsuarioSalida<<setw(10)<<valor<<setw(15)<<sistema1<<setw(15)<<sistema2<<setw(15)<<Hexatobin(valor)<<endl;
   }
   
 }  
return 0;
}




