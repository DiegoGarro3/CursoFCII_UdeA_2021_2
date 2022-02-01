// Uso de strcpy y strncpy.
#include <iostream>
#include <cstring> 
#include <iomanip>

using namespace std;

int main()
{
  char *s1 = "Felices Fiestas";
  char *s2 = "Felices Fiestas";
  char *s3 = "Felices Dias de fiesta";

  cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3
       << "\n\nstrcmp(s1, s2) = " << setw( 2 ) << strcmp( s1, s2 )
       << "\nstrcmp(s1, s3) = " << setw( 2 ) << strcmp( s1, s3 )
       << "\nstrcmp(s3, s1) = " << setw( 2 )<< strcmp( s3, s1 );

  cout << "\n\nstrncmp(s1, s3, 8) = " << setw( 2 )<< strncmp( s1, s3, 8 ) << "\nstrncmp(s1, s3, 9) = "
       << setw( 2 ) << strncmp( s1, s3, 9 ) << "\nstrncmp(s3, s1, 9) = "
       << setw( 2 ) << strncmp( s3, s1, 9 ) << endl;
  
 return 0; 
}
