// Дано перший член і різницю арифметичної прогресії. Написати рекурсивну функцію для
// знаходження:
//   а) n-го члена прогресії;
//   б) суми n перших членів прогресії.
#include <iostream>
using namespace std;

struct ProgressionResult {
    double number;
    double sum;
};

ProgressionResult recursive(double first, double diff, double roof) {
    ProgressionResult res;
    res.number = first + diff * (roof - 1);
    res.sum = ((2 * first + diff * (roof - 1))/2) * roof;
    return res;
}

int main() {
    system("chcp 65001 > nul");
    double n1, d, roof_n;
    cout << "Ввести 1-ий член прогресії: "; cin >> n1;
    cout << "Ввести різницю прогресії: "; cin >> d;
    cout << "Який елемент взяти на знаходження: "; cin >> roof_n;
    ProgressionResult res = recursive(n1, d, roof_n);

    cout << "N-ний член: " << res.number << endl;
    cout << "Сума: " << res.sum << endl;

    return 0;
}