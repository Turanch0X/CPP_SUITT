#include <iostream>
#include <queue>
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

    queue<Product> products;

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
    cout << "\nТовар успішно додано до черги!\n\n";

    cout << "================ СПИСОК ТОВАРІВ У ЧЕРЗІ ================\n";
    
    queue<Product> tempQueue = products; // тимчасова копія черги
    double totalPrice = 0.0;
    int count = 0;

    while (!tempQueue.empty()) {
        Product p = tempQueue.front(); // 1-ий елемент черги

        cout << "Товар №" << (count + 1) << ": " 
                  << left << setw(15) << p.name 
                  << " | Ціна: " << p.price << " грн\n";

        totalPrice += p.price;
        count++;

        tempQueue.pop(); // видалення копії черги з пам'яті.
    }

    // Обчислення та вивід середньої ціни
    cout << "--------------------------------------------------------\n";
    
    if (count > 0) {
        double averagePrice = totalPrice / count;
        cout << "Загальна кількість товарів: " << count << "\n";
        cout << "Загальна вартість:           " << totalPrice << " грн\n";
        cout << "Середня ціна товарів:       " << averagePrice << " грн\n";
    } else cout << "Черга порожня!\n";

    return 0;
}