#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct TList {
    Node* First;
    Node* Last;
    Node* Current;
};

void InsertLast(TList& L, int D) {
    Node* newNode = new Node;

    newNode->data = D;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (L.First == nullptr) {
        L.First = newNode;
        L.Last = newNode;
        L.Current = newNode;
    }

    else {
        newNode->prev = L.Last;
        L.Last->next = newNode;

        L.Last = newNode;
        L.Current = newNode;
    }
}

int main() {
    system("chcp 65001 > nul");
    TList L{nullptr, nullptr, nullptr};

    int N;

    cout << "N = ";
    cin >> N;

    cout << "Enter " << N << " numbers:\n";

    for (int i = 0; i < N; i++) {
        int number;
        cin >> number;

        InsertLast(L, number);
    }

    cout << "\nFirst:   " << L.First << endl;
    cout << "Last:    " << L.Last << endl;
    cout << "Current: " << L.Current << endl;

    return 0;
}