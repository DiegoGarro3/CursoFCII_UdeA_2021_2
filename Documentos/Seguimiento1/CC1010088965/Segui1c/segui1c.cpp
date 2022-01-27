#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    bool gameStillActive = true;
    bool userGuessing = true;
    int randomChoice = 0;
    int userNumberChoice = 0;
    string userContinueChoice;

    srand(time(NULL));
    while (gameStillActive) {
        randomChoice = 1 + rand() % 1000;
        cout << "Se ha obtenido un numero al azar del 1 al 1000. Por favor intente adivinarlo: ";
        cin >> userNumberChoice;

        while (userNumberChoice != randomChoice) {
            if (userNumberChoice < randomChoice) {
                cout << "Su numero es menor que el numero elegido aleatoriamente." << endl;
            } else {
                cout << "Su numero es mayor que el numero elegido aleatoriamente." << endl;
            }
            cout << "Por favor elija nuevamente: ";
            cin >> userNumberChoice;
        }

        cout << "Ha adivinado el numero correctamente, el cual es " << randomChoice << "." << endl;

        gameStillActive = false;
        cout << "Si desea jugar nuevamente escriba S. De lo contrario escriba cualquier cosa: ";
        cin >> userContinueChoice;

        if (userContinueChoice == "S" || userContinueChoice == "s") {
            cout << "Jugando nuevamente..." << endl;
            gameStillActive = true;
        } else {
            cout << "No ha seleccionado S por lo que el juego terminara. Hasta luego." << endl;
        }
    }
}