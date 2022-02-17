#include"s2.cpp"
#include<string>
#include <fstream> 
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    Conversion Conver;
    ifstream archivo( "ConvertirNum.dat" ); 
    if ( archivo.fail() )    
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
    cout<<endl;
    cout<<"Archivo leido: ConvertirNum.dat"<<endl;
    cout<<endl;

    int numero;
    string sis1;
    string sis2;
    cout<< "Número     Sist. Num. 1     Sist. Num. 2      Numero " << endl;
    cout<< "------     ------------     ------------      ------"<<endl;
    while ( archivo >> numero >> sis1 >> sis2 )
    {
        cout<<left<<setw(13)<<numero<<setw(18)<< sis1<<setw(15)<< sis2;
        if(sis1=="decimal")
        {
            if(sis2=="binario")
            cout<< Conver.DecimalToBinario(numero);
            if(sis2=="Hex")
            cout<< Conver.DecimalToHexadecimal(numero);
        }
        if(sis1=="binario")
        {
            string num=to_string(numero);
            if(sis2=="decimal")
            cout<< Conver.BinarioToDecimal(num);
            if(sis2=="Hex")
            cout<< Conver.BinarioToHexadecimal(num);
        };

        /*   
        if(sis1=="Hex")
        {
            string num=to_string(numero);
            if(sis2=="decimal")
            cout<< Conver.HexadecimalToDecimal(num);
            if(sis2=="binario")
            cout<< Conver.HexadecimalToBinario(num);
        }; */
        cout<<endl;


    };
    archivo.close();
    cout<<endl;
    return 0;
};
