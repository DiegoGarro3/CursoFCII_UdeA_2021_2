#include <iostream>
#include <fstream> // flujo de archivo
#include <string>
#include <sstream>
#include <cstring> // this is to use strlen to know the length of the char array
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int busquedaLineal( const char arreglo[], int clave, int tamanioDelArreglo )
{
  for ( int j = 0; j < tamanioDelArreglo; j++ ){
    if ( arreglo[ j ] == clave ){ 
      return j;
    }
  }
  
  return -1; // no se encontró la clave
}

int HextoDecimal( const char * num) //const char * equivale a string
{
    int NumConverted{0};
    size_t size = strlen(num);
    char nnumbers[]="0123456789";//{"0","1","2","3","4","5","6","7","8","9",'\0'};
    for (int i=0; num[i] != '\0'; i++){
      double b=0;
      b=busquedaLineal(nnumbers,num[i],strlen(nnumbers));
      //cout << b << endl;
      if (b!=-1){ //if the entry of the char array was a number
      	//cout << num[i] << endl;
      	stringstream str;
      
      	str << num[i];

      	int x{0};
      	str >> x;
        NumConverted=NumConverted+x*pow(16,(size-1-i));
        //cout << "exponent is" << (size-1-i) << endl;
      	//cout << "Converted value of character : " << (x) << endl;
      }
      if (b==-1)//if the entry was a letter
      {  
        int let{0};
        if (num[i]=='A'){ let=10;}
        if (num[i]=='B'){ let=11;}
        if (num[i]=='C'){ let=12;}
        if (num[i]=='D'){ let=13;}
        if (num[i]=='E'){ let=14;}
        if (num[i]=='F'){ let=15;}
        NumConverted=NumConverted+let*pow(16,(size-1-i));
        //cout << "let is" << let << "exponent is" << (size-1-i) << endl;
      }

    } //end of for for each number/letter
    cout << "from Hex to Decimal: " << NumConverted << endl;
    return NumConverted;
   
}

string DecimaltoHexa( const char * num)
{
    //convert char to int
    stringstream str;  
    str << num;
    int x{0};
    str >> x;
    
    int Quotient{1};
    int Remainder{0};
    string Converted;
    //char const *ConvertedtoHexa_c;
    
    while (Quotient!=0){

    	Quotient=x/16;
    	Remainder=x%16;
        string rem = to_string(Remainder);
        if (rem=="10"){rem="A";}
        if (rem=="11"){rem="B";}
        if (rem=="12"){rem="C";}
        if (rem=="13"){rem="D";}
        if (rem=="14"){rem="E";}
        if (rem=="15"){rem="F";}
        Converted=rem + Converted;
        //ConvertedtoHexa_c=Converted.c_str();
        
        
        x=Quotient;
       
    }
    cout << "from Decimal to Hexa: " << Converted << endl;
    return Converted; //*ConvertedtoHexa_c;

}


string bintohex( string num )
{
    string Hexa[20] ={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};;
    string Binary[]={"0000" ,"0001", "0010", "0011", "0100", "0101", "0110" , "0111" ,"1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    string Conversion;
    size_t size=num.length();
    string binst;
    //cout << Binary[2] << endl;
    if ((size % 2)!=0){num="0"+num;}
    
    for (int i=0; i<=size; i++)
    {   
 
       binst=binst+num[i];
       int j{0};
       while ( (binst.length() % 4)==0 ){
            
            //cout << binst << "=" << Binary[j] << endl;
	    if ( binst==Binary[j] )
	      {  
                
		Conversion=Conversion+Hexa[j];
                binst="";
                break;
	      }
            j++;

        }
     }
     cout << "from binary to Hexa: " << Conversion << endl;    
     return Conversion;
}

string Decitobin( string num )
{
    //convert char to int
    stringstream str;  
    str << num;
    int x{0};
    str >> x;
    
    int Quotient{1};
    int Remainder{0};
    string Converted;

    
    while (Quotient!=0){

    	Quotient=x/2;
    	Remainder=x%2;
        string rem = to_string(Remainder);
        Converted=rem + Converted;

        x=Quotient;
       
    }
    cout << fixed << "from Decimal to Binary: " << Converted << endl;
    return Converted; 

}

string whicConver(const char* a, string X, string Y){
    int nc;
    string numconverted;
    string hex;
    if (X=="Hex"){
       if (Y=="decimal"){nc=HextoDecimal(a); numconverted=to_string(nc);}
       if (Y=="binario"){nc=HextoDecimal(a); string ncs = to_string(nc);  string bin=Decitobin(ncs); numconverted=bin;}
    }
     
    if (X=="decimal"){
       if (Y=="Hex"){string Hexa=DecimaltoHexa(a); numconverted=Hexa;}
       if (Y=="binario"){string bin=Decitobin(a); numconverted=bin;}
    }
    
    if (X=="binario"){
       if (Y=="decimal"){hex=bintohex(a); const char* hexx=hex.c_str(); nc=HextoDecimal(hexx); numconverted=to_string(nc);}
       if (Y=="Hex"){hex=bintohex(a); numconverted=hex;}
    }
    return numconverted;
}


int main()
{   
    
    int nc;
    char num[20];
    string hex;
    string X;
    string Y;
    string numconverted;
     
    cout << "ingrese un numero entero cualquiera" << endl;
    cin >> num;
    cout << "ingrese el sistema numerico del numero anterior (decimal,binario o Hex)" << endl;
    cin >> X;
    cout << "ingrese el sistema numerico al cual quiere convertir el numero (decimal,binario o Hex)" << endl;
    cin >> Y; 
    numconverted=whicConver(num,X,Y);
    cout << "\n" << endl;

    ifstream Listtoconvert( "List.dat", ios::in );
  
    if ( !Listtoconvert )
      {
        cerr << "No se pudo abrir el archivo" << endl;
        exit( 1 );
      }

    Listtoconvert >> num >> X >> Y;
   
    //crea un archivo donde guardar los datos
    ofstream ListConverted( "ListConverted.dat", ios::out );
    // muestra el contenido del archivo (hasta eof)
    ListConverted << fixed << setw(5) << num << setw(18) << X << setw(18) << Y << setw(18) <<  "Num Converted" << endl;
    Listtoconvert >> num >> X >> Y;
    while ( !Listtoconvert.eof() )
      { 
          //cout << num << X << Y << endl;
          numconverted=whicConver(num,X,Y);
          cout << fixed << setw(5) << num << setw(18) << X << setw(18) << Y << setw(18) <<  numconverted << endl;
          ListConverted << fixed << setw(5) << num << setw(18) << X << setw(18) << Y << setw(18) <<  numconverted << endl;
          Listtoconvert >> num >> X >> Y;
      }
}
