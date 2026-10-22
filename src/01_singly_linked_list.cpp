#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    explicit Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = node;
        cout << value << " inserted.\n";
    }

    bool deleteValue(int value) {
        if (head == nullptr) return false;

        if (head->data == value) {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value)
            current = current->next;

        if (current->next == nullptr) return false;

        Node* target = current->next;
        current->next = target->next;
        delete target;
        return true;
    }

    bool search(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value;

    do {
        cout << "\n1. Insert at end\n2. Delete value\n3. Search\n4. Display\n0. Exit\nChoice: ";
        if (!(cin >> choice)) return 0;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                cout << (list.deleteValue(value) ? "Deleted.\n" : "Value not found.\n");
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (list.search(value) ? "Found.\n" : "Not found.\n");
                break;
            case 4:
                list.display();
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
