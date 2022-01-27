#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    bool gameContinued = true;
    bool playerWon;
    int dice1;
    int dice2;
    int sum;
    int diceThrow = 0;
    int playerPoint;

    srand(time(NULL));
    while (gameContinued) {
        diceThrow += 1;
        dice1 = 1 + rand() % 6;
        dice2 = 1 + rand() % 6;
        sum = dice1 + dice2;
        cout << "El jugador lanza dados y obtiene un " << dice1 << " junto con un " << dice2 << " para una suma de " << sum << "." << endl;
        if (diceThrow == 1) {
            if (sum == 7 || sum == 11) {
                cout << "Como la suma es 7 u 11 en el primer tiro, el jugador ha ganado." << endl;
                gameContinued = false;
                playerWon = true;
            } else if (sum == 2 || sum == 3 || sum == 12) {
                cout << "Como la suma es 2, 3 o 12 en el primer tiro, el jugador ha perdido." << endl;
                gameContinued = false;
                playerWon = false;
            } else {
                playerPoint = sum;
                cout << "El punto del jugador es " << playerPoint << "." << endl;
            }
        } else {
            if (sum == 7) {
                cout << "El jugador ha sacado 7 por lo que ha perdido." << endl;
                gameContinued = false;
                playerWon = false;
            } else if (sum == playerPoint) {
                cout << "El jugador ha sacado un numero igual a su punto, por lo que ha ganado." << endl;
                gameContinued = false;
                playerWon = true;
            }
        }
    }

    if (playerWon) {
        cout << "FELICITACIONES" << endl;
    } else {
        cout << "Mejor suerte la proxima." << endl;
    }
}