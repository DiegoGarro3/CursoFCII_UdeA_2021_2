#include <iostream>
#include <string>

using namespace std;

//bool isvalidInt(string); // declaración de función (prototipo)

namespace comprDatos
{

  bool isvalidInt(string str)
  {
    int inicio = 0;
    int i;
    bool valido = true; // supone un número válido 
    bool signo = false;
    // supone que no es signo

    // comprueba una cadena vacía
     if (int(str.length()) == 0) valido = false;
     // comprueba un signo a la izquierda
     
     if (str.at(0) == '-'|| str.at(0) == '+') 
     {  
       signo = true;
       inicio = 1; // inicia la comprobación de dígitos después del signo
     }
     
     // comprueba que haya al menos un carácter después del signo
     if (signo && int(str.length()) == 1) valido = false;
     
     // ahora comprueba la cadena, la cual sabemos que al menos tiene un carácter que no es un signo
     i = inicio;
     while(valido && i < int(str.length()))
       {
	 if(!isdigit(str.at(i))) valido = false;  // encuentra un caracter que no es un dígito
	   i++; // se mueve al siguiente carácter
     }
     return valido;
  }
  
  int getanInt()
  {
    //bool isvalidInt(string); // declaración de función (prototipo)
    bool notanint = true;
    string segundo_valor;
    while (notanint)
      {
	try
	  {
	    cin >> segundo_valor; // acepta una entrada de cadena
	    if (!isvalidInt(segundo_valor)) throw segundo_valor;
	  }
	catch (string e)
	  {
	    cout << "Número entero invalido - Por favor reintroduzca: ";
	    continue; // envía el control a
	  }
	notanint = false;
      }
    return atoi(segundo_valor.c_str());
  }
  
}  // fin del namespace comprDatos  
