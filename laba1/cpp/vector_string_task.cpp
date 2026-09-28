#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    system("chcp 65001 > nul");
    vector<string> words = {
        "TOKYO",
        "LONDON",
        "PariS",
        "c++",
        ""
    };

    int count = 0;

    for (string str : words) {
        if (str.empty())
            continue;
        bool is_upper = true;

        for (char c : str) {
            if (isalpha(c) && !isupper(c))
            {
                is_upper = false;
                break;
            }
        }

        if (is_upper)
        {
            count++;
        }
    }

    cout << "Кількість рядків: " << count << "\n";
}