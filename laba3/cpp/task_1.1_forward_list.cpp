#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

int main() {
    system("chcp 65001 > nul");
    forward_list<string> stringList; // forward-list 'string'-типу для додавання знаку "!" в майбутньому

    { // local vision block start
        forward_list<int> intList = {10, 7, 25, 13, 30}; // Початковий односпрямований список із цілих чисел (цілі числа)
        cout << "Початковий список (int): ";
        for (int num : intList) cout << num << " ";
        cout << "\n";

        auto before_end = stringList.before_begin();
        for (int num : intList) {
            before_end = stringList.insert_after(before_end, to_string(num));
            if (num % 5 == 0) before_end = stringList.insert_after(before_end, "!");
        }
    } // local vision block destroy

    cout << "Результуючий список: ";
    for (const auto& str_item : stringList) cout << str_item << " ";
    cout << "\n";

    return 0;
}