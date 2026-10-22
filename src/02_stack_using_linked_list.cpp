#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    explicit Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(int value) {
        Node* node = new Node(value);
        node->next = topNode;
        topNode = node;
        cout << value << " pushed.\n";
    }

    bool pop(int& removed) {
        if (topNode == nullptr) return false;
        Node* oldTop = topNode;
        removed = oldTop->data;
        topNode = topNode->next;
        delete oldTop;
        return true;
    }

    bool peek(int& value) const {
        if (topNode == nullptr) return false;
        value = topNode->data;
        return true;
    }

    void display() const {
        if (topNode == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top -> ";
        for (Node* current = topNode; current != nullptr; current = current->next)
            cout << current->data << " -> ";
        cout << "NULL\n";
    }

    ~Stack() {
        int ignored;
        while (pop(ignored)) {}
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\nChoice: ";
        if (!(cin >> choice)) return 0;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                if (stack.pop(value)) cout << "Popped: " << value << '\n';
                else cout << "Stack underflow: stack is empty.\n";
                break;
            case 3:
                if (stack.peek(value)) cout << "Top value: " << value << '\n';
                else cout << "Stack is empty.\n";
                break;
            case 4:
                stack.display();
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
