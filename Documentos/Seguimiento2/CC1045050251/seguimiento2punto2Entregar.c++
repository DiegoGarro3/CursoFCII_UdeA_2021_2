#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <conio.h>
using namespace std;

/*me base en este
https://www.lawebdelprogramador.com/foros/C-Visual-C/976836-Conversion-Hexadecimal-a-Decimal-en-C.html
*/

void binariodecimal(){
  int exp=0,digito=0; double binario, decimal;
  cout << "Ingrese numero binario: ";cin >> binario;
  while(((int)(binario/10))!=0){
    digito = (int)binario % 10;
    decimal = decimal + digito * pow(2.0,exp);
    exp++;
    binario=(int)(binario/10);
  }
  decimal=decimal + binario * pow(2.0,exp);
  cout << endl << "En decimal es: " << decimal << endl;

}

void hexadecimalbinario(){
  string bin,numero;
  int coc=1, i=0, deci=0,res, potencia=0;
  char hexa[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  cout<<"Ingrese en hexadecimal"<<endl;cin>>numero;
  cout<<"En binario es:"<<endl;

  for (int i = numero.length() - 1 ; i >= 0 ; i--){

    for(int j=0;j<=15;j++){
      if (numero[i] == hexa[j]){
        deci += j * pow(16, potencia);
        potencia += 1;}
 }
}
  vector<int> n;
  while(coc>=0){
    coc= deci/2;res=deci%2;
    deci=coc; n.push_back(res);
    i++;
if (coc==0){
  break;
}}
for (int j=0;j<i;j++)
{
cout<<n[i-(j+1)];

}
}

void hexadecimaldecimal(){
  string numero;
  int potencia=0,deci=0;
  cout<<"Ingrese numero hexadecimal"<<endl; cin>>numero;
  char hexa[16]={'0','1','2','3',
  '4','5','6','7','8',
  '9','A','B','C','D','E','F'};

  cout<<"En decimal es:"<<endl;
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
}

void binarioahexa(){
  int deci=0, potencia=1;string num;
  cout<<"Ingrese numero binario:"<<endl;cin>>num;
  cout<<"En hexadecimal es:"<<endl;

  char hexa[16] = {'0','1','2','3',
  '4','5','6','7',
  '8','9','A','B',
  'C','D','E','F'};
  for (int i = num.length() - 1 ; i >= 0 ; i--)
  {
    if(num[i]=='1')
    {
      deci += 1 * potencia;
    }
    potencia *= 2;
  }
    string res;
    while(deci % 16 !=0 )
    {
      int n = deci % 16;
      res = hexa [n] + res;
      deci /= 16;
    }
   cout<<res<<endl;
   }

string decimalbinario(){
  /* base mi codigo en este otro
  https://www.delftstack.com/es/howto/cpp/how-to-convert-decimal-number-to-binary-in-cpp/
  */
  int n;
  cout<<"Ingrese un numero decimal"<<endl;cin>>n;
  cout<<"en binario es:"<<endl;
  string r;
  while (n != 0){
      r += ( n % 2 == 0 ? "0" : "1" );
      n /= 2;
  }
  cout << r << '\n';
  return r;
}


void decimalhexa(){
  int deci,res,cociente=1,i=0,n[i];
  cout<<"Ingrese un numero decimal"<<endl;cin>>deci;
  cout<<"en hexadecimal es:"<<endl;

  string hexa[16]={"0","1","2","3",
  "4","5","6","7","8",
  "9","A","B","C",
  "D","E","F"};
  while(cociente!=0){
  	cociente= deci/16;
  	res=deci%16;
  	deci=cociente;
  	n[i]=res;
  	i++;
  }
  for (int j=0;j<i;j++)
  {cout<<hexa[n[i-(j+1)]];}
  cout<<endl;
}

int main() {
  int seleccion;
  std::cout << "opciones: " << '\n';
  std::cout << "1 - Decimal -> Binario\n" << '\n';
  std::cout << "2 - Decimal -> Hexadecimal\n" << '\n';
  std::cout << "3 - Binario -> Decimal\n" << '\n';
  std::cout << "4 - Binario -> Hexadecimal\n" << '\n';
  std::cout << "5 - Hexadecimal -> Decimal\n" << '\n';
  std::cout << "6 - Hexadecimal -> Binario\n" << '\n';
  std::cin >> seleccion;

  if (seleccion==1){decimalbinario();}
  if (seleccion==2){decimalhexa();}
  if (seleccion==3){binariodecimal();}
  if (seleccion==4){binarioahexa();}
  if (seleccion==5){hexadecimaldecimal();}
  if (seleccion==6){hexadecimalbinario();}

  //decimalhexa();
  //decimalbinario();
  //binarioahexa();
  //binariodecimal();
  //hexadecimaldecimal();
  //hexadecimalbinario();
  return 0;
}
