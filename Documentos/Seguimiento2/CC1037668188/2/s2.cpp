#include"s2.h"
#include<cmath>
#include<string>

Conversion::Conversion(void)
{

};

string Conversion::DecimalToBinario(int n)
{
    string nd_bin;

    while (n != 0)
    {
      if (n %2 == 0)
      { 
	nd_bin ="0"+ nd_bin; 
	n/=2; 
      }
      else
      {
	nd_bin= "1"+ nd_bin;
	n/=2;
      }
    }
    return nd_bin;

};

int Conversion::BinarioToDecimal(string n)
{
    int nb_dec = 0;
    int pot = 1;
    for (int i = n.length()-1 ; i >= 0 ; i--)
    { 
        if(n[i] == '1')
        { 
        nb_dec += pot;
        }
        pot *= 2;
    }
    return nb_dec;

};
string Conversion::DecimalToHexadecimal(int n)
{
    char alfab_hexa[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string nd_h;
    while( n%16 != 0 )
    {
      int k = n % 16; 
      nd_h = alfab_hexa[k]+nd_h;
      n/=16;  
    }
    return nd_h;
}; 
int Conversion::HexadecimalToDecimal(string n)
{
  char alfab_hexa[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  int pot=0; 
  int nh_d=0;
  for (int i = n.length() - 1 ; i >= 0 ; i--)
  {
    for(int j=0;j<=15;j++)
    {     
      if (n[i] == alfab_hexa[j]) 
        {
	nh_d += j * pow(16, pot);
	pot += 1;
        }
    }
  }
    return nh_d;
}; 
string Conversion::BinarioToHexadecimal(string n)
{
    int k;
    string nb_h;
    k=BinarioToDecimal(n);
    nb_h=DecimalToHexadecimal(k);
    return nb_h;

}; 
string Conversion::HexadecimalToBinario(string n)
{
    int k;
    string nh_b;
    k=HexadecimalToDecimal(n);
    nh_b=DecimalToBinario(k);
    return nh_b;
}; 

