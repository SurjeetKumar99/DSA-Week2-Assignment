#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void typeText(const string& addition) {
        undoStack.push(text);
        text += addition;
        while (!redoStack.empty()) redoStack.pop();
        cout << "Text updated.\n";
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }
        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
        cout << "Undo successful.\n";
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }
        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
        cout << "Redo successful.\n";
    }

    void showText() const {
        cout << "Current text: \"" << text << "\"\n";
    }
};

int main() {
    TextEditor editor;
    int choice;
    string addition;

    do {
        cout << "\n1. Type/append text\n2. Undo\n3. Redo\n4. Show text\n0. Exit\nChoice: ";
        if (!(cin >> choice)) return 0;

        switch (choice) {
            case 1:
                cout << "Enter text to append (use underscores instead of spaces): ";
                cin >> addition;
                for (char& ch : addition) if (ch == '_') ch = ' ';
                editor.typeText(addition);
                break;
            case 2:
                editor.undo();
                break;
            case 3:
                editor.redo();
                break;
            case 4:
                editor.showText();
                break;
            case 0:
                cout << "Exiting editor simulation.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
