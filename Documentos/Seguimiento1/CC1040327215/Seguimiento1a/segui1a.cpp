#include <iostream>
using namespace std;




int main()
{
  int notas[9], contador; // creamos el arreglo con 10 espacios y anunciamos el contador
  contador = 0; // inicializamos el contador
  cout << "Bienvenido al Libro Calificador, por favor ingrese las notas \n";
  for(int i=0 ; i<10; i++){ // Iniciamos el for que irá llenando el arreglo con las notas que ingrese el usuario

    cout << "\n Notal de " << i+1 << " estudiante:\n";
    cin >> notas[i]; // Le pedimos al usuario que ingrese las notas

  }

  for(int i=0; i<10; i++){ // Con este for miraremos cuantas veces se repite la nota 1, es decir, cuantos estudiantes ganaron el examen
    if(1==notas[i]){        // si hay 8 estudiantes o màs que ganaron el curso, felicitamos el instructor una vez finalice el programa
      contador++; // contador que nos dará cuenta de la cantidad de estudiantes que ganaron el curso

      if(contador==8){ // con que 8 ganen el examen felicitamos al instructor
	cout << "<excelente instructor>\n"; 

      }

    }

  }

  

return 0; 
}
