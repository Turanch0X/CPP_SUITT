//Створити стек, інформаційними полями якого є: назва товара та його
//ціна. Додати у стек відомості про новий товар. Організувати перегляд
//даних стека та обчислити середню ціну товарів.

// У програмі повинні бути передбачені наступні функції: «Додавання елемента»; «Видалення
// елемента»; «Перегляд»; «Очистка». Повинні бути передбачені аварійні ситуації
// (наприклад: не можна видалити елемент, якщо стек порожній).

#include <iostream>
#include <string>
using namespace std;

struct goods {
    string name;
    double price;
    goods* next;
};

goods* roof = 0;

void add_item(string item_name, double item_price) {
    goods* current = new goods;
    current->name = item_name;
    current->price = item_price;
    current->next = roof;
    roof = current;
}

void show_info() {
    goods* current = roof;

    while (current != 0) {
        cout << current->name << ":\t" << current->price << "\n";
        current = current->next;
    }
}

void del() {

    if (roof == nullptr) {
        cout << "Стек порожній! Немає чого видаляти." << endl;
        return;
    }

    goods* current = roof;
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

double average_price() {
    double total_sum = 0, items = 0;
    goods* current = roof;

    while (current != 0) {
        total_sum += current->price;
        current = current->next;
        items += 1;
    }

    return total_sum / items; //середнє арифметичне цінника (без урахування кіл-ті одиниць одного товару)
}



int main() {
    system("chcp 65001 > nul");
    int n;
    double price;
    string name = "";
    cout << "Введіть кількість товарів: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nНазва " << i << "-ого товару: ";
        cin >> name;
        cout << "Ціна " << i << "-ого товару: ";
        cin >> price;
        add_item(name, price);
    }
    show_info();
    double average = average_price();
    cout << "Середня вартість одного товару: " << average;
    clear();
    return 0;
}