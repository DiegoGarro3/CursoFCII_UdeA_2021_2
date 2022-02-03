
#include <iostream> 
using namespace std; 


int main() 
{ 
   int x = -1; 
  
   // instruciones preliminares.....

   cout << "antes del try \n"; 
   try { 
      cout << "dentro del try \n"; 
      if (x < 0) 
      { 
	throw x; // el tipo de escepcion sera un entero
         cout << "despues del throw (NO se debe ejecutar) \n"; 
      } 
   } 
   catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
  
   cout << "despues del catch (esto seguira ejecutandose) \n"; 

   
   cout << endl;
   cout << "aca una excepcion general. \n"; 

   try  { 
       throw 10; 
    } 
    catch (char excp)  { 
        cout << "Caught " << excp; 
    } 
    catch (...)  { 
        cout << "por default \n"; 
    } 
   

   return 0; 
} 

