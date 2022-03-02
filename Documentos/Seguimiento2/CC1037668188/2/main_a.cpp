#include"s2.cpp"
#include<string>
using namespace std;
int main()
{
    Conversion Conver;
    cout<<endl;
    cout<<"Ingrese 1 para convertir decimal a binario"<<endl;
    cout<<"Ingrese 2 para convertir binario a decimal"<<endl;
    cout<<"Ingrese 3 para convertir decimal a hexadecimal"<<endl;
    cout<<"Ingrese 4 para convertir hexadecimal a decimal"<<endl;
    cout<<"Ingrese 5 para convertir binario a hexadecimal"<<endl;
    cout<<"Ingrese 6 para convertir hexadecimal a binario"<<endl;

    cout<<endl;
    cout<<"Ingrese el numero del conversor: ";
    int out;
    cin>>out;
    cout<<endl;
    if(out==1)
    {
    int n;
    cout<<"Conversor Decimal a Binario"<<endl;
    cout<<"Ingrese el número a convertir: ";
    cin>>n;
    string k;
    k=Conver.DecimalToBinario(n);
    cout<< "El decimal: "<< n << " en el sistema Binario es: "<< k<<endl;
    };
    if(out==2)
    {
    string n;
    cout<<"Conversor Binario a Decimal"<<endl;
    cout<<"Ingrese el número a convertir: ";
    cin>>n;
    int k;
    k=Conver.BinarioToDecimal(n);
    cout<< "El binario: "<< n << " en el sistema Decimal es: "<< k <<endl;
    };
    if(out==3)
    {
    int n;
    cout<<"Conversor Decimal a Hexadecimal"<<endl;
    cout<<"Ingrese el número a convertir: ";
    cin>>n;
    string k;
    k=Conver.DecimalToHexadecimal(n);
    cout<< "El decimal: "<< n << " en el sistema Hexadecimal es: "<< k<<endl;
    };
    if(out==4)
    {
    string n;
    cout<<"Conversor Hexadecimal a Decimal"<<endl;
    cout<<"Ingrese el número a convertir: ";
    cin>>n;
    int k;
    k=Conver.HexadecimalToDecimal(n);
    cout<< "El Hexadecimal: "<< n << " en el sistema Decimal es: "<< k <<endl;
    };
    if(out==5)
    {
    string n;
    cout<<"Conversor  Binario a Hexadecimal"<<endl;
    cout<<"Ingrese el número a convertir: ";
    cin>>n;
    string k;
    k=Conver.BinarioToHexadecimal(n);
    cout<< "El Binario: "<< n << " en el sistema Hexadecimal es: "<< k <<endl;
    };
    if(out==6)
    {
    string n;
    cout<<"Conversor Hexadecimal a Binario"<<endl;
    cout<<"Ingrese el número a convertir: ";
    cin>>n;
    string k;
    k=Conver.HexadecimalToBinario(n);
    cout<< "El Hexadecimal: "<< n << " en el sistema Binario es: "<< k <<endl;
    };
    cout<<endl;

    return 0;
}