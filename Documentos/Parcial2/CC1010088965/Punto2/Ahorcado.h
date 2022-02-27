#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>
#include <map>

using namespace std;

class Ahorcado {
    public:
        Ahorcado();
        ~Ahorcado();

        void setLifes(int);
        int getLifes() const;
    
        void setWord(const string &);
        string getWord() const;

        void setLettersFound();
        map<char, bool> getLettersFound();

        void initializeRandomWord();
        void printWord();
        void play();

    private:
        int lifes;
        map<char, bool> lettersFound;
        string word;

};

#endif