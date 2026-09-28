// Дано перший член і різницю арифметичної прогресії. Написати рекурсивну функцію для
// знаходження:
//   а) n-го члена прогресії;
//   б) суми n перших членів прогресії.
#include <iostream>
using namespace std;

struct Stack {
    double number;
    double sum;
    Stack* next;
};

Stack* roof = nullptr;

void push(double num, double s) {
    Stack* current = new Stack;
    current->number = num;
    current->sum = s;
    current->next = roof;
    roof = current;
}

double getNthTerm(double first, double diff, int n) {
    if (n <= 1) {
        return first;
    }
    return getNthTerm(first, diff, n - 1) + diff;
}

double getSum(double first, double diff, int n) {
    if (n <= 1) {
        return first;
    }
    return getSum(first, diff, n - 1) + getNthTerm(first, diff, n);
}

void fillStackRecursively(double first, double diff, int n) {
    if (n <= 0) return;

    fillStackRecursively(first, diff, n - 1);

    double term = getNthTerm(first, diff, n);
    double sum = getSum(first, diff, n);
    push(term, sum);
}

void show_info() {
    Stack* current = roof;
    if (current == nullptr) {
        cout << "Стек порожній!" << endl;
        return;
    }
    cout << "\nЕлементи у стеку (число в прогресії -> поточна сума):\n";
    while (current != nullptr) {
        cout << current->number << "\t->\t" << current->sum << "\n";
        current = current->next;
    }
}

void del() {

    if (roof == nullptr) {
        cout << "Стек порожній! Немає чого видаляти." << endl;
        return;
    }

    Stack* current = roof;
    roof = roof->next;
    delete current;
}

void clear() {

    if (roof == nullptr) {
        cout << "Стек вже порожній." << endl;
        return;
    }

    while (roof != nullptr) {
        del(); // Послідовно видаляємо по одному елементу, поки roof не стане NULL
    }
    cout << "\nСтек успішно очищено!" << endl;
}


int main() {
    system("chcp 65001 > nul");
    double n1, d;
    int roof_n;
    cout << "Ввести 1-ий член прогресії: "; cin >> n1;
    cout << "Ввести різницю прогресії: "; cin >> d;
    cout << "Який елемент взяти на знаходження: "; cin >> roof_n;
    
    if (roof_n <= 0) {
        cout << "Номер має бути більше 0!" << endl;
        return 0;
    } 

    double nth_term = getNthTerm(n1, d, roof_n);
    double total_sum = getSum(n1, d, roof_n);

    cout << "\n--- Результати рекурсії ---" << endl;
    cout << roof_n << "-ий член прогресії: " << nth_term << endl;
    cout << "Сума перших " << roof_n << " членів: " << total_sum << endl;

    fillStackRecursively(n1, d, roof_n);
    show_info();
    clear();

    return 0;
}