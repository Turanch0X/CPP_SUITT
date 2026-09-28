#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

void push_back(Node*& head, string value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_node;
}

void print_list(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

void add_exclamation(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        int number = stoi(current->data);

        if (number % 5 == 0) {
            Node* exclamation = new Node("!");

            exclamation->next = current->next;
            current->next = exclamation;

            // Перестрибуємо через створений "!"
            current = exclamation->next;
        }
        else {
            current = current->next;
        }
    }
}

int main() {
    system("chcp 65001 > nul");
    Node* head = nullptr;

    push_back(head, "10");
    push_back(head, "7");
    push_back(head, "25");
    push_back(head, "13");
    push_back(head, "30");

    cout << "До: ";
    print_list(head);

    add_exclamation(head);

    cout << "Після: ";
    print_list(head);

    return 0;
}