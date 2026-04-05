#include <iostream>
using namespace std;

class TextEditor {
private:
    static const int size = 100;
    string undoStack[size];
    string redoStack[size];
    int undoTop;
    int redoTop;
    string text;

public:
    TextEditor() {
        undoTop = -1;
        redoTop = -1;
        text = "";
    }
    void push(string stack[], int& top, string value) {
        if (top == size - 1) {
            cout << "stack overFlow!\n";
            return;
        }
        stack[++top] = value;
    }
    string pop(string stack[], int& top) {
        if (top == -1) {
            return "";
        }
        return stack[top--];
    }
    void type(string str) {
        push(undoStack, undoTop, text);
        text += str;
         
        redoTop = -1;
        cout << "typed: " << str << endl;
    }
    void deleteText(int n) {
        if (n > text.length()) {
            cout << "cannot delete more than text length!\n";
            return;
        }
        push(undoStack, undoTop, text);
        text.erase(text.length() - n, n);
        redoTop = -1;

        cout << "deleted " << n << " characters\n";
    }
    void undo() {
        if (undoTop == -1) {
            cout << "nothing to undo!\n";
            return;
        }
        push(redoStack, redoTop, text);
        text = pop(undoStack, undoTop);

        cout << "Undo done\n";
    }
    void redo() {
        if (redoTop == -1) {
            cout << "nothing to redo!\n";
            return;
        }

        push(undoStack, undoTop, text);
        text = pop(redoStack, redoTop);

        cout << "redo done\n";
    }

    void show() {
        cout << "current Text: " << text << endl;
    }
};
int main() {
    TextEditor editor;

    int choice;
    string str;
    int n;

    do {
        cout << "1. type Text\n";
        cout << "2. delete Text\n";
        cout << "3. undo\n";
        cout << "4. redo\n";
        cout << "5. show Text\n";
        cout << "0. exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter text: ";
            cin >> str;
            editor.type(str);
            break;
        case 2:
            cout << "enter characters to delete: ";
            cin >> n;
            editor.deleteText(n);
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.show();
            break;

        case 0:
            cout << "exiting...\n";
            break;

        default:
            cout << "invalid choice!\n";
        }

    } while (choice != 0);
    return 0;
}