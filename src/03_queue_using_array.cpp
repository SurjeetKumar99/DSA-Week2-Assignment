#include <iostream>
using namespace std;

const int CAPACITY = 5;

class Queue {
private:
    int items[CAPACITY];
    int frontIndex;
    int rearIndex;

public:
    Queue() : frontIndex(0), rearIndex(-1) {}

    bool isEmpty() const { return rearIndex < frontIndex; }
    bool isFull() const { return rearIndex == CAPACITY - 1; }

    bool enqueue(int value) {
        if (isFull()) return false;
        items[++rearIndex] = value;
        return true;
    }

    bool dequeue(int& value) {
        if (isEmpty()) return false;
        value = items[frontIndex++];
        if (frontIndex > rearIndex) {
            frontIndex = 0;
            rearIndex = -1;
        }
        return true;
    }

    bool front(int& value) const {
        if (isEmpty()) return false;
        value = items[frontIndex];
        return true;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front -> ";
        for (int i = frontIndex; i <= rearIndex; ++i)
            cout << items[i] << (i < rearIndex ? " -> " : "");
        cout << " <- Rear\n";
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n0. Exit\nChoice: ";
        if (!(cin >> choice)) return 0;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << (queue.enqueue(value) ? "Enqueued.\n" : "Queue overflow: array is full.\n");
                break;
            case 2:
                if (queue.dequeue(value)) cout << "Dequeued: " << value << '\n';
                else cout << "Queue underflow: queue is empty.\n";
                break;
            case 3:
                if (queue.front(value)) cout << "Front value: " << value << '\n';
                else cout << "Queue is empty.\n";
                break;
            case 4:
                queue.display();
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
