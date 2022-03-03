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

    ofstream Archivo_salida( "Archivo_salida.dat" );
  
  	 
  
  	if(Archivo_salida.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}



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
            if(sis2=="binario"){
            cout<<Conver.DecimalToBinario(numero);
	        Archivo_salida<<left<<setw(13)<<numero<<setw(13)<<sis1<<setw(13)<<sis2<<setw(13)<<Conver.DecimalToBinario(numero)<<endl;
            };
            if(sis2=="Hex")
            {
            cout<<Conver.DecimalToHexadecimal(numero);
            Archivo_salida<<left<<setw(13)<<numero<<setw(13)<<sis1<<setw(13)<<sis2<<setw(13)<<Conver.DecimalToHexadecimal(numero)<<endl;
            }
        }
        if(sis1=="binario")
        {
            string num=to_string(numero);
            if(sis2=="decimal")
            {
            cout<< Conver.BinarioToDecimal(num);
            Archivo_salida<<left<<setw(13)<<numero<<setw(13)<<sis1<<setw(13)<<sis2<<setw(13)<<Conver.BinarioToDecimal(num)<<endl;
            }
            if(sis2=="Hex")
            {
            cout<< Conver.BinarioToHexadecimal(num);
            Archivo_salida<<left<<setw(13)<<numero<<setw(13)<<sis1<<setw(13)<<sis2<<setw(13)<<Conver.BinarioToHexadecimal(num)<<endl;
            }
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
