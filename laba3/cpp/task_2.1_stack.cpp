#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    system("chcp 65001 > nul");
    cout << fixed << setprecision(2);

    stack<Product> products;

    products.push({"Хліб", 26.14});
    products.push({"Сметана", 48.60});
    products.push({"Ізюм", 88.50});

    cout << "--- ДОДАВАННЯ НОВОГО ТОВАРУ ---\n";
    Product newProd;
    cout << "Введіть назву товару: ";
    cin >> newProd.name;
    cout << "Введіть ціну товару: ";
    cin >> newProd.price;

    products.push(newProd);
    cout << "\nТовар успішно додано до стека!\n\n";

    cout << "================ СПИСОК ТОВАРІВ У СТЕКУ ================\n";
    
    stack<Product> tempStack = products; // тимчасова копія стека
    double totalPrice = 0.0;
    int count = 0;

    while (!tempStack.empty()) {
        Product p = tempStack.top();
        cout << "Товар №" << (count + 1) << ": " 
                  << left << setw(15) << p.name 
                  << " | Ціна: " << p.price << " грн\n";

        totalPrice += p.price;
        count++;

        tempStack.pop(); // Видаляємо оброблений верхній елемент із копії
    }

    // Обчислення та вивід середньої ціни
    cout << "--------------------------------------------------------\n";
    if (count > 0) {
        double averagePrice = totalPrice / count;
        cout << "Загальна кількість товарів: " << count << "\n";
        cout << "Загальна вартість:           " << totalPrice << " грн\n";
        cout << "Середня ціна товарів:       " << averagePrice << " грн\n";
    } else {
        cout << "Стек порожній!\n";
    }

    return 0;
}