#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    explicit Node(int value) : data(value), next(nullptr) {}
};

void append(Node*& head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) current = current->next;
    current->next = node;
}

void display(const Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void reverseUsingStack(Node* head) {
    stack<int> values;
    for (Node* current = head; current != nullptr; current = current->next)
        values.push(current->data);

    for (Node* current = head; current != nullptr; current = current->next) {
        current->data = values.top();
        values.pop();
    }
}

void clearList(Node*& head) {
    while (head != nullptr) {
        Node* old = head;
        head = head->next;
        delete old;
    }
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "How many nodes? ";
    if (!(cin >> n) || n < 0) {
        cout << "Please enter a non-negative number.\n";
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        append(head, value);
    }

    cout << "Original list: ";
    display(head);

    reverseUsingStack(head);

    cout << "Reversed list: ";
    display(head);

    clearList(head);
    return 0;
}
