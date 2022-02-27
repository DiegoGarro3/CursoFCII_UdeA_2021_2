#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

#include <map>

#include "Ahorcado.h"

using namespace std;

Ahorcado::Ahorcado() {
    srand(time(NULL));
};

Ahorcado::~Ahorcado() {};

void Ahorcado::setWord(const string & wordIn) { word = wordIn; };
string Ahorcado::getWord() const { return word; };

void Ahorcado::setLifes(int lifesIn) { lifes = lifesIn; };
int Ahorcado::getLifes() const { return lifes; };

void Ahorcado::setLettersFound() {
    lettersFound.clear();
    for (size_t i = 0; i < word.length(); i++) {
        if (lettersFound.find(word[i]) == lettersFound.end()) {
            lettersFound.insert(pair<char, bool>(word[i], false));
        }
    }
}
map<char, bool> Ahorcado::getLettersFound() { return lettersFound; };

void Ahorcado::initializeRandomWord() {
    array<string, 10> words = {
        "palabra",
        "domino",
        "televisor",
        "estatua",
        "lampara",
        "videojuego",
        "computador",
        "teclado",
        "audifonos",
        "infusion"
    };
    int wordIndex = rand() % 10;
    word = words[wordIndex];
}

void Ahorcado::printWord() {
    cout << "\n" << "(Intentos restantes: " << lifes << ") Palabra: ";
    for (size_t i = 0; i < word.length(); i++) {
        if (lettersFound.at(word[i])) {
            cout << word[i];
        } else {
            cout << 'x';
        }
    }
    cout << endl << endl;
}

void Ahorcado::play() {
    map<char, bool>::iterator itr;
    string playerSelection;
    bool allLettersFound;
    bool sleep = true;

    bool globalGameContinued = true;
    bool localGameContinued = true;
    string userContinue;

    while (globalGameContinued) {
        allLettersFound = false;
        initializeRandomWord();
        localGameContinued = true;
        lifes = 7;
        setLettersFound();
        

        while (localGameContinued) {
            sleep = true;
            printWord();

            cout << "Adivine una letra: ";
            cin >> playerSelection;

            if (playerSelection.length() > 1) {
                cout << "¡SOLO UNA LETRA! Intento no válido." << endl;
            } else if (playerSelection.length() == 1) {
                if (lettersFound.find(playerSelection[0]) == lettersFound.end()) {
                    cout << "La letra no se encuentra en la palabra. Pierde un intento." << endl;
                    lifes--;
                } else {
                    if (lettersFound.at(playerSelection[0])) {
                        cout << "Esa letra ya la había adivinado. Intento no válido." << endl;
                    } else {
                        lettersFound.at(playerSelection[0]) = true;
                        allLettersFound = true;
                        for (itr = lettersFound.begin(); itr != lettersFound.end(); ++itr) {
                            if (!(itr->second)) {
                                allLettersFound = false;
                                break;
                            }
                        }
                        if (allLettersFound) {
                            cout << "¡FELICITACIONES! Ha adivinado la palabra." << endl;
                            localGameContinued = false;
                        } else {
                            printWord();
                            cout << "Adivinó correctamente. Si quiere adivine toda la palabra, de lo contrario escriba N: ";
                            cin >> playerSelection;
                            if (playerSelection != "N" && playerSelection != "n") {
                                if (playerSelection == word) {
                                    cout << "¡FELICITACIONES! Ha adivinado la palabra." << endl;
                                    localGameContinued = false;
                                } else {
                                    cout << "No adivinó la palabra. Pierde un intento." << endl;
                                    lifes--;
                                }
                            } else {
                                sleep = false;
                            }
                        }
                    }
                }
            }
            if (lifes == 0) {
                cout << "Mala suerte, ha perdido todos sus intentos." << endl;
                localGameContinued = false;
            }

            if (sleep) {
                this_thread::sleep_for(chrono::milliseconds(1500));
            }
        }

        cout << "Si desea jugar nuevamente escriba S. De lo contrario escriba cualquier cosa: " << endl;
        cin >> userContinue;
        if (userContinue != "S" && userContinue != "s") {
            globalGameContinued = false;
        }

    }

    cout << "Esperamos que haya disfrutado el juego. Hasta luego." << endl;
}