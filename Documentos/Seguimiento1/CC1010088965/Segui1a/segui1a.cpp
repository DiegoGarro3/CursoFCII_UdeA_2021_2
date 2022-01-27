#include <iostream>

using namespace std;

int main() {
    cout << "Ahora se muestra una lista de 10 estudiantes. Junto a cada nombre escriba un 1 si el estudiante ha aprobado el examen o un 2 si el estudiante ha fallado:" << endl;
    int approvedStudents;
    for (int i = 0; i < 10; i++)
    {
        cout << "Estudiante " << i + 1 << ": ";
        int score;
        cin >> score;
        if (score == 1) {
            approvedStudents += 1;
        }
    }
    if (approvedStudents > 8) {
        cout << "Excelente instructor" << endl;
    }

    return 0;
}