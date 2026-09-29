#include <iostream>
#include <list>
using namespace std;

using PNode = list<int>::iterator; // PNode визначаємо як тип ітератора для std::list<int>

struct TList { // Описуємо тип TList
    list<int> items; // Сам STL-контейнер двозв'язного списку
    PNode First;          // Ітератор на перший елемент
    PNode Last;           // Ітератор на останній елемент
    PNode Current;        // Ітератор на поточний елемент
};

// Процедура InsertLast(L, D)
void InsertLast(TList& L, int D) {
    L.items.push_back(D); // Додаємо новий елемент D в кінець списку STL

    L.First = L.items.begin(); // Оновлюємо ітератор на перший елемент

    L.Last = prev(L.items.end()); // Оновлюємо ітератор на останній елемент (--L.items.end() вказує на останній елемент)

    L.Current = L.Last; // За умовами завдання: доданий елемент стає поточним
}

int main() {
    system("chcp 65001 > nul");
    TList L;

    int N;
    cout << "Введіть кількість чисел N: "; cin >> N;

    if (N <= 0) {
        cout << "Кількість N має бути більше 0!\n";
        return 1;
    }

    cout << "Введіть " << N << " чисел:\n";
    for (int i = 0; i < N; ++i) {
        int D;
        cin >> D;
        InsertLast(L, D); // Додаємо елемент у кінець списку
    }

    // Виводимо адреси елементів у пам'яті за допомогою ітераторів First, Last, Current
    cout << "\n================ РЕЗУЛЬТАТ ================\n";
    cout << "Адреса першого елемента (&*First):   " << &(*L.First) << "\n";
    cout << "Адреса останнього елемента (&*Last):    " << &(*L.Last) << "\n";
    cout << "Адреса поточного елемента (&*Current):  " << &(*L.Current) << "\n";

    cout << "\n--- Значення за відповідними ітераторами ---\n";
    cout << "Значення First:   " << *L.First << "\n";
    cout << "Значення Last:    " << *L.Last << "\n";
    cout << "Значення Current: " << *L.Current << "\n";

    return 0;
}