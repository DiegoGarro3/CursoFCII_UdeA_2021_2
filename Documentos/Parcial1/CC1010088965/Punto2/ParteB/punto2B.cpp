#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

bool craps() {
    bool gameContinued = true;
    bool playerWon;
    int dice1;
    int dice2;
    int sum;
    int diceThrow = 0;
    int playerPoint;

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

    return playerWon;
}

int main() {
    int saldoEnBanco = 1000000;
    int playerContinues = true;
    int bet;
    bool playerWonGame;
    string playerResponse;
    int showMessage;

    cout << "Usted esta a punto de comenzar un juego de craps con un saldo de " << saldoEnBanco << endl;
    
    srand(time(NULL));
    while (playerContinues) {
        cout << "Introduzca su apuesta: ";
        cin >> bet;
        while (bet > saldoEnBanco) {
            cout << "La apuesta debe ser menor o igual que el saldo en banco. Introduzca otra apuesta: ";
            cin >> bet;
        }
        cout << "Ahora empieza el juego!" << endl;
        cout << "=============Juego de craps=============" << endl;
        playerWonGame = craps();
        cout << "========================================" << endl;
        if (playerWonGame) {
            showMessage = 1 + rand() % 8;
            if (showMessage < 3) {
                cout << "Uy, una partida ganada para variar! Seguro que esa suerte continua" << endl;
            } else if (showMessage < 5) {
                cout << "Buena racha de suerte, sigue apostando para seguirla!" << endl;
            } else if (showMessage < 7) {
                cout << "La sacaste del estadio! Tal vez sea buena idea cambiar las fichas por plata." << endl;
            } else if (showMessage < 9) {
                cout << "A eso le llamo suerte, y seguro tendras mas!" << endl;
            }
            saldoEnBanco = saldoEnBanco + bet;
        } else {
            showMessage = 1 + rand() % 8;
            if (showMessage < 2) {
                cout << "Hagale, no pasa nada! arriesguese y siga intentando" << endl;
            } else if (showMessage < 5) {
                cout << "Usted se esta quebrando, no le parece?" << endl;
            } else if (showMessage < 7) {
                cout << "No dejes que esa perdida te afecte mucho!" << endl;
            } else if (showMessage < 9) {
                cout << "Mejor trae un amuleto de la suerte la proxima que vengas" << endl;
            }
            saldoEnBanco = saldoEnBanco - bet;
        }
        cout << "Saldo restante: " << saldoEnBanco << endl;
        if (saldoEnBanco != 0) {
            cout << "Escriba S si desea parar el juego. Escriba cualquier otra cosa para lo contrario: ";
            cin >> playerResponse;
            if (playerResponse == "S") {
                playerContinues = false;
                cout << "Ha terminado el juego. Gracias por jugar." << endl;
            }
        } else {
            cout << "Lo siento. Se quedo sin fondos!" << endl;
            playerContinues = false;
        }
    }
}